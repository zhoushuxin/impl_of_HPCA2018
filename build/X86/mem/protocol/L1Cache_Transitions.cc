// Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// L1Cache: MI Example L1 Cache

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
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_MII, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MII, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MII, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MII, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Inv):
    return TransitionResult_ProtocolStall;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Inv):
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Store):
    s_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    p_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Ifetch):
    r_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    p_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Store):
    next_state = L1Cache_State_IM;
    if (!(*m_requestFromCache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueRequest(m_tbe_ptr, m_cache_entry_ptr, addr);
    p_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Ifetch):
    next_state = L1Cache_State_IS;
    if (!(*m_requestFromCache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueRequest(m_tbe_ptr, m_cache_entry_ptr, addr);
    p_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data):
    next_state = L1Cache_State_M;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    rx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data):
    next_state = L1Cache_State_M;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    sx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_I;
    if (!(*m_responseFromCache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    e_sendData(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Replacement):
    h_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Inv):
    next_state = L1Cache_State_MI;
    if (!(*m_requestFromCache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issuePUT(m_tbe_ptr, m_cache_entry_ptr, addr);
    x_copyDataFromCacheToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Writeback_Ack):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Writeback_Nack):
    next_state = L1Cache_State_I;
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_II;
    if (!(*m_responseFromCache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ee_sendDataFromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Writeback_Nack):
    next_state = L1Cache_State_MII;
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L1Cache_State_MII, L1Cache_Event_Fwd_GETX):
    next_state = L1Cache_State_I;
    if (!(*m_responseFromCache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ee_sendDataFromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
