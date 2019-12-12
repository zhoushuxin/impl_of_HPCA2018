/** \file RequestMsg.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __RequestMsg_HH__
#define __RequestMsg_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/CoherenceRequestType.hh"
#include "mem/protocol/MachineID.hh"
#include "mem/protocol/MachineType.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/MessageSizeType.hh"
#include "mem/protocol/RubyAccessMode.hh"
#include "mem/protocol/PrefetchBit.hh"
#include "mem/protocol/Message.hh"
class RequestMsg :  public Message
{
  public:
    RequestMsg
(Tick curTime) : Message(curTime) {
        // m_addr has no default
        m_Len = 0; // default value of int
        m_Type = CoherenceRequestType_NUM; // default value of CoherenceRequestType
        // m_Requestor has no default
        m_RequestorMachine = MachineType_NULL; // default value of MachineType
        // m_Destination has no default
        // m_DataBlk has no default
        m_Acks = 0; // default value of int
        m_MessageSize = MessageSizeType_NUM; // default value of MessageSizeType
        m_AccessMode = RubyAccessMode_User; // default value of RubyAccessMode
        m_Prefetch = PrefetchBit_No; // default value of PrefetchBit
    }
    RequestMsg(const RequestMsg&other)
        : Message(other)
    {
        m_addr = other.m_addr;
        m_Len = other.m_Len;
        m_Type = other.m_Type;
        m_Requestor = other.m_Requestor;
        m_RequestorMachine = other.m_RequestorMachine;
        m_Destination = other.m_Destination;
        m_DataBlk = other.m_DataBlk;
        m_Acks = other.m_Acks;
        m_MessageSize = other.m_MessageSize;
        m_AccessMode = other.m_AccessMode;
        m_Prefetch = other.m_Prefetch;
    }
    RequestMsg(const Tick curTime, const Addr& local_addr, const int& local_Len, const CoherenceRequestType& local_Type, const MachineID& local_Requestor, const MachineType& local_RequestorMachine, const NetDest& local_Destination, const DataBlock& local_DataBlk, const int& local_Acks, const MessageSizeType& local_MessageSize, const RubyAccessMode& local_AccessMode, const PrefetchBit& local_Prefetch)
        : Message(curTime)
    {
        m_addr = local_addr;
        m_Len = local_Len;
        m_Type = local_Type;
        m_Requestor = local_Requestor;
        m_RequestorMachine = local_RequestorMachine;
        m_Destination = local_Destination;
        m_DataBlk = local_DataBlk;
        m_Acks = local_Acks;
        m_MessageSize = local_MessageSize;
        m_AccessMode = local_AccessMode;
        m_Prefetch = local_Prefetch;
    }
    MsgPtr
    clone() const
    {
         return std::shared_ptr<Message>(new RequestMsg(*this));
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
    /** \brief Const accessor method for Len field.
     *  \return Len field
     */
    const int&
    getLen() const
    {
        return m_Len;
    }
    /** \brief Const accessor method for Type field.
     *  \return Type field
     */
    const CoherenceRequestType&
    getType() const
    {
        return m_Type;
    }
    /** \brief Const accessor method for Requestor field.
     *  \return Requestor field
     */
    const MachineID&
    getRequestor() const
    {
        return m_Requestor;
    }
    /** \brief Const accessor method for RequestorMachine field.
     *  \return RequestorMachine field
     */
    const MachineType&
    getRequestorMachine() const
    {
        return m_RequestorMachine;
    }
    /** \brief Const accessor method for Destination field.
     *  \return Destination field
     */
    const NetDest&
    getDestination() const
    {
        return m_Destination;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for Acks field.
     *  \return Acks field
     */
    const int&
    getAcks() const
    {
        return m_Acks;
    }
    /** \brief Const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    const MessageSizeType&
    getMessageSize() const
    {
        return m_MessageSize;
    }
    /** \brief Const accessor method for AccessMode field.
     *  \return AccessMode field
     */
    const RubyAccessMode&
    getAccessMode() const
    {
        return m_AccessMode;
    }
    /** \brief Const accessor method for Prefetch field.
     *  \return Prefetch field
     */
    const PrefetchBit&
    getPrefetch() const
    {
        return m_Prefetch;
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
    /** \brief Non-const accessor method for Len field.
     *  \return Len field
     */
    int&
    getLen()
    {
        return m_Len;
    }
    /** \brief Non-const accessor method for Type field.
     *  \return Type field
     */
    CoherenceRequestType&
    getType()
    {
        return m_Type;
    }
    /** \brief Non-const accessor method for Requestor field.
     *  \return Requestor field
     */
    MachineID&
    getRequestor()
    {
        return m_Requestor;
    }
    /** \brief Non-const accessor method for RequestorMachine field.
     *  \return RequestorMachine field
     */
    MachineType&
    getRequestorMachine()
    {
        return m_RequestorMachine;
    }
    /** \brief Non-const accessor method for Destination field.
     *  \return Destination field
     */
    NetDest&
    getDestination()
    {
        return m_Destination;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for Acks field.
     *  \return Acks field
     */
    int&
    getAcks()
    {
        return m_Acks;
    }
    /** \brief Non-const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    MessageSizeType&
    getMessageSize()
    {
        return m_MessageSize;
    }
    /** \brief Non-const accessor method for AccessMode field.
     *  \return AccessMode field
     */
    RubyAccessMode&
    getAccessMode()
    {
        return m_AccessMode;
    }
    /** \brief Non-const accessor method for Prefetch field.
     *  \return Prefetch field
     */
    PrefetchBit&
    getPrefetch()
    {
        return m_Prefetch;
    }
    // Mutator methods for each field
    /** \brief Mutator method for addr field */
    void
    setaddr(const Addr& local_addr)
    {
        m_addr = local_addr;
    }
    /** \brief Mutator method for Len field */
    void
    setLen(const int& local_Len)
    {
        m_Len = local_Len;
    }
    /** \brief Mutator method for Type field */
    void
    setType(const CoherenceRequestType& local_Type)
    {
        m_Type = local_Type;
    }
    /** \brief Mutator method for Requestor field */
    void
    setRequestor(const MachineID& local_Requestor)
    {
        m_Requestor = local_Requestor;
    }
    /** \brief Mutator method for RequestorMachine field */
    void
    setRequestorMachine(const MachineType& local_RequestorMachine)
    {
        m_RequestorMachine = local_RequestorMachine;
    }
    /** \brief Mutator method for Destination field */
    void
    setDestination(const NetDest& local_Destination)
    {
        m_Destination = local_Destination;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for Acks field */
    void
    setAcks(const int& local_Acks)
    {
        m_Acks = local_Acks;
    }
    /** \brief Mutator method for MessageSize field */
    void
    setMessageSize(const MessageSizeType& local_MessageSize)
    {
        m_MessageSize = local_MessageSize;
    }
    /** \brief Mutator method for AccessMode field */
    void
    setAccessMode(const RubyAccessMode& local_AccessMode)
    {
        m_AccessMode = local_AccessMode;
    }
    /** \brief Mutator method for Prefetch field */
    void
    setPrefetch(const PrefetchBit& local_Prefetch)
    {
        m_Prefetch = local_Prefetch;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this request */
    Addr m_addr;
    /** Length of Request */
    int m_Len;
    /** Type of request (GetS, GetX, PutX, etc) */
    CoherenceRequestType m_Type;
    /** Node who initiated the request */
    MachineID m_Requestor;
    /** type of component */
    MachineType m_RequestorMachine;
    /** Multicast destination mask */
    NetDest m_Destination;
    /** data for the cache line (DMA WRITE request) */
    DataBlock m_DataBlk;
    /** How many acks to expect */
    int m_Acks;
    /** size category of the message */
    MessageSizeType m_MessageSize;
    /** user/supervisor access type */
    RubyAccessMode m_AccessMode;
    /** Is this a prefetch request */
    PrefetchBit m_Prefetch;
    bool functionalWrite(Packet* param_pkt);
    bool functionalRead(Packet* param_pkt);
};
inline std::ostream&
operator<<(std::ostream& out, const RequestMsg& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __RequestMsg_HH__
