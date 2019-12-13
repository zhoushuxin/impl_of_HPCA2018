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
 */

#ifndef __CPU_O3_REGFILE_HH__
#define __CPU_O3_REGFILE_HH__

#include <vector>

#include "arch/isa_traits.hh"
#include "arch/kernel_stats.hh"
#include "arch/types.hh"
#include "base/trace.hh"
#include "config/the_isa.hh"
#include "cpu/o3/comm.hh"
#include "debug/IEW.hh"
#include "enums/VecRegRenameMode.hh"

#include "cpu/o3/RegPredictTable.hh"
#include "cpu/o3/PhyRegTable.hh"


class UnifiedFreeList;
class RegPredictTable;
//class PhyRegTable;

/**
 * Simple physical register file class.
 */
class PhysRegFile
{
private:

	typedef TheISA::IntReg IntReg;
	typedef TheISA::FloatReg FloatReg;
	typedef TheISA::FloatRegBits FloatRegBits;
	typedef TheISA::CCReg CCReg;
	using VecElem = TheISA::VecElem;
	using VecRegContainer = TheISA::VecRegContainer;
	using PhysIds = std::vector<PhysRegId>;
	using VecMode = Enums::VecRegRenameMode;

	enum RegType {
		non_sh,
		one_sh,
		two_sh,
		three_sh
	};


	typedef struct newIntReg {
		RegType type;
		IntReg main_cell;
		IntReg sh_cell[4];
		int main_status;
		int sh_status[4];
	}newIntReg;

	typedef union {
		FloatReg d;
		FloatRegBits q;
	} PhysFloatReg;


	typedef struct newFloatReg {
		RegType type;
		PhysFloatReg main_cell;
		PhysFloatReg sh_cell[4];
		int main_status;
		int sh_status[4];
	}newFloatReg;


	typedef struct newCCReg {
		RegType type;
		CCReg main_cell;
		CCReg sh_cell[4];
		int main_status;
		int sh_status[4];
	}newCCReg;

	typedef struct newVecReg {
		RegType type;
		VecRegContainer main_cell;
		VecRegContainer sh_cell[4];
		int main_status;
		int sh_status[4];
	}newVecReg;


	/*
	typedef struct newIntReg
	{
		RegType type;
		IntReg main_cell;
		IntReg sh_cell2;
		IntReg sh_cell1;
		IntReg sh_cell0;
		bool main_free;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}newIntReg;

	typedef struct newFloatReg {
		RegType type;
		FloatReg main_cell;
		FloatReg sh_cell2;
		FloatReg sh_cell1;
		FloatReg sh_cell0;
		bool main_free;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}newFloatReg;

	typedef struct newCCReg {
		RegType type;
		CCReg main_cell;
		CCReg sh_cell2;
		CCReg sh_cell1;
		CCReg sh_cell0;
		bool main_free;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}newCCReg;

	typedef struct newVecReg {
		RegType type;
		VecRegContainer main_cell;
		VecRegContainer sh_cell2;
		VecRegContainer sh_cell1;
		VecRegContainer sh_cell0;
		bool main_free;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}newVecReg;

	*/



/*
	typedef struct IntReg_0sh {
		IntReg main_cell;
	}IntReg_0sh;

	typedef struct IntReg_1sh {
		IntReg main_cell;
		IntReg sh_cell0;
		bool cell0_free;
	}IntReg_1sh;

	typedef struct IntReg_2sh {
		IntReg main_cell;
		IntReg sh_cell1;
		IntReg sh_cell0;
		bool cell1_free;
		bool cell0_free;
	}IntReg_2sh;

	typedef struct IntReg_3sh {
		IntReg main_cell;
		IntReg sh_cell2;
		IntReg sh_cell1;
		IntReg sh_cell0;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}IntReg_3sh;




	typedef struct FloatReg_0sh {
		FloatReg main_cell;
	}FloatReg_0sh;

	typedef struct FloatReg_1sh {
		FloatReg main_cell;
		FloatReg sh_cell0;
		bool cell0_free;
	}FloatReg_1sh;

	typedef struct FloatReg_2sh {
		FloatReg main_cell;
		FloatReg sh_cell1;
		FloatReg sh_cell0;
		bool cell1_free;
		bool cell0_free;
	}FloatReg_2sh;

	typedef struct FloatReg_3sh {
		FloatReg main_cell;
		FloatReg sh_cell2;
		FloatReg sh_cell1;
		FloatReg sh_cell0;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}FloatReg_3sh;




	typedef struct CCReg_0sh {
		CCReg main_cell;
	}CCReg_0sh;

	typedef struct CCReg_1sh {
		CCReg main_cell;
		CCReg sh_cell0;
		bool cell0_free;
	}CCReg_1sh;

	typedef struct CCReg_2sh {
		CCReg main_cell;
		CCReg sh_cell1;
		CCReg sh_cell0;
		bool cell1_free;
		bool cell0_free;
	}CCReg_2sh;

	typedef struct CCReg_3sh {
		CCReg main_cell;
		CCReg sh_cell2;
		CCReg sh_cell1;
		CCReg sh_cell0;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}CCReg_3sh;




	typedef struct VecReg_0sh {
		VecRegContainer main_cell;
	}IVecReg_0sh;

	typedef struct VecReg_1sh {
		VecRegContainer main_cell;
		VecRegContainer sh_cell0;
		bool cell0_free;
	}VecReg_1sh;

	typedef struct VecReg_2sh {
		VecRegContainer main_cell;
		VecRegContainer sh_cell1;
		VecRegContainer sh_cell0;
		bool cell1_free;
		bool cell0_free;
	}VecReg_2sh;

	typedef struct VecReg_3sh {
		VecRegContainer main_cell;
		VecRegContainer sh_cell2;
		VecRegContainer sh_cell1;
		VecRegContainer sh_cell0;
		bool cell2_free;
		bool cell1_free;
		bool cell0_free;
	}VecReg_3sh;
	*/

public:
	using IdRange = std::pair<PhysIds::const_iterator,
		PhysIds::const_iterator>;
public:
	static constexpr auto NumVecElemPerVecReg = TheISA::NumVecElemPerVecReg;

