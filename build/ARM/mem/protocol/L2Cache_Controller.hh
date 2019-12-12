/** \file L2Cache_Controller.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:281
 * Created by slicc definition of Module "Token protocol"
 */

#ifndef __L2Cache_CONTROLLER_HH__
#define __L2Cache_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/protocol/TransitionResult.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/L2Cache_Controller.hh"

#include "mem/protocol/TBETable.hh"
#include "mem/protocol/PerfectCacheMemory.hh"
extern std::stringstream L2Cache_transitionComment;

class L2Cache_Controller : public AbstractController
{
  public:
    typedef L2Cache_ControllerParams Params;
    L2Cache_Controller(const Params *p);
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

    void countTransition(L2Cache_State state, L2Cache_Event event);
    void possibleTransition(L2Cache_State state, L2Cache_Event event);
    uint64_t getEventCount(L2Cache_Event event);
    bool isPossible(L2Cache_State state, L2Cache_Event event);
    uint64_t getTransitionCount(L2Cache_State state, L2Cache_Event event);

private:
    CacheMemory* m_L2cache_ptr;
    Cycles m_response_latency;
    Cycles m_request_latency;
    MessageBuffer* m_L1RequestFromL2Cache_ptr;
    MessageBuffer* m_GlobalRequestFromL2Cache_ptr;
    MessageBuffer* m_responseFromL2Cache_ptr;
    MessageBuffer* m_L1RequestToL2Cache_ptr;
    MessageBuffer* m_GlobalRequestToL2Cache_ptr;
    MessageBuffer* m_responseToL2Cache_ptr;
    MessageBuffer* m_triggerQueue_ptr;
    TransitionResult doTransition(L2Cache_Event event,
                                  L2Cache_Entry* m_cache_entry_ptr,
                                  L2Cache_TBE* m_tbe_ptr,
                                  Addr addr);

    TransitionResult doTransitionWorker(L2Cache_Event event,
                                        L2Cache_State state,
                                        L2Cache_State& next_state,
                                        L2Cache_TBE*& m_tbe_ptr,
                                        L2Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr);

