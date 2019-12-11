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
 *          Gabe Black
 *          Steve Reinhardt
 */

#include "cpu/o3/regfile.hh"

#include "cpu/o3/free_list.hh"
#include "arch/generic/types.hh"
#include "cpu/o3/free_list.hh"

PhysRegFile::PhysRegFile(unsigned _numPhysicalIntRegs,
	unsigned _numPhysicalFloatRegs,
	unsigned _numPhysicalVecRegs,
	unsigned _numPhysicalCCRegs,

	unsigned _numPhysicalInt_0sh_Regs,
	unsigned _numPhysicalInt_1sh_Regs,
	unsigned _numPhysicalInt_2sh_Regs,
	unsigned _numPhysicalInt_3sh_Regs,

	unsigned _numPhysicalFloat_0sh_Regs,
	unsigned _numPhysicalFloat_1sh_Regs,
	unsigned _numPhysicalFloat_2sh_Regs,
	unsigned _numPhysicalFloat_3sh_Regs,

	unsigned _numPhysicalVec_0sh_Regs,
	unsigned _numPhysicalVec_1sh_Regs,
	unsigned _numPhysicalVec_2sh_Regs,
	unsigned _numPhysicalVec_3sh_Regs,

	unsigned _numPhysicalCC_0sh_Regs,
	unsigned _numPhysicalCC_1sh_Regs,
	unsigned _numPhysicalCC_2sh_Regs,
	unsigned _numPhysicalCC_3sh_Regs,

	VecMode vmode)

	: intRegFile(_numPhysicalIntRegs),
	floatRegFile(_numPhysicalFloatRegs),
	vectorRegFile(_numPhysicalVecRegs),
	ccRegFile(_numPhysicalCCRegs),
	numPhysicalIntRegs(_numPhysicalIntRegs),
	numPhysicalFloatRegs(_numPhysicalFloatRegs),
	numPhysicalVecRegs(_numPhysicalVecRegs),
	numPhysicalVecElemRegs(_numPhysicalVecRegs *
		NumVecElemPerVecReg),
	numPhysicalCCRegs(_numPhysicalCCRegs),


	numPhysicalInt_0sh_Regs(_numPhysicalInt_0sh_Regs),
	numPhysicalInt_1sh_Regs(_numPhysicalInt_1sh_Regs),
	numPhysicalInt_2sh_Regs(_numPhysicalInt_2sh_Regs),
	numPhysicalInt_3sh_Regs(_numPhysicalInt_3sh_Regs),

	numPhysicalFloat_0sh_Regs(_numPhysicalFloat_0sh_Regs),
	numPhysicalFloat_1sh_Regs(_numPhysicalFloat_1sh_Regs),
	numPhysicalFloat_2sh_Regs(_numPhysicalFloat_2sh_Regs),
	numPhysicalFloat_3sh_Regs(_numPhysicalFloat_3sh_Regs),

	numPhysicalVec_0sh_Regs(_numPhysicalVec_0sh_Regs),
	numPhysicalVec_1sh_Regs(_numPhysicalVec_1sh_Regs),
	numPhysicalVec_2sh_Regs(_numPhysicalVec_2sh_Regs),
	numPhysicalVec_3sh_Regs(_numPhysicalVec_3sh_Regs),

	numPhysicalCC_0sh_Regs(_numPhysicalCC_0sh_Regs),
	numPhysicalCC_1sh_Regs(_numPhysicalCC_1sh_Regs),
	numPhysicalCC_2sh_Regs(_numPhysicalCC_2sh_Regs),
	numPhysicalCC_3sh_Regs(_numPhysicalCC_3sh_Regs),


	totalNumRegs(_numPhysicalIntRegs
		+ _numPhysicalFloatRegs
		+ _numPhysicalVecRegs
		+ _numPhysicalVecRegs * NumVecElemPerVecReg
		+ _numPhysicalCCRegs),
	vecMode(vmode)
{
	PhysRegIndex phys_reg;
	PhysRegIndex flat_reg_idx = 0;

	if (TheISA::NumCCRegs == 0 && _numPhysicalCCRegs != 0) {
		// Just make this a warning and go ahead and allocate them
		// anyway, to keep from having to add checks everywhere
		warn("Non-zero number of physical CC regs specified, even though\n"
			"    ISA does not use them.\n");
	}
	//zsx debug:
	//printf("numPhyIntRegs=%u\nnumPhysFloatRegs=%u\nnumPhysVecRegs=%u\nnumPhysCCRegs=%u\n", numPhysicalIntRegs, numPhysicalFloatRegs, numPhysicalVecRegs, numPhysicalCCRegs);

	// The initial batch of registers are the integer ones
	for (phys_reg = 0; phys_reg < numPhysicalIntRegs; phys_reg++) {
		intRegIds.emplace_back(IntRegClass, phys_reg, flat_reg_idx++);
		
		assert(numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs + numPhysicalInt_3sh_Regs == numPhysicalIntRegs);

		//zsx add: init shadow cells
		if (phys_reg < numPhysicalInt_0sh_Regs)
		{
			intRegFile[phys_reg].type = non_sh;
			//intRegFile[phys_reg].main_status = 0;
			intRegFile[phys_reg].sh_status[0] = 0;
			intRegFile[phys_reg].sh_status[1] = -1;
			intRegFile[phys_reg].sh_status[2] = -1;
			intRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalInt_0sh_Regs && phys_reg < numPhysicalInt_1sh_Regs + numPhysicalInt_0sh_Regs)
		{
			intRegFile[phys_reg].type = one_sh;
			//intRegFile[phys_reg].main_status = 0;
			intRegFile[phys_reg].sh_status[0] = 0;
			intRegFile[phys_reg].sh_status[1] = 0;
			intRegFile[phys_reg].sh_status[2] = -1;
			intRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalInt_1sh_Regs + numPhysicalInt_0sh_Regs && phys_reg < numPhysicalInt_1sh_Regs + numPhysicalInt_0sh_Regs + numPhysicalInt_2sh_Regs)
		{
			intRegFile[phys_reg].type = two_sh;
			//intRegFile[phys_reg].main_status = 0;
			intRegFile[phys_reg].sh_status[0] = 0;
			intRegFile[phys_reg].sh_status[1] = 0;
			intRegFile[phys_reg].sh_status[2] = 0;
			intRegFile[phys_reg].sh_status[3] = -1;
		}
		else if(phys_reg >= numPhysicalInt_1sh_Regs + numPhysicalInt_0sh_Regs + numPhysicalInt_2sh_Regs && phys_reg < numPhysicalIntRegs)
		{
			intRegFile[phys_reg].type = three_sh;
			//intRegFile[phys_reg].main_status = 0;
			intRegFile[phys_reg].sh_status[0] = 0;
			intRegFile[phys_reg].sh_status[1] = 0;
			intRegFile[phys_reg].sh_status[2] = 0;
			intRegFile[phys_reg].sh_status[3] = 0;
		}
	}
	//printf("int regfile constructed succeed! non=%d, one=%d, two=%d, three=%d\n", numPhysicalInt_0sh_Regs, numPhysicalInt_1sh_Regs, numPhysicalInt_2sh_Regs, numPhysicalInt_3sh_Regs);


	// The next batch of the registers are the floating-point physical
	// registers; put them onto the floating-point free list.
	for (phys_reg = 0; phys_reg < numPhysicalFloatRegs; phys_reg++) {
		floatRegIds.emplace_back(FloatRegClass, phys_reg, flat_reg_idx++);

		assert(numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs + numPhysicalFloat_3sh_Regs == numPhysicalFloatRegs);
		//zsx add: init shadow cells
		if (phys_reg < numPhysicalFloat_0sh_Regs)
		{
			floatRegFile[phys_reg].type = non_sh;
			//floatRegFile[phys_reg].main_status = 0;
			floatRegFile[phys_reg].sh_status[0] = 0;
			floatRegFile[phys_reg].sh_status[1] = -1;
			floatRegFile[phys_reg].sh_status[2] = -1;
			floatRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalFloat_0sh_Regs && phys_reg < numPhysicalFloat_1sh_Regs + numPhysicalFloat_0sh_Regs)
		{
			floatRegFile[phys_reg].type = one_sh;
			//floatRegFile[phys_reg].main_status = 0;
			floatRegFile[phys_reg].sh_status[0] = 0;
			floatRegFile[phys_reg].sh_status[1] = 0;
			floatRegFile[phys_reg].sh_status[2] = -1;
			floatRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalFloat_1sh_Regs + numPhysicalFloat_0sh_Regs && phys_reg < numPhysicalFloat_1sh_Regs + numPhysicalFloat_0sh_Regs + numPhysicalFloat_2sh_Regs)
		{
			floatRegFile[phys_reg].type = two_sh;
			//floatRegFile[phys_reg].main_status = 0;
			floatRegFile[phys_reg].sh_status[0] = 0;
			floatRegFile[phys_reg].sh_status[1] = 0;
			floatRegFile[phys_reg].sh_status[2] = 0;
			floatRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalFloat_1sh_Regs + numPhysicalFloat_0sh_Regs + numPhysicalFloat_2sh_Regs && phys_reg < numPhysicalFloatRegs)
		{
			floatRegFile[phys_reg].type = three_sh;
			//floatRegFile[phys_reg].main_status = 0;
			floatRegFile[phys_reg].sh_status[0] = 0;
			floatRegFile[phys_reg].sh_status[1] = 0;
			floatRegFile[phys_reg].sh_status[2] = 0;
			floatRegFile[phys_reg].sh_status[3] = 0;
		}

	}
	//printf("float regfile constructed succeed! non=%d, one=%d, two=%d, three=%d\n", numPhysicalFloat_0sh_Regs, numPhysicalFloat_1sh_Regs, numPhysicalFloat_2sh_Regs, numPhysicalFloat_3sh_Regs);

	// The next batch of the registers are the vector physical
	// registers; put them onto the vector free list.
	for (phys_reg = 0; phys_reg < numPhysicalVecRegs; phys_reg++) {
		vectorRegFile[phys_reg].main_cell.zero();
		vecRegIds.emplace_back(VecRegClass, phys_reg, flat_reg_idx++);

		assert(numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs + numPhysicalVec_3sh_Regs == numPhysicalVecRegs);
		if (phys_reg < numPhysicalVec_0sh_Regs)
		{
			vectorRegFile[phys_reg].type = non_sh;
			//vectorRegFile[phys_reg].main_status = 0;
			vectorRegFile[phys_reg].sh_status[0] = 0;
			vectorRegFile[phys_reg].sh_status[1] = -1;
			vectorRegFile[phys_reg].sh_status[2] = -1;
			vectorRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalVec_0sh_Regs && phys_reg < numPhysicalVec_1sh_Regs + numPhysicalVec_0sh_Regs)
		{
			vectorRegFile[phys_reg].type = one_sh;
			//vectorRegFile[phys_reg].main_status = 0;
			vectorRegFile[phys_reg].sh_status[0] = 0;
			vectorRegFile[phys_reg].sh_status[1] = 0;
			vectorRegFile[phys_reg].sh_status[2] = -1;
			vectorRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalVec_1sh_Regs + numPhysicalVec_0sh_Regs && phys_reg < numPhysicalVec_1sh_Regs + numPhysicalVec_0sh_Regs + numPhysicalVec_2sh_Regs)
		{
			vectorRegFile[phys_reg].type = two_sh;
			//vectorRegFile[phys_reg].main_status = 0;
			vectorRegFile[phys_reg].sh_status[0] = 0;
			vectorRegFile[phys_reg].sh_status[1] = 0;
			vectorRegFile[phys_reg].sh_status[2] = 0;
			vectorRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalVec_1sh_Regs + numPhysicalVec_0sh_Regs + numPhysicalVec_2sh_Regs && phys_reg < numPhysicalVecRegs)
		{
			vectorRegFile[phys_reg].type = three_sh;
			//vectorRegFile[phys_reg].main_status = 0;
			vectorRegFile[phys_reg].sh_status[0] = 0;
			vectorRegFile[phys_reg].sh_status[1] = 0;
			vectorRegFile[phys_reg].sh_status[2] = 0;
			vectorRegFile[phys_reg].sh_status[3] = 0;
		}

	}
	//printf("vec regfile constructed succeed! non=%d, one=%d, two=%d, three=%d\n", numPhysicalVec_0sh_Regs, numPhysicalVec_1sh_Regs, numPhysicalVec_2sh_Regs, numPhysicalVec_3sh_Regs);

	// The next batch of the registers are the vector element physical
	// registers; they refer to the same containers as the vector
	// registers, just a different (and incompatible) way to access
	// them; put them onto the vector free list.
	for (phys_reg = 0; phys_reg < numPhysicalVecRegs; phys_reg++) {
		for (ElemIndex eIdx = 0; eIdx < NumVecElemPerVecReg; eIdx++) {
			vecElemIds.emplace_back(VecElemClass, phys_reg,
				eIdx, flat_reg_idx++);
		}
	}
	//printf("vec elem regfile constructed succeed!\n");

	// The rest of the registers are the condition-code physical
	// registers; put them onto the condition-code free list.
	for (phys_reg = 0; phys_reg < numPhysicalCCRegs; phys_reg++) {
		ccRegIds.emplace_back(CCRegClass, phys_reg, flat_reg_idx++);

		assert(numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs + numPhysicalCC_3sh_Regs == numPhysicalCCRegs);
		if (phys_reg < numPhysicalCC_0sh_Regs)
		{
			ccRegFile[phys_reg].type = non_sh;
			//ccRegFile[phys_reg].main_status = 0;
			ccRegFile[phys_reg].sh_status[0] = 0;
			ccRegFile[phys_reg].sh_status[1] = -1;
			ccRegFile[phys_reg].sh_status[2] = -1;
			ccRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalCC_0sh_Regs && phys_reg < numPhysicalCC_1sh_Regs + numPhysicalCC_0sh_Regs)
		{
			ccRegFile[phys_reg].type = one_sh;
			//ccRegFile[phys_reg].main_status = 0;
			ccRegFile[phys_reg].sh_status[0] = 0;
			ccRegFile[phys_reg].sh_status[1] = 0;
			ccRegFile[phys_reg].sh_status[2] = -1;
			ccRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalCC_1sh_Regs + numPhysicalCC_0sh_Regs && phys_reg < numPhysicalCC_1sh_Regs + numPhysicalCC_0sh_Regs + numPhysicalCC_2sh_Regs)
		{
			ccRegFile[phys_reg].type = two_sh;
			//ccRegFile[phys_reg].main_status = 0;
			ccRegFile[phys_reg].sh_status[0] = 0;
			ccRegFile[phys_reg].sh_status[1] = 0;
			ccRegFile[phys_reg].sh_status[2] = 0;
			ccRegFile[phys_reg].sh_status[3] = -1;
		}
		else if (phys_reg >= numPhysicalCC_1sh_Regs + numPhysicalCC_0sh_Regs + numPhysicalCC_2sh_Regs && phys_reg < numPhysicalCCRegs)
		{
			ccRegFile[phys_reg].type = three_sh;
			//ccRegFile[phys_reg].main_status = 0;
			ccRegFile[phys_reg].sh_status[0] = 0;
			ccRegFile[phys_reg].sh_status[1] = 0;
			ccRegFile[phys_reg].sh_status[2] = 0;
			ccRegFile[phys_reg].sh_status[3] = 0;
		}

	}
	//printf("cc regfile constructed succeed! non=%d, one=%d, two=%d, three=%d\n", numPhysicalCC_0sh_Regs, numPhysicalCC_1sh_Regs, numPhysicalCC_2sh_Regs, numPhysicalCC_3sh_Regs);
	// Misc regs have a fixed mapping but still need PhysRegIds.
	for (phys_reg = 0; phys_reg < TheISA::NumMiscRegs; phys_reg++) {
		miscRegIds.emplace_back(MiscRegClass, phys_reg, 0);
	}
}

