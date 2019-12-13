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

#ifndef __CPU_O3_FREE_LIST_HH__
#define __CPU_O3_FREE_LIST_HH__

#include <iostream>
#include <queue>
#include <vector>

#include "base/logging.hh"
#include "base/trace.hh"
#include "cpu/o3/comm.hh"
#include "cpu/o3/regfile.hh"
#include "debug/FreeList.hh"

 /**
  * Free list for a single class of registers (e.g., integer
  * or floating point).  Because the register class is implicitly
  * determined by the rename map instance being accessed, all
  * architectural register index parameters and values in this class
  * are relative (e.g., %fp2 is just index 2).
  */
class SimpleFreeList
{
public:

	/** The actual free list */
	//zsx add: freelist is orangized as four queues, each indicates having n shadow cells
	//using freeReg = std::queue<PhysRegIdPtr>;

	std::vector<std::queue<PhysRegIdPtr>> freeRegs;

public:

	SimpleFreeList() {};

	/** Add a physical register to the free list */
	//zsx add: emphasize which regtype it is
	void addReg(PhysRegIdPtr reg, int RegType) { (freeRegs[RegType]).push(reg); }

	/*
	//zsx change:
	template<class InputIt>
	void
		addRegs(InputIt first, InputIt last, int RegType) {
		std::for_each(first, last,
			std::bind2nd(std::ptr_fun(this->FreeRegs_Add(typename InputIt::value_type& reg, RegType))));
	}
	*/
	/*
	//Add physical registers to the free list 
	template<class InputIt>
	void
		addRegs(InputIt first, InputIt last, int RegType) {
		std::for_each(first, last,
			[this](const typename InputIt::value_type& reg, int RegType) {
			this->freeRegs[RegType].push(&reg);
		});
	}
	*/
	/*
	template<class InputIt>
	void
		addRegs(InputIt first, InputIt last, int RegType) {
		//typename InputIt::value_type reg;
		
		//typename std::vector<PhysRegId> 

		for (typename InputIt::value_type reg = first; reg != last; ++reg)
		{
			freeRegs[RegType].push(reg);
		}

		//if(InputIt::value_type = intRegIds)

	}

	

	void addRegs(std::vector<PhysRegId> RegIds, int first, int last, int RegType)
	{
		printf("begin add regs:\n");
		for (int i = first; i < last; i++)
		{
			(freeRegs[RegType]).push(&(RegIds[i]));
			//printf("add reg:%d\n",i);
		}
		
	}
	*/


	//Add physical registers to the free list 
	template<class InputIt>
	void
		addRegs(InputIt first, InputIt last, int RegType) {

		if (RegType == 0)
		{
			std::for_each(first, last,
				[this](const typename InputIt::value_type& reg) {
				this->freeRegs[0].push(&reg);
			});
		}
		else if (RegType == 1)
		{
			std::for_each(first, last,
				[this](const typename InputIt::value_type& reg) {
				this->freeRegs[1].push(&reg);
			});
		}
		else if (RegType == 2)
		{
			std::for_each(first, last,
				[this](const typename InputIt::value_type& reg) {
				this->freeRegs[2].push(&reg);
			});
		}
		else if (RegType == 3)
		{
			std::for_each(first, last,
				[this](const typename InputIt::value_type& reg) {
				this->freeRegs[3].push(&reg);
			});
		}
		else
		{
			//printf("wrong reg type!\n");
		}
	}


	/** Get the next available register from the free list */
	PhysRegIdPtr getReg(int RegType)
	{
		assert(!freeRegs[RegType].empty());
		PhysRegIdPtr free_reg = freeRegs[RegType].front();
		freeRegs[RegType].pop();

		DPRINTF(FreeList, "delete reg from freelist index=%d\n", free_reg->index());

		return free_reg;
	}

	/** Return the number of free registers on the list. */
	unsigned numFreeRegs(int RegType) const { return freeRegs[RegType].size(); }

