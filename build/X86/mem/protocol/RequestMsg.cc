/** \file RequestMsg.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/RequestMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
RequestMsg::print(ostream& out) const
{
    out << "[RequestMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "Type = " << m_Type << " ";
    out << "Requestor = " << m_Requestor << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "]";
}
bool
RequestMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_addr, m_DataBlk, param_pkt));

}
bool
RequestMsg::functionalRead(Packet* param_pkt)
{
    if ((m_Type == CoherenceRequestType_PUTX)) {
        return (testAndRead(m_addr, m_DataBlk, param_pkt));
    }
    return (false);

}
