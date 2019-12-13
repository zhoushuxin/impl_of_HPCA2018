/** \file DMA_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:204
 */

#ifndef __DMA_TBE_HH__
#define __DMA_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"
#include "mem/protocol/DMA_State.hh"
#include "mem/protocol/DataBlock.hh"
class DMA_TBE
{
  public:
    DMA_TBE
()
		{
        m_TBEState = DMA_State_READY; // default value of DMA_State
        // m_DataBlk has no default
    }
    DMA_TBE(const DMA_TBE&other)
    {
        m_TBEState = other.m_TBEState;
        m_DataBlk = other.m_DataBlk;
    }
    DMA_TBE(const DMA_State& local_TBEState, const DataBlock& local_DataBlk)
    {
        m_TBEState = local_TBEState;
        m_DataBlk = local_DataBlk;
    }
    DMA_TBE*
    clone() const
    {
         return new DMA_TBE(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for TBEState field.
     *  \return TBEState field
     */
    const DMA_State&
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
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for TBEState field.
     *  \return TBEState field
     */
    DMA_State&
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
    // Mutator methods for each field
    /** \brief Mutator method for TBEState field */
    void
    setTBEState(const DMA_State& local_TBEState)
    {
        m_TBEState = local_TBEState;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    void print(std::ostream& out) const;
  //private:
    /** Transient state */
    DMA_State m_TBEState;
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