	unsigned numMinFreeRegs()
	{
		return std::min(
			std::min(numFreeRegs(0), numFreeRegs(1)),
			std::min(numFreeRegs(2), numFreeRegs(3))
		);
	}

	unsigned numMaxFreeRegs()
	{
		return std::max(
			std::max(numFreeRegs(0), numFreeRegs(1)),
			std::max(numFreeRegs(2), numFreeRegs(3))
		);
	}

	unsigned numSumFreeRegs()
	{
		return numFreeRegs(0) + numFreeRegs(1) + numFreeRegs(2) + numFreeRegs(3);
	}

	/** True iff there are free registers on the list. */
	bool hasFreeRegs(int RegType) const { return !freeRegs[RegType].empty(); }

	bool hasAnyFreeRegs()
	{
		return hasFreeRegs(0) || hasFreeRegs(1) || hasFreeRegs(2) || hasFreeRegs(3);
	}
};


/**
 * FreeList class that simply holds the list of free integer and floating
 * point registers.  Can request for a free register of either type, and
 * also send back free registers of either type.  This is a very simple
 * class, but it should be sufficient for most implementations.  Like all
 * other classes, it assumes that the indices for the floating point
 * registers starts after the integer registers end.  Hence the variable
 * numPhysicalIntRegs is logically equivalent to the baseFP dependency.
 * Note that while this most likely should be called FreeList, the name
 * "FreeList" is used in a typedef within the CPU Policy, and therefore no
 * class can be named simply "FreeList".
 * @todo: Give a better name to the base FP dependency.
 */
class UnifiedFreeList
{
public:

	/** The object name, for DPRINTF.  We have to declare this
	 *  explicitly because Scoreboard is not a SimObject. */
	const std::string _name;

	/** The list of free integer registers. */
	SimpleFreeList intList;

	/** The list of free floating point registers. */
	SimpleFreeList floatList;

	/** The following two are exclusive interfaces. */
	/** @{ */
	/** The list of free vector registers. */
	SimpleFreeList vecList;

	/** The list of free vector element registers. */

	//zsx add: vecElem has no four types registers, it is only the one type
	//std::queue<PhysRegIdPtr> vecElemList;
	SimpleFreeList vecElemList;
	/** @} */

	/** The list of free condition-code registers. */
	SimpleFreeList ccList;

	/**
	 * The register file object is used only to distinguish integer
	 * from floating-point physical register indices.
	 */
	PhysRegFile *regFile;

	/*
	 * We give UnifiedRenameMap internal access so it can get at the
	 * internal per-class free lists and associate those with its
	 * per-class rename maps. See UnifiedRenameMap::init().
	 */
	friend class UnifiedRenameMap;

public:
	/** Constructs a free list.
	 *  @param _numPhysicalIntRegs Number of physical integer registers.
	 *  @param reservedIntRegs Number of integer registers already
	 *                         used by initial mappings.
	 *  @param _numPhysicalFloatRegs Number of physical fp registers.
	 *  @param reservedFloatRegs Number of fp registers already
	 *                           used by initial mappings.
	 */
	UnifiedFreeList(const std::string &_my_name, PhysRegFile *_regFile);

	/** Gives the name of the freelist. */
	std::string name() const { return _name; };

	/** Returns a pointer to the condition-code free list */
	SimpleFreeList *getCCList() { return &ccList; }

	/** Gets a free integer register. */
	PhysRegIdPtr getIntReg(int RegType) { 
		//PhysRegIdPtr free_reg;
		//regFile->intRegFile[free_reg.index()].sh_free[RegType]
		return intList.getReg(RegType); 
	}

	/** Gets a free fp register. */
	PhysRegIdPtr getFloatReg(int RegType) { return floatList.getReg(RegType); }

	/** Gets a free vector register. */
	PhysRegIdPtr getVecReg(int RegType) { return vecList.getReg(RegType); }

	/** Gets a free vector elemenet register. */
	//zsx change:
	
	PhysRegIdPtr getVecElem(int RegType) { return vecElemList.getReg(RegType); }

