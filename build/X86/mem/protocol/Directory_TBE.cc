/** \file Directory_TBE.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/Directory_TBE.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
Directory_TBE::print(ostream& out) const
{
    out << "[Directory_TBE: ";
    out << "PhysicalAddress = " << printAddress(m_PhysicalAddress) << " ";
    out << "TBEState = " << m_TBEState << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Len = " << m_Len << " ";
    out << "DmaRequestor = " << m_DmaRequestor << " ";
    out << "]";
}
