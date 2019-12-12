/** \file L2Cache_DirEntry.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __L2Cache_DirEntry_HH__
#define __L2Cache_DirEntry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/MachineID.hh"
#include "mem/protocol/L2Cache_State.hh"
#include "mem/protocol/AbstractEntry.hh"
class L2Cache_DirEntry :  public AbstractEntry
{
  public:
    L2Cache_DirEntry
()
		{
        // m_Sharers has no default
        // m_Owner has no default
        m_OwnerValid = false; // default for this field
        m_DirState = L2Cache_State_I; // default value of L2Cache_State
    }
    L2Cache_DirEntry(const L2Cache_DirEntry&other)
        : AbstractEntry(other)
    {
        m_Sharers = other.m_Sharers;
        m_Owner = other.m_Owner;
        m_OwnerValid = other.m_OwnerValid;
        m_DirState = other.m_DirState;
    }
    L2Cache_DirEntry(const NetDest& local_Sharers, const MachineID& local_Owner, const bool& local_OwnerValid, const L2Cache_State& local_DirState)
        : AbstractEntry()
    {
        m_Sharers = local_Sharers;
        m_Owner = local_Owner;
        m_OwnerValid = local_OwnerValid;
        m_DirState = local_DirState;
    }
    L2Cache_DirEntry*
    clone() const
    {
         return new L2Cache_DirEntry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for Sharers field.
     *  \return Sharers field
     */
    const NetDest&
    getSharers() const
    {
        return m_Sharers;
    }
    /** \brief Const accessor method for Owner field.
     *  \return Owner field
     */
    const MachineID&
    getOwner() const
    {
        return m_Owner;
    }
    /** \brief Const accessor method for OwnerValid field.
     *  \return OwnerValid field
     */
    const bool&
    getOwnerValid() const
    {
        return m_OwnerValid;
    }
    /** \brief Const accessor method for DirState field.
     *  \return DirState field
     */
    const L2Cache_State&
    getDirState() const
    {
        return m_DirState;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for Sharers field.
     *  \return Sharers field
     */
    NetDest&
    getSharers()
    {
        return m_Sharers;
    }
    /** \brief Non-const accessor method for Owner field.
     *  \return Owner field
     */
    MachineID&
    getOwner()
    {
        return m_Owner;
    }
    /** \brief Non-const accessor method for OwnerValid field.
     *  \return OwnerValid field
     */
    bool&
    getOwnerValid()
    {
        return m_OwnerValid;
    }
    /** \brief Non-const accessor method for DirState field.
     *  \return DirState field
     */
    L2Cache_State&
    getDirState()
    {
        return m_DirState;
    }
    // Mutator methods for each field
    /** \brief Mutator method for Sharers field */
    void
    setSharers(const NetDest& local_Sharers)
    {
        m_Sharers = local_Sharers;
    }
    /** \brief Mutator method for Owner field */
    void
    setOwner(const MachineID& local_Owner)
    {
        m_Owner = local_Owner;
    }
    /** \brief Mutator method for OwnerValid field */
    void
    setOwnerValid(const bool& local_OwnerValid)
    {
        m_OwnerValid = local_OwnerValid;
    }
    /** \brief Mutator method for DirState field */
    void
    setDirState(const L2Cache_State& local_DirState)
    {
        m_DirState = local_DirState;
    }
    void print(std::ostream& out) const;
  //private:
    /** Set of the internal processors that want the block in shared state */
    NetDest m_Sharers;
    /** ID of the L1 cache to forward the block to once we get a response */
    MachineID m_Owner;
    /** true if Owner means something */
    bool m_OwnerValid;
    /** directory state */
    L2Cache_State m_DirState;
};
inline std::ostream&
operator<<(std::ostream& out, const L2Cache_DirEntry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L2Cache_DirEntry_HH__