	/** Integer register file. */
	std::vector<newIntReg> intRegFile;
	/*typedef struct intRegFile {
		std::vector<IntReg_0sh> IntReg_0shs;
		std::vector<IntReg_1sh> IntReg_1shs;
		std::vector<IntReg_2sh> IntReg_2shs;
		std::vector<IntReg_3sh> IntReg_3shs;
	}intRegFile;*/
	std::vector<PhysRegId> intRegIds;


	/** Floating point register file. */
	std::vector<newFloatReg> floatRegFile;
	/*typedef struct floatRegFile {
		std::vector<FloatReg_0sh> FloatReg_0shs;
		std::vector<FloatReg_1sh> FloatReg_1shs;
		std::vector<FloatReg_2sh> FloatReg_2shs;
		std::vector<FloatReg_3sh> FloatReg_3shs;
	}floatRegFile;*/
	std::vector<PhysRegId> floatRegIds;



	/** Vector register file. */
	std::vector<newVecReg> vectorRegFile;
	/*typedef struct vectorRegFile {
		std::vector<VecReg_0sh> VecReg_0shs;
		std::vector<VecReg_1sh> VecReg_1shs;
		std::vector<VecReg_2sh> VecReg_2shs;
		std::vector<VecReg_3sh> VecReg_3shs;
	}vectorRegFile;*/
	std::vector<PhysRegId> vecRegIds;
	std::vector<PhysRegId> vecElemIds;

	/** Condition-code register file. */
	std::vector<newCCReg> ccRegFile;
	/*typedef struct ccRegFile {
		std::vector<CCReg_0sh> CCReg_0shs;
		std::vector<CCReg_1sh> CCReg_1shs;
		std::vector<CCReg_2sh> CCReg_2shs;
		std::vector<CCReg_3sh> CCReg_3shs;
	}ccRegFile;*/
	std::vector<PhysRegId> ccRegIds;

	/** Misc Reg Ids */
	std::vector<PhysRegId> miscRegIds;



	unsigned numPhysicalIntRegs;
	unsigned numPhysicalFloatRegs;
	unsigned numPhysicalVecRegs;
	unsigned numPhysicalVecElemRegs;
	unsigned numPhysicalCCRegs;


	/*Number of physical integer registers*/

	
	unsigned numPhysicalInt_0sh_Regs;
	unsigned numPhysicalInt_1sh_Regs;
	unsigned numPhysicalInt_2sh_Regs;
	unsigned numPhysicalInt_3sh_Regs;

	/**
 * Number of physical floating point registers
 */
	
	unsigned numPhysicalFloat_0sh_Regs;
	unsigned numPhysicalFloat_1sh_Regs;
	unsigned numPhysicalFloat_2sh_Regs;
	unsigned numPhysicalFloat_3sh_Regs;

	/**
 * Number of physical vector registers
 */
	
	unsigned numPhysicalVec_0sh_Regs;
	unsigned numPhysicalVec_1sh_Regs;
	unsigned numPhysicalVec_2sh_Regs;
	unsigned numPhysicalVec_3sh_Regs;

	/**
 * Number of physical vector element registers
 */
	

	/**
	 * Number of physical CC registers
	 */
	
	unsigned numPhysicalCC_0sh_Regs;
	unsigned numPhysicalCC_1sh_Regs;
	unsigned numPhysicalCC_2sh_Regs;
	unsigned numPhysicalCC_3sh_Regs;


	/** Total number of physical registers. */
	unsigned totalNumRegs;

	/** Mode in which vector registers are addressed. */
	VecMode vecMode;

	

public:
	//zsx add
	PhyRegTable * phyRegTable = new PhyRegTable(totalNumRegs);
	/**
	 * Constructs a physical register file with the specified amount of
	 * integer and floating point registers.
	 */
	/*
	PhysRegFile(unsigned _numPhysicalIntRegs,
		unsigned _numPhysicalInt_0sh_Regs,
		unsigned _numPhysicalInt_1sh_Regs,
		unsigned _numPhysicalInt_2sh_Regs,
		unsigned _numPhysicalInt_3sh_Regs,

		unsigned _numPhysicalFloatRegs,
		unsigned _numPhysicalFloat_0sh_Regs,
		unsigned _numPhysicalFloat_1sh_Regs,
		unsigned _numPhysicalFloat_2sh_Regs,
		unsigned _numPhysicalFloat_3sh_Regs,

		unsigned _numPhysicalVecRegs,
		unsigned _numPhysicalVec_0sh_Regs,
		unsigned _numPhysicalVec_1sh_Regs,
		unsigned _numPhysicalVec_2sh_Regs,
		unsigned _numPhysicalVec_3sh_Regs,

		unsigned _numPhysicalCCRegs,
		unsigned numPhysicalCC_0sh_Regs,
		unsigned numPhysicalCC_1sh_Regs,
		unsigned numPhysicalCC_2sh_Regs,
		unsigned numPhysicalCC_3sh_Regs,

		VecMode vmode
	);
	*/

