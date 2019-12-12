/** \file L2Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:465
 * Created by slicc definition of Module "Token protocol"
 */

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <string>
#include <typeinfo>

#include "base/compiler.hh"
#include "mem/ruby/common/BoolVec.hh"
#include "base/cprintf.hh"

#include "debug/RubySlicc.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/L2Cache_Controller.hh"
#include "mem/protocol/L2Cache_Event.hh"
#include "mem/protocol/L2Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/network/Network.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/protocol/TBETable.hh"
#include "mem/protocol/PerfectCacheMemory.hh"
L2Cache_Controller *
L2Cache_ControllerParams::create()
{
    return new L2Cache_Controller(this);
}

int L2Cache_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  L2Cache_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  L2Cache_Controller::transVec;

// for adding information to the protocol debug trace
stringstream L2Cache_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (L2Cache_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
L2Cache_Controller::L2Cache_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_L2Cache;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 4;
    m_L2cache_ptr = p->L2cache;
    m_response_latency = p->response_latency;
    m_request_latency = p->request_latency;
    m_L1RequestFromL2Cache_ptr = p->L1RequestFromL2Cache;
    m_GlobalRequestFromL2Cache_ptr = p->GlobalRequestFromL2Cache;
    m_responseFromL2Cache_ptr = p->responseFromL2Cache;
    m_L1RequestToL2Cache_ptr = p->L1RequestToL2Cache;
    m_GlobalRequestToL2Cache_ptr = p->GlobalRequestToL2Cache;
    m_responseToL2Cache_ptr = p->responseToL2Cache;
    m_triggerQueue_ptr = p->triggerQueue;

    for (int state = 0; state < L2Cache_State_NUM; state++) {
        for (int event = 0; event < L2Cache_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < L2Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
L2Cache_Controller::initNetQueues()
{
    MachineType machine_type = string_to_MachineType("L2Cache");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    assert(m_L1RequestFromL2Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_L1RequestFromL2Cache_ptr->getOrdered(), 0,
                                     "request", m_L1RequestFromL2Cache_ptr);
    assert(m_GlobalRequestFromL2Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_GlobalRequestFromL2Cache_ptr->getOrdered(), 1,
                                     "request", m_GlobalRequestFromL2Cache_ptr);
    assert(m_responseFromL2Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_responseFromL2Cache_ptr->getOrdered(), 2,
                                     "response", m_responseFromL2Cache_ptr);
    assert(m_L1RequestToL2Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_L1RequestToL2Cache_ptr->getOrdered(), 0,
                                     "request", m_L1RequestToL2Cache_ptr);
    assert(m_GlobalRequestToL2Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_GlobalRequestToL2Cache_ptr->getOrdered(), 1,
                                     "request", m_GlobalRequestToL2Cache_ptr);
    assert(m_responseToL2Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_responseToL2Cache_ptr->getOrdered(), 2,
                                     "response", m_responseToL2Cache_ptr);
}

void
L2Cache_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<L2Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);
    m_localDirectory_ptr  = new PerfectCacheMemory<L2Cache_DirEntry>();
    assert(m_localDirectory_ptr != NULL);


    (*m_triggerQueue_ptr).setConsumer(this);
    (*m_GlobalRequestToL2Cache_ptr).setConsumer(this);
    (*m_L1RequestToL2Cache_ptr).setConsumer(this);
    (*m_responseToL2Cache_ptr).setConsumer(this);

    possibleTransition(L2Cache_State_II, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_II, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_II, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_II, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_II, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_II, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OFGX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_I, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_O, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_S, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_I, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_I, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOSD, L2Cache_Event_DmaAck);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOSXD, L2Cache_Event_DmaAck);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOD, L2Cache_Event_DmaAck);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILXD, L2Cache_Event_DmaAck);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_ILOXD, L2Cache_Event_DmaAck);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ISFGS, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_IFGS, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_IFGX, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_IFGXX, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_O, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_O, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_O, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_M, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_M, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_M, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_OLSF, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_I, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_II, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_II, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_S, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSXS, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_IFLOX, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IFLS, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IFLOSX, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_IFLOXX, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_IFLO, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IFLXO, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_I, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_I, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_S, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_Inv);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_ExtAck);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_IGMLS, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_S, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_IGMIOFS, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_OGMIOF, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_IGMIOF, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_Own_GETX);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_IGM, L2Cache_Event_ExtAck);
    possibleTransition(L2Cache_State_IGMIO, L2Cache_Event_ExtAck);
    possibleTransition(L2Cache_State_OGMIO, L2Cache_Event_ExtAck);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_ExtAck);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Data);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Data_Exclusive);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IGS, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SLSS, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_O, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OLSS, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_IGMO, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETX);
    possibleTransition(L2Cache_State_MM, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_S, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_SS, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_O, L2Cache_Event_L1_GETS);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_OO, L2Cache_Event_Exclusive_Unblock);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTO);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOSX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_SW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L1_PUTS_only);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L1_PUTS);
    possibleTransition(L2Cache_State_OLSXW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_OW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_OXW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L1_PUTX);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_WBDIRTYDATA);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_ILXW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_ILSW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_IW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_ILOW, L2Cache_Event_L1_WBDIRTYDATA);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_WBDIRTYDATA);
    possibleTransition(L2Cache_State_ILOXW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_ILOSW, L2Cache_Event_L1_WBDIRTYDATA);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_WBCLEANDATA);
    possibleTransition(L2Cache_State_ILOSXW, L2Cache_Event_L1_WBDIRTYDATA);
    possibleTransition(L2Cache_State_SLSW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_OLSW, L2Cache_Event_Unblock);
    possibleTransition(L2Cache_State_I, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_S, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILO, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_ILOS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_SLS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLS, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSX, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_O, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_IntAck);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_All_Acks);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_Fwd_GETS);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_Fwd_DMA);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_Fwd_GETX);
    possibleTransition(L2Cache_State_MI, L2Cache_Event_Writeback_Ack);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_Writeback_Ack);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_Writeback_Nack);
    possibleTransition(L2Cache_State_OI, L2Cache_Event_Writeback_Nack);
    possibleTransition(L2Cache_State_OLSI, L2Cache_Event_Writeback_Ack);
    possibleTransition(L2Cache_State_MII, L2Cache_Event_Writeback_Ack);
    possibleTransition(L2Cache_State_ILSI, L2Cache_Event_Writeback_Ack);
    AbstractController::init();
    resetStats();
}

