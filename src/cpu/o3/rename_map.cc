/*
 * Copyright (c) 2016 ARM Limited
 * All rights reserved
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder. You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright (c) 2004-2005 The Regents of The University of Michigan
 * Copyright (c) 2013 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Kevin Lim
 */

#include "cpu/o3/rename_map.hh"

#include <vector>

#include "cpu/reg_class_impl.hh"
#include "debug/Rename.hh"

using namespace std;

/**** SimpleRenameMap methods ****/

SimpleRenameMap::SimpleRenameMap()
	: freeList(NULL), zeroReg(IntRegClass, 0)
{
}


void
SimpleRenameMap::init(unsigned size, SimpleFreeList *_freeList,
	RegIndex _zeroReg)
{
	assert(freeList == NULL);
	assert(map.empty());

	map.resize(size);
	freeList = _freeList;
	zeroReg = RegId(IntRegClass, _zeroReg);
}

SimpleRenameMap::RenameInfo
SimpleRenameMap::rename(const RegId& arch_reg, int RegType)
{
	Rename_Result renamed_reg;
	// Record the current physical register that is renamed to the
	// requested architected register.
	Rename_Result prev_reg = map[arch_reg.index()];

	// If it's not referencing the zero register, then rename the
	// register.
	if (arch_reg != zeroReg) {
		if (freeList->hasFreeRegs(RegType))
		{
			renamed_reg.first = freeList->getReg(RegType);
			renamed_reg.second = 0;
		}
		else
		{

			//zsx add: if there is no such type registers, find other types.
			int min_distance = 3;
			int result_type = RegType;
			for (int i = 3; i >= 0; i--)
			{
				if((i != RegType) && (freeList->hasFreeRegs(i)) && (abs(i - RegType) <= min_distance))
				{
					min_distance = abs(i - RegType);
					result_type = i;
				}
			}
			//printf("result_type=%d\n", result_type);
			renamed_reg.first = freeList->getReg(result_type);
		}

		map[arch_reg.index()].first = renamed_reg.first;
		map[arch_reg.index()].second = 0;
		renamed_reg.second = 0;
		//regFile->
	}
	else {
		// Otherwise return the zero register so nothing bad happens.
		assert(prev_reg.first->isZeroReg());
		renamed_reg = prev_reg;
	}

	DPRINTF(Rename, "Renamed reg %d to physical reg %d (%d) counter=%d old mapping was"
		" %d (%d) counter=%d\n",
		arch_reg, renamed_reg.first->index(), renamed_reg.first->flatIndex(), renamed_reg.second, 
		prev_reg.first->index(), prev_reg.first->flatIndex(), prev_reg.second);

	return RenameInfo(renamed_reg, prev_reg);
}


/**** UnifiedRenameMap methods ****/

void
UnifiedRenameMap::init(PhysRegFile *_regFile,
	RegIndex _intZeroReg,
	RegIndex _floatZeroReg,
	UnifiedFreeList *freeList,
	VecMode _mode)
{
	regFile = _regFile;
	vecMode = _mode;

	intMap.init(TheISA::NumIntRegs, &(freeList->intList), _intZeroReg);

	floatMap.init(TheISA::NumFloatRegs, &(freeList->floatList), _floatZeroReg);

	vecMap.init(TheISA::NumVecRegs, &(freeList->vecList), (RegIndex)-1);

	vecElemMap.init(TheISA::NumVecRegs * NVecElems,
		&(freeList->vecElemList), (RegIndex)-1);

	ccMap.init(TheISA::NumCCRegs, &(freeList->ccList), (RegIndex)-1);

}

void
UnifiedRenameMap::switchMode(VecMode newVecMode, UnifiedFreeList* freeList)
{
	if (newVecMode == Enums::Elem && vecMode == Enums::Full) {
		/* Switch to vector element rename mode. */
		/* The free list should currently be tracking full registers. */
		panic_if(freeList->hasAnyFreeVecElems(),
			"The free list is already tracking Vec elems");
		panic_if((freeList->numFreeVecRegs(0) + freeList->numFreeVecRegs(1) + freeList->numFreeVecRegs(2) + freeList->numFreeVecRegs(3)) !=
			regFile->numVecPhysRegs() - TheISA::NumVecRegs,
			"The free list has lost vector registers");
		/* Split the mapping of each arch reg. */
		int reg = 0;
		for (auto &e : vecMap) {
			PhysRegFile::IdRange range = this->regFile->getRegElemIds(e.first);
			uint32_t i;
			for (i = 0; range.first != range.second; i++, range.first++) {
				vecElemMap.setEntry(RegId(VecElemClass, reg, i),
					&(*range.first), 0);
			}
			panic_if(i != NVecElems,
				"Wrong name of elems: expecting %u, got %d\n",
				TheISA::NumVecElemPerVecReg, i);
			reg++;
		}
		/* Split the free regs. */
		//zsx change:
		//std::vector<PhysRegId>::const_iterator it;
		//it = regFile->vecElemIds.begin();
		while (freeList->hasAnyFreeVecRegs()) {
			for (int i = 0; i < 4; i++)
			{
				auto vr = freeList->getVecReg(i);
				auto range = this->regFile->getRegElemIds(vr);
				//freeList->addRegs(regFile->vecElemIds, std::distance(range.first, it), std::distance(range.second, it), i);
				freeList->addRegs(range.first, range.second, i);
			}
			
		}
		vecMode = Enums::Elem;
	}

	else if (newVecMode == Enums::Full && vecMode == Enums::Elem) {
		/* Switch to full vector register rename mode. */
		/* The free list should currently be tracking register elems. */
		panic_if(freeList->hasAnyFreeVecRegs(),
			"The free list is already tracking full Vec");
		panic_if(freeList->numFreeVecRegs(0) !=
			regFile->numVecElemPhysRegs() - TheISA::NumFloatRegs,
			"The free list has lost vector register elements");
		/* To rebuild the arch regs we take the easy road:
		 *  1.- Stitch the elems together into vectors.
		 *  2.- Replace the contents of the register file with the vectors
		 *  3.- Set the remaining registers as free
		 */
		TheISA::VecRegContainer new_RF[TheISA::NumVecRegs];
		for (uint32_t i = 0; i < TheISA::NumVecRegs; i++) {
			VecReg dst = new_RF[i].as<TheISA::VecElem>();
			for (uint32_t l = 0; l < NVecElems; l++) {
				RegId s_rid(VecElemClass, i, l);
				PhysRegIdPtr s_prid = vecElemMap.lookup(s_rid).first;
				dst[l] = regFile->readVecElem(s_prid);
			}
		}

		for (uint32_t i = 0; i < TheISA::NumVecRegs; i++) {
			PhysRegId pregId(VecRegClass, i, 0);
			regFile->setVecReg(regFile->getTrueId(&pregId), 0, new_RF[i]);
		}

		//zsx change:
		//std::vector<PhysRegId>::const_iterator it;
		//it = regFile->vecRegIds.begin();
		auto range = regFile->getRegIds(VecRegClass);
		//freeList->addRegs(regFile->vecRegIds, std::distance(range.first, it) + TheISA::NumVecRegs, std::distance(range.second, it), 0);
		freeList->addRegs(range.first + TheISA::NumVecRegs, range.second, 0);

		//zsx change:
		/* We remove the elems from the free list. */
		for (int i = 0; i < 4; i++)
		{
			while (freeList->hasFreeVecElems(i))
			{
				freeList->getVecElem(i);
			}
		}
		
		vecMode = Enums::Full;
	}
}


