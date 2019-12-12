/** \file SequencerMsg.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/SequencerMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
SequencerMsg::print(ostream& out) const
{
    out << "[SequencerMsg: ";
    out << "LineAddress = " << printAddress(m_LineAddress) << " ";
    out << "PhysicalAddress = " << printAddress(m_PhysicalAddress) << " ";
    out << "Type = " << m_Type << " ";
    out << "ProgramCounter = " << printAddress(m_ProgramCounter) << " ";
    out << "AccessMode = " << m_AccessMode << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Len = " << m_Len << " ";
    out << "Prefetch = " << m_Prefetch << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "]";
}
bool
SequencerMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_PhysicalAddress, m_DataBlk, param_pkt));

}
bool
SequencerMsg::functionalRead(Packet* param_pkt)
{
return (testAndRead(m_PhysicalAddress, m_DataBlk, param_pkt));

}
