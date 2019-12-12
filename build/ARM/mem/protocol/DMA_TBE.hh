/** \file DMA_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __DMA_TBE_HH__
#define __DMA_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/DataBlock.hh"
class DMA_TBE
{
  public:
    DMA_TBE
()
		{
        // m_address has no default
        m_NumAcks = 0; // default for this field
        // m_DataBlk has no default
    }
    DMA_TBE(const DMA_TBE&other)
    {
        m_address = other.m_address;
        m_NumAcks = other.m_NumAcks;
        m_DataBlk = other.m_DataBlk;
    }
    DMA_TBE(const Addr& local_address, const int& local_NumAcks, const DataBlock& local_DataBlk)
    {
        m_address = local_address;
        m_NumAcks = local_NumAcks;
        m_DataBlk = local_DataBlk;
    }
    DMA_TBE*
    clone() const
    {
         return new DMA_TBE(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for address field.
     *  \return address field
     */
    const Addr&
    getaddress() const
    {
        return m_address;
    }
    /** \brief Const accessor method for NumAcks field.
     *  \return NumAcks field
     */
    const int&
    getNumAcks() const
    {
        return m_NumAcks;
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
    /** \brief Non-const accessor method for address field.
     *  \return address field
     */
    Addr&
    getaddress()
    {
        return m_address;
    }
    /** \brief Non-const accessor method for NumAcks field.
     *  \return NumAcks field
     */
    int&
    getNumAcks()
    {
        return m_NumAcks;
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
    /** \brief Mutator method for address field */
    void
    setaddress(const Addr& local_address)
    {
        m_address = local_address;
    }
    /** \brief Mutator method for NumAcks field */
    void
    setNumAcks(const int& local_NumAcks)
    {
        m_NumAcks = local_NumAcks;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address */
    Addr m_address;
    /** Number of Acks pending */
    int m_NumAcks;
    /** Data */
    DataBlock m_DataBlk;
};
inline std::ostream&
operator<<(std::ostream& out, const DMA_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __DMA_TBE_HH__