    int m_counters[L2Cache_State_NUM][L2Cache_Event_NUM];
    int m_event_counters[L2Cache_Event_NUM];
    bool m_possible[L2Cache_State_NUM][L2Cache_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    L2Cache_Entry* getCacheEntry(const Addr& param_address);
    bool isDirTagPresent(const Addr& param_addr);
    L2Cache_DirEntry* getDirEntry(const Addr& param_address);
    bool isOnlySharer(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_shar_id);
    void copyCacheStateToDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    void copyDirToCache(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    void recordLocalSharerInDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_shar_id);
    void recordNewLocalExclusiveInDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_exc_id);
    void removeAllLocalSharersFromDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    void removeSharerFromDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_sender);
    void removeOwnerFromDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_sender);
    bool isLocalSharer(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_shar_id);
    NetDest getLocalSharers(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    MachineID getLocalOwner(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    int countLocalSharers(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    bool isLocalOwnerValid(L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    int countLocalSharersExceptRequestor(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_requestor);
    L2Cache_State getState(L2Cache_TBE* param_tbe, L2Cache_Entry* param_cache_entry, const Addr& param_addr);
    std::string getCoherenceRequestTypeStr(const CoherenceRequestType& param_type);
    void setState(L2Cache_TBE* param_tbe, L2Cache_Entry* param_cache_entry, const Addr& param_addr, const L2Cache_State& param_state);
    AccessPermission getAccessPermission(const Addr& param_addr);
    void setAccessPermission(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const L2Cache_State& param_state);
    void functionalRead(const Addr& param_addr, Packet* param_pkt);
    int functionalWrite(const Addr& param_addr, Packet* param_pkt);

    // Set and Reset for cache_entry variable
    void set_cache_entry(L2Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry);
    void unset_cache_entry(L2Cache_Entry*& m_cache_entry_ptr);

    // Set and Reset for tbe variable
    void set_tbe(L2Cache_TBE*& m_tbe_ptr, L2Cache_TBE* m_new_tbe);
    void unset_tbe(L2Cache_TBE*& m_tbe_ptr);

    // Actions
    /** \brief issue local request globally */
    void a_issueGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief issue local request globally */
    void a_issueGETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue PUTX */
    void b_issuePUTX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue PUTO */
    void b_issuePUTO(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Issue PUTO */
    void b_issuePUTO_ls(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to L1 requestors in TBE */
    void c_sendDataFromTBEToL1GETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to L1 requestors in TBE */
    void c_sendDataFromTBEToL1GETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to L1 requestors in TBE */
    void c_sendExclusiveDataFromTBEToL1GETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to external GETX */
    void c_sendDataFromTBEToFwdGETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to external GETX */
    void cd_sendDataFromTBEToFwdDma(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to external GETX */
    void c_sendDataFromTBEToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to external GETX */
    void c_sendExclusiveDataFromTBEToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data directly to L1 requestor */
    void d_sendDataToL1GETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data and a token from TBE to L1 requestor */
    void d_sendDataToL1GETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data */
    void dd_sendDataToFwdGETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data */
    void dd_sendDataToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief send data */
    void dd_sendExclusiveDataToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send ack with the tokens we've collected thus far. */
    void e_sendAck(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send ack with the tokens we've collected thus far. */
    void e_sendAckToL1Requestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send ack with the tokens we've collected thus far. */
    void e_sendAckToL1RequestorFromTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send local invalidates */
    void ee_sendLocalInv(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send local invalidates to sharers if they exist */
    void ee_sendLocalInvSharersOnly(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief add a local ack to wait for */
    void ee_addLocalIntAck(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send local invalidates to sharers if they exist */
    void ee_issueLocalInvExceptL1Requestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send local invalidates to sharers if they exist */
    void ee_issueLocalInvExceptL1RequestorInTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send unblock to global directory */
    void f_sendUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send unblock to global directory */
    void f_sendExclusiveUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Record new local sharer from unblock message */
    void g_recordLocalSharer(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Record new local exclusive sharer from unblock message */
    void g_recordLocalExclusive(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Clear local sharers */
    void gg_clearLocalSharers(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Clear sharer from L1 response queue */
    void gg_clearSharerFromL1Response(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Clear sharer from L1 response queue */
    void gg_clearOwnerFromL1Response(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief counts number of acks needed for L1 GETX */
    void h_countLocalSharersExceptRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief clear IntAcks */
    void h_clearIntAcks(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief counts number of acks needed for L1 GETX */
    void hh_countLocalSharersExceptL1GETXRequestorInTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Copy data from response queue to TBE */
    void i_copyDataToTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Allocate TBE for internal/external request(isPrefetch=0, number of invalidates=0) */
    void i_allocateTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Forward external request to local owner */
    void j_forwardGlobalRequestToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Forward dma request to local owner */
    void jd_forwardDmaRequestToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Forward local request to local sharer/owner */
    void k_forwardLocalGETSToLocalSharer(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Forward local request to local owner */
    void k_forwardLocalGETXToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Forward local request to local owner */
    void kk_forwardLocalGETXToLocalExclusive(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Forward local request to local owner */
    void kk_forwardLocalGETSToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send writeback ack to L1 requesting data */
    void l_writebackAckNeedData(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send writeback ack to L1 indicating to drop data */
    void l_writebackAckDropData(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send writeback nack to L1 */
    void ll_writebackNack(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop request queue. */
    void m_popRequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Decrement the number of messages for which we're waiting */
    void m_decrementNumberOfMessagesInt(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Decrement the number of messages for which we're waiting */
    void m_decrementNumberOfMessagesExt(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Decrement the number of messages for which we're waiting */
    void mm_decrementNumberOfMessagesExt(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop response queue */
    void n_popResponseQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop trigger queue. */
    void n_popTriggerQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Pop L1 request queue. */
    void o_popL1RequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Check if we have received all the messages required for completion */
    void o_checkForIntCompletion(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Check if we have received all the messages required for completion */
    void o_checkForExtCompletion(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send data from TBE to directory */
    void qq_sendDataFromTBEToMemory(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief manually set the MRU bit for cache line */
    void r_setMRU(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief record local GETX requestor */
    void s_recordGetXL1ID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate external TBE */
    void s_deallocateTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief record local GETS requestor */
    void s_recordGetSL1ID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief record global GETX requestor */
    void t_recordFwdXID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief record global GETS requestor */
    void t_recordFwdSID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Write data to cache */
    void u_writeDataToCache(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Set L2 cache tag equal to tag of block B. */
    void vv_allocateL2CacheBlock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Deallocate L2 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch. */
    void rr_deallocateL2CacheBlock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Assert that the incoming data and the data in the cache match */
    void w_assertIncomingDataAndCacheDataMatch(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand miss */
    void uu_profileMiss(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Profile the demand hit */
    void uu_profileHit(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Copy cache state to directory state */
    void y_copyCacheStateToDir(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Copy dir state to cache and remove */
    void y_copyDirToCacheAndRemove(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send the head of the mandatory queue to the back of the queue. */
    void zz_recycleL1RequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send the head of the mandatory queue to the back of the queue. */
    void zz_recycleRequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send the head of the mandatory queue to the back of the queue. */
    void zz_recycleResponseQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);
    /** \brief Send dma ack to global directory */
    void da_sendDmaAckUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr);

    // Objects
    TBETable<L2Cache_TBE>* m_TBEs_ptr;
    PerfectCacheMemory<L2Cache_DirEntry>* m_localDirectory_ptr;
};
#endif // __L2Cache_CONTROLLER_H__
