/** \file L1Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:465
 * Created by slicc definition of Module "Directory protocol"
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
#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/L1Cache_Event.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/network/Network.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/protocol/TBETable.hh"
#include "mem/protocol/TimerTable.hh"
L1Cache_Controller *
L1Cache_ControllerParams::create()
{
    return new L1Cache_Controller(this);
}

int L1Cache_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  L1Cache_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  L1Cache_Controller::transVec;

// for adding information to the protocol debug trace
stringstream L1Cache_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (L1Cache_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
L1Cache_Controller::L1Cache_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_L1Cache;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 5;
    m_sequencer_ptr = p->sequencer;
    if (m_sequencer_ptr != NULL) {
        m_sequencer_ptr->setController(this);
    }
    m_L1Icache_ptr = p->L1Icache;
    m_L1Dcache_ptr = p->L1Dcache;
    m_l2_select_num_bits = p->l2_select_num_bits;
    m_request_latency = p->request_latency;
    m_use_timeout_latency = p->use_timeout_latency;
    m_send_evictions = p->send_evictions;
    m_requestFromL1Cache_ptr = p->requestFromL1Cache;
    m_responseFromL1Cache_ptr = p->responseFromL1Cache;
    m_requestToL1Cache_ptr = p->requestToL1Cache;
    m_responseToL1Cache_ptr = p->responseToL1Cache;
    m_triggerQueue_ptr = p->triggerQueue;
    m_mandatoryQueue_ptr = p->mandatoryQueue;

    for (int state = 0; state < L1Cache_State_NUM; state++) {
        for (int event = 0; event < L1Cache_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < L1Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
L1Cache_Controller::initNetQueues()
{
    MachineType machine_type = string_to_MachineType("L1Cache");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    assert(m_requestFromL1Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_requestFromL1Cache_ptr->getOrdered(), 0,
                                     "request", m_requestFromL1Cache_ptr);
    assert(m_responseFromL1Cache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_responseFromL1Cache_ptr->getOrdered(), 2,
                                     "response", m_responseFromL1Cache_ptr);
    assert(m_requestToL1Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_requestToL1Cache_ptr->getOrdered(), 0,
                                     "request", m_requestToL1Cache_ptr);
    assert(m_responseToL1Cache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_responseToL1Cache_ptr->getOrdered(), 2,
                                     "response", m_responseToL1Cache_ptr);
}

void
L1Cache_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<L1Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);
    m_useTimerTable_ptr  = new TimerTable();
    assert(m_useTimerTable_ptr != NULL);
    m_l2_select_low_bit_ptr = new int;
    (*m_l2_select_low_bit_ptr) = RubySystem::getBlockSizeBits();


    (*m_useTimerTable_ptr).setConsumer(this);
    (*m_triggerQueue_ptr).setConsumer(this);
    (*m_requestToL1Cache_ptr).setConsumer(this);
    (*m_responseToL1Cache_ptr).setConsumer(this);
    (*m_mandatoryQueue_ptr).setConsumer(this);

    possibleTransition(L1Cache_State_IM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_II, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Own_GETX);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Own_GETX);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_I, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_O, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_O, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_S, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_S, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_O, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_O, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_O, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_O, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_O, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_MM, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_M, L1Cache_Event_L1_Replacement);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Ack);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Exclusive_Data);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Ack);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Exclusive_Data);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_SM, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Own_GETX);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_Ack);
    possibleTransition(L1Cache_State_OM, L1Cache_Event_All_acks);
    possibleTransition(L1Cache_State_MM_W, L1Cache_Event_Use_Timeout);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Exclusive_Data);
    possibleTransition(L1Cache_State_M_W, L1Cache_Event_Use_Timeout);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Fwd_GETS);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Fwd_DMA);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Writeback_Ack_Data);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Writeback_Ack_Data);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Ack_Data);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Writeback_Ack);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Writeback_Ack);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Ack);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Nack);
    possibleTransition(L1Cache_State_OI, L1Cache_Event_Writeback_Nack);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Writeback_Ack);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Writeback_Ack_Data);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Writeback_Nack);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Writeback_Nack);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_SI, L1Cache_Event_Inv);
    AbstractController::init();
    resetStats();
}
Sequencer*
L1Cache_Controller::getCPUSequencer() const
{
    if (NULL != m_sequencer_ptr && m_sequencer_ptr->isCPUSequencer()) {
        return m_sequencer_ptr;
    } else {
        return NULL;
    }
}

GPUCoalescer*
L1Cache_Controller::getGPUCoalescer() const
{
    return NULL;
}

void
L1Cache_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(params()->ruby_system->name() + ".L1Cache_Controller." +
                L1Cache_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (L1Cache_State state = L1Cache_State_FIRST;
             state < L1Cache_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (L1Cache_Event event = L1Cache_Event_FIRST;
                 event < L1Cache_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(params()->ruby_system->name() + ".L1Cache_Controller." +
                        L1Cache_State_to_string(state) +
                        "." + L1Cache_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
L1Cache_Controller::collateStats()
{
    for (L1Cache_Event event = L1Cache_Event_FIRST;
         event < L1Cache_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            RubySystem *rs = params()->ruby_system;
            std::map<uint32_t, AbstractController *>::iterator it =
                     rs->m_abstract_controls[MachineType_L1Cache].find(i);
            assert(it != rs->m_abstract_controls[MachineType_L1Cache].end());
            (*eventVec[event])[i] =
                ((L1Cache_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (L1Cache_State state = L1Cache_State_FIRST;
         state < L1Cache_State_NUM; ++state) {

        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                RubySystem *rs = params()->ruby_system;
                std::map<uint32_t, AbstractController *>::iterator it =
                         rs->m_abstract_controls[MachineType_L1Cache].find(i);
                assert(it != rs->m_abstract_controls[MachineType_L1Cache].end());
                (*transVec[state][event])[i] =
                    ((L1Cache_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
L1Cache_Controller::countTransition(L1Cache_State state, L1Cache_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
L1Cache_Controller::possibleTransition(L1Cache_State state,
                             L1Cache_Event event)
{
    m_possible[state][event] = true;
}

uint64_t
L1Cache_Controller::getEventCount(L1Cache_Event event)
{
    return m_event_counters[event];
}

bool
L1Cache_Controller::isPossible(L1Cache_State state, L1Cache_Event event)
{
    return m_possible[state][event];
}

uint64_t
L1Cache_Controller::getTransitionCount(L1Cache_State state,
                             L1Cache_Event event)
{
    return m_counters[state][event];
}

int
L1Cache_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
L1Cache_Controller::getMandatoryQueue() const
{
    return m_mandatoryQueue_ptr;
}

MessageBuffer*
L1Cache_Controller::getMemoryQueue() const
{
    return NULL;
}

void
L1Cache_Controller::print(ostream& out) const
{
    out << "[L1Cache_Controller " << m_version << "]";
}

void L1Cache_Controller::resetStats()
{
    for (int state = 0; state < L1Cache_State_NUM; state++) {
        for (int event = 0; event < L1Cache_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < L1Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for cache_entry variable
void
L1Cache_Controller::set_cache_entry(L1Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry)
{
  m_cache_entry_ptr = (L1Cache_Entry*)m_new_cache_entry;
}

void
L1Cache_Controller::unset_cache_entry(L1Cache_Entry*& m_cache_entry_ptr)
{
  m_cache_entry_ptr = 0;
}

// Set and Reset for tbe variable
void
L1Cache_Controller::set_tbe(L1Cache_TBE*& m_tbe_ptr, L1Cache_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
L1Cache_Controller::unset_tbe(L1Cache_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
L1Cache_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
    m_L1Icache_ptr->recordCacheContents(cntrl, tr);
    m_L1Dcache_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief Issue GETS */
