/** \file DMARequestMsg.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __DMARequestMsg_HH__
#define __DMARequestMsg_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/DMARequestType.hh"
#include "mem/protocol/MachineID.hh"
#include "mem/protocol/NetDest.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/MessageSizeType.hh"
#include "mem/protocol/Message.hh"
class DMARequestMsg :  public Message
{
  public:
    DMARequestMsg
(Tick curTime) : Message(curTime) {
        m_Type = DMARequestType_NULL; // default value of DMARequestType
        // m_PhysicalAddress has no default
        // m_LineAddress has no default
        // m_Requestor has no default
        // m_Destination has no default
        // m_DataBlk has no default
        m_Len = 0; // default value of int
        m_MessageSize = MessageSizeType_NUM; // default value of MessageSizeType
    }
    DMARequestMsg(const DMARequestMsg&other)
        : Message(other)
    {
        m_Type = other.m_Type;
        m_PhysicalAddress = other.m_PhysicalAddress;
        m_LineAddress = other.m_LineAddress;
        m_Requestor = other.m_Requestor;
        m_Destination = other.m_Destination;
        m_DataBlk = other.m_DataBlk;
        m_Len = other.m_Len;
        m_MessageSize = other.m_MessageSize;
    }
    DMARequestMsg(const Tick curTime, const DMARequestType& local_Type, const Addr& local_PhysicalAddress, const Addr& local_LineAddress, const MachineID& local_Requestor, const NetDest& local_Destination, const DataBlock& local_DataBlk, const int& local_Len, const MessageSizeType& local_MessageSize)
        : Message(curTime)
    {
        m_Type = local_Type;
        m_PhysicalAddress = local_PhysicalAddress;
        m_LineAddress = local_LineAddress;
        m_Requestor = local_Requestor;
        m_Destination = local_Destination;
        m_DataBlk = local_DataBlk;
        m_Len = local_Len;
        m_MessageSize = local_MessageSize;
    }
    MsgPtr
    clone() const
    {
         return std::shared_ptr<Message>(new DMARequestMsg(*this));
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for Type field.
     *  \return Type field
     */
    const DMARequestType&
    getType() const
    {
        return m_Type;
    }
    /** \brief Const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    const Addr&
    getPhysicalAddress() const
    {
        return m_PhysicalAddress;
    }
    /** \brief Const accessor method for LineAddress field.
     *  \return LineAddress field
     */
    const Addr&
    getLineAddress() const
    {
        return m_LineAddress;
    }
    /** \brief Const accessor method for Requestor field.
     *  \return Requestor field
     */
    const MachineID&
    getRequestor() const
    {
        return m_Requestor;
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
    /** \brief Const accessor method for Len field.
     *  \return Len field
     */
    const int&
    getLen() const
    {
        return m_Len;
    }
    /** \brief Const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    const MessageSizeType&
    getMessageSize() const
    {
        return m_MessageSize;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for Type field.
     *  \return Type field
     */
    DMARequestType&
    getType()
    {
        return m_Type;
    }
    /** \brief Non-const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    Addr&
    getPhysicalAddress()
    {
        return m_PhysicalAddress;
    }
    /** \brief Non-const accessor method for LineAddress field.
     *  \return LineAddress field
     */
    Addr&
    getLineAddress()
    {
        return m_LineAddress;
    }
    /** \brief Non-const accessor method for Requestor field.
     *  \return Requestor field
     */
    MachineID&
    getRequestor()
    {
        return m_Requestor;
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
    /** \brief Non-const accessor method for Len field.
     *  \return Len field
     */
    int&
    getLen()
    {
        return m_Len;
    }
    /** \brief Non-const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    MessageSizeType&
    getMessageSize()
    {
        return m_MessageSize;
    }
    // Mutator methods for each field
    /** \brief Mutator method for Type field */
    void
    setType(const DMARequestType& local_Type)
    {
        m_Type = local_Type;
    }
    /** \brief Mutator method for PhysicalAddress field */
    void
    setPhysicalAddress(const Addr& local_PhysicalAddress)
    {
        m_PhysicalAddress = local_PhysicalAddress;
    }
    /** \brief Mutator method for LineAddress field */
    void
    setLineAddress(const Addr& local_LineAddress)
    {
        m_LineAddress = local_LineAddress;
    }
    /** \brief Mutator method for Requestor field */
    void
    setRequestor(const MachineID& local_Requestor)
    {
        m_Requestor = local_Requestor;
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
    /** \brief Mutator method for Len field */
    void
    setLen(const int& local_Len)
    {
        m_Len = local_Len;
    }
    /** \brief Mutator method for MessageSize field */
    void
    setMessageSize(const MessageSizeType& local_MessageSize)
    {
        m_MessageSize = local_MessageSize;
    }
    void print(std::ostream& out) const;
  //private:
    /** Request type (read/write) */
    DMARequestType m_Type;
    /** Physical address for this request */
    Addr m_PhysicalAddress;
    /** Line address for this request */
    Addr m_LineAddress;
    /** Node who initiated the request */
    MachineID m_Requestor;
    /** Destination */
    NetDest m_Destination;
    /** DataBlk attached to this request */
    DataBlock m_DataBlk;
    /** The length of the request */
    int m_Len;
    /** size category of the message */
    MessageSizeType m_MessageSize;
    bool functionalWrite(Packet* param_pkt);
    bool functionalRead(Packet* param_pkt);
};
inline std::ostream&
operator<<(std::ostream& out, const DMARequestMsg& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __DMARequestMsg_HH__
