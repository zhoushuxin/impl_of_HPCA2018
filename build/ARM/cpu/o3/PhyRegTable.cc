#include "cpu/o3/PhyRegTable.hh"

#include "config/the_isa.hh"
#include "arch/registers.hh"
#include "base/trace.hh"
#include "config/the_isa.hh"
//#include "debug/Scoreboard.hh"
/*
PhyRegTable::PhyRegTable(PhysRegFile *_regFile) :regFile(_regFile) 
{
	regFile->initPhyRegTable(this);
}*/


PhyRegTable::PhyRegTable(unsigned _totalNumRegs)
{
	PhyRegTableArray.reserve(_totalNumRegs);
	for (int i = 0; i < _totalNumRegs; i++)
	{
		PhyRegTableArray[i].ReadBit = false;
		PhyRegTableArray[i].TwoBitCounter = 0;
	}
}

