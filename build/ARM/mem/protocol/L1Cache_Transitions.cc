// Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// L1Cache: Directory protocol

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/L1Cache_Event.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*L1Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L1Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L1Cache_transitionComment.str(""))

TransitionResult
L1Cache_Controller::doTransition(L1Cache_Event event,
                                  L1Cache_Entry* m_cache_entry_ptr,
                                  L1Cache_TBE* m_tbe_ptr,
                                  Addr addr)
{
    L1Cache_State state = getState(m_tbe_ptr, m_cache_entry_ptr, addr);
    L1Cache_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), L1Cache_State_to_string(state),
            L1Cache_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, m_cache_entry_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                L1Cache_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, m_cache_entry_ptr, addr, next_state);
    setAccessPermission(m_cache_entry_ptr, addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
L1Cache_Controller::doTransitionWorker(L1Cache_Event event,
                                        L1Cache_State state,
                                        L1Cache_State& next_state,
                                        L1Cache_TBE*& m_tbe_ptr,
                                        L1Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Ifetch):
    zz_recycleMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Own_GETX):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Own_GETX):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Inv):
    z_recycleRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Load):
    next_state = L1Cache_State_IS;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ii_allocateL1DCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Ifetch):
    next_state = L1Cache_State_IS;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    jj_allocateL1ICacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileInstMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Store):
    next_state = L1Cache_State_IM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ii_allocateL1DCacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_L1_Replacement):
    kk_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Inv):
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_O, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Load):
    h_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_O, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Ifetch):
    h_ifetch_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileInstHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Store):
    next_state = L1Cache_State_SM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_L1_Replacement):
    next_state = L1Cache_State_SI;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    dd_issuePUTS(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    kk_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Inv):
    next_state = L1Cache_State_I;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_O, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Fwd_GETS):
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    e_sendData(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_O, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Fwd_DMA):
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    e_sendData(m_tbe_ptr, m_cache_entry_ptr, addr);
    ub_dmaUnblockL2Cache(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_O, L1Cache_Event_Store):
    next_state = L1Cache_State_OM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_O, L1Cache_Event_L1_Replacement):
    next_state = L1Cache_State_OI;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    dd_issuePUTO(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    kk_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_O, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_I;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    ee_sendDataExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Store):
    hh_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_L1_Replacement):
    next_state = L1Cache_State_MI;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    d_issuePUTX(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    kk_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Store):
    next_state = L1Cache_State_MM;
    hh_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Store):
    next_state = L1Cache_State_MM_W;
    hh_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileDataHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GETS):
    next_state = L1Cache_State_O;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    e_sendData(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ack):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ack):
  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Ack):
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_decrementNumberOfMessages(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Exclusive_Data):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data):
    next_state = L1Cache_State_OM;
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessages(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Inv):
    next_state = L1Cache_State_IM;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Data):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Exclusive_Data):
    next_state = L1Cache_State_OM;
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_decrementNumberOfMessages(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Own_GETX):
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    mm_decrementNumberOfMessages(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_IM;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    ee_sendDataExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_OM, L1Cache_Event_All_acks):
    next_state = L1Cache_State_MM_W;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    xx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_sendUnblockExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_scheduleUseTimeout(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MM_W, L1Cache_Event_Use_Timeout):
    next_state = L1Cache_State_MM;
    jj_unsetUseTimer(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data):
    next_state = L1Cache_State_S;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessages(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    g_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Exclusive_Data):
    next_state = L1Cache_State_M_W;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessages(m_tbe_ptr, m_cache_entry_ptr, addr);
    hx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_sendUnblockExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_scheduleUseTimeout(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M_W, L1Cache_Event_Use_Timeout):
    next_state = L1Cache_State_M;
    jj_unsetUseTimer(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Fwd_GETS):
    next_state = L1Cache_State_OI;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    q_sendDataFromTBEToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Fwd_DMA):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Fwd_DMA):
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    q_sendDataFromTBEToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    ub_dmaUnblockL2Cache(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_II;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    q_sendExclusiveDataFromTBEToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Fwd_GETS):
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    q_sendDataFromTBEToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Writeback_Ack_Data):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Writeback_Ack_Data):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Writeback_Ack_Data):
    next_state = L1Cache_State_I;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_sendWBDataFromTBEToL2(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Writeback_Ack):
  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Writeback_Ack):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Writeback_Ack):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Writeback_Ack):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Writeback_Ack_Data):
    next_state = L1Cache_State_I;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    g_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Writeback_Nack):
    next_state = L1Cache_State_OI;
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_issuePUTO(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_OI, L1Cache_Event_Writeback_Nack):
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_issuePUTO(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Writeback_Nack):
    next_state = L1Cache_State_I;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Writeback_Nack):
    if (!(*m_requestFromL1Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_issuePUTS(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_SI, L1Cache_Event_Inv):
    next_state = L1Cache_State_II;
    if (!(*m_responseFromL1Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    l_popForwardQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
