/** \file TriggerMsg.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/TriggerMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
TriggerMsg::print(ostream& out) const
{
    out << "[TriggerMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "Type = " << m_Type << " ";
    out << "]";
}
bool
TriggerMsg::functionalWrite(Packet* param_pkt)
{
return (false);

}
bool
TriggerMsg::functionalRead(Packet* param_pkt)
{
return (false);

}