/*
void PhysRegFile::initRegPredictTable(RegPredictTable * regpredicttable)
{

}
*/
/*void PhysRegFile::initPhyRegTable(PhyRegTable * _phyRegTable)
{
	//phyRegTable(totalNumRegs);
	_phyRegTable->PhyRegTableArray.reserve(totalNumRegs);
	phyRegTable = _phyRegTable;
}
*/
void
PhysRegFile::initFreeList(UnifiedFreeList *freeList)
{
	// Initialize the free lists.
	int reg_idx = 0;

	// The initial batch of registers are the integer ones
	for (reg_idx = 0; reg_idx < numPhysicalIntRegs; reg_idx++) {
		assert(intRegIds[reg_idx].index() == reg_idx);
	}
	
	//zsx change:
	
	freeList->addRegs(intRegIds.begin(), intRegIds.begin()+numPhysicalInt_0sh_Regs, 0);
	freeList->addRegs(intRegIds.begin()+ numPhysicalInt_0sh_Regs, intRegIds.begin()+numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs, 1);
	freeList->addRegs(intRegIds.begin()+ numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs, intRegIds.begin()+ numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs, 2);
	freeList->addRegs(intRegIds.begin()+ numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs, intRegIds.begin()+numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs + numPhysicalInt_3sh_Regs, 3);
	

	/*freeList->addRegs(intRegIds, 0, numPhysicalInt_0sh_Regs, 0);
	freeList->addRegs(intRegIds, numPhysicalInt_0sh_Regs + 1, numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs, 1);
	freeList->addRegs(intRegIds, numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + 1, numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs, 2);
	freeList->addRegs(intRegIds, numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs + 1, numPhysicalInt_0sh_Regs + numPhysicalInt_1sh_Regs + numPhysicalInt_2sh_Regs + numPhysicalInt_3sh_Regs, 3);
	*/
	//printf("int freelist constructed succeed!\n");


	// The next batch of the registers are the floating-point physical
	// registers; put them onto the floating-point free list.
	for (reg_idx = 0; reg_idx < numPhysicalFloatRegs; reg_idx++) {
		assert(floatRegIds[reg_idx].index() == reg_idx);
	}
	//freeList->addRegs(floatRegIds.begin(), floatRegIds.end());
	
	freeList->addRegs(floatRegIds.begin(), floatRegIds.begin()+numPhysicalFloat_0sh_Regs, 0);
	freeList->addRegs(floatRegIds.begin()+ numPhysicalFloat_0sh_Regs, floatRegIds.begin()+numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs, 1);
	freeList->addRegs(floatRegIds.begin()+numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs, floatRegIds.begin()+numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs, 2);
	freeList->addRegs(floatRegIds.begin() + numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs, floatRegIds.begin() + numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs + numPhysicalFloat_3sh_Regs, 3);

	/*
	freeList->addRegs(floatRegIds, 0, numPhysicalFloat_0sh_Regs, 0);
	freeList->addRegs(floatRegIds, numPhysicalFloat_0sh_Regs + 1, numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs, 1);
	freeList->addRegs(floatRegIds, numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + 1, numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs, 2);
	freeList->addRegs(floatRegIds, numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs + 1, numPhysicalFloat_0sh_Regs + numPhysicalFloat_1sh_Regs + numPhysicalFloat_2sh_Regs + numPhysicalFloat_3sh_Regs, 3);
*/

	//printf("float freelist constructed succeed!\n");
	/* The next batch of the registers are the vector physical
	 * registers; put them onto the vector free list. */
	for (reg_idx = 0; reg_idx < numPhysicalVecRegs; reg_idx++) {
		assert(vecRegIds[reg_idx].index() == reg_idx);
		for (ElemIndex elemIdx = 0; elemIdx < NumVecElemPerVecReg; elemIdx++) {
			assert(vecElemIds[reg_idx * NumVecElemPerVecReg +
				elemIdx].index() == reg_idx);
			assert(vecElemIds[reg_idx * NumVecElemPerVecReg +
				elemIdx].elemIndex() == elemIdx);
		}
	}
	


	/* depending on the mode we add the vector registers as whole units or
	 * as different elements. */
	if (vecMode == Enums::Full)
		//freeList->addRegs(vecRegIds.begin(), vecRegIds.end());
	{
		//zsx add: init vector register, four types
		//printf("vecMode=Full\n");
		freeList->addRegs(vecRegIds.begin(), vecRegIds.begin() + numPhysicalVec_0sh_Regs, 0);
		//printf("add 0 type vec reg to free list succeed!\n");
		freeList->addRegs(vecRegIds.begin() + numPhysicalVec_0sh_Regs, vecRegIds.begin() + numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs, 1);
		//printf("add 1 type vec reg to free list succeed!\n");
		freeList->addRegs(vecRegIds.begin() + numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs, vecRegIds.begin() + numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs, 2);
		//printf("add 2 type vec reg to free list succeed!\n");
		freeList->addRegs(vecRegIds.begin() + numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs, vecRegIds.begin() + numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs + numPhysicalVec_3sh_Regs, 3);
		//("add 3 type vec reg to free list succeed!\n");

		/*
		freeList->addRegs(vecRegIds, 0, numPhysicalVec_0sh_Regs, 0);
		freeList->addRegs(vecRegIds, numPhysicalVec_0sh_Regs + 1, numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs, 1);
		freeList->addRegs(vecRegIds, numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + 1, numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs, 2);
		freeList->addRegs(vecRegIds, numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs + 1, numPhysicalVec_0sh_Regs + numPhysicalVec_1sh_Regs + numPhysicalVec_2sh_Regs + numPhysicalVec_3sh_Regs, 3);
		*/
	}
	else
	{
		//printf("vecMode=Elem\n");
		freeList->addRegs(vecElemIds.begin(), vecElemIds.end(), 0);
	}
		
	//printf("vec freelist constructed succeed!\n");
	// The rest of the registers are the condition-code physical
	// registers; put them onto the condition-code free list.
	for (reg_idx = 0; reg_idx < numPhysicalCCRegs; reg_idx++) {
		assert(ccRegIds[reg_idx].index() == reg_idx);
	}
	//freeList->addRegs(ccRegIds.begin(), ccRegIds.end());
	//zsx change:
	freeList->addRegs(ccRegIds.begin(), ccRegIds.begin()+numPhysicalCC_0sh_Regs, 0);
	freeList->addRegs(ccRegIds.begin() + numPhysicalCC_0sh_Regs, ccRegIds.begin() + numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs, 1);
	freeList->addRegs(ccRegIds.begin() + numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs, ccRegIds.begin() + numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs, 2);
	freeList->addRegs(ccRegIds.begin() + numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs, ccRegIds.begin() + numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs + numPhysicalCC_3sh_Regs, 3);
	

	/*
	freeList->addRegs(ccRegIds, 0, numPhysicalCC_0sh_Regs, 0);
	freeList->addRegs(ccRegIds, numPhysicalCC_0sh_Regs + 1, numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs, 1);
	freeList->addRegs(ccRegIds, numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + 1, numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs, 2);
	freeList->addRegs(ccRegIds, numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs + 1, numPhysicalCC_0sh_Regs + numPhysicalCC_1sh_Regs + numPhysicalCC_2sh_Regs + numPhysicalCC_3sh_Regs, 3);
	*/
	//printf("cc freelist constructed succeed!\n");
}