	PhysRegFile(unsigned _numPhysicalIntRegs,
		unsigned _numPhysicalFloatRegs,
		unsigned _numPhysicalVecRegs,
		unsigned _numPhysicalCCRegs,

		unsigned numPhysicalInt_0sh_Regs,
		unsigned numPhysicalInt_1sh_Regs,
		unsigned numPhysicalInt_2sh_Regs,
		unsigned numPhysicalInt_3sh_Regs,

		unsigned numPhysicalFloat_0sh_Regs,
		unsigned numPhysicalFloat_1sh_Regs,
		unsigned numPhysicalFloat_2sh_Regs,
		unsigned numPhysicalFloat_3sh_Regs,

		unsigned numPhysicalVec_0sh_Regs,
		unsigned numPhysicalVec_1sh_Regs,
		unsigned numPhysicalVec_2sh_Regs,
		unsigned numPhysicalVec_3sh_Regs,

		unsigned numPhysicalCC_0sh_Regs,
		unsigned numPhysicalCC_1sh_Regs,
		unsigned numPhysicalCC_2sh_Regs,
		unsigned numPhysicalCC_3sh_Regs,

		VecMode vmode
	);

	/**
	 * Destructor to free resources
	 */
	~PhysRegFile() {}

	/** Initialize the free list */
	void initFreeList(UnifiedFreeList *freeList);
	
	/*zsx add*/
	//void initRegPredictTable(RegPredictTable * regpredicttable);
	//void initPhyRegTable(PhyRegTable * _phyRegTable);


	/** @return the number of integer physical registers. */
	unsigned numIntPhysRegs() const { return numPhysicalIntRegs; }

	/** @return the number of floating-point physical registers. */
	unsigned numFloatPhysRegs() const { return numPhysicalFloatRegs; }
	/** @return the number of vector physical registers. */
	unsigned numVecPhysRegs() const { return numPhysicalVecRegs; }

	/** @return the number of vector element physical registers. */
	unsigned numVecElemPhysRegs() const { return numPhysicalVecElemRegs; }

	/** @return the number of condition-code physical registers. */
	unsigned numCCPhysRegs() const { return numPhysicalCCRegs; }

	/** @return the total number of physical registers. */
	unsigned totalNumPhysRegs() const { return totalNumRegs; }

	//zsx add
	int NumFreeShadowCell(PhysRegIdPtr phys_reg)
	{
		int result = 0;
		if (phys_reg->isIntReg())
		{
			for (int i = 0; i < 4; i++)
			{
				if (intRegFile[phys_reg->index()].sh_status[i] == 0)
				{
					//printf("type=%d, sh %d is free\n", whatRegType(phys_reg), i);
					result++;
				}
			}

			/*
			switch (intRegFile[phys_reg->index()].type)
			{
			case 0:
				if (!intRegFile[phys_reg->index()].main_val)
				{
					result = 1;
				}
				else result = 0;
				//break;

			case 1:
				if (!intRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!intRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				//break;
			
			case 2:
				if (!intRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!intRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!intRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}

			case 3:
				if (!intRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!intRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!intRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}
				if (!intRegFile[phys_reg->index()].sh_val[2])
				{
					result++;
				}
			}*/
			/*for (int i = 0; i < 3; i++)
			{
				if (intRegFile[phys_reg->index()].sh_free[i] == true)
				{
					result++;
				}
			}*/
		}
		else if (phys_reg->isFloatReg())
		{
			for (int i = 0; i < 4; i++)
			{
				if (floatRegFile[phys_reg->index()].sh_status[i] == 0)
				{
					result++;
				}
			}

			/*
			switch (floatRegFile[phys_reg->index()].type)
			{
			case 0:
				if (!floatRegFile[phys_reg->index()].main_val)
				{
					result = 1;
				}
				else result = 0;
				//break;

			case 1:
				if (!floatRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!floatRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				//break;

			case 2:
				if (!floatRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!floatRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!floatRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}

			case 3:
				if (!floatRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!floatRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!floatRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}
				if (!floatRegFile[phys_reg->index()].sh_val[2])
				{
					result++;
				}
			}*/
		}
		else if (phys_reg->isVecReg())
		{
			for (int i = 0; i < 4; i++)
			{
				if (vectorRegFile[phys_reg->index()].sh_status[i] == 0)
				{
					result++;
				}
			}

			/*
			switch (vectorRegFile[phys_reg->index()].type)
			{
			case 0:
				if (!vectorRegFile[phys_reg->index()].main_val)
				{
					result = 1;
				}
				else result = 0;
				//break;

			case 1:
				if (!vectorRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!vectorRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				//break;

			case 2:
				if (!vectorRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!vectorRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!vectorRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}

			case 3:
				if (!vectorRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!vectorRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!vectorRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}
				if (!vectorRegFile[phys_reg->index()].sh_val[2])
				{
					result++;
				}
			}*/
		}
		else if (phys_reg->isCCReg())
		{
			for (int i = 0; i < 4; i++)
			{
				if (ccRegFile[phys_reg->index()].sh_status[i] == 0)
				{
					result++;
				}
			}

			/*
			switch (ccRegFile[phys_reg->index()].type)
			{
			case 0:
				if (!ccRegFile[phys_reg->index()].main_val)
				{
					result = 1;
				}
				else result = 0;
				//break;

			case 1:
				if (!ccRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!ccRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				//break;

			case 2:
				if (!ccRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!ccRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!ccRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}

			case 3:
				if (!ccRegFile[phys_reg->index()].main_val)
				{
					result++;
				}
				if (!ccRegFile[phys_reg->index()].sh_val[0])
				{
					result++;
				}
				if (!ccRegFile[phys_reg->index()].sh_val[1])
				{
					result++;
				}
				if (!ccRegFile[phys_reg->index()].sh_val[2])
				{
					result++;
				}
			}
			*/
		}
		else
		{
			//return result;
			//DPRINTF(IEW, "Rename: unknown register type for getInvalidShadowCell function(%s)\n",phys_reg->className());
		}
		return result;
	}


