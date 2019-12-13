/** \file DMA_Controller.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:281
 * Created by slicc definition of Module "DMA Controller"
 */

#ifndef __DMA_CONTROLLER_HH__
#define __DMA_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/protocol/TransitionResult.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/DMA_Controller.hh"

#include "mem/protocol/TBETable.hh"
extern std::stringstream DMA_transitionComment;

class DMA_Controller : public AbstractController
{
  public:
    typedef DMA_ControllerParams Params;
    DMA_Controller(const Params *p);
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

    void countTransition(DMA_State state, DMA_Event event);
    void possibleTransition(DMA_State state, DMA_Event event);
    uint64_t getEventCount(DMA_Event event);
    bool isPossible(DMA_State state, DMA_Event event);
    uint64_t getTransitionCount(DMA_State state, DMA_Event event);

private:
    DMASequencer* m_dma_sequencer_ptr;
    Cycles m_request_latency;
    MessageBuffer* m_responseFromDir_ptr;
    MessageBuffer* m_requestToDir_ptr;
    MessageBuffer* m_mandatoryQueue_ptr;
    TransitionResult doTransition(DMA_Event event,
                                  DMA_TBE* m_tbe_ptr,
                                  Addr addr);

    TransitionResult doTransitionWorker(DMA_Event event,
                                        DMA_State state,
                                        DMA_State& next_state,
                                        DMA_TBE*& m_tbe_ptr,
                                        Addr addr);

    int m_counters[DMA_State_NUM][DMA_Event_NUM];
    int m_event_counters[DMA_Event_NUM];
    bool m_possible[DMA_State_NUM][DMA_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    DMA_State getState(DMA_TBE* param_tbe, const Addr& param_addr);
    void setState(DMA_TBE* param_tbe, const Addr& param_addr, const DMA_State& param_state);
    AccessPermission getAccessPermission(const Addr& param_addr);
    void setAccessPermission(const Addr& param_addr, const DMA_State& param_state);
    void functionalRead(const Addr& param_addr, Packet* param_pkt);
    int functionalWrite(const Addr& param_addr, Packet* param_pkt);

    // Set and Reset for tbe variable
    void set_tbe(DMA_TBE*& m_tbe_ptr, DMA_TBE* m_new_tbe);
    void unset_tbe(DMA_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Send a DMA read request to memory */
    void s_sendReadRequest(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Send a DMA write request to memory */
    void s_sendWriteRequest(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Notify dma controller that write request completed */
    void a_ackCallback(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Write data to dma sequencer */
    void d_dataCallback(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Update TBE Data */
    void t_updateTBEData(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Allocate TBE entry */
    void v_allocateTBE(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Deallocate TBE entry */
    void w_deallocateTBE(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Pop request queue */
    void p_popRequestQueue(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief Pop request queue */
    void p_popResponseQueue(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief ... */
    void zz_stallAndWaitRequestQueue(DMA_TBE*& m_tbe_ptr, Addr addr);
    /** \brief wake-up all dependents */
    void wkad_wakeUpAllDependents(DMA_TBE*& m_tbe_ptr, Addr addr);

    // Objects
    TBETable<DMA_TBE>* m_TBEs_ptr;
};
#endif // __DMA_CONTROLLER_H__
