/** \file L1Cache_Controller.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:281
 * Created by slicc definition of Module "Directory protocol"
 */

#ifndef __L1Cache_CONTROLLER_HH__
#define __L1Cache_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/protocol/TransitionResult.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/L1Cache_Controller.hh"

#include "mem/protocol/TBETable.hh"
#include "mem/protocol/TimerTable.hh"
extern std::stringstream L1Cache_transitionComment;

class L1Cache_Controller : public AbstractController
{
  public:
    typedef L1Cache_ControllerParams Params;
    L1Cache_Controller(const Params *p);
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

    void countTransition(L1Cache_State state, L1Cache_Event event);
    void possibleTransition(L1Cache_State state, L1Cache_Event event);
    uint64_t getEventCount(L1Cache_Event event);
    bool isPossible(L1Cache_State state, L1Cache_Event event);
    uint64_t getTransitionCount(L1Cache_State state, L1Cache_Event event);

private:
    Sequencer* m_sequencer_ptr;
    CacheMemory* m_L1Icache_ptr;
    CacheMemory* m_L1Dcache_ptr;
    int m_l2_select_num_bits;
    Cycles m_request_latency;
    Cycles m_use_timeout_latency;
    bool m_send_evictions;
    MessageBuffer* m_requestFromL1Cache_ptr;
    MessageBuffer* m_responseFromL1Cache_ptr;
    MessageBuffer* m_requestToL1Cache_ptr;
    MessageBuffer* m_responseToL1Cache_ptr;
    MessageBuffer* m_triggerQueue_ptr;
    MessageBuffer* m_mandatoryQueue_ptr;
    TransitionResult doTransition(L1Cache_Event event,
                                  L1Cache_Entry* m_cache_entry_ptr,
                                  L1Cache_TBE* m_tbe_ptr,
                                  Addr addr);

    TransitionResult doTransitionWorker(L1Cache_Event event,
                                        L1Cache_State state,
                                        L1Cache_State& next_state,
                                        L1Cache_TBE*& m_tbe_ptr,
                                        L1Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr);

    int m_counters[L1Cache_State_NUM][L1Cache_Event_NUM];
    int m_event_counters[L1Cache_Event_NUM];
    bool m_possible[L1Cache_State_NUM][L1Cache_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    L1Cache_Entry* getCacheEntry(const Addr& param_addr);
    L1Cache_Entry* getL1DCacheEntry(const Addr& param_addr);
    L1Cache_Entry* getL1ICacheEntry(const Addr& param_addr);
    L1Cache_State getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr);
    void setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state);
    AccessPermission getAccessPermission(const Addr& param_addr);
    void setAccessPermission(L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state);
    void functionalRead(const Addr& param_addr, Packet* param_pkt);
    int functionalWrite(const Addr& param_addr, Packet* param_pkt);
    L1Cache_Event mandatory_request_type_to_event(const RubyRequestType& param_type);

    // Set and Reset for cache_entry variable
    void set_cache_entry(L1Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry);
    void unset_cache_entry(L1Cache_Entry*& m_cache_entry_ptr);

    // Set and Reset for tbe variable
    void set_tbe(L1Cache_TBE*& m_tbe_ptr, L1Cache_TBE* m_new_tbe);
    void unset_tbe(L1Cache_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Issue GETS */
    void a_issueGETS(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue GETX */
    void b_issueGETX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue PUTX */
    void d_issuePUTX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue PUTO */
    void dd_issuePUTO(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue PUTS */
    void dd_issuePUTS(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from cache to requestor */
    void e_sendData(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from cache to requestor */
    void e_sendDataToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from cache to requestor, don't keep a shared copy */
    void ee_sendDataExclusive(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send ack from cache to requestor */
    void f_sendAck(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send unblock to memory */
    void g_sendUnblock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send unblock exclusive to memory */
    void gg_sendUnblockExclusive(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Notify sequencer the load completed. */
    void h_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Notify the sequencer about ifetch completion. */
    void h_ifetch_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Notify sequencer the load completed. */
    void hx_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Notify sequencer that store completed. */
    void hh_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Notify sequencer that store completed. */
    void xx_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Allocate TBE */
    void i_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop trigger queue. */
    void j_popTriggerQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Unset use timer. */
    void jj_unsetUseTimer(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop mandatory queue. */
    void k_popMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop forwareded request queue. */
    void l_popForwardQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Decrement the number of messages for which we're waiting */
    void m_decrementNumberOfMessages(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Decrement the number of messages for which we're waiting */
    void mm_decrementNumberOfMessages(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop response queue */
    void n_popResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Check if we have received all the messages required for completion */
    void o_checkForCompletion(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Schedule a use timeout. */
    void o_scheduleUseTimeout(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send dma ack to l2 cache */
    void ub_dmaUnblockL2Cache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to cache */
    void q_sendDataFromTBEToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to cache */
    void q_sendExclusiveDataFromTBEToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to L2 */
    void qq_sendWBDataFromTBEToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate TBE */
    void s_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeDataToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache, assert it was same as before */
    void v_writeDataToCacheVerify(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate cache block.  Sets the cache to invalid, allowing a replacement in parallel with a fetch. */
    void kk_deallocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Set L1 D-cache tag equal to tag of block B. */
    void ii_allocateL1DCacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Set L1 I-cache tag equal to tag of block B. */
    void jj_allocateL1ICacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief sends eviction information to the processor */
    void forward_eviction_to_cpu(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileInstMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand hit */
    void uu_profileInstHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileDataMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand hit */
    void uu_profileDataHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send the head of the mandatory queue to the back of the queue. */
    void z_recycleRequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send the head of the mandatory queue to the back of the queue. */
    void zz_recycleMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr);

    // Objects
    TBETable<L1Cache_TBE>* m_TBEs_ptr;
    TimerTable* m_useTimerTable_ptr;
    int* m_l2_select_low_bit_ptr;
};
#endif // __L1Cache_CONTROLLER_H__
