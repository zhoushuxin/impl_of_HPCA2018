/** \file L1Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:465
 * Created by slicc definition of Module "MI Example L1 Cache"
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

    m_in_ports = 3;
    m_sequencer_ptr = p->sequencer;
    if (m_sequencer_ptr != NULL) {
        m_sequencer_ptr->setController(this);
    }
    m_cacheMemory_ptr = p->cacheMemory;
    m_cache_response_latency = p->cache_response_latency;
    m_issue_latency = p->issue_latency;
    m_send_evictions = p->send_evictions;
    m_requestFromCache_ptr = p->requestFromCache;
    m_responseFromCache_ptr = p->responseFromCache;
    m_forwardToCache_ptr = p->forwardToCache;
    m_responseToCache_ptr = p->responseToCache;
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

    assert(m_requestFromCache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_requestFromCache_ptr->getOrdered(), 2,
                                     "request", m_requestFromCache_ptr);
    assert(m_responseFromCache_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_responseFromCache_ptr->getOrdered(), 4,
                                     "response", m_responseFromCache_ptr);
    assert(m_forwardToCache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_forwardToCache_ptr->getOrdered(), 3,
                                     "forward", m_forwardToCache_ptr);
    assert(m_responseToCache_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_responseToCache_ptr->getOrdered(), 4,
                                     "response", m_responseToCache_ptr);
}

void
L1Cache_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<L1Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);


    (*m_forwardToCache_ptr).setConsumer(this);
    (*m_responseToCache_ptr).setConsumer(this);
    (*m_mandatoryQueue_ptr).setConsumer(this);

    possibleTransition(L1Cache_State_MI, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Replacement);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Replacement);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Ack);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Nack);
    possibleTransition(L1Cache_State_MII, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Writeback_Nack);
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
    m_cacheMemory_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief Issue a request */
