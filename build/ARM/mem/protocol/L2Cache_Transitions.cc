// Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:1188
// L2Cache: Token protocol

#include <cassert>

#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/L2Cache_Controller.hh"
#include "mem/protocol/L2Cache_Event.hh"
#include "mem/protocol/L2Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#define HASH_FUN(state, event)  ((int(state)*L2Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L2Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L2Cache_transitionComment.str(""))

TransitionResult
L2Cache_Controller::doTransition(L2Cache_Event event,
                                  L2Cache_Entry* m_cache_entry_ptr,
                                  L2Cache_TBE* m_tbe_ptr,
                                  Addr addr)
{
    L2Cache_State state = getState(m_tbe_ptr, m_cache_entry_ptr, addr);
    L2Cache_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %#x\n",
            *this, curCycle(), L2Cache_State_to_string(state),
            L2Cache_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, m_cache_entry_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                L2Cache_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L2Cache",
                 L2Cache_Event_to_string(event),
                 L2Cache_State_to_string(state),
                 L2Cache_State_to_string(next_state),
                 printAddress(addr), GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, m_cache_entry_ptr, addr, next_state);
    setAccessPermission(m_cache_entry_ptr, addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L2Cache",
                 L2Cache_Event_to_string(event),
                 L2Cache_State_to_string(state),
                 L2Cache_State_to_string(next_state),
                 printAddress(addr), "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %#x %s\n",
                 curTick(), m_version, "L2Cache",
                 L2Cache_Event_to_string(event),
                 L2Cache_State_to_string(state),
                 L2Cache_State_to_string(next_state),
                 printAddress(addr), "Protocol Stall");
    }

    return result;
}

