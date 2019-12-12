/** \file MemoryMsg.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/MemoryMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
MemoryMsg::print(ostream& out) const
{
    out << "[MemoryMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "Type = " << m_Type << " ";
    out << "Sender = " << m_Sender << " ";
    out << "OriginalRequestorMachId = " << m_OriginalRequestorMachId << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "Prefetch = " << m_Prefetch << " ";
    out << "ReadX = " << m_ReadX << " ";
    out << "Acks = " << m_Acks << " ";
    out << "]";
}
bool
MemoryMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_addr, m_DataBlk, param_pkt));

}
bool
MemoryMsg::functionalRead(Packet* param_pkt)
{
return (testAndRead(m_addr, m_DataBlk, param_pkt));

}