auto
PhysRegFile::getRegElemIds(PhysRegIdPtr reg) -> IdRange
{
	panic_if(!reg->isVectorPhysReg(),
		"Trying to get elems of a %s register", reg->className());
	auto idx = reg->index();
	return std::make_pair(
		vecElemIds.begin() + idx * NumVecElemPerVecReg,
		vecElemIds.begin() + (idx + 1) * NumVecElemPerVecReg);
}

auto
PhysRegFile::getRegIds(RegClass cls) -> IdRange
{
	switch (cls)
	{
	case IntRegClass:
		return std::make_pair(intRegIds.begin(), intRegIds.end());
	case FloatRegClass:
		return std::make_pair(floatRegIds.begin(), floatRegIds.end());
	case VecRegClass:
		return std::make_pair(vecRegIds.begin(), vecRegIds.end());
	case VecElemClass:
		return std::make_pair(vecElemIds.begin(), vecElemIds.end());
	case CCRegClass:
		return std::make_pair(ccRegIds.begin(), ccRegIds.end());
	case MiscRegClass:
		return std::make_pair(miscRegIds.begin(), miscRegIds.end());
	}
	/* There is no way to make an empty iterator */
	return std::make_pair(PhysIds::const_iterator(),
		PhysIds::const_iterator());
}

PhysRegIdPtr
PhysRegFile::getTrueId(PhysRegIdPtr reg)
{
	switch (reg->classValue()) {
	case VecRegClass:
		return &vecRegIds[reg->index()];
	case VecElemClass:
		return &vecElemIds[reg->index() * NumVecElemPerVecReg +
			reg->elemIndex()];
	default:
		panic_if(!reg->isVectorPhysElem(),
			"Trying to get the register of a %s register", reg->className());
	}
	return nullptr;
}


