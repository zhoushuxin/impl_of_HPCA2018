/** \file Directory_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __Directory_TBE_HH__
#define __Directory_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/DataBlock.hh"
#include "mem/protocol/MachineID.hh"
class Directory_TBE
{
  public:
    Directory_TBE
()
		{
        // m_PhysicalAddress has no default
        m_Len = 0; // default value of int
        // m_DataBlk has no default
        // m_Requestor has no default
    }
    Directory_TBE(const Directory_TBE&other)
    {
        m_PhysicalAddress = other.m_PhysicalAddress;
        m_Len = other.m_Len;
        m_DataBlk = other.m_DataBlk;
        m_Requestor = other.m_Requestor;
    }
    Directory_TBE(const Addr& local_PhysicalAddress, const int& local_Len, const DataBlock& local_DataBlk, const MachineID& local_Requestor)
    {
        m_PhysicalAddress = local_PhysicalAddress;
        m_Len = local_Len;
        m_DataBlk = local_DataBlk;
        m_Requestor = local_Requestor;
    }
    Directory_TBE*
    clone() const
    {
         return new Directory_TBE(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    const Addr&
    getPhysicalAddress() const
    {
        return m_PhysicalAddress;
    }
    /** \brief Const accessor method for Len field.
     *  \return Len field
     */
    const int&
    getLen() const
    {
        return m_Len;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for Requestor field.
     *  \return Requestor field
     */
    const MachineID&
    getRequestor() const
    {
        return m_Requestor;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for PhysicalAddress field.
     *  \return PhysicalAddress field
     */
    Addr&
    getPhysicalAddress()
    {
        return m_PhysicalAddress;
    }
    /** \brief Non-const accessor method for Len field.
     *  \return Len field
     */
    int&
    getLen()
    {
        return m_Len;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for Requestor field.
     *  \return Requestor field
     */
    MachineID&
    getRequestor()
    {
        return m_Requestor;
    }
    // Mutator methods for each field
    /** \brief Mutator method for PhysicalAddress field */
    void
    setPhysicalAddress(const Addr& local_PhysicalAddress)
    {
        m_PhysicalAddress = local_PhysicalAddress;
    }
    /** \brief Mutator method for Len field */
    void
    setLen(const int& local_Len)
    {
        m_Len = local_Len;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for Requestor field */
    void
    setRequestor(const MachineID& local_Requestor)
    {
        m_Requestor = local_Requestor;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this entry */
    Addr m_PhysicalAddress;
    /** Length of request */
    int m_Len;
    /** DataBlk */
    DataBlock m_DataBlk;
    /** original requestor */
    MachineID m_Requestor;
};
inline std::ostream&
operator<<(std::ostream& out, const Directory_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __Directory_TBE_HH__