TransitionResult
L2Cache_Controller::doTransitionWorker(L2Cache_Event event,
                                        L2Cache_State state,
                                        L2Cache_State& next_state,
                                        L2Cache_TBE*& m_tbe_ptr,
                                        L2Cache_Entry*& m_cache_entry_ptr,
                                        Addr addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L1_GETS):
    zz_recycleL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_L2_Replacement):
    zz_recycleResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OFGX, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_Own_GETX):
    zz_recycleRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_O, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_S, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_I, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_I, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L1_PUTS_only):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L1_PUTO):
  case HASH_FUN(L2Cache_State_S, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_L1_PUTS):
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ll_writebackNack(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_L1_PUTO):
    next_state = L2Cache_State_ILOW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L1_PUTO):
    next_state = L2Cache_State_ILOSW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTO):
    next_state = L2Cache_State_ILOSXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_Fwd_GETS):
    next_state = L2Cache_State_IFGS;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_forwardGlobalRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_Fwd_GETS):
    next_state = L2Cache_State_ISFGS;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_forwardGlobalRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_Fwd_DMA):
    next_state = L2Cache_State_ILOSD;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    jd_forwardDmaRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSD, L2Cache_Event_DmaAck):
    next_state = L2Cache_State_ILOS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_Fwd_DMA):
    next_state = L2Cache_State_ILOSXD;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    jd_forwardDmaRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSXD, L2Cache_Event_DmaAck):
    next_state = L2Cache_State_ILOSX;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_Fwd_DMA):
    next_state = L2Cache_State_ILOD;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    jd_forwardDmaRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOD, L2Cache_Event_DmaAck):
    next_state = L2Cache_State_ILO;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_Fwd_DMA):
    next_state = L2Cache_State_ILXD;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    jd_forwardDmaRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILXD, L2Cache_Event_DmaAck):
    next_state = L2Cache_State_ILX;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_Fwd_DMA):
    next_state = L2Cache_State_ILOXD;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    jd_forwardDmaRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOXD, L2Cache_Event_DmaAck):
    next_state = L2Cache_State_ILOX;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_Data):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_Data):
    next_state = L2Cache_State_ILO;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ISFGS, L2Cache_Event_Data):
    next_state = L2Cache_State_ILOS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGS, L2Cache_Event_Data_Exclusive):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendExclusiveDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_IFGX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_forwardGlobalRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_Data_Exclusive):
  case HASH_FUN(L2Cache_State_IFGX, L2Cache_Event_Data):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_IFGXX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_forwardGlobalRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInvSharersOnly(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_addLocalIntAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_IntAck):
  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_IntAck):
  case HASH_FUN(L2Cache_State_II, L2Cache_Event_IntAck):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_IntAck):
  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_IntAck):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_IntAck):
  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_IntAck):
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_decrementNumberOfMessagesInt(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForIntCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_Data_Exclusive):
  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_Data_Exclusive):
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessagesInt(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForIntCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFGXX, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_O, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendDataToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_O, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_Fwd_GETS):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendDataToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_O, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_Fwd_DMA):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendDataToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_Fwd_GETS):
    next_state = L2Cache_State_OLS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendDataToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendDataToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_Fwd_GETS):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendExclusiveDataToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_Fwd_DMA):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    dd_sendExclusiveDataToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_OLSF;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInv(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSF, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Inv):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_I, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_Inv):
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_Inv):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_Inv):
    next_state = L2Cache_State_II;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInv(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_Inv):
    next_state = L2Cache_State_II;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInv(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_II, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    e_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_S, L2Cache_Event_Inv):
    next_state = L2Cache_State_I;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IFLOX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_issueLocalInvExceptL1Requestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    d_sendDataToL1GETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_IFLXO, L2Cache_Event_Exclusive_Unblock):
    next_state = L2Cache_State_ILX;
    g_recordLocalExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_OLSXS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSXS, L2Cache_Event_Unblock):
    next_state = L2Cache_State_OLSX;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_Own_GETX):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_Own_GETX):
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    mm_decrementNumberOfMessagesExt(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForExtCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_IFLOXX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    kk_forwardLocalGETSToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_IFLOSX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    kk_forwardLocalGETSToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_IFLO;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    kk_forwardLocalGETSToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_IFLS;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    k_forwardLocalGETSToLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IFLOXX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    kk_forwardLocalGETXToLocalExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAckToL1Requestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_IFLOX;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    kk_forwardLocalGETSToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFLOX, L2Cache_Event_Unblock):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_Unblock):
  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILOSX;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFLS, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILS;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFLOSX, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_IFLOXX, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_MM, L2Cache_Event_Exclusive_Unblock):
    next_state = L2Cache_State_ILX;
    g_recordLocalExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IFLO, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILOS;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IFLXO;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_issueLocalInvExceptL1Requestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_forwardLocalGETXToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAckToL1RequestorFromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_I, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_IGS;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetSL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_I, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGM;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_S, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGM;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGMLS;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_Inv):
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInv(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_IGM;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_clearIntAcks(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_ExtAck):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_ExtAck):
  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_ExtAck):
  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_ExtAck):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_ExtAck):
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    m_decrementNumberOfMessagesExt(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForExtCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_IGMLS, L2Cache_Event_Data_Exclusive):
    next_state = L2Cache_State_IGMO;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ee_issueLocalInvExceptL1RequestorInTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessagesExt(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForExtCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGMIO;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_OGMIO;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_Fwd_GETS):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_Fwd_GETS):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGMIO;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_IGMIOF;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_forwardGlobalRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInvSharersOnly(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_addLocalIntAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_Fwd_GETS):
    next_state = L2Cache_State_IGMIOFS;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    j_forwardGlobalRequestToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMIOFS, L2Cache_Event_Data):
    next_state = L2Cache_State_IGMIO;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_OGMIOF;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInvSharersOnly(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OGMIOF, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_IGM;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    hh_countLocalSharersExceptL1GETXRequestorInTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMIOF, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_IGM;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMIO, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_IGMO;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    hh_countLocalSharersExceptL1GETXRequestorInTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_issueLocalInvExceptL1RequestorInTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    k_forwardLocalGETXToLocalOwner(m_tbe_ptr, m_cache_entry_ptr, addr);
    e_sendAckToL1RequestorFromTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OGMIO, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_IGMO;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    ee_issueLocalInvExceptL1RequestorInTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToL1GETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Data):
  case HASH_FUN(L2Cache_State_IGM, L2Cache_Event_Data_Exclusive):
    next_state = L2Cache_State_IGMO;
    if (!(*m_triggerQueue_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessagesExt(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_checkForExtCompletion(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Data):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessagesExt(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Data_Exclusive):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_copyDataToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_decrementNumberOfMessagesExt(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendExclusiveDataFromTBEToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGS, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_Exclusive_Unblock):
    next_state = L2Cache_State_ILX;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    g_recordLocalExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    f_sendExclusiveUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_All_Acks):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    c_sendDataFromTBEToL1GETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGMLS;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_SLSS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLSS, L2Cache_Event_Unblock):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_Unblock):
    next_state = L2Cache_State_SLS;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_O, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_IGMO;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_recordGetXL1ID(m_tbe_ptr, m_cache_entry_ptr, addr);
    a_issueGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_OLSS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSS, L2Cache_Event_Unblock):
  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_Unblock):
    next_state = L2Cache_State_OLS;
    g_recordLocalSharer(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IGMO, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_IGM;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETX):
    next_state = L2Cache_State_MM;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    d_sendDataToL1GETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_OO;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_countLocalSharersExceptRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    d_sendDataToL1GETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_S, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_SS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_O, L2Cache_Event_L1_GETS):
    next_state = L2Cache_State_OO;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    d_sendDataToL1GETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    r_setMRU(m_tbe_ptr, m_cache_entry_ptr, addr);
    uu_profileHit(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OO, L2Cache_Event_Exclusive_Unblock):
    next_state = L2Cache_State_ILX;
    g_recordLocalExclusive(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOX, L2Cache_Event_L1_PUTO):
    next_state = L2Cache_State_ILOXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L1_PUTS_only):
    next_state = L2Cache_State_ILOW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILS;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILO;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTS_only):
    next_state = L2Cache_State_ILOXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILOX;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L1_PUTS):
    next_state = L2Cache_State_ILOSW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTS):
    next_state = L2Cache_State_ILOSXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILOS;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILOSX;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_L1_PUTS):
    next_state = L2Cache_State_SLSW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_L1_PUTS_only):
    next_state = L2Cache_State_SW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_S;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_L1_PUTS):
    next_state = L2Cache_State_OLSW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L1_PUTS):
    next_state = L2Cache_State_ILSW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L1_PUTS_only):
    next_state = L2Cache_State_IW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_L1_PUTS_only):
    next_state = L2Cache_State_OW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L1_PUTS_only):
    next_state = L2Cache_State_OXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L1_PUTS):
    next_state = L2Cache_State_OLSXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckDropData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSXW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_OLSX;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_O;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OXW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_M;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L1_PUTX):
    next_state = L2Cache_State_ILXW;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    l_writebackAckNeedData(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popL1RequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_WBDIRTYDATA):
  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_L1_WBCLEANDATA):
    next_state = L2Cache_State_M;
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILXW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_ILX;
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILSW, L2Cache_Event_L1_WBCLEANDATA):
    next_state = L2Cache_State_SLS;
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_IW, L2Cache_Event_L1_WBCLEANDATA):
    next_state = L2Cache_State_S;
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_WBCLEANDATA):
  case HASH_FUN(L2Cache_State_ILOW, L2Cache_Event_L1_WBDIRTYDATA):
    next_state = L2Cache_State_O;
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearOwnerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_WBDIRTYDATA):
  case HASH_FUN(L2Cache_State_ILOXW, L2Cache_Event_L1_WBCLEANDATA):
    next_state = L2Cache_State_M;
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearOwnerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_WBCLEANDATA):
  case HASH_FUN(L2Cache_State_ILOSW, L2Cache_Event_L1_WBDIRTYDATA):
    next_state = L2Cache_State_OLS;
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearOwnerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_WBCLEANDATA):
  case HASH_FUN(L2Cache_State_ILOSXW, L2Cache_Event_L1_WBDIRTYDATA):
    next_state = L2Cache_State_OLSX;
    vv_allocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    y_copyDirToCacheAndRemove(m_tbe_ptr, m_cache_entry_ptr, addr);
    gg_clearOwnerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLSW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_SLS;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSW, L2Cache_Event_Unblock):
    next_state = L2Cache_State_OLS;
    gg_clearSharerFromL1Response(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_I, L2Cache_Event_L2_Replacement):
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_S, L2Cache_Event_L2_Replacement):
    next_state = L2Cache_State_I;
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILX, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILO, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ILOS, L2Cache_Event_L2_Replacement):
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_SLS, L2Cache_Event_L2_Replacement):
    next_state = L2Cache_State_ILS;
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_OLSX, L2Cache_Event_L2_Replacement):
    next_state = L2Cache_State_OLSI;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    y_copyCacheStateToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    b_issuePUTO_ls(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_O, L2Cache_Event_L2_Replacement):
    next_state = L2Cache_State_OI;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    b_issuePUTO(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement):
    next_state = L2Cache_State_MI;
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    if (!(*m_TBEs_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    b_issuePUTX(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    rr_deallocateL2CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_ILSI;
    if (!(*m_L1RequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    ee_sendLocalInv(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_All_Acks):
    next_state = L2Cache_State_MII;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    gg_clearLocalSharers(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popTriggerQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_Fwd_GETS):
    next_state = L2Cache_State_OI;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdSID(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETS(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_Fwd_DMA):
    next_state = L2Cache_State_OI;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    cd_sendDataFromTBEToFwdDma(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_Fwd_DMA):
  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_Fwd_DMA):
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(2, clockEdge()))
        return TransitionResult_ResourceStall;
    cd_sendDataFromTBEToFwdDma(m_tbe_ptr, m_cache_entry_ptr, addr);
    da_sendDmaAckUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_Fwd_GETX):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_Fwd_GETX):
    next_state = L2Cache_State_MII;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    t_recordFwdXID(m_tbe_ptr, m_cache_entry_ptr, addr);
    c_sendDataFromTBEToFwdGETX(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MI, L2Cache_Event_Writeback_Ack):
  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_Writeback_Ack):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_sendDataFromTBEToMemory(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_Writeback_Nack):
    next_state = L2Cache_State_I;
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OI, L2Cache_Event_Writeback_Nack):
    if (!(*m_GlobalRequestFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    b_issuePUTO(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_OLSI, L2Cache_Event_Writeback_Ack):
    next_state = L2Cache_State_ILS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    qq_sendDataFromTBEToMemory(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_MII, L2Cache_Event_Writeback_Ack):
    next_state = L2Cache_State_I;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(L2Cache_State_ILSI, L2Cache_Event_Writeback_Ack):
    next_state = L2Cache_State_ILS;
    if (!(*m_responseFromL2Cache_ptr).areNSlotsAvailable(1, clockEdge()))
        return TransitionResult_ResourceStall;
    f_sendUnblock(m_tbe_ptr, m_cache_entry_ptr, addr);
    s_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;

      default:
        panic("Invalid transition\n"
              "%s time: %d addr: %#x event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
