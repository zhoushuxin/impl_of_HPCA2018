/** \file L1Cache_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __L1Cache_TBE_HH__
#define __L1Cache_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/DataBlock.hh"
class L1Cache_TBE
{
  public:
    L1Cache_TBE
()
		{
        // m_addr has no default
        m_TBEState = L1Cache_State_I; // default value of L1Cache_State
        // m_DataBlk has no default
        m_Dirty = false; // default value of bool
        m_NumPendingMsgs = 0; // default for this field
    }
    L1Cache_TBE(const L1Cache_TBE&other)
    {
        m_addr = other.m_addr;
        m_TBEState = other.m_TBEState;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
        m_NumPendingMsgs = other.m_NumPendingMsgs;
    }
    L1Cache_TBE(const Addr& local_addr, const L1Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Dirty, const int& local_NumPendingMsgs)
    {
        m_addr = local_addr;
        m_TBEState = local_TBEState;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
        m_NumPendingMsgs = local_NumPendingMsgs;
    }
    L1Cache_TBE*
    clone() const
    {
         return new L1Cache_TBE(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for addr field.
     *  \return addr field
     */
    const Addr&
    getaddr() const
    {
        return m_addr;
    }
    /** \brief Const accessor method for TBEState field.
     *  \return TBEState field
     */
    const L1Cache_State&
    getTBEState() const
    {
        return m_TBEState;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for Dirty field.
     *  \return Dirty field
     */
    const bool&
    getDirty() const
    {
        return m_Dirty;
    }
    /** \brief Const accessor method for NumPendingMsgs field.
     *  \return NumPendingMsgs field
     */
    const int&
    getNumPendingMsgs() const
    {
        return m_NumPendingMsgs;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for addr field.
     *  \return addr field
     */
    Addr&
    getaddr()
    {
        return m_addr;
    }
    /** \brief Non-const accessor method for TBEState field.
     *  \return TBEState field
     */
    L1Cache_State&
    getTBEState()
    {
        return m_TBEState;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for Dirty field.
     *  \return Dirty field
     */
    bool&
    getDirty()
    {
        return m_Dirty;
    }
    /** \brief Non-const accessor method for NumPendingMsgs field.
     *  \return NumPendingMsgs field
     */
    int&
    getNumPendingMsgs()
    {
        return m_NumPendingMsgs;
    }
    // Mutator methods for each field
    /** \brief Mutator method for addr field */
    void
    setaddr(const Addr& local_addr)
    {
        m_addr = local_addr;
    }
    /** \brief Mutator method for TBEState field */
    void
    setTBEState(const L1Cache_State& local_TBEState)
    {
        m_TBEState = local_TBEState;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for Dirty field */
    void
    setDirty(const bool& local_Dirty)
    {
        m_Dirty = local_Dirty;
    }
    /** \brief Mutator method for NumPendingMsgs field */
    void
    setNumPendingMsgs(const int& local_NumPendingMsgs)
    {
        m_NumPendingMsgs = local_NumPendingMsgs;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this TBE */
    Addr m_addr;
    /** Transient state */
    L1Cache_State m_TBEState;
    /** data for the block, required for concurrent writebacks */
    DataBlock m_DataBlk;
    /** Is the data dirty (different than memory)? */
    bool m_Dirty;
    /** Number of acks/data messages that this processor is waiting for */
    int m_NumPendingMsgs;
};
inline std::ostream&
operator<<(std::ostream& out, const L1Cache_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L1Cache_TBE_HH__
