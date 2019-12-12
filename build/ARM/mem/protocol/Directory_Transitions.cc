// Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// Directory: Directory protocol

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*Directory_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (Directory_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (Directory_transitionComment.str(""))

TransitionResult
Directory_Controller::doTransition(Directory_Event event,
                                  Directory_TBE* m_tbe_ptr,
                                  Addr addr)
{
    Directory_State state = getState(m_tbe_ptr, addr);
    Directory_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), Directory_State_to_string(state),
            Directory_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                Directory_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, addr, next_state);
    setAccessPermission(addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
Directory_Controller::doTransitionWorker(Directory_Event event,
                                        Directory_State state,
                                        Directory_State& next_state,
                                        Directory_TBE*& m_tbe_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(Directory_State_I, Directory_Event_GETX):
    next_state = Directory_State_MM;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_DMA_READ):
    next_state = Directory_State_XI_M;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_DMA_WRITE):
    next_state = Directory_State_XI_U;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qw_queueMemoryWBRequest2(m_tbe_ptr, addr);
    a_sendDMAAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_XI_M, Directory_Event_Memory_Data):
    next_state = Directory_State_I;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataMsg(m_tbe_ptr, addr);
    q_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_XI_U, Directory_Event_Exclusive_Unblock):
    next_state = Directory_State_I;
    cc_clearSharers(m_tbe_ptr, addr);
    c_clearOwner(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_S, Directory_Event_GETX):
    next_state = Directory_State_MM;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    g_sendInvalidations(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_S, Directory_Event_DMA_READ):
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    p_fwdDataToDMA(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_S, Directory_Event_DMA_WRITE):
    next_state = Directory_State_XI_U;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qw_queueMemoryWBRequest2(m_tbe_ptr, addr);
    a_sendDMAAck(m_tbe_ptr, addr);
    g_sendInvalidations(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_GETS):
    next_state = Directory_State_IS;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_S, Directory_Event_GETS):
    next_state = Directory_State_SS;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    n_incrementOutstanding(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_SS, Directory_Event_GETS):
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    n_incrementOutstanding(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_S, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_I, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_S, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_O, Directory_Event_PUTX):
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    b_sendWriteBackNack(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_O, Directory_Event_GETX):
    next_state = Directory_State_MM;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    g_sendInvalidations(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_O, Directory_Event_DMA_READ):
    next_state = Directory_State_OD;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_OD, Directory_Event_DMA_ACK):
  case HASH_FUN(Directory_State_OS, Directory_Event_Unblock):
  case HASH_FUN(Directory_State_OSS, Directory_Event_Unblock):
    next_state = Directory_State_O;
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_O, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_M, Directory_Event_DMA_WRITE):
    next_state = Directory_State_OI_D;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequestDirIsRequestor(m_tbe_ptr, addr);
    g_sendInvalidations(m_tbe_ptr, addr);
    v_allocateTBE(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_OI_D, Directory_Event_Data):
    next_state = Directory_State_XI_U;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qw_queueMemoryWBRequestFromMessageAndTBE(m_tbe_ptr, addr);
    a_sendDMAAck2(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_O, Directory_Event_GETS):
    next_state = Directory_State_OO;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    n_incrementOutstanding(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_OO, Directory_Event_GETS):
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    n_incrementOutstanding(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_GETX):
    next_state = Directory_State_MM;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_DMA_READ):
    next_state = Directory_State_MD;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MD, Directory_Event_DMA_ACK):
  case HASH_FUN(Directory_State_MI, Directory_Event_Unblock):
  case HASH_FUN(Directory_State_MIS, Directory_Event_Unblock):
    next_state = Directory_State_M;
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_GETS):
    next_state = Directory_State_MO;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_M, Directory_Event_PUTO):
    next_state = Directory_State_MI;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_PUTO_SHARERS):
    next_state = Directory_State_MIS;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_O, Directory_Event_PUTO):
    next_state = Directory_State_OS;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_O, Directory_Event_PUTO_SHARERS):
    next_state = Directory_State_OSS;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MM, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MM, Directory_Event_GETX):
  case HASH_FUN(Directory_State_MM, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_MM, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_MM, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_MM, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MM, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_MO, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MO, Directory_Event_GETX):
  case HASH_FUN(Directory_State_MO, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_MO, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_MO, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_MO, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MO, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_MI, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MI, Directory_Event_GETX):
  case HASH_FUN(Directory_State_MI, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_MI, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_MI, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_MI, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MI, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_MIS, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MIS, Directory_Event_GETX):
  case HASH_FUN(Directory_State_MIS, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_MIS, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_MIS, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_MIS, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MIS, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_OS, Directory_Event_GETS):
  case HASH_FUN(Directory_State_OS, Directory_Event_GETX):
  case HASH_FUN(Directory_State_OS, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_OS, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_OS, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_OS, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_OS, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_OSS, Directory_Event_GETS):
  case HASH_FUN(Directory_State_OSS, Directory_Event_GETX):
  case HASH_FUN(Directory_State_OSS, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_OSS, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_OSS, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_OSS, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_OSS, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_GETS):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_GETX):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_GETS):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_GETX):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_GETS):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_GETX):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_OI_D, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_OD, Directory_Event_GETS):
  case HASH_FUN(Directory_State_OD, Directory_Event_GETX):
  case HASH_FUN(Directory_State_OD, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_OD, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_OD, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_OD, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_OD, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_MD, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MD, Directory_Event_GETX):
  case HASH_FUN(Directory_State_MD, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_MD, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_MD, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_MD, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MD, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_IS, Directory_Event_GETX):
  case HASH_FUN(Directory_State_IS, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_IS, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_IS, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_IS, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_IS, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_SS, Directory_Event_GETX):
  case HASH_FUN(Directory_State_SS, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_SS, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_SS, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_SS, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_SS, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_OO, Directory_Event_GETX):
  case HASH_FUN(Directory_State_OO, Directory_Event_PUTO):
  case HASH_FUN(Directory_State_OO, Directory_Event_PUTO_SHARERS):
  case HASH_FUN(Directory_State_OO, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_OO, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_OO, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_IS, Directory_Event_GETS):
    zz_recycleRequest(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MM, Directory_Event_Exclusive_Unblock):
  case HASH_FUN(Directory_State_MO, Directory_Event_Exclusive_Unblock):
  case HASH_FUN(Directory_State_IS, Directory_Event_Exclusive_Unblock):
    next_state = Directory_State_M;
    cc_clearSharers(m_tbe_ptr, addr);
    e_ownerIsUnblocker(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MO, Directory_Event_Unblock):
    next_state = Directory_State_O;
    m_addUnlockerToSharers(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_IS, Directory_Event_Unblock):
    next_state = Directory_State_S;
    m_addUnlockerToSharers(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_SS, Directory_Event_Unblock):
  case HASH_FUN(Directory_State_OO, Directory_Event_Unblock):
    m_addUnlockerToSharers(m_tbe_ptr, addr);
    o_decrementOutstanding(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_SS, Directory_Event_Last_Unblock):
    next_state = Directory_State_S;
    m_addUnlockerToSharers(m_tbe_ptr, addr);
    o_decrementOutstanding(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_OO, Directory_Event_Last_Unblock):
    next_state = Directory_State_O;
    m_addUnlockerToSharers(m_tbe_ptr, addr);
    o_decrementOutstanding(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MI, Directory_Event_Dirty_Writeback):
    next_state = Directory_State_I;
    c_clearOwner(m_tbe_ptr, addr);
    cc_clearSharers(m_tbe_ptr, addr);
    qw_queueMemoryWBRequest(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MIS, Directory_Event_Dirty_Writeback):
  case HASH_FUN(Directory_State_OSS, Directory_Event_Dirty_Writeback):
    next_state = Directory_State_S;
    c_moveOwnerToSharer(m_tbe_ptr, addr);
    qw_queueMemoryWBRequest(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MIS, Directory_Event_Clean_Writeback):
  case HASH_FUN(Directory_State_OSS, Directory_Event_Clean_Writeback):
    next_state = Directory_State_S;
    c_moveOwnerToSharer(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_OS, Directory_Event_Dirty_Writeback):
    next_state = Directory_State_S;
    c_clearOwner(m_tbe_ptr, addr);
    qw_queueMemoryWBRequest(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_MI, Directory_Event_Clean_Writeback):
    next_state = Directory_State_I;
    c_clearOwner(m_tbe_ptr, addr);
    cc_clearSharers(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_OS, Directory_Event_Clean_Writeback):
    next_state = Directory_State_S;
    c_clearOwner(m_tbe_ptr, addr);
    j_popIncomingUnblockQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_S, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_O, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_M, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_IS, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_SS, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_OO, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_MO, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_MM, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_MI, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_MIS, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_OS, Directory_Event_Memory_Data):
  case HASH_FUN(Directory_State_OSS, Directory_Event_Memory_Data):
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataMsg(m_tbe_ptr, addr);
    q_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_S, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_O, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_M, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_IS, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_SS, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_OO, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_MO, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_MM, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_MI, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_MIS, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_OS, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_OSS, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_XI_U, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_XI_M, Directory_Event_Memory_Ack):
    q_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
