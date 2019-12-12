/** \file L2Cache_Entry.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:411
 */

#include <iostream>
#include <memory>

#include "mem/protocol/L2Cache_Entry.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
L2Cache_Entry::print(ostream& out) const
{
    out << "[L2Cache_Entry: ";
    out << "CacheState = " << m_CacheState << " ";
    out << "Sharers = " << m_Sharers << " ";
    out << "Owner = " << m_Owner << " ";
    out << "OwnerValid = " << m_OwnerValid << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "]";
}