void
L1Cache_Controller::a_issueRequest(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_issueRequest\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETX;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    ((*m_requestFromCache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_issue_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:a_issueRequest: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Issue a PUT request */
void
L1Cache_Controller::b_issuePUT(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_issuePUT\n");
    try {
       {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MI_example-cache.sm:283: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTX;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((mapAddressToMachine(addr, MachineType_Directory))));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Data;
    ((*m_requestFromCache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_issue_latency)));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:b_issuePUT: "
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
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_forwardToCache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MI_example-cache.sm:296: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromCache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_cache_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:e_sendData: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Send data from TBE to requestor */
void
L1Cache_Controller::ee_sendDataFromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing ee_sendDataFromTBE\n");
    try {
       {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_forwardToCache_ptr)).peek());
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
        panic("Runtime Error at MI_example-cache.sm:310: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromCache_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_cache_response_latency)));
}
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:ee_sendDataFromTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate a cache block */
void
L1Cache_Controller::i_allocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateL1CacheBlock\n");
    try {
           if ((m_cache_entry_ptr != NULL)) {
    } else {
        set_cache_entry(m_cache_entry_ptr, (((*m_cacheMemory_ptr)).allocate(addr, new L1Cache_Entry)));;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:i_allocateL1CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief deallocate a cache block */
void
L1Cache_Controller::h_deallocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing h_deallocateL1CacheBlock\n");
    try {
           if ((m_cache_entry_ptr != NULL)) {
        (((*m_cacheMemory_ptr)).deallocate(addr));
        unset_cache_entry(m_cache_entry_ptr);;
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:h_deallocateL1CacheBlock: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop the mandatory request queue */
void
L1Cache_Controller::m_popMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_popMandatoryQueue\n");
    try {
       (((*m_mandatoryQueue_ptr)).dequeue((clockEdge())));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:m_popMandatoryQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop the response queue */
void
L1Cache_Controller::n_popResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing n_popResponseQueue\n");
    try {
       Tick delay
 = (((*m_responseToCache_ptr)).dequeue((clockEdge())));
(profileMsgDelay((1), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:n_popResponseQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Pop the forwarded request queue */
void
L1Cache_Controller::o_popForwardedRequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_popForwardedRequestQueue\n");
    try {
       Tick delay
 = (((*m_forwardToCache_ptr)).dequeue((clockEdge())));
(profileMsgDelay((2), (ticksToCycles(delay))));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:o_popForwardedRequestQueue: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile cache miss */
void
L1Cache_Controller::p_profileMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing p_profileMiss\n");
    try {
       (++ ((*m_cacheMemory_ptr)).m_demand_misses);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:p_profileMiss: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Profile cache miss */
void
L1Cache_Controller::p_profileHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing p_profileHit\n");
    try {
       (++ ((*m_cacheMemory_ptr)).m_demand_hits);

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:p_profileHit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify sequencer the load completed. */
void
L1Cache_Controller::r_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing r_load_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:358: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:359: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_cacheMemory_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (false)));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:r_load_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief External load completed. */
void
L1Cache_Controller::rx_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing rx_load_hit\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:366: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:367: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_cacheMemory_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true), (machineIDToMachineType(((*in_msg_ptr)).m_Sender))));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:rx_load_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Notify sequencer that store completed. */
void
L1Cache_Controller::s_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing s_store_hit\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:375: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:376: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_cacheMemory_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (false)));

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:s_store_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief External store completed. */
void
L1Cache_Controller::sx_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing sx_store_hit\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:383: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:384: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_cacheMemory_ptr)).setMRU(m_cache_entry_ptr));
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true), (machineIDToMachineType(((*in_msg_ptr)).m_Sender))));
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:sx_store_hit: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Write data to the cache */
void
L1Cache_Controller::u_writeDataToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataToCache\n");
    try {
       {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:393: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:u_writeDataToCache: "
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
        DPRINTF(RubySlicc, "MI_example-cache.sm:400: Sending invalidation for %#x to the CPU\n", addr);
        (((*m_sequencer_ptr)).evictionCallback(addr));
    }

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:forward_eviction_to_cpu: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Allocate TBE */
void
L1Cache_Controller::v_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing v_allocateTBE\n");
    try {
       (((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:v_allocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Deallocate TBE */
void
L1Cache_Controller::w_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing w_deallocateTBE\n");
    try {
       (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:w_deallocateTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief Copy data from cache to TBE */
void
L1Cache_Controller::x_copyDataFromCacheToTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing x_copyDataFromCacheToTBE\n");
    try {
       #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:416: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:417: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;

    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:x_copyDataFromCacheToTBE: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

/** \brief stall */
void
L1Cache_Controller::z_stall(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing z_stall\n");
    try {
       
    } catch (const RejectException & e) {
       fatal("Error in action L1Cache:z_stall: "
             "executed a peek statement with the wrong message "
             "type specified. ");
    }
}

L1Cache_Entry*
L1Cache_Controller::getCacheEntry(const Addr& param_address)
{
return static_cast<L1Cache_Entry *>((((*m_cacheMemory_ptr)).lookup(param_address)));

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
                        panic("Runtime Error at MI_example-cache.sm:128: %s.\n", ("Invalid RubyRequestType"));
                        ;
                    }
                }
            }

}
L1Cache_State
L1Cache_Controller::getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            } else {
                return L1Cache_State_I;
            }
        }

}
void
L1Cache_Controller::setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Addr& param_addr, const L1Cache_State& param_state)
{
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((param_cache_entry != NULL)) {
            (*param_cache_entry).m_CacheState = param_state;
        }

}
AccessPermission
L1Cache_Controller::getAccessPermission(const Addr& param_addr)
{
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        return (L1Cache_State_to_permission((*tbe).m_TBEState));
    }
    L1Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            return (L1Cache_State_to_permission((*cache_entry).m_CacheState));
        }
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
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (testAndRead(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt));
    }

}
int
L1Cache_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
int
L1Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_requestFromCache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromCache_ptr->functionalWrite(pkt);
num_functional_writes += m_forwardToCache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToCache_ptr->functionalWrite(pkt);
num_functional_writes += m_mandatoryQueue_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
