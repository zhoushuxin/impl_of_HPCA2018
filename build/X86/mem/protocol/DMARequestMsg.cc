/** \file DMARequestMsg.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/DMARequestMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
DMARequestMsg::print(ostream& out) const
{
    out << "[DMARequestMsg: ";
    out << "Type = " << m_Type << " ";
    out << "PhysicalAddress = " << printAddress(m_PhysicalAddress) << " ";
    out << "LineAddress = " << printAddress(m_LineAddress) << " ";
    out << "Requestor = " << m_Requestor << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Len = " << m_Len << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "]";
}
bool
DMARequestMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_LineAddress, m_DataBlk, param_pkt));

}
bool
DMARequestMsg::functionalRead(Packet* param_pkt)
{
return (testAndRead(m_LineAddress, m_DataBlk, param_pkt));

}