	//zsx add
	bool isShadowCellAllocated(PhysRegIdPtr phys_reg, int sh_cell)
	{
		if (phys_reg->isIntPhysReg())
		{
			if (intRegFile[phys_reg->index()].sh_status[sh_cell] == 1)
			{
				return true;
			}
			else return false;
			//return intRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else if (phys_reg->isFloatPhysReg())
		{
			if (floatRegFile[phys_reg->index()].sh_status[sh_cell] == 1)
			{
				return true;
			}
			else return false;
			//return floatRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else if (phys_reg->isVectorPhysReg())
		{
			if (vectorRegFile[phys_reg->index()].sh_status[sh_cell] == 1)
			{
				return true;
			}
			else return false;
			//return vectorRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else if (phys_reg->isCCPhysReg())
		{
			if (ccRegFile[phys_reg->index()].sh_status[sh_cell] == 1)
			{
				return true;
			}
			else return false;
			//return ccRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
			return true;
		}
	}

	bool isShadowCellValid(PhysRegIdPtr phys_reg, int sh_cell)
	{
		if (phys_reg->isIntPhysReg())
		{
			if (intRegFile[phys_reg->index()].sh_status[sh_cell] == 2)
			{
				return true;
			}
			else return false;
			//return intRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else if (phys_reg->isFloatPhysReg())
		{
			if (floatRegFile[phys_reg->index()].sh_status[sh_cell] == 2)
			{
				return true;
			}
			else return false;
			//return floatRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else if (phys_reg->isVectorPhysReg())
		{
			if (vectorRegFile[phys_reg->index()].sh_status[sh_cell] == 2)
			{
				return true;
			}
			else return false;
			//return vectorRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else if (phys_reg->isCCPhysReg())
		{
			if (ccRegFile[phys_reg->index()].sh_status[sh_cell] == 2)
			{
				return true;
			}
			else return false;
			//return ccRegFile[phys_reg->index()].sh_val[sh_cell];
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
			return true;
		}
	}

	//zsx add function
	int whatRegType(PhysRegIdPtr phys_reg)
	{
		if (phys_reg->isIntPhysReg())
		{
			return intRegFile[phys_reg->index()].type;
		}
		else if (phys_reg->isFloatPhysReg())
		{
			return floatRegFile[phys_reg->index()].type;
		}
		else if (phys_reg->isVectorPhysReg())
		{
			return vectorRegFile[phys_reg->index()].type;
		}
		else if (phys_reg->isCCPhysReg())
		{
			return ccRegFile[phys_reg->index()].type;
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
			return 0;
		}
	}


	//zsx add function
	void FreeShadowCell(PhysRegIdPtr phys_reg, int sh_cell)
	{
		//printf("free reg->index=%d, sh=%d\n", phys_reg->index(), sh_cell);
		if (phys_reg->isIntPhysReg())
		{
			/*
			if (sh_cell == whatRegType(phys_reg))
			{
				intRegFile[phys_reg->index()].main_status = 0;
			}*/
			intRegFile[phys_reg->index()].sh_status[sh_cell] = 0;
		}
		else if (phys_reg->isFloatPhysReg())
		{
			/*
			if (sh_cell == whatRegType(phys_reg))
			{
				floatRegFile[phys_reg->index()].main_status = 0;
			}*/
			floatRegFile[phys_reg->index()].sh_status[sh_cell] = 0;
		}
		else if (phys_reg->isVectorPhysReg())
		{
			/*if (sh_cell == whatRegType(phys_reg))
			{
				vectorRegFile[phys_reg->index()].main_status = 0;
			}*/
			vectorRegFile[phys_reg->index()].sh_status[sh_cell] = 0;
		}
		else if (phys_reg->isCCPhysReg())
		{
			/*if (sh_cell == whatRegType(phys_reg))
			{
				ccRegFile[phys_reg->index()].main_status = 0;
			}*/
			ccRegFile[phys_reg->index()].sh_status[sh_cell] = 0;
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
		}
	}


	//zsx add function
	bool isSingleUseRegFree(PhysRegIdPtr phys_reg)
	{
		if (phys_reg->isIntPhysReg())
		{
			//if(intRegFile[phys_reg->index()].main_status == 0 && 
			 if( (intRegFile[phys_reg->index()].sh_status[0] == 0 || intRegFile[phys_reg->index()].sh_status[0] == -1) && 
			  (intRegFile[phys_reg->index()].sh_status[1] == 0 || intRegFile[phys_reg->index()].sh_status[1] == -1) && 
			  (intRegFile[phys_reg->index()].sh_status[2] == 0 || intRegFile[phys_reg->index()].sh_status[2] == -1) &&
			  (intRegFile[phys_reg->index()].sh_status[3] == 0 || intRegFile[phys_reg->index()].sh_status[3] == -1))
			/*
			if (!intRegFile[phys_reg->index()].main_val &&
				!intRegFile[phys_reg->index()].sh_val[0] &&
				!intRegFile[phys_reg->index()].sh_val[1] &&
				!intRegFile[phys_reg->index()].sh_val[2] &&
				!intRegFile[phys_reg->index()].sh_val[3])*/
				return true;
			else return false;
			
		}
		else if (phys_reg->isFloatPhysReg())
		{
			//if (floatRegFile[phys_reg->index()].main_status == 0 &&
				if((floatRegFile[phys_reg->index()].sh_status[0] == 0 || floatRegFile[phys_reg->index()].sh_status[0] == -1) &&
				(floatRegFile[phys_reg->index()].sh_status[1] == 0 || floatRegFile[phys_reg->index()].sh_status[1] == -1) &&
				(floatRegFile[phys_reg->index()].sh_status[2] == 0 || floatRegFile[phys_reg->index()].sh_status[2] == -1) &&
				(floatRegFile[phys_reg->index()].sh_status[3] == 0 || floatRegFile[phys_reg->index()].sh_status[3] == -1))
			/*
			if (!floatRegFile[phys_reg->index()].main_val &&
				!floatRegFile[phys_reg->index()].sh_val[0] &&
				!floatRegFile[phys_reg->index()].sh_val[1] &&
				!floatRegFile[phys_reg->index()].sh_val[2] &&
				!floatRegFile[phys_reg->index()].sh_val[3])*/
				return true;
			else return false;
		}
		else if (phys_reg->isVectorPhysReg())
		{
			//if (vectorRegFile[phys_reg->index()].main_status == 0 &&
			if(	(vectorRegFile[phys_reg->index()].sh_status[0] == 0 || vectorRegFile[phys_reg->index()].sh_status[0] == -1) &&
				(vectorRegFile[phys_reg->index()].sh_status[1] == 0 || vectorRegFile[phys_reg->index()].sh_status[1] == -1) &&
				(vectorRegFile[phys_reg->index()].sh_status[2] == 0 || vectorRegFile[phys_reg->index()].sh_status[2] == -1) &&
				(vectorRegFile[phys_reg->index()].sh_status[3] == 0 || vectorRegFile[phys_reg->index()].sh_status[3] == -1))
			/*
				if (!vectorRegFile[phys_reg->index()].main_val &&
				!vectorRegFile[phys_reg->index()].sh_val[0] &&
				!vectorRegFile[phys_reg->index()].sh_val[1] &&
				!vectorRegFile[phys_reg->index()].sh_val[2] &&
				!vectorRegFile[phys_reg->index()].sh_val[3])*/
				return true;
			else return false;
		}
		else if (phys_reg->isCCPhysReg())
		{
			//if (ccRegFile[phys_reg->index()].main_status == 0 &&
			if(	(ccRegFile[phys_reg->index()].sh_status[0] == 0 || ccRegFile[phys_reg->index()].sh_status[0] == -1) &&
				(ccRegFile[phys_reg->index()].sh_status[1] == 0 || ccRegFile[phys_reg->index()].sh_status[1] == -1) &&
				(ccRegFile[phys_reg->index()].sh_status[2] == 0 || ccRegFile[phys_reg->index()].sh_status[2] == -1) &&
				(ccRegFile[phys_reg->index()].sh_status[3] == 0 || ccRegFile[phys_reg->index()].sh_status[3] == -1))
			/*if (!ccRegFile[phys_reg->index()].main_val &&
				!ccRegFile[phys_reg->index()].sh_val[0] &&
				!ccRegFile[phys_reg->index()].sh_val[1] &&
				!ccRegFile[phys_reg->index()].sh_val[2] &&
				!ccRegFile[phys_reg->index()].sh_val[3])*/
				return true;
			else return false;
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
			return false;
		}
	}



	//zsx add function
	void RecoverSingleUseReg(PhysRegIdPtr phys_reg, int prevTwoBitCounter)
	{
		if (phys_reg->isIntPhysReg())
		{
			//auto value = intRegFile[phys_reg->index()].main_cell;
			intRegFile[phys_reg->index()].main_cell = intRegFile[phys_reg->index()].sh_cell[prevTwoBitCounter];
			//value = intRegFile[phys_reg->index()].main_cell;
			intRegFile[phys_reg->index()].sh_status[prevTwoBitCounter] = 2;
			//DPRINTF(IEW, "RegFile: Recover int register:%i sh %d value is %x\n", phys_reg->index(), prevTwoBitCounter, value);
		}
		else if (phys_reg->isFloatPhysReg())
		{
			floatRegFile[phys_reg->index()].main_cell = floatRegFile[phys_reg->index()].sh_cell[prevTwoBitCounter];
			//value = floatRegFile[phys_reg->index()].main_cell.d;
		}
		else if (phys_reg->isVectorPhysReg())
		{
			vectorRegFile[phys_reg->index()].main_cell = vectorRegFile[phys_reg->index()].sh_cell[prevTwoBitCounter];
			//value = vectorRegFile[phys_reg->index()].main_cell;
		}
		else if (phys_reg->isCCPhysReg())
		{
			ccRegFile[phys_reg->index()].main_cell = ccRegFile[phys_reg->index()].sh_cell[prevTwoBitCounter];
			//value = ccRegFile[phys_reg->index()].main_cell;
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
		}
	}

	void setShadowCellAllocated(PhysRegIdPtr phys_reg, int sh_cell)
	{
		//printf("set allocated class=%s, index=%d, flatindex=%d, counter=%d\n", phys_reg->className(), phys_reg->index(), phys_reg->flatIndex(), sh_cell);
		if (phys_reg->isIntPhysReg())
		{
			intRegFile[phys_reg->index()].sh_status[sh_cell] = 1;
		}
		else if (phys_reg->isFloatPhysReg())
		{
			floatRegFile[phys_reg->index()].sh_status[sh_cell] = 1;
		}
		else if (phys_reg->isVectorPhysReg())
		{
			vectorRegFile[phys_reg->index()].sh_status[sh_cell] = 1;
		}
		else if (phys_reg->isCCPhysReg())
		{
			ccRegFile[phys_reg->index()].sh_status[sh_cell] = 1;
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
		}
	}

	void setShadowCellValid(PhysRegIdPtr phys_reg, int sh_cell)
	{
		if (phys_reg->isIntPhysReg())
		{
			intRegFile[phys_reg->index()].sh_status[sh_cell] = 2;
		}
		else if (phys_reg->isFloatPhysReg())
		{
			floatRegFile[phys_reg->index()].sh_status[sh_cell] = 2;
		}
		else if (phys_reg->isVectorPhysReg())
		{
			vectorRegFile[phys_reg->index()].sh_status[sh_cell] = 2;
		}
		else if (phys_reg->isCCPhysReg())
		{
			ccRegFile[phys_reg->index()].sh_status[sh_cell] = 2;
		}
		else
		{
			//DPRINTF(IEW, "Rename: warning! the register class is :%s\n", phys_reg->className());
		}
	}


	/** Gets a misc register PhysRegIdPtr. */
	PhysRegIdPtr getMiscRegId(RegIndex reg_idx) {
		return &miscRegIds[reg_idx];
	}

	/** Reads an integer register. */
	uint64_t readIntReg(PhysRegIdPtr phys_reg)
	{
		assert(phys_reg->isIntPhysReg());

		DPRINTF(IEW, "RegFile: Access to int register %i, has data "
			"%#x\n", phys_reg->index(), (intRegFile[phys_reg->index()]).main_cell);
		return (intRegFile[phys_reg->index()]).main_cell;
	}

	/** Reads a floating point register (double precision). */
	FloatReg readFloatReg(PhysRegIdPtr phys_reg)
	{
		assert(phys_reg->isFloatPhysReg());

		DPRINTF(IEW, "RegFile: Access to float register %i, has "
			"data %#x\n", phys_reg->index(),
			(floatRegFile[phys_reg->index()]).main_cell.q);
		return (floatRegFile[phys_reg->index()]).main_cell.d;
	}

	FloatRegBits readFloatRegBits(PhysRegIdPtr phys_reg) const
	{
		assert(phys_reg->isFloatPhysReg());

		FloatRegBits floatRegBits = floatRegFile[phys_reg->index()].main_cell.q;

		DPRINTF(IEW, "RegFile: Access to float register %i as int, "
			"has data %#x\n", phys_reg->index(),
			(uint64_t)floatRegBits);

		return floatRegBits;
	}

	/** Reads a vector register. */
	const VecRegContainer& readVecReg(PhysRegIdPtr phys_reg) const
	{
		assert(phys_reg->isVectorPhysReg());

		DPRINTF(IEW, "RegFile: Access to vector register %i, has "
			"data %s\n", int(phys_reg->index()),
			(vectorRegFile[phys_reg->index()]).main_cell.as<VecElem>().print());

		return (vectorRegFile[phys_reg->index()]).main_cell;
	}

	/** Reads a vector register for modification. */
	VecRegContainer& getWritableVecReg(PhysRegIdPtr phys_reg)
	{
		/* const_cast for not duplicating code above. */
		return const_cast<VecRegContainer&>(readVecReg(phys_reg));
	}

	/** Reads a vector register lane. */
	template <typename VecElem, int LaneIdx>
	VecLaneT<VecElem, true>
		readVecLane(PhysRegIdPtr phys_reg) const
	{
		return readVecReg(phys_reg).laneView<VecElem, LaneIdx>();
	}

	/** Reads a vector register lane. */
	template <typename VecElem>
	VecLaneT<VecElem, true>
		readVecLane(PhysRegIdPtr phys_reg) const
	{
		return readVecReg(phys_reg).laneView<VecElem>(phys_reg->elemIndex());
	}

	/** Get a vector register lane for modification. */
	template <typename LD>
	void
		setVecLane(PhysRegIdPtr phys_reg, const LD& val)
	{
		assert(phys_reg->isVectorPhysReg());

		DPRINTF(IEW, "RegFile: Setting vector register %i[%d] to %lx\n",
			int(phys_reg->index()), phys_reg->elemIndex(), val);

		(vectorRegFile[phys_reg->index()]).main_cell.laneView<typename LD::UnderlyingType>(
			phys_reg->elemIndex()) = val;
	}

	/** Reads a vector element. */
	const VecElem& readVecElem(PhysRegIdPtr phys_reg) const
	{
		assert(phys_reg->isVectorPhysElem());
		auto ret = (vectorRegFile[phys_reg->index()]).main_cell.as<VecElem>();
		const VecElem& val = ret[phys_reg->elemIndex()];
		DPRINTF(IEW, "RegFile: Access to element %d of vector register %i,"
			" has data %#x\n", phys_reg->elemIndex(),
			int(phys_reg->index()), val);

		return val;
	}

	/** Reads a condition-code register. */
	CCReg readCCReg(PhysRegIdPtr phys_reg)
	{
		assert(phys_reg->isCCPhysReg());

		DPRINTF(IEW, "RegFile: Access to cc register %i, has "
			"data %#x\n", phys_reg->index(),
			(ccRegFile[phys_reg->index()]).main_cell);

		return (ccRegFile[phys_reg->index()]).main_cell;
	}






	/*void setIntReg(PhysRegIdPtr phys_reg, uint64_t val)
	{
		assert(phys_reg->isIntPhysReg());

		DPRINTF(IEW, "RegFile: Setting int register %i to %#x\n",
			phys_reg->index(), val);

		if (!phys_reg->isZeroReg())
		{
			intRegFile[phys_reg->index()].main_cell = val;
			intRegFile[phys_reg->index()].main_status = 2;
		}
	}*/


	/** Sets an integer register to the given value. */
	void setIntReg(PhysRegIdPtr phys_reg, int twoBitCounter, uint64_t val)
	{
		assert(phys_reg->isIntPhysReg());

		DPRINTF(IEW, "RegFile: Setting int register %i sh %d to %#x\n",
			phys_reg->index(), twoBitCounter, val);

		if (!phys_reg->isZeroReg())
		{
			intRegFile[phys_reg->index()].main_cell = val;
			intRegFile[phys_reg->index()].sh_cell[twoBitCounter] = val;
			intRegFile[phys_reg->index()].sh_status[twoBitCounter] = 2;
			intRegFile[phys_reg->index()].main_status = 2;
			/*
			if ((intRegFile[phys_reg->index()]).type == non_sh) {
				intRegFile[phys_reg->index()].main_cell = val;
				intRegFile[phys_reg->index()].main_val = 2;
			}

			else
			{
				
				if ((intRegFile[phys_reg->index()]).type == one_sh) {
					if (intRegFile[phys_reg->index()].main_free == false)
					{
						IntReg TempIntReg = intRegFile[phys_reg->index()].main_cell;
						intRegFile[phys_reg->index()].sh_cell[0] = TempIntReg;
						intRegFile[phys_reg->index()].sh_free[0] = false;

						intRegFile[phys_reg->index()].main_cell = val;

					}
					else
					{
						intRegFile[phys_reg->index()].main_cell = val;
						intRegFile[phys_reg->index()].main_free = false;
					}
				}
				

				//else if ((intRegFile[phys_reg->index()]).type == two_sh) 
				//else
				{
					if (intRegFile[phys_reg->index()].main_val == true)
					{
						//IntReg TempIntReg = intRegFile[phys_reg->index()].main_cell;
						intRegFile[phys_reg->index()].sh_cell[phyRegTable->getTwoBitCounter(phys_reg)] = val;
						intRegFile[phys_reg->index()].sh_val[phyRegTable->getTwoBitCounter(phys_reg)] = true;

						intRegFile[phys_reg->index()].main_cell = val;
					}
					else
					{
						intRegFile[phys_reg->index()].main_cell = val;
						intRegFile[phys_reg->index()].main_val = true;
					}
				}
				//IntReg TempIntReg=
			}
			*/
			//intRegFile[phys_reg->index()] = val;
		}
	}




	/** Sets a double precision floating point register to the given value. */
	void setFloatReg(PhysRegIdPtr phys_reg, int twoBitCounter, FloatReg val)
	{
		assert(phys_reg->isFloatPhysReg());

		DPRINTF(IEW, "RegFile: Setting float register %i sh %d to %#x\n",
			phys_reg->index(), twoBitCounter, (uint64_t)val);
		
		if (!phys_reg->isZeroReg())
		{
			floatRegFile[phys_reg->index()].main_cell.d = val;
			floatRegFile[phys_reg->index()].sh_cell[twoBitCounter].d = val;
			floatRegFile[phys_reg->index()].sh_status[twoBitCounter] = 2;
			floatRegFile[phys_reg->index()].main_status = 2;
		}
		

		/*
		if (!phys_reg->isZeroReg()) {
			if ((floatRegFile[phys_reg->index()]).type == non_sh) {
				floatRegFile[phys_reg->index()].main_cell.d = val;
				floatRegFile[phys_reg->index()].main_val = true;
			}

			else
			{
				if (floatRegFile[phys_reg->index()].main_val == true)
				{
					//FloatReg TempFloatReg = floatRegFile[phys_reg->index()].main_cell.d;
					floatRegFile[phys_reg->index()].sh_cell[phyRegTable->getTwoBitCounter(phys_reg)].d = val;
					floatRegFile[phys_reg->index()].sh_val[phyRegTable->getTwoBitCounter(phys_reg)] = true;

					floatRegFile[phys_reg->index()].main_cell.d = val;
				}
				else
				{
					floatRegFile[phys_reg->index()].main_cell.d = val;
					floatRegFile[phys_reg->index()].main_val = true;
				}
			}
		}*/
		//floatRegFile[phys_reg->index()].d = val;
	}




	void setFloatRegBits(PhysRegIdPtr phys_reg, int twoBitCounter, FloatRegBits val)
	{
		assert(phys_reg->isFloatPhysReg());

		DPRINTF(IEW, "RegFile: Setting float register %i sh %d to %#x\n",
			phys_reg->index(), twoBitCounter, (uint64_t)val);

		floatRegFile[phys_reg->index()].main_cell.q = val;
		floatRegFile[phys_reg->index()].sh_cell[twoBitCounter].q = val;
		floatRegFile[phys_reg->index()].sh_status[twoBitCounter] = 2;
		floatRegFile[phys_reg->index()].main_status = 2;

		/*
		if (!phys_reg->isZeroReg())
		{
			if ((floatRegFile[phys_reg->index()]).type == non_sh) {
				floatRegFile[phys_reg->index()].main_cell.q = val;
				floatRegFile[phys_reg->index()].main_val = true;
			}

			else
			{
				if (floatRegFile[phys_reg->index()].main_val == true)
				{
					//FloatRegBits TempFloatRegBits = floatRegFile[phys_reg->index()].main_cell.q;
					floatRegFile[phys_reg->index()].sh_cell[phyRegTable->getTwoBitCounter(phys_reg)].q = val;
					floatRegFile[phys_reg->index()].sh_val[phyRegTable->getTwoBitCounter(phys_reg)] = true;

					floatRegFile[phys_reg->index()].main_cell.q = val;
				}
				else
				{
					floatRegFile[phys_reg->index()].main_cell.q = val;
					floatRegFile[phys_reg->index()].main_val = true;
				}
			}
		}*/
			//floatRegFile[phys_reg->index()].q = val;
	}




	/** Sets a vector register to the given value. */
	void setVecReg(PhysRegIdPtr phys_reg, int twoBitCounter, const VecRegContainer& val)
	{
		assert(phys_reg->isVectorPhysReg());

		DPRINTF(IEW, "RegFile: Setting vector register %i sh %d to %s\n",
			int(phys_reg->index()), twoBitCounter, val.print());

		vectorRegFile[phys_reg->index()].main_cell = val;
		vectorRegFile[phys_reg->index()].sh_cell[twoBitCounter] = val;
		vectorRegFile[phys_reg->index()].sh_status[twoBitCounter] = 2;
		vectorRegFile[phys_reg->index()].main_status = 2;


		/*
		if ((vectorRegFile[phys_reg->index()]).type == non_sh) {
			vectorRegFile[phys_reg->index()].main_cell = val;
			vectorRegFile[phys_reg->index()].main_val = true;
		}

		else
		{
			{
				if (vectorRegFile[phys_reg->index()].main_val == true)
				{
					//VecRegContainer TempVecRegContainer = vectorRegFile[phys_reg->index()].main_cell;
					vectorRegFile[phys_reg->index()].sh_cell[phyRegTable->getTwoBitCounter(phys_reg)] = val;
					vectorRegFile[phys_reg->index()].sh_val[phyRegTable->getTwoBitCounter(phys_reg)] = true;

					vectorRegFile[phys_reg->index()].main_cell = val;
				}
				else
				{
					vectorRegFile[phys_reg->index()].main_cell = val;
					vectorRegFile[phys_reg->index()].main_val = true;
				}
			}
		}
		*/
		//vectorRegFile[phys_reg->index()] = val;
	}




	/** Sets a vector register to the given value. */
	void setVecElem(PhysRegIdPtr phys_reg, int twoBitCounter, const VecElem val)
	{
		assert(phys_reg->isVectorPhysElem());

		DPRINTF(IEW, "RegFile: Setting element %d of vector register %i to"
			" %#x\n", phys_reg->elemIndex(), int(phys_reg->index()), val);

		(vectorRegFile[phys_reg->index()].sh_cell[twoBitCounter]).as<VecElem>()[phys_reg->elemIndex()] =
			val;
	}





	/** Sets a condition-code register to the given value. */
	void setCCReg(PhysRegIdPtr phys_reg, int twoBitCounter, CCReg val)
	{
		assert(phys_reg->isCCPhysReg());

		DPRINTF(IEW, "RegFile: Setting cc register %i to %#x\n",
			phys_reg->index(), (uint64_t)val);

		ccRegFile[phys_reg->index()].main_cell = val;
		ccRegFile[phys_reg->index()].sh_cell[twoBitCounter] = val;
		ccRegFile[phys_reg->index()].sh_status[twoBitCounter] = 2;
		ccRegFile[phys_reg->index()].main_status = 2;


		/*
		if ((ccRegFile[phys_reg->index()]).type == non_sh) {
			ccRegFile[phys_reg->index()].main_cell = val;
			ccRegFile[phys_reg->index()].main_val = true;
		}

		else
		{
			if (ccRegFile[phys_reg->index()].main_val == true)
			{
				//CCReg TempCCReg = ccRegFile[phys_reg->index()].main_cell;
				ccRegFile[phys_reg->index()].sh_cell[phyRegTable->getTwoBitCounter(phys_reg)] = val;
				ccRegFile[phys_reg->index()].sh_val[phyRegTable->getTwoBitCounter(phys_reg)] = true;

				ccRegFile[phys_reg->index()].main_cell = val;
			}
			else
			{
				ccRegFile[phys_reg->index()].main_cell = val;
				ccRegFile[phys_reg->index()].main_val = true;
			}
		}*/
		//ccRegFile[phys_reg->index()] = val;
	}





	/** Get the PhysRegIds of the elems of a vector register.
	 * Auxiliary function to transition from Full vector mode to Elem mode.
	 */
	IdRange getRegElemIds(PhysRegIdPtr reg);

	/**
	 * Get the PhysRegIds of the elems of all vector registers.
	 * Auxiliary function to transition from Full vector mode to Elem mode
	 * and to initialise the rename map.
	 */
	IdRange getRegIds(RegClass cls);

	/**
	 * Get the true physical register id.
	 * As many parts work with PhysRegIdPtr, we need to be able to produce
	 * the pointer out of just class and register idx.
	 */
	PhysRegIdPtr getTrueId(PhysRegIdPtr reg);
};


#endif //__CPU_O3_REGFILE_HH__