	/*
	PhysRegIdPtr getVecElem() { 
		PhysRegIdPtr free_reg = vecElemList.front();
		vecElemList.pop();
		return free_reg;
	}
	*/
	/** Gets a free cc register. */
	PhysRegIdPtr getCCReg(int RegType) { return ccList.getReg(RegType); }



	/** Adds a register back to the free list. */
	void addReg(PhysRegIdPtr freed_reg, int RegType);

	//zsx add
	//void addRegs(std::vector<PhysRegId> RegIds, int first, int last, int RegType);

	//Adds a register back to the free list. 
	template<class InputIt>
	void addRegs(InputIt first, InputIt last, int RegType);

	/** Adds an integer register back to the free list. */
	void addIntReg(PhysRegIdPtr freed_reg, int RegType) { intList.addReg(freed_reg, RegType); }

	/** Adds a fp register back to the free list. */
	void addFloatReg(PhysRegIdPtr freed_reg, int RegType) { floatList.addReg(freed_reg, RegType); }

	/** Adds a vector register back to the free list. */
	void addVecReg(PhysRegIdPtr freed_reg, int RegType) { vecList.addReg(freed_reg, RegType); }

	/** Adds a vector element register back to the free list. */
	//zsx change:
	void addVecElem(PhysRegIdPtr freed_reg, int RegType) {
		vecElemList.addReg(freed_reg, RegType);
		//vecElemList.push(freed_reg);
	}

	/** Adds a cc register back to the free list. */
	void addCCReg(PhysRegIdPtr freed_reg, int RegType) { ccList.addReg(freed_reg, RegType); }




	/** Checks if there are any free integer registers. */
	bool hasFreeIntRegs(int RegType) const { return intList.hasFreeRegs(RegType); }
	bool hasAnyIntRegs()
	{
		return intList.hasAnyFreeRegs();
	}

	/** Checks if there are any free fp registers. */
	bool hasFreeFloatRegs(int RegType) const { return floatList.hasFreeRegs(RegType); }
	bool hasAnyFloatRegs()
	{
		return floatList.hasAnyFreeRegs();
	}

	/** Checks if there are any free vector registers. */
	bool hasFreeVecRegs(int RegType) const { return vecList.hasFreeRegs(RegType); }
	bool hasAnyFreeVecRegs()
	{
		return vecList.hasAnyFreeRegs();
	}

	/** Checks if there are any free vector registers. */
	bool hasFreeVecElems(int RegType) const { return vecElemList.hasFreeRegs(RegType);}
	bool hasAnyFreeVecElems()
	{
		return vecElemList.hasAnyFreeRegs();
	}

	/** Checks if there are any free cc registers. */
	bool hasFreeCCRegs(int RegType) const { return ccList.hasFreeRegs(RegType); }
	bool hasAnyFreeCCRegs()
	{
		return ccList.hasAnyFreeRegs();
	}



	/** Returns the number of free integer registers. */
	unsigned numFreeIntRegs(int RegType) const { return intList.numFreeRegs(RegType); }
	unsigned numMinFreeIntRegs()
	{
		return intList.numMinFreeRegs();
	}

	unsigned numSumFreeIntRegs()
	{
		return intList.numSumFreeRegs();
	}

	/** Returns the number of free fp registers. */
	unsigned numFreeFloatRegs(int RegType) const { return floatList.numFreeRegs(RegType); }
	unsigned numMinFreeFloatRegs()
	{
		return floatList.numMinFreeRegs();
	}

	unsigned numSumFreeFloatRegs()
	{
		return floatList.numSumFreeRegs();
	}

	/** Returns the number of free vector registers. */
	unsigned numFreeVecRegs(int RegType) const { return vecList.numFreeRegs(RegType); }
	unsigned numMinFreeVecRegs()
	{
		return vecList.numMinFreeRegs();
	}
	unsigned numSumFreeVecRegs()
	{
		return vecList.numSumFreeRegs();
	}


