#ifndef __CPU_RegPredictTable_HH__
#define __CPU_RegPredictTable_HH__

#include <vector>

#include "base/intmath.hh"
#include "base/logging.hh"


#include "base/statistics.hh"
#include "base/types.hh"
#include "cpu/inst_seq.hh"
#include "cpu/static_inst.hh"

class RegPredictTable
{
private:
	std::vector<int> RegPredictTableArray;
	unsigned AddrWidth;

public:
	RegPredictTable(const unsigned _AddrWidth, unsigned _totalNumRegs);
	~RegPredictTable() {}
	/*
	int lookupRegPredTable(PhysRegIdPtr phys_reg)
	{

	}*/

	std::vector<int> PhysRegIndexAddr;

	int lookupRegPredTable(Addr pc_in)
	{
		int long part_pc;
		int long pc_first_part = (pc_in & 0xffff000000000000) / pow(2, 48);
		int long pc_second_part = (pc_in & 0x0000ffff00000000) / pow(2, 32);
		int long pc_third_part = (pc_in & 0x00000000ffff0000) / pow(2, 16);
		int long pc_forth_part = pc_in & 0x000000000000ffff;

		//for (int i = 0; i < 4; i++)
		
		part_pc = pc_first_part ^ pc_second_part ^ pc_third_part ^ pc_forth_part;
		//printf("part_pc=%ld\n", part_pc);
		return RegPredictTableArray[part_pc];
	}

	void updateRegPredTable(Addr pc_in, int ActualReuseTime)
	{
		RegPredictTableArray[pc_in] = ActualReuseTime;
	}

	void incRegPredTable(Addr pc_in)
	{
		RegPredictTableArray[pc_in] ++;
		if (RegPredictTableArray[pc_in] > 3)
		{
			RegPredictTableArray[pc_in] = 3;
			//printf("error! RegPredictTable cannot exceed 3!\n");
		}
	}

	void decRegPredTable(Addr pc_in)
	{
		RegPredictTableArray[pc_in] --;
		if (RegPredictTableArray[pc_in] < 0)
		{
			RegPredictTableArray[pc_in] = 0;
			//printf("error! RegPredictTable cannot less than 0!\n");
		}
	}

	void recordPhysRegIndexAddr(RegIndex phys_reg_index, Addr instPC)
	{
		PhysRegIndexAddr[phys_reg_index] = instPC;
	}
};



#endif
