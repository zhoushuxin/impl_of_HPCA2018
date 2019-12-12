/** \file L2Cache_Entry.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __L2Cache_Entry_HH__
#define __L2Cache_Entry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/L2Cache_State.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/MachineID.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/AbstractCacheEntry.hh"
class L2Cache_Entry :  public AbstractCacheEntry
{
  public:
    L2Cache_Entry
()
		{
        m_CacheState = L2Cache_State_I; // default value of L2Cache_State
        // m_Sharers has no default
        // m_Owner has no default
        m_OwnerValid = false; // default for this field
        m_Dirty = false; // default value of bool
        // m_DataBlk has no default
    }
    L2Cache_Entry(const L2Cache_Entry&other)
        : AbstractCacheEntry(other)
    {
        m_CacheState = other.m_CacheState;
        m_Sharers = other.m_Sharers;
        m_Owner = other.m_Owner;
        m_OwnerValid = other.m_OwnerValid;
        m_Dirty = other.m_Dirty;
        m_DataBlk = other.m_DataBlk;
    }
    L2Cache_Entry(const L2Cache_State& local_CacheState, const NetDest& local_Sharers, const MachineID& local_Owner, const bool& local_OwnerValid, const bool& local_Dirty, const DataBlock& local_DataBlk)
        : AbstractCacheEntry()
    {
        m_CacheState = local_CacheState;
        m_Sharers = local_Sharers;
        m_Owner = local_Owner;
        m_OwnerValid = local_OwnerValid;
        m_Dirty = local_Dirty;
        m_DataBlk = local_DataBlk;
    }
    L2Cache_Entry*
    clone() const
    {
         return new L2Cache_Entry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for CacheState field.
     *  \return CacheState field
     */
    const L2Cache_State&
    getCacheState() const
    {
        return m_CacheState;
    }
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
    /** \brief Const accessor method for Dirty field.
     *  \return Dirty field
     */
    const bool&
    getDirty() const
    {
        return m_Dirty;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for CacheState field.
     *  \return CacheState field
     */
    L2Cache_State&
    getCacheState()
    {
        return m_CacheState;
    }
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
    /** \brief Non-const accessor method for Dirty field.
     *  \return Dirty field
     */
    bool&
    getDirty()
    {
        return m_Dirty;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    // Mutator methods for each field
    /** \brief Mutator method for CacheState field */
    void
    setCacheState(const L2Cache_State& local_CacheState)
    {
        m_CacheState = local_CacheState;
    }
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
    /** \brief Mutator method for Dirty field */
    void
    setDirty(const bool& local_Dirty)
    {
        m_Dirty = local_Dirty;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    void print(std::ostream& out) const;
  //private:
    /** cache state */
    L2Cache_State m_CacheState;
    /** Set of the internal processors that want the block in shared state */
    NetDest m_Sharers;
    /** ID of the L1 cache to forward the block to once we get a response */
    MachineID m_Owner;
    /** true if Owner means something */
    bool m_OwnerValid;
    /** Is the data dirty (different than memory)? */
    bool m_Dirty;
    /** data for the block */
    DataBlock m_DataBlk;
};
inline std::ostream&
operator<<(std::ostream& out, const L2Cache_Entry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L2Cache_Entry_HH__
