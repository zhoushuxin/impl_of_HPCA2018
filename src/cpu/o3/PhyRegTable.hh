#ifndef __CPU_O3_PhyRegTable_HH__
#define __CPU_O3_PhyRegTable_HH__

#include <iostream>
#include <utility>
#include <vector>
//#include "cpu/o3/regfile.hh"

#include "base/trace.hh"
#include "config/the_isa.hh"
#include "cpu/o3/comm.hh"

#include "base/logging.hh"
#include "base/trace.hh"
//class PhysRegFile;

typedef struct PhyRegTableEntry {
	bool ReadBit;
	int TwoBitCounter;
}PhyRegTableEntry;

class PhyRegTable
{
private:
	//const std::string _name;

	std::vector<PhyRegTableEntry> PhyRegTableArray;
	//PhysRegFile *regFile;

	/** The number of actual physical registers */
	//unsigned M5_CLASS_VAR_USED numPhysRegs;

public:
	/** Constructs a PhyRegTable.
	 *  @param _numPhysicalRegs Number of physical registers.
	 *  @param _numMiscRegs Number of miscellaneous registers.
	 */
	/*PhyRegTable(PhysRegFile * _regFile)
	{
		//PhyRegTableArray.resize(_totalNumRegs);
	}
	*/
	PhyRegTable(unsigned _totalNumRegs);



	/** Destructor. */
	~PhyRegTable() {}


	bool getReadBit(PhysRegIdPtr phys_reg) const
	{
		bool read_bit = (PhyRegTableArray[phys_reg->flatIndex()]).ReadBit;
		return read_bit;
	}

	void setReadBit(PhysRegIdPtr phys_reg)
	{
		(PhyRegTableArray[phys_reg->flatIndex()]).ReadBit = true;
	}

	void unsetReadBit(PhysRegIdPtr phys_reg)
	{
		(PhyRegTableArray[phys_reg->flatIndex()]).ReadBit = false;
	}

	void recoverReadBit(PhysRegIdPtr phys_reg, bool new_ReadBit)
	{
		(PhyRegTableArray[phys_reg->flatIndex()]).ReadBit = new_ReadBit;
	}






	int getTwoBitCounter(PhysRegIdPtr phys_reg)
	{
		int two_bit_counter = (PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter;
		return two_bit_counter;
	}

	void incTwoBitCounter(PhysRegIdPtr phys_reg)
	{
		int two_bit_counter = (PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter;
		(PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter = two_bit_counter + 1;
	}

	void decTwoBitCounter(PhysRegIdPtr phys_reg)
	{
		int two_bit_counter = (PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter;
		(PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter = two_bit_counter - 1;
	}

	void setTwoBitCounter(PhysRegIdPtr phys_reg, int new_TwoBitCounter)
	{
		(PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter = new_TwoBitCounter;
	}


	void initTwoBitCounter(PhysRegIdPtr phys_reg)
	{
		(PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter = 0;
	}


	void initPhyRegTableEntry(PhysRegIdPtr phys_reg)
	{
		(PhyRegTableArray[phys_reg->flatIndex()]).ReadBit = false;
		(PhyRegTableArray[phys_reg->flatIndex()]).TwoBitCounter = 0;
	}
};

#endif
