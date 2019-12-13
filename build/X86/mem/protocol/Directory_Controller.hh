/** \file Directory_Controller.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:281
 * Created by slicc definition of Module "Directory protocol"
 */

#ifndef __Directory_CONTROLLER_HH__
#define __Directory_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/protocol/TransitionResult.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/Directory_Controller.hh"

#include "mem/protocol/TBETable.hh"
extern std::stringstream Directory_transitionComment;

class Directory_Controller : public AbstractController
{
  public:
    typedef Directory_ControllerParams Params;
    Directory_Controller(const Params *p);
    static int getNumControllers();
    void init();

    MessageBuffer *getMandatoryQueue() const;
    MessageBuffer *getMemoryQueue() const;
    void initNetQueues();

    void print(std::ostream& out) const;
    void wakeup();
    void resetStats();
    void regStats();
    void collateStats();

    void recordCacheTrace(int cntrl, CacheRecorder* tr);
    Sequencer* getCPUSequencer() const;
    GPUCoalescer* getGPUCoalescer() const;

    int functionalWriteBuffers(PacketPtr&);

    void countTransition(Directory_State state, Directory_Event event);
    void possibleTransition(Directory_State state, Directory_Event event);
    uint64_t getEventCount(Directory_Event event);
    bool isPossible(Directory_State state, Directory_Event event);
    uint64_t getTransitionCount(Directory_State state, Directory_Event event);

private:
    DirectoryMemory* m_directory_ptr;
    Cycles m_directory_latency;
    Cycles m_to_memory_controller_latency;
    MessageBuffer* m_forwardFromDir_ptr;
    MessageBuffer* m_responseFromDir_ptr;
    MessageBuffer* m_dmaResponseFromDir_ptr;
    MessageBuffer* m_requestToDir_ptr;
    MessageBuffer* m_dmaRequestToDir_ptr;
    MessageBuffer* m_responseFromMemory_ptr;
    TransitionResult doTransition(Directory_Event event,
                                  Directory_TBE* m_tbe_ptr,
                                  Addr addr);

    TransitionResult doTransitionWorker(Directory_Event event,
                                        Directory_State state,
                                        Directory_State& next_state,
                                        Directory_TBE*& m_tbe_ptr,
                                        Addr addr);

    int m_counters[Directory_State_NUM][Directory_Event_NUM];
    int m_event_counters[Directory_Event_NUM];
    bool m_possible[Directory_State_NUM][Directory_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    Directory_Entry* getDirectoryEntry(const Addr& param_addr);
    Directory_State getState(Directory_TBE* param_tbe, const Addr& param_addr);
    void setState(Directory_TBE* param_tbe, const Addr& param_addr, const Directory_State& param_state);
    AccessPermission getAccessPermission(const Addr& param_addr);
    void setAccessPermission(const Addr& param_addr, const Directory_State& param_state);
    void functionalRead(const Addr& param_addr, Packet* param_pkt);
    int functionalWrite(const Addr& param_addr, Packet* param_pkt);

    // Set and Reset for tbe variable
    void set_tbe(Directory_TBE*& m_tbe_ptr, Directory_TBE* m_new_tbe);
    void unset_tbe(Directory_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Send writeback ack to requestor */
    void a_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send writeback ack to requestor */
    void l_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send writeback nack to requestor */
    void b_sendWriteBackNack(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Clear the owner field */
    void c_clearOwner(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send data to requestor */
    void d_sendData(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send Data to DMA controller from directory */
    void dr_sendDMAData(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send Data to DMA controller from incoming PUTX */
    void drp_sendDMAData(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send Ack to DMA controller */
    void da_sendDMAAck(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief The owner is now the requestor */
    void e_ownerIsRequestor(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Forward request to owner */
    void f_forwardRequest(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Invalidate a cache block */
    void inv_sendCacheInvalidate(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Pop incoming request queue */
    void i_popIncomingRequestQueue(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Pop incoming DMA queue */
    void p_popIncomingDMARequestQueue(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Allocate TBE */
    void v_allocateTBE(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Allocate TBE for DMA Read */
    void r_allocateTbeForDmaRead(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Allocate TBE */
    void v_allocateTBEFromRequestNet(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Deallocate TBE */
    void w_deallocateTBE(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief recycle request queue */
    void z_recycleRequestQueue(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief recycle dma request queue */
    void y_recycleDMARequestQueue(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Queue off-chip fetch request */
    void qf_queueMemoryFetchRequest(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Queue off-chip fetch request */
    void qf_queueMemoryFetchRequestDMA(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Queue off-chip writeback request */
    void qw_queueMemoryWBRequest_partial(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Queue off-chip writeback request */
    void qw_queueMemoryWBRequest_partialTBE(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Write PUTX data to memory */
    void l_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Pop off-chip request queue */
    void l_popMemQueue(Directory_TBE*& m_tbe_ptr, Addr addr);

    // Objects
    TBETable<Directory_TBE>* m_TBEs_ptr;
};
#endif // __Directory_CONTROLLER_H__
