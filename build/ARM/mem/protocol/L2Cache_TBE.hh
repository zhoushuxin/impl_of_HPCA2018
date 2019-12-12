/** \file L2Cache_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __L2Cache_TBE_HH__
#define __L2Cache_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/L2Cache_State.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/MachineID.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/MachineID.hh"
class L2Cache_TBE
{
  public:
    L2Cache_TBE
()
		{
        // m_addr has no default
        m_TBEState = L2Cache_State_I; // default value of L2Cache_State
        // m_PC has no default
        // m_DataBlk has no default
        m_Dirty = false; // default value of bool
        m_NumExtPendingAcks = 0; // default for this field
        m_NumIntPendingAcks = 0; // default for this field
        m_Fwd_GETX_ExtAcks = 0; // default for this field
        m_Local_GETX_IntAcks = 0; // default for this field
        // m_L1_GetS_IDs has no default
        // m_L1_GetX_ID has no default
        // m_Fwd_GetS_IDs has no default
        // m_Fwd_GetX_ID has no default
    }
    L2Cache_TBE(const L2Cache_TBE&other)
    {
        m_addr = other.m_addr;
        m_TBEState = other.m_TBEState;
        m_PC = other.m_PC;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
        m_NumExtPendingAcks = other.m_NumExtPendingAcks;
        m_NumIntPendingAcks = other.m_NumIntPendingAcks;
        m_Fwd_GETX_ExtAcks = other.m_Fwd_GETX_ExtAcks;
        m_Local_GETX_IntAcks = other.m_Local_GETX_IntAcks;
        m_L1_GetS_IDs = other.m_L1_GetS_IDs;
        m_L1_GetX_ID = other.m_L1_GetX_ID;
        m_Fwd_GetS_IDs = other.m_Fwd_GetS_IDs;
        m_Fwd_GetX_ID = other.m_Fwd_GetX_ID;
    }
    L2Cache_TBE(const Addr& local_addr, const L2Cache_State& local_TBEState, const Addr& local_PC, const DataBlock& local_DataBlk, const bool& local_Dirty, const int& local_NumExtPendingAcks, const int& local_NumIntPendingAcks, const int& local_Fwd_GETX_ExtAcks, const int& local_Local_GETX_IntAcks, const NetDest& local_L1_GetS_IDs, const MachineID& local_L1_GetX_ID, const NetDest& local_Fwd_GetS_IDs, const MachineID& local_Fwd_GetX_ID)
    {
        m_addr = local_addr;
        m_TBEState = local_TBEState;
        m_PC = local_PC;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
        m_NumExtPendingAcks = local_NumExtPendingAcks;
        m_NumIntPendingAcks = local_NumIntPendingAcks;
        m_Fwd_GETX_ExtAcks = local_Fwd_GETX_ExtAcks;
        m_Local_GETX_IntAcks = local_Local_GETX_IntAcks;
        m_L1_GetS_IDs = local_L1_GetS_IDs;
        m_L1_GetX_ID = local_L1_GetX_ID;
        m_Fwd_GetS_IDs = local_Fwd_GetS_IDs;
        m_Fwd_GetX_ID = local_Fwd_GetX_ID;
    }
    L2Cache_TBE*
    clone() const
    {
         return new L2Cache_TBE(*this);
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
    const L2Cache_State&
    getTBEState() const
    {
        return m_TBEState;
    }
    /** \brief Const accessor method for PC field.
     *  \return PC field
     */
    const Addr&
    getPC() const
    {
        return m_PC;
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
    /** \brief Const accessor method for NumExtPendingAcks field.
     *  \return NumExtPendingAcks field
     */
    const int&
    getNumExtPendingAcks() const
    {
        return m_NumExtPendingAcks;
    }
    /** \brief Const accessor method for NumIntPendingAcks field.
     *  \return NumIntPendingAcks field
     */
    const int&
    getNumIntPendingAcks() const
    {
        return m_NumIntPendingAcks;
    }
    /** \brief Const accessor method for Fwd_GETX_ExtAcks field.
     *  \return Fwd_GETX_ExtAcks field
     */
    const int&
    getFwd_GETX_ExtAcks() const
    {
        return m_Fwd_GETX_ExtAcks;
    }
    /** \brief Const accessor method for Local_GETX_IntAcks field.
     *  \return Local_GETX_IntAcks field
     */
    const int&
    getLocal_GETX_IntAcks() const
    {
        return m_Local_GETX_IntAcks;
    }
    /** \brief Const accessor method for L1_GetS_IDs field.
     *  \return L1_GetS_IDs field
     */
    const NetDest&
    getL1_GetS_IDs() const
    {
        return m_L1_GetS_IDs;
    }
    /** \brief Const accessor method for L1_GetX_ID field.
     *  \return L1_GetX_ID field
     */
    const MachineID&
    getL1_GetX_ID() const
    {
        return m_L1_GetX_ID;
    }
    /** \brief Const accessor method for Fwd_GetS_IDs field.
     *  \return Fwd_GetS_IDs field
     */
    const NetDest&
    getFwd_GetS_IDs() const
    {
        return m_Fwd_GetS_IDs;
    }
    /** \brief Const accessor method for Fwd_GetX_ID field.
     *  \return Fwd_GetX_ID field
     */
    const MachineID&
    getFwd_GetX_ID() const
    {
        return m_Fwd_GetX_ID;
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
    L2Cache_State&
    getTBEState()
    {
        return m_TBEState;
    }
    /** \brief Non-const accessor method for PC field.
     *  \return PC field
     */
    Addr&
    getPC()
    {
        return m_PC;
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
    /** \brief Non-const accessor method for NumExtPendingAcks field.
     *  \return NumExtPendingAcks field
     */
    int&
    getNumExtPendingAcks()
    {
        return m_NumExtPendingAcks;
    }
    /** \brief Non-const accessor method for NumIntPendingAcks field.
     *  \return NumIntPendingAcks field
     */
    int&
    getNumIntPendingAcks()
    {
        return m_NumIntPendingAcks;
    }
    /** \brief Non-const accessor method for Fwd_GETX_ExtAcks field.
     *  \return Fwd_GETX_ExtAcks field
     */
    int&
    getFwd_GETX_ExtAcks()
    {
        return m_Fwd_GETX_ExtAcks;
    }
    /** \brief Non-const accessor method for Local_GETX_IntAcks field.
     *  \return Local_GETX_IntAcks field
     */
    int&
    getLocal_GETX_IntAcks()
    {
        return m_Local_GETX_IntAcks;
    }
    /** \brief Non-const accessor method for L1_GetS_IDs field.
     *  \return L1_GetS_IDs field
     */
    NetDest&
    getL1_GetS_IDs()
    {
        return m_L1_GetS_IDs;
    }
    /** \brief Non-const accessor method for L1_GetX_ID field.
     *  \return L1_GetX_ID field
     */
    MachineID&
    getL1_GetX_ID()
    {
        return m_L1_GetX_ID;
    }
    /** \brief Non-const accessor method for Fwd_GetS_IDs field.
     *  \return Fwd_GetS_IDs field
     */
    NetDest&
    getFwd_GetS_IDs()
    {
        return m_Fwd_GetS_IDs;
    }
    /** \brief Non-const accessor method for Fwd_GetX_ID field.
     *  \return Fwd_GetX_ID field
     */
    MachineID&
    getFwd_GetX_ID()
    {
        return m_Fwd_GetX_ID;
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
    setTBEState(const L2Cache_State& local_TBEState)
    {
        m_TBEState = local_TBEState;
    }
    /** \brief Mutator method for PC field */
    void
    setPC(const Addr& local_PC)
    {
        m_PC = local_PC;
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
    /** \brief Mutator method for NumExtPendingAcks field */
    void
    setNumExtPendingAcks(const int& local_NumExtPendingAcks)
    {
        m_NumExtPendingAcks = local_NumExtPendingAcks;
    }
    /** \brief Mutator method for NumIntPendingAcks field */
    void
    setNumIntPendingAcks(const int& local_NumIntPendingAcks)
    {
        m_NumIntPendingAcks = local_NumIntPendingAcks;
    }
    /** \brief Mutator method for Fwd_GETX_ExtAcks field */
    void
    setFwd_GETX_ExtAcks(const int& local_Fwd_GETX_ExtAcks)
    {
        m_Fwd_GETX_ExtAcks = local_Fwd_GETX_ExtAcks;
    }
    /** \brief Mutator method for Local_GETX_IntAcks field */
    void
    setLocal_GETX_IntAcks(const int& local_Local_GETX_IntAcks)
    {
        m_Local_GETX_IntAcks = local_Local_GETX_IntAcks;
    }
    /** \brief Mutator method for L1_GetS_IDs field */
    void
    setL1_GetS_IDs(const NetDest& local_L1_GetS_IDs)
    {
        m_L1_GetS_IDs = local_L1_GetS_IDs;
    }
    /** \brief Mutator method for L1_GetX_ID field */
    void
    setL1_GetX_ID(const MachineID& local_L1_GetX_ID)
    {
        m_L1_GetX_ID = local_L1_GetX_ID;
    }
    /** \brief Mutator method for Fwd_GetS_IDs field */
    void
    setFwd_GetS_IDs(const NetDest& local_Fwd_GetS_IDs)
    {
        m_Fwd_GetS_IDs = local_Fwd_GetS_IDs;
    }
    /** \brief Mutator method for Fwd_GetX_ID field */
    void
    setFwd_GetX_ID(const MachineID& local_Fwd_GetX_ID)
    {
        m_Fwd_GetX_ID = local_Fwd_GetX_ID;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this TBE */
    Addr m_addr;
    /** Transient state */
    L2Cache_State m_TBEState;
    /** Program counter of request */
    Addr m_PC;
    /** Buffer for the data block */
    DataBlock m_DataBlk;
    /** Is the data dirty (different than memory)? */
    bool m_Dirty;
    /** Number of global acks/data messages waiting for */
    int m_NumExtPendingAcks;
    /** Number of global acks/data messages waiting for */
    int m_NumIntPendingAcks;
    /** Number of acks that requestor will need */
    int m_Fwd_GETX_ExtAcks;
    /** Number of acks that requestor will need */
    int m_Local_GETX_IntAcks;
    /** Set of the internal processors that want the block in shared state */
    NetDest m_L1_GetS_IDs;
    /** ID of the L1 cache to forward the block to once we get a response */
    MachineID m_L1_GetX_ID;
    /** Set of the internal processors that want the block in shared state */
    NetDest m_Fwd_GetS_IDs;
    /** ID of the L1 cache to forward the block to once we get a response */
    MachineID m_Fwd_GetX_ID;
};
inline std::ostream&
operator<<(std::ostream& out, const L2Cache_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L2Cache_TBE_HH__