Sequencer*
L2Cache_Controller::getCPUSequencer() const
{
    return NULL;
}

GPUCoalescer*
L2Cache_Controller::getGPUCoalescer() const
{
    return NULL;
}

void
L2Cache_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (L2Cache_Event event = L2Cache_Event_FIRST;
             event < L2Cache_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(params()->ruby_system->name() + ".L2Cache_Controller." +
                L2Cache_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (L2Cache_State state = L2Cache_State_FIRST;
             state < L2Cache_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (L2Cache_Event event = L2Cache_Event_FIRST;
                 event < L2Cache_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(params()->ruby_system->name() + ".L2Cache_Controller." +
                        L2Cache_State_to_string(state) +
                        "." + L2Cache_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
L2Cache_Controller::collateStats()
{
    for (L2Cache_Event event = L2Cache_Event_FIRST;
         event < L2Cache_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            RubySystem *rs = params()->ruby_system;
            std::map<uint32_t, AbstractController *>::iterator it =
                     rs->m_abstract_controls[MachineType_L2Cache].find(i);
            assert(it != rs->m_abstract_controls[MachineType_L2Cache].end());
            (*eventVec[event])[i] =
                ((L2Cache_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (L2Cache_State state = L2Cache_State_FIRST;
         state < L2Cache_State_NUM; ++state) {

        for (L2Cache_Event event = L2Cache_Event_FIRST;
             event < L2Cache_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                RubySystem *rs = params()->ruby_system;
                std::map<uint32_t, AbstractController *>::iterator it =
                         rs->m_abstract_controls[MachineType_L2Cache].find(i);
                assert(it != rs->m_abstract_controls[MachineType_L2Cache].end());
                (*transVec[state][event])[i] =
                    ((L2Cache_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
L2Cache_Controller::countTransition(L2Cache_State state, L2Cache_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
L2Cache_Controller::possibleTransition(L2Cache_State state,
                             L2Cache_Event event)
{
    m_possible[state][event] = true;
}

uint64_t
L2Cache_Controller::getEventCount(L2Cache_Event event)
{
    return m_event_counters[event];
}

bool
L2Cache_Controller::isPossible(L2Cache_State state, L2Cache_Event event)
{
    return m_possible[state][event];
}

uint64_t
L2Cache_Controller::getTransitionCount(L2Cache_State state,
                             L2Cache_Event event)
{
    return m_counters[state][event];
}

int
L2Cache_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
L2Cache_Controller::getMandatoryQueue() const
{
    return NULL;
}

MessageBuffer*
L2Cache_Controller::getMemoryQueue() const
{
    return NULL;
}

void
L2Cache_Controller::print(ostream& out) const
{
    out << "[L2Cache_Controller " << m_version << "]";
}

void L2Cache_Controller::resetStats()
{
    for (int state = 0; state < L2Cache_State_NUM; state++) {
        for (int event = 0; event < L2Cache_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < L2Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for cache_entry variable
void
L2Cache_Controller::set_cache_entry(L2Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry)
{
  m_cache_entry_ptr = (L2Cache_Entry*)m_new_cache_entry;
}

void
L2Cache_Controller::unset_cache_entry(L2Cache_Entry*& m_cache_entry_ptr)
{
  m_cache_entry_ptr = 0;
}

// Set and Reset for tbe variable
void
L2Cache_Controller::set_tbe(L2Cache_TBE*& m_tbe_ptr, L2Cache_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
L2Cache_Controller::unset_tbe(L2Cache_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
L2Cache_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
    m_L2cache_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief issue local request globally */
void
L2Cache_Controller::a_issueGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueGETS\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETS;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*m_GlobalRequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:a_issueGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief issue local request globally */
void
L2Cache_Controller::a_issueGETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueGETX\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETX;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*m_GlobalRequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:a_issueGETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue PUTX */
void
L2Cache_Controller::b_issuePUTX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issuePUTX\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTX;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_GlobalRequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:b_issuePUTX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue PUTO */
void
L2Cache_Controller::b_issuePUTO(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issuePUTO\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTO;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_GlobalRequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:b_issuePUTO: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue PUTO */
void
L2Cache_Controller::b_issuePUTO_ls(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issuePUTO_ls\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTO_SHARERS;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_GlobalRequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:b_issuePUTO_ls: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to L1 requestors in TBE */
void
L2Cache_Controller::c_sendDataFromTBEToL1GETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_sendDataFromTBEToL1GETS\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:788: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).addNetDest((*m_tbe_ptr).m_L1_GetS_IDs));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:801: Address: %#x, Data Block: %s\n", addr, (*m_tbe_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_sendDataFromTBEToL1GETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to L1 requestors in TBE */
void
L2Cache_Controller::c_sendDataFromTBEToL1GETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_sendDataFromTBEToL1GETX\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:806: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_L1_GetX_ID));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_Acks = (*m_tbe_ptr).m_Local_GETX_IntAcks;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:818: Address: %#x, Data Block: %s\n", addr, (*m_tbe_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_sendDataFromTBEToL1GETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to L1 requestors in TBE */
void
L2Cache_Controller::c_sendExclusiveDataFromTBEToL1GETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_sendExclusiveDataFromTBEToL1GETS\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:823: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).addNetDest((*m_tbe_ptr).m_L1_GetS_IDs));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_sendExclusiveDataFromTBEToL1GETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to external GETX */
void
L2Cache_Controller::c_sendDataFromTBEToFwdGETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_sendDataFromTBEToFwdGETX\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:837: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_Fwd_GetX_ID));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_Acks = (*m_tbe_ptr).m_Fwd_GETX_ExtAcks;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_sendDataFromTBEToFwdGETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to external GETX */
void
L2Cache_Controller::cd_sendDataFromTBEToFwdDma(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing cd_sendDataFromTBEToFwdDma\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:852: %s.\n", "assert failure");

}
#endif
;
{
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_Acks = (*m_tbe_ptr).m_Fwd_GETX_ExtAcks;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:868: Address: %#x, Data Block: %s\n", addr, (*m_tbe_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:cd_sendDataFromTBEToFwdDma: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to external GETX */
void
L2Cache_Controller::c_sendDataFromTBEToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_sendDataFromTBEToFwdGETS\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:873: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).addNetDest((*m_tbe_ptr).m_Fwd_GetS_IDs));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_Acks = (*m_tbe_ptr).m_Fwd_GETX_ExtAcks;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:887: Address: %#x, Data Block: %s\n", addr, (*m_tbe_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_sendDataFromTBEToFwdGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to external GETX */
void
L2Cache_Controller::c_sendExclusiveDataFromTBEToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_sendExclusiveDataFromTBEToFwdGETS\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:892: %s.\n", "assert failure");

}
#endif
;
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).addNetDest((*m_tbe_ptr).m_Fwd_GetS_IDs));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
    (*out_msg).m_Acks = (*m_tbe_ptr).m_Fwd_GETX_ExtAcks;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:904: Address: %#x, Data Block: %s\n", addr, (*m_tbe_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:c_sendExclusiveDataFromTBEToFwdGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data directly to L1 requestor */
void
L2Cache_Controller::d_sendDataToL1GETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d_sendDataToL1GETS\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:909: %s.\n", "assert failure");

}
#endif
;
{
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_MessageSize = MessageSizeType_ResponseL2hit_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:924: Address: %#x, Data Block: %s\n", addr, (*m_cache_entry_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:d_sendDataToL1GETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data and a token from TBE to L1 requestor */
void
L2Cache_Controller::d_sendDataToL1GETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d_sendDataToL1GETX\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:929: %s.\n", "assert failure");

}
#endif
;
{
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:932: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_ResponseL2hit_Data;
    (*out_msg).m_Acks = (*m_tbe_ptr).m_Local_GETX_IntAcks;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:944: Address: %#x, Data Block: %s\n", addr, (*m_cache_entry_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:d_sendDataToL1GETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data */
void
L2Cache_Controller::dd_sendDataToFwdGETX(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dd_sendDataToFwdGETX\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:949: %s.\n", "assert failure");

}
#endif
;
{
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:963: Address: %#x, Data Block: %s\n", addr, (*m_cache_entry_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:dd_sendDataToFwdGETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data */
void
L2Cache_Controller::dd_sendDataToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dd_sendDataToFwdGETS\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:969: %s.\n", "assert failure");

}
#endif
;
{
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:984: Address: %#x, Data Block: %s\n", addr, (*m_cache_entry_ptr).m_DataBlk);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:dd_sendDataToFwdGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief send data */
void
L2Cache_Controller::dd_sendExclusiveDataToFwdGETS(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dd_sendExclusiveDataToFwdGETS\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:989: %s.\n", "assert failure");

}
#endif
;
{
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:dd_sendExclusiveDataToFwdGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send ack with the tokens we've collected thus far. */
void
L2Cache_Controller::e_sendAck(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendAck\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1006: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_Fwd_GetX_ID));
    (*out_msg).m_Acks = ((0) - (1));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:e_sendAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send ack with the tokens we've collected thus far. */
void
L2Cache_Controller::e_sendAckToL1Requestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendAckToL1Requestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_Acks = ((0) - (1));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:e_sendAckToL1Requestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send ack with the tokens we've collected thus far. */
void
L2Cache_Controller::e_sendAckToL1RequestorFromTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendAckToL1RequestorFromTBE\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1034: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_ACK;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_L1_GetX_ID));
    (*out_msg).m_Acks = ((0) - (1));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:e_sendAckToL1RequestorFromTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send local invalidates */
void
L2Cache_Controller::ee_sendLocalInv(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_sendLocalInv\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1046: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumIntPendingAcks = (countLocalSharers(m_cache_entry_ptr, addr));
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:1048: Address: %#x, Local Sharers: %s, Pending Acks: %d\n", addr, (getLocalSharers(m_cache_entry_ptr, addr)), (*m_tbe_ptr).m_NumIntPendingAcks);
    if ((isLocalOwnerValid(m_cache_entry_ptr, addr))) {
        (*m_tbe_ptr).m_NumIntPendingAcks = ((*m_tbe_ptr).m_NumIntPendingAcks + (1));
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:1053: %s\n", (getLocalOwner(m_cache_entry_ptr, addr)));
    }
    {
        std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
        (*out_msg).m_addr = addr;
        (*out_msg).m_Type = CoherenceRequestType_INV;
        (*out_msg).m_Requestor = m_machineID;
        (*out_msg).m_RequestorMachine = MachineType_L2Cache;
        (((*out_msg).m_Destination).addNetDest((getLocalSharers(m_cache_entry_ptr, addr))));
            if ((isLocalOwnerValid(m_cache_entry_ptr, addr))) {
                (((*out_msg).m_Destination).add((getLocalOwner(m_cache_entry_ptr, addr))));
            }
            (*out_msg).m_MessageSize = MessageSizeType_Invalidate_Control;
            ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
        }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ee_sendLocalInv: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send local invalidates to sharers if they exist */
void
L2Cache_Controller::ee_sendLocalInvSharersOnly(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_sendLocalInvSharersOnly\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1073: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumIntPendingAcks = (countLocalSharers(m_cache_entry_ptr, addr));
    if (((countLocalSharers(m_cache_entry_ptr, addr)) > (0))) {
        {
            std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceRequestType_INV;
            (*out_msg).m_Requestor = m_machineID;
            (*out_msg).m_RequestorMachine = MachineType_L2Cache;
            (((*out_msg).m_Destination).addNetDest((getLocalSharers(m_cache_entry_ptr, addr))));
            (*out_msg).m_MessageSize = MessageSizeType_Invalidate_Control;
            ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
        }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ee_sendLocalInvSharersOnly: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief add a local ack to wait for */
void
L2Cache_Controller::ee_addLocalIntAck(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_addLocalIntAck\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1089: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumIntPendingAcks = ((*m_tbe_ptr).m_NumIntPendingAcks + (1));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ee_addLocalIntAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send local invalidates to sharers if they exist */
void
L2Cache_Controller::ee_issueLocalInvExceptL1Requestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_issueLocalInvExceptL1Requestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
    if (((countLocalSharers(m_cache_entry_ptr, addr)) == (0))) {
        (*m_tbe_ptr).m_NumIntPendingAcks = (0);
    } else {
            if ((isLocalSharer(m_cache_entry_ptr, addr, ((*in_msg_ptr)).m_Requestor))) {
                (*m_tbe_ptr).m_NumIntPendingAcks = ((countLocalSharers(m_cache_entry_ptr, addr)) - (1));
            } else {
                (*m_tbe_ptr).m_NumIntPendingAcks = (countLocalSharers(m_cache_entry_ptr, addr));
            }
            {
                std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
                (*out_msg).m_addr = addr;
                (*out_msg).m_Type = CoherenceRequestType_INV;
                (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
                (*out_msg).m_RequestorMachine = MachineType_L1Cache;
                (((*out_msg).m_Destination).addNetDest((getLocalSharers(m_cache_entry_ptr, addr))));
                (((*out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
                (*out_msg).m_MessageSize = MessageSizeType_Invalidate_Control;
                ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
            }
        }
        }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ee_issueLocalInvExceptL1Requestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send local invalidates to sharers if they exist */
void
L2Cache_Controller::ee_issueLocalInvExceptL1RequestorInTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_issueLocalInvExceptL1RequestorInTBE\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1123: %s.\n", "assert failure");

}
#endif
;
    if (((countLocalSharers(m_cache_entry_ptr, addr)) == (0))) {
        (*m_tbe_ptr).m_NumIntPendingAcks = (0);
    } else {
            if ((isLocalSharer(m_cache_entry_ptr, addr, (*m_tbe_ptr).m_L1_GetX_ID))) {
                (*m_tbe_ptr).m_NumIntPendingAcks = ((countLocalSharers(m_cache_entry_ptr, addr)) - (1));
            } else {
                (*m_tbe_ptr).m_NumIntPendingAcks = (countLocalSharers(m_cache_entry_ptr, addr));
            }
        }
        {
            std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceRequestType_INV;
            (*out_msg).m_Requestor = (*m_tbe_ptr).m_L1_GetX_ID;
            (*out_msg).m_RequestorMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).addNetDest((getLocalSharers(m_cache_entry_ptr, addr))));
            (((*out_msg).m_Destination).remove((*m_tbe_ptr).m_L1_GetX_ID));
            (*out_msg).m_MessageSize = MessageSizeType_Invalidate_Control;
            ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
        }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ee_issueLocalInvExceptL1RequestorInTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send unblock to global directory */
void
L2Cache_Controller::f_sendUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_sendUnblock\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_UNBLOCK;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (*out_msg).m_MessageSize = MessageSizeType_Unblock_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:f_sendUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send unblock to global directory */
void
L2Cache_Controller::f_sendExclusiveUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_sendExclusiveUnblock\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_UNBLOCK_EXCLUSIVE;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (*out_msg).m_MessageSize = MessageSizeType_Unblock_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:f_sendExclusiveUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Record new local sharer from unblock message */
void
L2Cache_Controller::g_recordLocalSharer(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing g_recordLocalSharer\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(recordLocalSharerInDir(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr, ((*in_msg_ptr)).m_Sender));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:g_recordLocalSharer: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Record new local exclusive sharer from unblock message */
void
L2Cache_Controller::g_recordLocalExclusive(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing g_recordLocalExclusive\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(recordNewLocalExclusiveInDir(m_cache_entry_ptr, addr, ((*in_msg_ptr)).m_Sender));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:g_recordLocalExclusive: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Clear local sharers */
void
L2Cache_Controller::gg_clearLocalSharers(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing gg_clearLocalSharers\n");
    try {
       (removeAllLocalSharersFromDir(m_cache_entry_ptr, addr));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:gg_clearLocalSharers: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Clear sharer from L1 response queue */
void
L2Cache_Controller::gg_clearSharerFromL1Response(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing gg_clearSharerFromL1Response\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(removeSharerFromDir(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr, ((*in_msg_ptr)).m_Sender));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:gg_clearSharerFromL1Response: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Clear sharer from L1 response queue */
void
L2Cache_Controller::gg_clearOwnerFromL1Response(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing gg_clearOwnerFromL1Response\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(removeOwnerFromDir(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr, ((*in_msg_ptr)).m_Sender));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:gg_clearOwnerFromL1Response: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief counts number of acks needed for L1 GETX */
void
L2Cache_Controller::h_countLocalSharersExceptRequestor(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_countLocalSharersExceptRequestor\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1201: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_Local_GETX_IntAcks = (countLocalSharersExceptRequestor(m_cache_entry_ptr, addr, ((*in_msg_ptr)).m_Requestor));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:h_countLocalSharersExceptRequestor: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief clear IntAcks */
void
L2Cache_Controller::h_clearIntAcks(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_clearIntAcks\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1207: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_Local_GETX_IntAcks = (0);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:h_clearIntAcks: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief counts number of acks needed for L1 GETX */
void
L2Cache_Controller::hh_countLocalSharersExceptL1GETXRequestorInTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hh_countLocalSharersExceptL1GETXRequestorInTBE\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1212: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_Local_GETX_IntAcks = (countLocalSharersExceptRequestor(m_cache_entry_ptr, addr, (*m_tbe_ptr).m_L1_GetX_ID));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:hh_countLocalSharersExceptL1GETXRequestorInTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Copy data from response queue to TBE */
void
L2Cache_Controller::i_copyDataToTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_copyDataToTBE\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1218: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
(*m_tbe_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Sender);
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:i_copyDataToTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate TBE for internal/external request(isPrefetch=0, number of invalidates=0) */
void
L2Cache_Controller::i_allocateTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateTBE\n");
    try {
       (((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
    if ((m_cache_entry_ptr != NULL)) {
        (*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
        (*m_tbe_ptr).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    }
    (*m_tbe_ptr).m_NumIntPendingAcks = (0);
    (*m_tbe_ptr).m_NumExtPendingAcks = (0);
    (((*m_tbe_ptr).m_Fwd_GetS_IDs).clear());
    (((*m_tbe_ptr).m_L1_GetS_IDs).clear());

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:i_allocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward external request to local owner */
void
L2Cache_Controller::j_forwardGlobalRequestToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing j_forwardGlobalRequestToLocalOwner\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((getLocalOwner(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr))));
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
    (*out_msg).m_Acks = ((0) - (1));
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:j_forwardGlobalRequestToLocalOwner: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward dma request to local owner */
void
L2Cache_Controller::jd_forwardDmaRequestToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing jd_forwardDmaRequestToLocalOwner\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = ((*in_msg_ptr)).m_RequestorMachine;
    (((*out_msg).m_Destination).add((getLocalOwner(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr))));
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
    (*out_msg).m_Acks = ((0) - (1));
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:jd_forwardDmaRequestToLocalOwner: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward local request to local sharer/owner */
void
L2Cache_Controller::k_forwardLocalGETSToLocalSharer(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing k_forwardLocalGETSToLocalSharer\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = CoherenceRequestType_GETS;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    L2Cache_DirEntry* dir_entry
     = (getDirEntry(((*in_msg_ptr)).m_addr));
    (((*out_msg).m_Destination).add((((*dir_entry).m_Sharers).smallestElement(MachineType_L1Cache))));
    (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:k_forwardLocalGETSToLocalSharer: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward local request to local owner */
void
L2Cache_Controller::k_forwardLocalGETXToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing k_forwardLocalGETXToLocalOwner\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1289: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETX;
    (*out_msg).m_Requestor = (*m_tbe_ptr).m_L1_GetX_ID;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    L2Cache_DirEntry* dir_entry
     = (getDirEntry(addr));
    (((*out_msg).m_Destination).add((*dir_entry).m_Owner));
    (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
    (*out_msg).m_Acks = ((1) + (*m_tbe_ptr).m_Local_GETX_IntAcks);
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:k_forwardLocalGETXToLocalOwner: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward local request to local owner */
void
L2Cache_Controller::kk_forwardLocalGETXToLocalExclusive(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kk_forwardLocalGETXToLocalExclusive\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = CoherenceRequestType_GETX;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((getLocalOwner(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr))));
    (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
    (*out_msg).m_Acks = (1);
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:kk_forwardLocalGETXToLocalExclusive: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Forward local request to local owner */
void
L2Cache_Controller::kk_forwardLocalGETSToLocalOwner(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kk_forwardLocalGETSToLocalOwner\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = CoherenceRequestType_GETS;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((getLocalOwner(m_cache_entry_ptr, ((*in_msg_ptr)).m_addr))));
    (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:kk_forwardLocalGETSToLocalOwner: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send writeback ack to L1 requesting data */
void
L2Cache_Controller::l_writebackAckNeedData(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing l_writebackAckNeedData\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK_DATA;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:l_writebackAckNeedData: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send writeback ack to L1 indicating to drop data */
void
L2Cache_Controller::l_writebackAckDropData(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing l_writebackAckDropData\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:l_writebackAckDropData: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send writeback nack to L1 */
void
L2Cache_Controller::ll_writebackNack(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ll_writebackNack\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = ((*in_msg_ptr)).m_addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_NACK;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_L1RequestFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:ll_writebackNack: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop request queue. */
void
L2Cache_Controller::m_popRequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_popRequestQueue\n");
    try {
       (((*m_GlobalRequestToL2Cache_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:m_popRequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Decrement the number of messages for which we're waiting */
void
L2Cache_Controller::m_decrementNumberOfMessagesInt(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_decrementNumberOfMessagesInt\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1377: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumIntPendingAcks = ((*m_tbe_ptr).m_NumIntPendingAcks + ((*in_msg_ptr)).m_Acks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:m_decrementNumberOfMessagesInt: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Decrement the number of messages for which we're waiting */
void
L2Cache_Controller::m_decrementNumberOfMessagesExt(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_decrementNumberOfMessagesExt\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1384: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumExtPendingAcks = ((*m_tbe_ptr).m_NumExtPendingAcks - ((*in_msg_ptr)).m_Acks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:m_decrementNumberOfMessagesExt: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Decrement the number of messages for which we're waiting */
void
L2Cache_Controller::mm_decrementNumberOfMessagesExt(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing mm_decrementNumberOfMessagesExt\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1391: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumExtPendingAcks = ((*m_tbe_ptr).m_NumExtPendingAcks - ((*in_msg_ptr)).m_Acks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:mm_decrementNumberOfMessagesExt: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop response queue */
void
L2Cache_Controller::n_popResponseQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing n_popResponseQueue\n");
    try {
       (((*m_responseToL2Cache_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:n_popResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop trigger queue. */
void
L2Cache_Controller::n_popTriggerQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing n_popTriggerQueue\n");
    try {
       (((*m_triggerQueue_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:n_popTriggerQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop L1 request queue. */
void
L2Cache_Controller::o_popL1RequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_popL1RequestQueue\n");
    try {
       (((*m_L1RequestToL2Cache_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:o_popL1RequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Check if we have received all the messages required for completion */
void
L2Cache_Controller::o_checkForIntCompletion(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_checkForIntCompletion\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1410: %s.\n", "assert failure");

}
#endif
;
    if (((*m_tbe_ptr).m_NumIntPendingAcks == (0))) {
        {
            std::shared_ptr<TriggerMsg> out_msg = std::make_shared<TriggerMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = TriggerType_ALL_ACKS;
            ((*m_triggerQueue_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(1)));
        }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:o_checkForIntCompletion: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Check if we have received all the messages required for completion */
void
L2Cache_Controller::o_checkForExtCompletion(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_checkForExtCompletion\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1420: %s.\n", "assert failure");

}
#endif
;
    if (((*m_tbe_ptr).m_NumExtPendingAcks == (0))) {
        {
            std::shared_ptr<TriggerMsg> out_msg = std::make_shared<TriggerMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = TriggerType_ALL_ACKS;
            ((*m_triggerQueue_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(1)));
        }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:o_checkForExtCompletion: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to directory */
void
L2Cache_Controller::qq_sendDataFromTBEToMemory(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qq_sendDataFromTBEToMemory\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1432: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
        if ((*m_tbe_ptr).m_Dirty) {
            (*out_msg).m_Type = CoherenceResponseType_WRITEBACK_DIRTY_DATA;
            (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
            (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
        } else {
            (*out_msg).m_Type = CoherenceResponseType_WRITEBACK_CLEAN_ACK;
            (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
            (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
        }
        ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:qq_sendDataFromTBEToMemory: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief manually set the MRU bit for cache line */
void
L2Cache_Controller::r_setMRU(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing r_setMRU\n");
    try {
           if ((m_cache_entry_ptr != NULL)) {
        (((*m_L2cache_ptr)).setMRU(addr));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:r_setMRU: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief record local GETX requestor */
void
L2Cache_Controller::s_recordGetXL1ID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_recordGetXL1ID\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1460: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_L1_GetX_ID = ((*in_msg_ptr)).m_Requestor;
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:s_recordGetXL1ID: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate external TBE */
void
L2Cache_Controller::s_deallocateTBE(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_deallocateTBE\n");
    try {
       (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:s_deallocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief record local GETS requestor */
void
L2Cache_Controller::s_recordGetSL1ID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_recordGetSL1ID\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1472: %s.\n", "assert failure");

}
#endif
;
(((*m_tbe_ptr).m_L1_GetS_IDs).add(((*in_msg_ptr)).m_Requestor));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:s_recordGetSL1ID: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief record global GETX requestor */
void
L2Cache_Controller::t_recordFwdXID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing t_recordFwdXID\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1479: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_Fwd_GetX_ID = ((*in_msg_ptr)).m_Requestor;
(*m_tbe_ptr).m_Fwd_GETX_ExtAcks = ((*in_msg_ptr)).m_Acks;
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:t_recordFwdXID: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief record global GETS requestor */
void
L2Cache_Controller::t_recordFwdSID(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing t_recordFwdSID\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1487: %s.\n", "assert failure");

}
#endif
;
(((*m_tbe_ptr).m_Fwd_GetS_IDs).clear());
(((*m_tbe_ptr).m_Fwd_GetS_IDs).add(((*in_msg_ptr)).m_Requestor));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:t_recordFwdSID: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L2Cache_Controller::u_writeDataToCache(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataToCache\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1496: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:1498: Address: %#x, Data Block: %s\n", addr, (*m_cache_entry_ptr).m_DataBlk);
    if ((((*m_cache_entry_ptr).m_Dirty == (false)) && ((*in_msg_ptr)).m_Dirty)) {
        (*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:u_writeDataToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set L2 cache tag equal to tag of block B. */
void
L2Cache_Controller::vv_allocateL2CacheBlock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing vv_allocateL2CacheBlock\n");
    try {
       set_cache_entry(m_cache_entry_ptr, (((*m_L2cache_ptr)).allocate(addr, new L2Cache_Entry)));;

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:vv_allocateL2CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate L2 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch. */
void
L2Cache_Controller::rr_deallocateL2CacheBlock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing rr_deallocateL2CacheBlock\n");
    try {
       (((*m_L2cache_ptr)).deallocate(addr));
unset_cache_entry(m_cache_entry_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:rr_deallocateL2CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Assert that the incoming data and the data in the cache match */
void
L2Cache_Controller::w_assertIncomingDataAndCacheDataMatch(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing w_assertIncomingDataAndCacheDataMatch\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1518: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!(((*m_cache_entry_ptr).m_DataBlk == ((*in_msg_ptr)).m_DataBlk))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:1519: %s.\n", "assert failure");

}
#endif
;
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:w_assertIncomingDataAndCacheDataMatch: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L2Cache_Controller::uu_profileMiss(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileMiss\n");
    try {
       (++ ((*m_L2cache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:uu_profileMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand hit */
void
L2Cache_Controller::uu_profileHit(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileHit\n");
    try {
       (++ ((*m_L2cache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:uu_profileHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Copy cache state to directory state */
void
L2Cache_Controller::y_copyCacheStateToDir(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing y_copyCacheStateToDir\n");
    try {
       (copyCacheStateToDir(m_cache_entry_ptr, addr));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:y_copyCacheStateToDir: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Copy dir state to cache and remove */
void
L2Cache_Controller::y_copyDirToCacheAndRemove(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing y_copyDirToCacheAndRemove\n");
    try {
       (copyDirToCache(m_cache_entry_ptr, addr));
(((*m_localDirectory_ptr)).deallocate(addr));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:y_copyDirToCacheAndRemove: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send the head of the mandatory queue to the back of the queue. */
void
L2Cache_Controller::zz_recycleL1RequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zz_recycleL1RequestQueue\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1RequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
}
(((*m_L1RequestToL2Cache_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:zz_recycleL1RequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send the head of the mandatory queue to the back of the queue. */
void
L2Cache_Controller::zz_recycleRequestQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zz_recycleRequestQueue\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_GlobalRequestToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
}
(((*m_GlobalRequestToL2Cache_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:zz_recycleRequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send the head of the mandatory queue to the back of the queue. */
void
L2Cache_Controller::zz_recycleResponseQueue(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zz_recycleResponseQueue\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL2Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Sender);
}
(((*m_responseToL2Cache_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:zz_recycleResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send dma ack to global directory */
void
L2Cache_Controller::da_sendDmaAckUnblock(L2Cache_TBE*& m_tbe_ptr, L2Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing da_sendDmaAckUnblock\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DMA_ACK;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L2Cache;
    (*out_msg).m_MessageSize = MessageSizeType_Unblock_Control;
    ((*m_responseFromL2Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_response_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L2Cache:da_sendDmaAckUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

L2Cache_Entry*
L2Cache_Controller::getCacheEntry(const Addr& param_address)
{
return static_cast<L2Cache_Entry *>((((*m_L2cache_ptr)).lookup(param_address)));

}
bool
L2Cache_Controller::isDirTagPresent(const Addr& param_addr)
{
return (((*m_localDirectory_ptr)).isTagPresent(param_addr));

}
L2Cache_DirEntry*
L2Cache_Controller::getDirEntry(const Addr& param_address)
{
return (((*m_localDirectory_ptr)).lookup(param_address));

}
bool
L2Cache_Controller::isOnlySharer(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_shar_id)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:252: %s.\n", "assert failure");

        }
        #endif
        ;
            if (((((*param_cache_entry).m_Sharers).count()) > (1))) {
                return (false);
            } else {
                    if (((((*param_cache_entry).m_Sharers).count()) == (1))) {
                            if ((((*param_cache_entry).m_Sharers).isElement(param_shar_id))) {
                                return (true);
                            } else {
                                return (false);
                            }
                            return (true);
                        } else {
                            return (false);
                        }
                    }
                } else {
                        if ((((*m_localDirectory_ptr)).isTagPresent(param_addr))) {
                            L2Cache_DirEntry* dir_entry
                             = (getDirEntry(param_addr));
                                if (((((*dir_entry).m_Sharers).count()) > (1))) {
                                    return (false);
                                } else {
                                        if (((((*dir_entry).m_Sharers).count()) == (1))) {
                                                if ((((*dir_entry).m_Sharers).isElement(param_shar_id))) {
                                                    return (true);
                                                } else {
                                                    return (false);
                                                }
                                            } else {
                                                return (false);
                                            }
                                        }
                                    } else {
                                        return (false);
                                    }
                                }

}
void
L2Cache_Controller::copyCacheStateToDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
#ifndef NDEBUG
if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:293: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!((param_cache_entry != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:294: %s.\n", "assert failure");

}
#endif
;
(((*m_localDirectory_ptr)).allocate(param_addr));
L2Cache_DirEntry* dir_entry
 = (getDirEntry(param_addr));
(*dir_entry).m_DirState = (*param_cache_entry).m_CacheState;
(*dir_entry).m_Sharers = (*param_cache_entry).m_Sharers;
(*dir_entry).m_Owner = (*param_cache_entry).m_Owner;
(*dir_entry).m_OwnerValid = (*param_cache_entry).m_OwnerValid;

}
void
L2Cache_Controller::copyDirToCache(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
#ifndef NDEBUG
if (!((param_cache_entry != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:305: %s.\n", "assert failure");

}
#endif
;
L2Cache_DirEntry* dir_entry
 = (getDirEntry(param_addr));
(*param_cache_entry).m_Sharers = (*dir_entry).m_Sharers;
(*param_cache_entry).m_Owner = (*dir_entry).m_Owner;
(*param_cache_entry).m_OwnerValid = (*dir_entry).m_OwnerValid;

}
void
L2Cache_Controller::recordLocalSharerInDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_shar_id)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:315: %s.\n", "assert failure");

        }
        #endif
        ;
        (((*param_cache_entry).m_Sharers).add(param_shar_id));
    } else {
            if (((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false))) {
                (((*m_localDirectory_ptr)).allocate(param_addr));
                L2Cache_DirEntry* dir_entry
                 = (getDirEntry(param_addr));
                (((*dir_entry).m_Sharers).clear());
                (*dir_entry).m_OwnerValid = (false);
            }
            L2Cache_DirEntry* dir_entry
             = (getDirEntry(param_addr));
            (((*dir_entry).m_Sharers).add(param_shar_id));
        }

}
void
L2Cache_Controller::recordNewLocalExclusiveInDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_exc_id)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:333: %s.\n", "assert failure");

        }
        #endif
        ;
        (((*param_cache_entry).m_Sharers).clear());
        (*param_cache_entry).m_OwnerValid = (true);
        (*param_cache_entry).m_Owner = param_exc_id;
    } else {
            if (((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false))) {
                (((*m_localDirectory_ptr)).allocate(param_addr));
            }
            L2Cache_DirEntry* dir_entry
             = (getDirEntry(param_addr));
            (((*dir_entry).m_Sharers).clear());
            (*dir_entry).m_OwnerValid = (true);
            (*dir_entry).m_Owner = param_exc_id;
        }

}
void
L2Cache_Controller::removeAllLocalSharersFromDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:351: %s.\n", "assert failure");

        }
        #endif
        ;
        (((*param_cache_entry).m_Sharers).clear());
        (*param_cache_entry).m_OwnerValid = (false);
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        (((*dir_entry).m_Sharers).clear());
        (*dir_entry).m_OwnerValid = (false);
    }

}
void
L2Cache_Controller::removeSharerFromDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_sender)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:364: %s.\n", "assert failure");

        }
        #endif
        ;
        (((*param_cache_entry).m_Sharers).remove(param_sender));
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        (((*dir_entry).m_Sharers).remove(param_sender));
    }

}
void
L2Cache_Controller::removeOwnerFromDir(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_sender)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:375: %s.\n", "assert failure");

        }
        #endif
        ;
        (*param_cache_entry).m_OwnerValid = (false);
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        (*dir_entry).m_OwnerValid = (false);
    }

}
bool
L2Cache_Controller::isLocalSharer(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_shar_id)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:386: %s.\n", "assert failure");

        }
        #endif
        ;
        return (((*param_cache_entry).m_Sharers).isElement(param_shar_id));
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        return (((*dir_entry).m_Sharers).isElement(param_shar_id));
    }

}
NetDest
L2Cache_Controller::getLocalSharers(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:397: %s.\n", "assert failure");

        }
        #endif
        ;
        return (*param_cache_entry).m_Sharers;
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        return (*dir_entry).m_Sharers;
    }

}
MachineID
L2Cache_Controller::getLocalOwner(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:408: %s.\n", "assert failure");

        }
        #endif
        ;
        return (*param_cache_entry).m_Owner;
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        return (*dir_entry).m_Owner;
    }

}
int
L2Cache_Controller::countLocalSharers(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:419: %s.\n", "assert failure");

        }
        #endif
        ;
        return (((*param_cache_entry).m_Sharers).count());
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        return (((*dir_entry).m_Sharers).count());
    }

}
bool
L2Cache_Controller::isLocalOwnerValid(L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:430: %s.\n", "assert failure");

        }
        #endif
        ;
        return (*param_cache_entry).m_OwnerValid;
    } else {
        L2Cache_DirEntry* dir_entry
         = (getDirEntry(param_addr));
        return (*dir_entry).m_OwnerValid;
    }

}
int
L2Cache_Controller::countLocalSharersExceptRequestor(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const MachineID& param_requestor)
{
    if ((param_cache_entry != NULL)) {
        #ifndef NDEBUG
        if (!(((((*m_localDirectory_ptr)).isTagPresent(param_addr)) == (false)))) {
            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:441: %s.\n", "assert failure");

        }
        #endif
        ;
            if ((((*param_cache_entry).m_Sharers).isElement(param_requestor))) {
                return ((((*param_cache_entry).m_Sharers).count()) - (1));
            } else {
                return (((*param_cache_entry).m_Sharers).count());
            }
        } else {
            L2Cache_DirEntry* dir_entry
             = (getDirEntry(param_addr));
                if ((((*dir_entry).m_Sharers).isElement(param_requestor))) {
                    return ((((*dir_entry).m_Sharers).count()) - (1));
                } else {
                    return (((*dir_entry).m_Sharers).count());
                }
            }

}
L2Cache_State
L2Cache_Controller::getState(L2Cache_TBE* param_tbe, L2Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            } else {
                    if ((isDirTagPresent(param_addr))) {
                        L2Cache_DirEntry* dir_entry
                         = (getDirEntry(param_addr));
                        return (*dir_entry).m_DirState;
                    } else {
                        return L2Cache_State_NP;
                    }
                }
            }

}
std::string
L2Cache_Controller::getCoherenceRequestTypeStr(const CoherenceRequestType& param_type)
{
return (CoherenceRequestType_to_string(param_type));

}
void
L2Cache_Controller::setState(L2Cache_TBE* param_tbe, L2Cache_Entry* param_cache_entry, const Addr& param_addr, const L2Cache_State& param_state)
{
#ifndef NDEBUG
if (!((((((*m_localDirectory_ptr)).isTagPresent(param_addr)) && (((*m_L2cache_ptr)).isTagPresent(param_addr))) == (false)))) {
    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:479: %s.\n", "assert failure");

}
#endif
;
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((((((((param_state == L2Cache_State_M) || (param_state == L2Cache_State_O)) || (param_state == L2Cache_State_S)) || (param_state == L2Cache_State_OLS)) || (param_state == L2Cache_State_SLS)) || (param_state == L2Cache_State_OLSX)) || (param_state == L2Cache_State_SLS))) {
            #ifndef NDEBUG
            if (!((param_cache_entry != NULL))) {
                panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:494: %s.\n", "assert failure");

            }
            #endif
            ;
        } else {
                if (((((((param_state == L2Cache_State_ILS) || (param_state == L2Cache_State_ILX)) || (param_state == L2Cache_State_ILO)) || (param_state == L2Cache_State_ILOX)) || (param_state == L2Cache_State_ILOS)) || (param_state == L2Cache_State_ILOSX))) {
                }
            }
                if ((param_cache_entry != NULL)) {
                        if ((((((*param_cache_entry).m_CacheState != L2Cache_State_M) && (param_state == L2Cache_State_M)) || (((*param_cache_entry).m_CacheState != L2Cache_State_S) && (param_state == L2Cache_State_S))) || (((*param_cache_entry).m_CacheState != L2Cache_State_O) && (param_state == L2Cache_State_O)))) {
                            (*param_cache_entry).m_CacheState = param_state;
                        } else {
                            (*param_cache_entry).m_CacheState = param_state;
                        }
                    } else {
                            if ((((*m_localDirectory_ptr)).isTagPresent(param_addr))) {
                                L2Cache_DirEntry* dir_entry
                                 = (getDirEntry(param_addr));
                                (*dir_entry).m_DirState = param_state;
                            }
                        }

}
AccessPermission
L2Cache_Controller::getAccessPermission(const Addr& param_addr)
{
L2Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:528: %s\n", (L2Cache_State_to_permission((*tbe).m_TBEState)));
        return (L2Cache_State_to_permission((*tbe).m_TBEState));
    }
    L2Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:534: %s\n", (L2Cache_State_to_permission((*cache_entry).m_CacheState)));
            return (L2Cache_State_to_permission((*cache_entry).m_CacheState));
        }
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L2cache.sm:538: AccessPermission_NotPresent\n");
        return AccessPermission_NotPresent;

}
void
L2Cache_Controller::setAccessPermission(L2Cache_Entry* param_cache_entry, const Addr& param_addr, const L2Cache_State& param_state)
{
    if ((param_cache_entry != NULL)) {
        ((*(param_cache_entry)).changePermission((L2Cache_State_to_permission(param_state))));
    }

}
void
L2Cache_Controller::functionalRead(const Addr& param_addr, Packet* param_pkt)
{
L2Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (testAndRead(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt));
    }

}
int
L2Cache_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L2Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
int
L2Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_L1RequestFromL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_GlobalRequestFromL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_L1RequestToL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_GlobalRequestToL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToL2Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_triggerQueue_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
