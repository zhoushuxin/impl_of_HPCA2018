/** \file DMAResponseMsg.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/DMAResponseMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
DMAResponseMsg::print(ostream& out) const
{
    out << "[DMAResponseMsg: ";
    out << "Type = " << m_Type << " ";
    out << "PhysicalAddress = " << printAddress(m_PhysicalAddress) << " ";
    out << "LineAddress = " << printAddress(m_LineAddress) << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "]";
}
bool
DMAResponseMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_LineAddress, m_DataBlk, param_pkt));

}
bool
DMAResponseMsg::functionalRead(Packet* param_pkt)
{
return (testAndRead(m_LineAddress, m_DataBlk, param_pkt));

}