	/** Returns the number of free cc registers. */
	unsigned numFreeCCRegs(int RegType) const { return ccList.numFreeRegs(RegType); }
	unsigned numMinFreeCCRegs()
	{
		return ccList.numMinFreeRegs();
	}
	unsigned numSumFreeCCRegs()
	{
		return ccList.numSumFreeRegs();
	}
};
/*
//template<class InputIt>
//inline void
//UnifiedFreeList::addRegs(std::vector<PhysRegId> RegIds, int first, int last, int RegType)
{
	// Are there any registers to add?
	if (first == last || first > last)
		return;

	panic_if((first != last) &&
		first->classValue() != (last - 1)->classValue(),
		"Attempt to add mixed type regs: %s and %s",
		first->className(),
		(last - 1)->className());
	switch (RegIds[first].classValue()) {
	case IntRegClass:
		intList.addRegs(RegIds, first, last, RegType);
		break;
	case FloatRegClass:
		floatList.addRegs(RegIds, first, last, RegType);
		break;
	case VecRegClass:
		vecList.addRegs(RegIds, first, last, RegType);
		break;
	case VecElemClass:
		//zsx change:
		{
		std::for_each(first, last,
			[this](const typename InputIt::value_type& reg) {
			this->vecElemList.push(&reg);
		});
		}
		
		vecElemList.addRegs(RegIds, first, last, RegType);
		break;
	case CCRegClass:
		ccList.addRegs(RegIds, first, last, RegType);
		break;
	default:
		break;
		panic("Unexpected RegClass (%s)",
			RegIds[first].className());
	}

}
*/

template<class InputIt>
inline void
UnifiedFreeList::addRegs(InputIt first, InputIt last, int RegType)
{
	// Are there any registers to add?
	if (first == last)
		return;

	panic_if((first != last) &&
		first->classValue() != (last - 1)->classValue(),
		"Attempt to add mixed type regs: %s and %s",
		first->className(),
		(last - 1)->className());
	switch (first->classValue()) {
	case IntRegClass:
		intList.addRegs(first, last, RegType);
		break;
	case FloatRegClass:
		floatList.addRegs(first, last, RegType);
		break;
	case VecRegClass:
		vecList.addRegs(first, last, RegType);
		break;
	case VecElemClass:
		vecElemList.addRegs(first, last, RegType);
		break;
	case CCRegClass:
		ccList.addRegs(first, last, RegType);
		break;
	default:
		panic("Unexpected RegClass (%s)",
			first->className());
	}

}

inline void
UnifiedFreeList::addReg(PhysRegIdPtr freed_reg, int RegType)
{
	DPRINTF(FreeList, "Freeing register %i (%s).\n", freed_reg->index(),
		freed_reg->className());
	//Might want to add in a check for whether or not this register is
	//already in there.  A bit vector or something similar would be useful.
	switch (freed_reg->classValue()) {
	case IntRegClass:
		intList.addReg(freed_reg, RegType);
		break;
	case FloatRegClass:
		floatList.addReg(freed_reg, RegType);
		break;
	case VecRegClass:
		vecList.addReg(freed_reg, RegType);
		break;
	case VecElemClass:
		vecElemList.addReg(freed_reg, RegType);
		//vecElemList.push(freed_reg);
		break;
	case CCRegClass:
		ccList.addReg(freed_reg, RegType);
		break;
	default:
		panic("Unexpected RegClass (%s)",
			freed_reg->className());
	}

	// These assert conditions ensure that the number of free
	// registers are not more than the # of total Physical  Registers.
	// If this were false, it would mean that registers
	// have been freed twice, overflowing the free register
	// pool and potentially crashing SMT workloads.
	// ----
	// Comment out for now so as to not potentially break
	// CMP and single-threaded workloads
	// ----
	// assert(freeIntRegs.size() <= numPhysicalIntRegs);
	// assert(freeFloatRegs.size() <= numPhysicalFloatRegs);
}


#endif // __CPU_O3_FREE_LIST_HH__

