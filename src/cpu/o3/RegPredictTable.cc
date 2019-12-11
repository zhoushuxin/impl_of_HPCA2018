#include "cpu/o3/RegPredictTable.hh"

#include "config/the_isa.hh"
//#include "debug/Scoreboard.hh"

RegPredictTable::RegPredictTable(const unsigned _AddrWidth, unsigned _totalNumRegs)
{
	int entry_num = (1 << (_AddrWidth / 4));
	//printf("RegPredictTable entry_num=%d, totalNumRegs=%u\n", entry_num, _totalNumRegs);
	RegPredictTableArray.resize(entry_num, 3);
	/*
	RegPredictTableArray.resize(entry_num);

	int interval = entry_num / 4;

	for (int i = 0; i < entry_num; i++)
	{
		if (i % interval == 0)
		{
			RegPredictTableArray[i] = 1;
		}
		else
			RegPredictTableArray[i] = 0;
	}
	*/
	PhysRegIndexAddr.resize(_totalNumRegs, 0);
	
	/*
	for (int i = 0; i < _totalNumRegs; i++)
	{
		Phys_Reg_Index_Addr[i].resize(2);
	}
	*/
}