void
L1Cache_Controller::a_issueGETS(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueGETS\n");
    try {
       {
    // Declare message
    const RubyRequest* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RubyRequest *>(((*m_mandatoryQueue_ptr)).peek());
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
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    (*out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
    ((*m_requestFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:a_issueGETS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue GETX */
void
L1Cache_Controller::b_issueGETX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issueGETX\n");
    try {
       {
    // Declare message
    const RubyRequest* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RubyRequest *>(((*m_mandatoryQueue_ptr)).peek());
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
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
    (*out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
    (*out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
    ((*m_requestFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:b_issueGETX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue PUTX */
void
L1Cache_Controller::d_issuePUTX(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d_issuePUTX\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTX;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_requestFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:d_issuePUTX: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue PUTO */
void
L1Cache_Controller::dd_issuePUTO(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dd_issuePUTO\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTO;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_requestFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:dd_issuePUTO: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue PUTS */
void
L1Cache_Controller::dd_issuePUTS(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing dd_issuePUTS\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTS;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_requestFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:dd_issuePUTS: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to requestor */
void
L1Cache_Controller::e_sendData(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendData\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:502: %s.\n", "assert failure");

}
#endif
;
    if ((((*in_msg_ptr)).m_RequestorMachine == MachineType_L2Cache)) {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
            (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (false);
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:517: Sending data to L2: %#x\n", ((*in_msg_ptr)).m_addr);
    } else {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
            (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (false);
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_ResponseLocal_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:532: Sending data to L1\n");
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:e_sendData: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to requestor */
void
L1Cache_Controller::e_sendDataToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_sendDataToL2\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:539: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
    (*out_msg).m_Acks = (0);
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:e_sendDataToL2: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from cache to requestor, don't keep a shared copy */
void
L1Cache_Controller::ee_sendDataExclusive(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_sendDataExclusive\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:555: %s.\n", "assert failure");

}
#endif
;
    if ((((*in_msg_ptr)).m_RequestorMachine == MachineType_L2Cache)) {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
            (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:569: Sending exclusive data to L2\n");
    } else {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
            (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (*m_cache_entry_ptr).m_Dirty;
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_ResponseLocal_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:583: Sending exclusive data to L1\n");
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:ee_sendDataExclusive: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send ack from cache to requestor */
void
L1Cache_Controller::f_sendAck(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_sendAck\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
    if ((((*in_msg_ptr)).m_RequestorMachine == MachineType_L1Cache)) {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_ACK;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
            (*out_msg).m_Acks = ((0) - (1));
            (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
    } else {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_ACK;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
            (*out_msg).m_Acks = ((0) - (1));
            (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:f_sendAck: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send unblock to memory */
void
L1Cache_Controller::g_sendUnblock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing g_sendUnblock\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_UNBLOCK;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Unblock_Control;
    ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:g_sendUnblock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send unblock exclusive to memory */
void
L1Cache_Controller::gg_sendUnblockExclusive(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing gg_sendUnblockExclusive\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_UNBLOCK_EXCLUSIVE;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_MessageSize = MessageSizeType_Unblock_Control;
    ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:gg_sendUnblockExclusive: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify sequencer the load completed. */
void
L1Cache_Controller::h_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_load_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:641: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:642: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_L1Dcache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:h_load_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify the sequencer about ifetch completion. */
void
L1Cache_Controller::h_ifetch_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_ifetch_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:648: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:649: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_L1Icache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:h_ifetch_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify sequencer the load completed. */
void
L1Cache_Controller::hx_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hx_load_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:655: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:656: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_L1Icache_ptr)).setMRU(addr));
(((*m_L1Dcache_ptr)).setMRU(addr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true)));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:hx_load_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify sequencer that store completed. */
void
L1Cache_Controller::hh_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing hh_store_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:663: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:664: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_L1Dcache_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk));
(*m_cache_entry_ptr).m_Dirty = (true);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:hh_store_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify sequencer that store completed. */
void
L1Cache_Controller::xx_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing xx_store_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:671: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:672: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_L1Icache_ptr)).setMRU(addr));
(((*m_L1Dcache_ptr)).setMRU(addr));
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true)));
(*m_cache_entry_ptr).m_Dirty = (true);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:xx_store_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate TBE */
void
L1Cache_Controller::i_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateTBE\n");
    try {
       (((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:683: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
(*m_tbe_ptr).m_Dirty = (*m_cache_entry_ptr).m_Dirty;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:i_allocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop trigger queue. */
void
L1Cache_Controller::j_popTriggerQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing j_popTriggerQueue\n");
    try {
       (((*m_triggerQueue_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:j_popTriggerQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Unset use timer. */
void
L1Cache_Controller::jj_unsetUseTimer(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing jj_unsetUseTimer\n");
    try {
       (((*m_useTimerTable_ptr)).unset(addr));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:jj_unsetUseTimer: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop mandatory queue. */
void
L1Cache_Controller::k_popMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing k_popMandatoryQueue\n");
    try {
       (((*m_mandatoryQueue_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:k_popMandatoryQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop forwareded request queue. */
void
L1Cache_Controller::l_popForwardQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing l_popForwardQueue\n");
    try {
       (((*m_requestToL1Cache_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:l_popForwardQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Decrement the number of messages for which we're waiting */
void
L1Cache_Controller::m_decrementNumberOfMessages(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_decrementNumberOfMessages\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:706: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:707: L1 decrementNumberOfMessages: %d\n", ((*in_msg_ptr)).m_Acks);
(*m_tbe_ptr).m_NumPendingMsgs = ((*m_tbe_ptr).m_NumPendingMsgs - ((*in_msg_ptr)).m_Acks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:m_decrementNumberOfMessages: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Decrement the number of messages for which we're waiting */
void
L1Cache_Controller::mm_decrementNumberOfMessages(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing mm_decrementNumberOfMessages\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:714: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_NumPendingMsgs = ((*m_tbe_ptr).m_NumPendingMsgs - ((*in_msg_ptr)).m_Acks);
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:mm_decrementNumberOfMessages: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop response queue */
void
L1Cache_Controller::n_popResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing n_popResponseQueue\n");
    try {
       (((*m_responseToL1Cache_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:n_popResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Check if we have received all the messages required for completion */
void
L1Cache_Controller::o_checkForCompletion(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_checkForCompletion\n");
    try {
       #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:724: %s.\n", "assert failure");

}
#endif
;
    if (((*m_tbe_ptr).m_NumPendingMsgs == (0))) {
        {
            std::shared_ptr<TriggerMsg> out_msg = std::make_shared<TriggerMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = TriggerType_ALL_ACKS;
            ((*m_triggerQueue_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(1)));
        }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:o_checkForCompletion: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Schedule a use timeout. */
void
L1Cache_Controller::o_scheduleUseTimeout(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_scheduleUseTimeout\n");
    try {
       (((*m_useTimerTable_ptr)).set(addr, ((clockEdge()) + (cyclesToTicks(m_use_timeout_latency)))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:o_scheduleUseTimeout: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send dma ack to l2 cache */
void
L1Cache_Controller::ub_dmaUnblockL2Cache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ub_dmaUnblockL2Cache\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DMA_ACK;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_Acks = (1);
    (*out_msg).m_MessageSize = MessageSizeType_Response_Control;
    ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:ub_dmaUnblockL2Cache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to cache */
void
L1Cache_Controller::q_sendDataFromTBEToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing q_sendDataFromTBEToCache\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:756: %s.\n", "assert failure");

}
#endif
;
    if (((((*in_msg_ptr)).m_RequestorMachine == MachineType_L1Cache) || (((*in_msg_ptr)).m_RequestorMachine == MachineType_DMA))) {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
            (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (false);
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_ResponseLocal_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
    } else {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
            (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (false);
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:q_sendDataFromTBEToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to cache */
void
L1Cache_Controller::q_sendExclusiveDataFromTBEToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing q_sendExclusiveDataFromTBEToCache\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:792: %s.\n", "assert failure");

}
#endif
;
    if ((((*in_msg_ptr)).m_RequestorMachine == MachineType_L1Cache)) {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
            (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_ResponseLocal_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
    } else {
        {
            std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
            (*out_msg).m_Sender = m_machineID;
            (*out_msg).m_SenderMachine = MachineType_L1Cache;
            (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
            (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
            (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
            (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
            (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
            ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
        }
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:q_sendExclusiveDataFromTBEToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to L2 */
void
L1Cache_Controller::qq_sendWBDataFromTBEToL2(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qq_sendWBDataFromTBEToL2\n");
    try {
       {
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:826: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_L1Cache;
    (((*out_msg).m_Destination).add((mapAddressToRange(addr, MachineType_L2Cache, (*m_l2_select_low_bit_ptr), m_l2_select_num_bits, (intToID((0)))))));
    (*out_msg).m_Dirty = (*m_tbe_ptr).m_Dirty;
        if ((*m_tbe_ptr).m_Dirty) {
            (*out_msg).m_Type = CoherenceResponseType_WRITEBACK_DIRTY_DATA;
        } else {
            (*out_msg).m_Type = CoherenceResponseType_WRITEBACK_CLEAN_DATA;
        }
        (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
        (*out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
        ((*m_responseFromL1Cache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_request_latency)));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:qq_sendWBDataFromTBEToL2: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate TBE */
void
L1Cache_Controller::s_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_deallocateTBE\n");
    try {
       (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:s_deallocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache */
void
L1Cache_Controller::u_writeDataToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataToCache\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:850: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
(*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
    }
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:u_writeDataToCache: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to cache, assert it was same as before */
void
L1Cache_Controller::v_writeDataToCacheVerify(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing v_writeDataToCacheVerify\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToL1Cache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:862: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!(((*m_cache_entry_ptr).m_DataBlk == ((*in_msg_ptr)).m_DataBlk))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:863: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
(*m_cache_entry_ptr).m_Dirty = ((*in_msg_ptr)).m_Dirty;
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:v_writeDataToCacheVerify: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate cache block.  Sets the cache to invalid, allowing a replacement in parallel with a fetch. */
void
L1Cache_Controller::kk_deallocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing kk_deallocateL1CacheBlock\n");
    try {
           if ((((*m_L1Dcache_ptr)).isTagPresent(addr))) {
        (((*m_L1Dcache_ptr)).deallocate(addr));
    } else {
        (((*m_L1Icache_ptr)).deallocate(addr));
    }
    unset_cache_entry(m_cache_entry_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:kk_deallocateL1CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set L1 D-cache tag equal to tag of block B. */
void
L1Cache_Controller::ii_allocateL1DCacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ii_allocateL1DCacheBlock\n");
    try {
           if ((m_cache_entry_ptr == NULL)) {
        set_cache_entry(m_cache_entry_ptr, (((*m_L1Dcache_ptr)).allocate(addr, new L1Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:ii_allocateL1DCacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Set L1 I-cache tag equal to tag of block B. */
void
L1Cache_Controller::jj_allocateL1ICacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing jj_allocateL1ICacheBlock\n");
    try {
           if ((m_cache_entry_ptr == NULL)) {
        set_cache_entry(m_cache_entry_ptr, (((*m_L1Icache_ptr)).allocate(addr, new L1Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:jj_allocateL1ICacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief sends eviction information to the processor */
void
L1Cache_Controller::forward_eviction_to_cpu(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing forward_eviction_to_cpu\n");
    try {
           if (m_send_evictions) {
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:892: Sending invalidation for %#x to the CPU\n", addr);
        (((*m_sequencer_ptr)).evictionCallback(addr));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:forward_eviction_to_cpu: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L1Cache_Controller::uu_profileInstMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileInstMiss\n");
    try {
       (++ ((*m_L1Icache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:uu_profileInstMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand hit */
void
L1Cache_Controller::uu_profileInstHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileInstHit\n");
    try {
       (++ ((*m_L1Icache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:uu_profileInstHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand miss */
void
L1Cache_Controller::uu_profileDataMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileDataMiss\n");
    try {
       (++ ((*m_L1Dcache_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:uu_profileDataMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile the demand hit */
void
L1Cache_Controller::uu_profileDataHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing uu_profileDataHit\n");
    try {
       (++ ((*m_L1Dcache_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:uu_profileDataHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send the head of the mandatory queue to the back of the queue. */
void
L1Cache_Controller::z_recycleRequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing z_recycleRequestQueue\n");
    try {
       (((*m_requestToL1Cache_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:z_recycleRequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send the head of the mandatory queue to the back of the queue. */
void
L1Cache_Controller::zz_recycleMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zz_recycleMandatoryQueue\n");
    try {
       (((*m_mandatoryQueue_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:zz_recycleMandatoryQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

L1Cache_Entry*
L1Cache_Controller::getCacheEntry(const Addr& param_addr)
{
L1Cache_Entry* L1Dcache_entry
 = static_cast<L1Cache_Entry *>((((*m_L1Dcache_ptr)).lookup(param_addr)))
;
    if ((L1Dcache_entry != NULL)) {
        return L1Dcache_entry;
    }
    L1Cache_Entry* L1Icache_entry
     = static_cast<L1Cache_Entry *>((((*m_L1Icache_ptr)).lookup(param_addr)))
    ;
    return L1Icache_entry;

}
L1Cache_Entry*
L1Cache_Controller::getL1DCacheEntry(const Addr& param_addr)
{
return static_cast<L1Cache_Entry *>((((*m_L1Dcache_ptr)).lookup(param_addr)));

}
L1Cache_Entry*
L1Cache_Controller::getL1ICacheEntry(const Addr& param_addr)
{
return static_cast<L1Cache_Entry *>((((*m_L1Icache_ptr)).lookup(param_addr)));

}
L1Cache_State
L1Cache_Controller::getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            }
        }
        return L1Cache_State_I;

}
void
L1Cache_Controller::setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state)
{
#ifndef NDEBUG
if (!((((((*m_L1Dcache_ptr)).isTagPresent(param_addr)) && (((*m_L1Icache_ptr)).isTagPresent(param_addr))) == (false)))) {
    panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:175: %s.\n", "assert failure");

}
#endif
;
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((param_cache_entry != NULL)) {
                if (((((((*param_cache_entry).m_CacheState != L1Cache_State_M) && (param_state == L1Cache_State_M)) || (((*param_cache_entry).m_CacheState != L1Cache_State_MM) && (param_state == L1Cache_State_MM))) || (((*param_cache_entry).m_CacheState != L1Cache_State_S) && (param_state == L1Cache_State_S))) || (((*param_cache_entry).m_CacheState != L1Cache_State_O) && (param_state == L1Cache_State_O)))) {
                    (*param_cache_entry).m_CacheState = param_state;
                    (((*m_sequencer_ptr)).checkCoherence(param_addr));
                } else {
                    (*param_cache_entry).m_CacheState = param_state;
                }
            }

}
AccessPermission
L1Cache_Controller::getAccessPermission(const Addr& param_addr)
{
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:199: %s\n", (L1Cache_State_to_permission((*tbe).m_TBEState)));
        return (L1Cache_State_to_permission((*tbe).m_TBEState));
    }
    L1Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:205: %s\n", (L1Cache_State_to_permission((*cache_entry).m_CacheState)));
            return (L1Cache_State_to_permission((*cache_entry).m_CacheState));
        }
        DPRINTF(RubySlicc, "MOESI_CMP_directory-L1cache.sm:209: AccessPermission_NotPresent\n");
        return AccessPermission_NotPresent;

}
void
L1Cache_Controller::setAccessPermission(L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state)
{
    if ((param_cache_entry != NULL)) {
        ((*(param_cache_entry)).changePermission((L1Cache_State_to_permission(param_state))));
    }

}
void
L1Cache_Controller::functionalRead(const Addr& param_addr, Packet* param_pkt)
{
L1Cache_Entry* cache_entry
 = (getCacheEntry(param_addr));
    if ((cache_entry != NULL)) {
        (testAndRead(param_addr, (*cache_entry).m_DataBlk, param_pkt));
    } else {
        L1Cache_TBE* tbe
         = (((*m_TBEs_ptr)).lookup(param_addr));
            if ((tbe != NULL)) {
                (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
            } else {
                panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:228: %s.\n", ("Data block missing!"));
                ;
            }
        }

}
int
L1Cache_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L1Cache_Entry* cache_entry
 = (getCacheEntry(param_addr));
    if ((cache_entry != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*cache_entry).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    L1Cache_TBE* tbe
     = (((*m_TBEs_ptr)).lookup(param_addr));
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
L1Cache_Event
L1Cache_Controller::mandatory_request_type_to_event(const RubyRequestType& param_type)
{
    if ((param_type == RubyRequestType_LD)) {
        return L1Cache_Event_Load;
    } else {
            if ((param_type == RubyRequestType_IFETCH)) {
                return L1Cache_Event_Ifetch;
            } else {
                    if (((param_type == RubyRequestType_ST) || (param_type == RubyRequestType_ATOMIC))) {
                        return L1Cache_Event_Store;
                    } else {
                        panic("Runtime Error at MOESI_CMP_directory-L1cache.sm:257: %s.\n", ("Invalid RubyRequestType"));
                        ;
                    }
                }
            }

}
int
L1Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_requestFromL1Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromL1Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_requestToL1Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToL1Cache_ptr->functionalWrite(pkt);
num_functional_writes += m_triggerQueue_ptr->functionalWrite(pkt);
num_functional_writes += m_mandatoryQueue_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
