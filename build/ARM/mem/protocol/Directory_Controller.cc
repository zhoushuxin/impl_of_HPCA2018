/** \file Directory_Controller.cc
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
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/network/Network.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/protocol/TBETable.hh"
Directory_Controller *
Directory_ControllerParams::create()
{
    return new Directory_Controller(this);
}

int Directory_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  Directory_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  Directory_Controller::transVec;

// for adding information to the protocol debug trace
stringstream Directory_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (Directory_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
Directory_Controller::Directory_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_Directory;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 3;
    m_directory_ptr = p->directory;
    m_directory_latency = p->directory_latency;
    m_to_memory_controller_latency = p->to_memory_controller_latency;
    m_requestToDir_ptr = p->requestToDir;
    m_responseToDir_ptr = p->responseToDir;
    m_forwardFromDir_ptr = p->forwardFromDir;
    m_responseFromDir_ptr = p->responseFromDir;
    m_responseFromMemory_ptr = p->responseFromMemory;

    for (int state = 0; state < Directory_State_NUM; state++) {
        for (int event = 0; event < Directory_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < Directory_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
Directory_Controller::initNetQueues()
{
    MachineType machine_type = string_to_MachineType("Directory");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    assert(m_requestToDir_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_requestToDir_ptr->getOrdered(), 1,
                                     "request", m_requestToDir_ptr);
    assert(m_responseToDir_ptr != NULL);
    m_net_ptr->setFromNetQueue(m_version + base, m_responseToDir_ptr->getOrdered(), 2,
                                     "response", m_responseToDir_ptr);
    assert(m_forwardFromDir_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_forwardFromDir_ptr->getOrdered(), 1,
                                     "forward", m_forwardFromDir_ptr);
    assert(m_responseFromDir_ptr != NULL);
    m_net_ptr->setToNetQueue(m_version + base, m_responseFromDir_ptr->getOrdered(), 2,
                                     "response", m_responseFromDir_ptr);
}

void
Directory_Controller::init()
{
    // initialize objects
    m_TBEs_ptr  = new TBETable<Directory_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);


    (*m_responseToDir_ptr).setConsumer(this);
    (*m_requestToDir_ptr).setConsumer(this);
    (*m_responseFromMemory_ptr).setConsumer(this);

    possibleTransition(Directory_State_I, Directory_Event_GETX);
    possibleTransition(Directory_State_I, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_I, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_XI_M, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_XI_U, Directory_Event_Exclusive_Unblock);
    possibleTransition(Directory_State_S, Directory_Event_GETX);
    possibleTransition(Directory_State_S, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_S, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_I, Directory_Event_GETS);
    possibleTransition(Directory_State_S, Directory_Event_GETS);
    possibleTransition(Directory_State_SS, Directory_Event_GETS);
    possibleTransition(Directory_State_I, Directory_Event_PUTO);
    possibleTransition(Directory_State_S, Directory_Event_PUTO);
    possibleTransition(Directory_State_I, Directory_Event_PUTX);
    possibleTransition(Directory_State_S, Directory_Event_PUTX);
    possibleTransition(Directory_State_O, Directory_Event_PUTX);
    possibleTransition(Directory_State_O, Directory_Event_GETX);
    possibleTransition(Directory_State_O, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_OD, Directory_Event_DMA_ACK);
    possibleTransition(Directory_State_O, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_M, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_OI_D, Directory_Event_Data);
    possibleTransition(Directory_State_O, Directory_Event_GETS);
    possibleTransition(Directory_State_OO, Directory_Event_GETS);
    possibleTransition(Directory_State_M, Directory_Event_GETX);
    possibleTransition(Directory_State_M, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MD, Directory_Event_DMA_ACK);
    possibleTransition(Directory_State_M, Directory_Event_GETS);
    possibleTransition(Directory_State_M, Directory_Event_PUTX);
    possibleTransition(Directory_State_M, Directory_Event_PUTO);
    possibleTransition(Directory_State_M, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_O, Directory_Event_PUTO);
    possibleTransition(Directory_State_O, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_MM, Directory_Event_GETS);
    possibleTransition(Directory_State_MM, Directory_Event_GETX);
    possibleTransition(Directory_State_MM, Directory_Event_PUTO);
    possibleTransition(Directory_State_MM, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_MM, Directory_Event_PUTX);
    possibleTransition(Directory_State_MM, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MM, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_MO, Directory_Event_GETS);
    possibleTransition(Directory_State_MO, Directory_Event_GETX);
    possibleTransition(Directory_State_MO, Directory_Event_PUTO);
    possibleTransition(Directory_State_MO, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_MO, Directory_Event_PUTX);
    possibleTransition(Directory_State_MO, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MO, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_MI, Directory_Event_GETS);
    possibleTransition(Directory_State_MI, Directory_Event_GETX);
    possibleTransition(Directory_State_MI, Directory_Event_PUTO);
    possibleTransition(Directory_State_MI, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_MI, Directory_Event_PUTX);
    possibleTransition(Directory_State_MI, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MI, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_MIS, Directory_Event_GETS);
    possibleTransition(Directory_State_MIS, Directory_Event_GETX);
    possibleTransition(Directory_State_MIS, Directory_Event_PUTO);
    possibleTransition(Directory_State_MIS, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_MIS, Directory_Event_PUTX);
    possibleTransition(Directory_State_MIS, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MIS, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_OS, Directory_Event_GETS);
    possibleTransition(Directory_State_OS, Directory_Event_GETX);
    possibleTransition(Directory_State_OS, Directory_Event_PUTO);
    possibleTransition(Directory_State_OS, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_OS, Directory_Event_PUTX);
    possibleTransition(Directory_State_OS, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_OS, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_OSS, Directory_Event_GETS);
    possibleTransition(Directory_State_OSS, Directory_Event_GETX);
    possibleTransition(Directory_State_OSS, Directory_Event_PUTO);
    possibleTransition(Directory_State_OSS, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_OSS, Directory_Event_PUTX);
    possibleTransition(Directory_State_OSS, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_OSS, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_XI_M, Directory_Event_GETS);
    possibleTransition(Directory_State_XI_M, Directory_Event_GETX);
    possibleTransition(Directory_State_XI_M, Directory_Event_PUTO);
    possibleTransition(Directory_State_XI_M, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_XI_M, Directory_Event_PUTX);
    possibleTransition(Directory_State_XI_M, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_XI_M, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_XI_U, Directory_Event_GETS);
    possibleTransition(Directory_State_XI_U, Directory_Event_GETX);
    possibleTransition(Directory_State_XI_U, Directory_Event_PUTO);
    possibleTransition(Directory_State_XI_U, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_XI_U, Directory_Event_PUTX);
    possibleTransition(Directory_State_XI_U, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_XI_U, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_OI_D, Directory_Event_GETS);
    possibleTransition(Directory_State_OI_D, Directory_Event_GETX);
    possibleTransition(Directory_State_OI_D, Directory_Event_PUTO);
    possibleTransition(Directory_State_OI_D, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_OI_D, Directory_Event_PUTX);
    possibleTransition(Directory_State_OI_D, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_OI_D, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_OD, Directory_Event_GETS);
    possibleTransition(Directory_State_OD, Directory_Event_GETX);
    possibleTransition(Directory_State_OD, Directory_Event_PUTO);
    possibleTransition(Directory_State_OD, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_OD, Directory_Event_PUTX);
    possibleTransition(Directory_State_OD, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_OD, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_MD, Directory_Event_GETS);
    possibleTransition(Directory_State_MD, Directory_Event_GETX);
    possibleTransition(Directory_State_MD, Directory_Event_PUTO);
    possibleTransition(Directory_State_MD, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_MD, Directory_Event_PUTX);
    possibleTransition(Directory_State_MD, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MD, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_MM, Directory_Event_Exclusive_Unblock);
    possibleTransition(Directory_State_MO, Directory_Event_Exclusive_Unblock);
    possibleTransition(Directory_State_MO, Directory_Event_Unblock);
    possibleTransition(Directory_State_IS, Directory_Event_GETX);
    possibleTransition(Directory_State_IS, Directory_Event_PUTO);
    possibleTransition(Directory_State_IS, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_IS, Directory_Event_PUTX);
    possibleTransition(Directory_State_IS, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_IS, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_SS, Directory_Event_GETX);
    possibleTransition(Directory_State_SS, Directory_Event_PUTO);
    possibleTransition(Directory_State_SS, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_SS, Directory_Event_PUTX);
    possibleTransition(Directory_State_SS, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_SS, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_OO, Directory_Event_GETX);
    possibleTransition(Directory_State_OO, Directory_Event_PUTO);
    possibleTransition(Directory_State_OO, Directory_Event_PUTO_SHARERS);
    possibleTransition(Directory_State_OO, Directory_Event_PUTX);
    possibleTransition(Directory_State_OO, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_OO, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_IS, Directory_Event_GETS);
    possibleTransition(Directory_State_IS, Directory_Event_Unblock);
    possibleTransition(Directory_State_IS, Directory_Event_Exclusive_Unblock);
    possibleTransition(Directory_State_SS, Directory_Event_Unblock);
    possibleTransition(Directory_State_SS, Directory_Event_Last_Unblock);
    possibleTransition(Directory_State_OO, Directory_Event_Unblock);
    possibleTransition(Directory_State_OO, Directory_Event_Last_Unblock);
    possibleTransition(Directory_State_MI, Directory_Event_Dirty_Writeback);
    possibleTransition(Directory_State_MIS, Directory_Event_Dirty_Writeback);
    possibleTransition(Directory_State_MIS, Directory_Event_Clean_Writeback);
    possibleTransition(Directory_State_OS, Directory_Event_Dirty_Writeback);
    possibleTransition(Directory_State_OSS, Directory_Event_Dirty_Writeback);
    possibleTransition(Directory_State_OSS, Directory_Event_Clean_Writeback);
    possibleTransition(Directory_State_MI, Directory_Event_Clean_Writeback);
    possibleTransition(Directory_State_OS, Directory_Event_Clean_Writeback);
    possibleTransition(Directory_State_MI, Directory_Event_Unblock);
    possibleTransition(Directory_State_MIS, Directory_Event_Unblock);
    possibleTransition(Directory_State_OS, Directory_Event_Unblock);
    possibleTransition(Directory_State_OSS, Directory_Event_Unblock);
    possibleTransition(Directory_State_I, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_S, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_O, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_M, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_IS, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_SS, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_OO, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_MO, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_MM, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_MI, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_MIS, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_OS, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_OSS, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_I, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_S, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_O, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_M, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_IS, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_SS, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_OO, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_MO, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_MM, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_MI, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_MIS, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_OS, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_OSS, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_XI_U, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_XI_M, Directory_Event_Memory_Ack);
    AbstractController::init();
    resetStats();
}

Sequencer*
Directory_Controller::getCPUSequencer() const
{
    return NULL;
}

GPUCoalescer*
Directory_Controller::getGPUCoalescer() const
{
    return NULL;
}

void
Directory_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (Directory_Event event = Directory_Event_FIRST;
             event < Directory_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(params()->ruby_system->name() + ".Directory_Controller." +
                Directory_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (Directory_State state = Directory_State_FIRST;
             state < Directory_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (Directory_Event event = Directory_Event_FIRST;
                 event < Directory_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(params()->ruby_system->name() + ".Directory_Controller." +
                        Directory_State_to_string(state) +
                        "." + Directory_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
Directory_Controller::collateStats()
{
    for (Directory_Event event = Directory_Event_FIRST;
         event < Directory_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            RubySystem *rs = params()->ruby_system;
            std::map<uint32_t, AbstractController *>::iterator it =
                     rs->m_abstract_controls[MachineType_Directory].find(i);
            assert(it != rs->m_abstract_controls[MachineType_Directory].end());
            (*eventVec[event])[i] =
                ((Directory_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (Directory_State state = Directory_State_FIRST;
         state < Directory_State_NUM; ++state) {

        for (Directory_Event event = Directory_Event_FIRST;
             event < Directory_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                RubySystem *rs = params()->ruby_system;
                std::map<uint32_t, AbstractController *>::iterator it =
                         rs->m_abstract_controls[MachineType_Directory].find(i);
                assert(it != rs->m_abstract_controls[MachineType_Directory].end());
                (*transVec[state][event])[i] =
                    ((Directory_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
Directory_Controller::countTransition(Directory_State state, Directory_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
Directory_Controller::possibleTransition(Directory_State state,
                             Directory_Event event)
{
    m_possible[state][event] = true;
}

uint64_t
Directory_Controller::getEventCount(Directory_Event event)
{
    return m_event_counters[event];
}

bool
Directory_Controller::isPossible(Directory_State state, Directory_Event event)
{
    return m_possible[state][event];
}

uint64_t
Directory_Controller::getTransitionCount(Directory_State state,
                             Directory_Event event)
{
    return m_counters[state][event];
}

int
Directory_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
Directory_Controller::getMandatoryQueue() const
{
    return NULL;
}

MessageBuffer*
Directory_Controller::getMemoryQueue() const
{
    return m_responseFromMemory_ptr;
}

void
Directory_Controller::print(ostream& out) const
{
    out << "[Directory_Controller " << m_version << "]";
}

void Directory_Controller::resetStats()
{
    for (int state = 0; state < Directory_State_NUM; state++) {
        for (int event = 0; event < Directory_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < Directory_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for tbe variable
void
Directory_Controller::set_tbe(Directory_TBE*& m_tbe_ptr, Directory_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
Directory_Controller::unset_tbe(Directory_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
Directory_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
}

// Actions
/** \brief Send writeback ack to requestor */
void
Directory_Controller::a_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_sendWriteBackAck\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = MachineType_Directory;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_directory_latency)));
}
}

}

/** \brief Send writeback nack to requestor */
void
Directory_Controller::b_sendWriteBackNack(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing b_sendWriteBackNack\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_NACK;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = MachineType_Directory;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_directory_latency)));
}
}

}

/** \brief Clear the owner field */
void
Directory_Controller::c_clearOwner(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_clearOwner\n");
    (((*(getDirectoryEntry(addr))).m_Owner).clear());

}

/** \brief Move owner to sharers */
void
Directory_Controller::c_moveOwnerToSharer(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing c_moveOwnerToSharer\n");
    (((*(getDirectoryEntry(addr))).m_Sharers).addNetDest((*(getDirectoryEntry(addr))).m_Owner));
(((*(getDirectoryEntry(addr))).m_Owner).clear());

}

/** \brief Clear the sharers field */
void
Directory_Controller::cc_clearSharers(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing cc_clearSharers\n");
    (((*(getDirectoryEntry(addr))).m_Sharers).clear());

}

/** \brief Send data to requestor */
void
Directory_Controller::d_sendDataMsg(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing d_sendDataMsg\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_responseFromMemory_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_Directory;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_Acks = ((*in_msg_ptr)).m_Acks;
        if (((*in_msg_ptr)).m_ReadX) {
            (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
        } else {
            (*out_msg).m_Type = CoherenceResponseType_DATA;
        }
        (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
        ((*m_responseFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles((1))));
    }
    }

}

/** \brief Send data to requestor */
void
Directory_Controller::p_fwdDataToDMA(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing p_fwdDataToDMA\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_Directory;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_Dirty = (false);
    (*out_msg).m_Type = CoherenceResponseType_DATA_EXCLUSIVE;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles((1))));
}
}

}

/** \brief The owner is now the unblocker */
void
Directory_Controller::e_ownerIsUnblocker(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing e_ownerIsUnblocker\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(((*(getDirectoryEntry(addr))).m_Owner).clear());
(((*(getDirectoryEntry(addr))).m_Owner).add(((*in_msg_ptr)).m_Sender));
}

}

/** \brief Forward request to owner */
void
Directory_Controller::f_forwardRequest(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_forwardRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_RequestorMachine = (machineIDToMachineType(((*in_msg_ptr)).m_Requestor));
    (((*out_msg).m_Destination).addNetDest((*(getDirectoryEntry(((*in_msg_ptr)).m_addr))).m_Owner));
    (*out_msg).m_Acks = (((*(getDirectoryEntry(addr))).m_Sharers).count());
        if ((((*(getDirectoryEntry(addr))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
            (*out_msg).m_Acks = ((*out_msg).m_Acks - (1));
        }
        (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
        ((*m_forwardFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_directory_latency)));
    }
    }

}

/** \brief Forward request to owner */
void
Directory_Controller::f_forwardRequestDirIsRequestor(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing f_forwardRequestDirIsRequestor\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_RequestorMachine = (machineIDToMachineType(((*in_msg_ptr)).m_Requestor));
    (((*out_msg).m_Destination).addNetDest((*(getDirectoryEntry(((*in_msg_ptr)).m_addr))).m_Owner));
    (*out_msg).m_Acks = (((*(getDirectoryEntry(addr))).m_Sharers).count());
        if ((((*(getDirectoryEntry(addr))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
            (*out_msg).m_Acks = ((*out_msg).m_Acks - (1));
        }
        (*out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
        ((*m_forwardFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_directory_latency)));
    }
    }

}

/** \brief Send invalidations to sharers, not including the requester */
void
Directory_Controller::g_sendInvalidations(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing g_sendInvalidations\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
    if ((((((*(getDirectoryEntry(((*in_msg_ptr)).m_addr))).m_Sharers).count()) > (1)) || (((((*(getDirectoryEntry(((*in_msg_ptr)).m_addr))).m_Sharers).count()) > (0)) && ((((*(getDirectoryEntry(((*in_msg_ptr)).m_addr))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor)) == (false))))) {
        {
            std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
            (*out_msg).m_addr = addr;
            (*out_msg).m_Type = CoherenceRequestType_INV;
            (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
            (*out_msg).m_RequestorMachine = (machineIDToMachineType(((*in_msg_ptr)).m_Requestor));
            (((*out_msg).m_Destination).addNetDest((*(getDirectoryEntry(((*in_msg_ptr)).m_addr))).m_Sharers));
            (((*out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
            (*out_msg).m_MessageSize = MessageSizeType_Invalidate_Control;
            ((*m_forwardFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles(m_directory_latency)));
        }
    }
    }

}

/** \brief Pop incoming request queue */
void
Directory_Controller::i_popIncomingRequestQueue(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing i_popIncomingRequestQueue\n");
    (((*m_requestToDir_ptr)).dequeue((clockEdge())));

}

/** \brief Pop incoming unblock queue */
void
Directory_Controller::j_popIncomingUnblockQueue(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing j_popIncomingUnblockQueue\n");
    (((*m_responseToDir_ptr)).dequeue((clockEdge())));

}

/** \brief Add the unlocker to the sharer list */
void
Directory_Controller::m_addUnlockerToSharers(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing m_addUnlockerToSharers\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(((*(getDirectoryEntry(addr))).m_Sharers).add(((*in_msg_ptr)).m_Sender));
}

}

/** \brief Increment outstanding requests */
void
Directory_Controller::n_incrementOutstanding(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing n_incrementOutstanding\n");
    (*(getDirectoryEntry(addr))).m_WaitingUnblocks = ((*(getDirectoryEntry(addr))).m_WaitingUnblocks + (1));

}

/** \brief Decrement outstanding requests */
void
Directory_Controller::o_decrementOutstanding(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing o_decrementOutstanding\n");
    (*(getDirectoryEntry(addr))).m_WaitingUnblocks = ((*(getDirectoryEntry(addr))).m_WaitingUnblocks - (1));
#ifndef NDEBUG
if (!(((*(getDirectoryEntry(addr))).m_WaitingUnblocks >= (0)))) {
    panic("Runtime Error at MOESI_CMP_directory-dir.sm:462: %s.\n", "assert failure");

}
#endif
;

}

/** \brief Pop off-chip request queue */
void
Directory_Controller::q_popMemQueue(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing q_popMemQueue\n");
    (((*m_responseFromMemory_ptr)).dequeue((clockEdge())));

}

/** \brief Queue off-chip fetch request */
void
Directory_Controller::qf_queueMemoryFetchRequest(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qf_queueMemoryFetchRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(queueMemoryRead(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency));
}

}

/** \brief Queue off-chip writeback request */
void
Directory_Controller::qw_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qw_queueMemoryWBRequest\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
    if ((m_tbe_ptr != NULL)) {
        (queueMemoryWrite((*m_tbe_ptr).m_Requestor, addr, m_to_memory_controller_latency, ((*in_msg_ptr)).m_DataBlk));
    } else {
        (queueMemoryWrite(((*in_msg_ptr)).m_Sender, addr, m_to_memory_controller_latency, ((*in_msg_ptr)).m_DataBlk));
    }
    }

}

/** \brief Queue off-chip writeback request */
void
Directory_Controller::qw_queueMemoryWBRequestFromMessageAndTBE(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qw_queueMemoryWBRequestFromMessageAndTBE\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
DataBlock DataBlk
 = ((*in_msg_ptr)).m_DataBlk;
((DataBlk).copyPartial((*m_tbe_ptr).m_DataBlk, (getOffset((*m_tbe_ptr).m_PhysicalAddress)), (*m_tbe_ptr).m_Len));
(queueMemoryWrite((*m_tbe_ptr).m_Requestor, addr, m_to_memory_controller_latency, DataBlk));
}

}

/** \brief Queue off-chip writeback request */
void
Directory_Controller::qw_queueMemoryWBRequest2(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing qw_queueMemoryWBRequest2\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(queueMemoryWrite(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency, ((*in_msg_ptr)).m_DataBlk));
}

}

/** \brief Recycle the request queue */
void
Directory_Controller::zz_recycleRequest(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing zz_recycleRequest\n");
    (((*m_requestToDir_ptr)).recycle((clockEdge()), (cyclesToTicks(m_recycle_latency))));

}

/** \brief Send DMA Ack that write completed, along with Inv Ack count */
void
Directory_Controller::a_sendDMAAck(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_sendDMAAck\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_Directory;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (*out_msg).m_Acks = (((*(getDirectoryEntry(addr))).m_Sharers).count());
    (*out_msg).m_Type = CoherenceResponseType_DMA_ACK;
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_responseFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles((1))));
}
}

}

/** \brief Send DMA Ack that write completed, along with Inv Ack count */
void
Directory_Controller::a_sendDMAAck2(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing a_sendDMAAck2\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_addr = addr;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_SenderMachine = MachineType_Directory;
        if ((m_tbe_ptr != NULL)) {
            (((*out_msg).m_Destination).add((*m_tbe_ptr).m_Requestor));
        }
        (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
        (*out_msg).m_Acks = (((*(getDirectoryEntry(addr))).m_Sharers).count());
        (*out_msg).m_Type = CoherenceResponseType_DMA_ACK;
        (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
        ((*m_responseFromDir_ptr)).enqueue(out_msg, clockEdge(), cyclesToTicks(Cycles((1))));
    }
    }

}

/** \brief Allocate TBE entry */
void
Directory_Controller::v_allocateTBE(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing v_allocateTBE\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    if (in_msg_ptr == NULL) {
        // If the cast fails, this is the wrong inport (wrong message type).
        // Throw an exception, and the caller will decide to either try a
        // different inport or punt.
        throw RejectException();
    }
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_PhysicalAddress = ((*in_msg_ptr)).m_addr;
(*m_tbe_ptr).m_Len = ((*in_msg_ptr)).m_Len;
(*m_tbe_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
(*m_tbe_ptr).m_Requestor = ((*in_msg_ptr)).m_Requestor;
}

}

/** \brief Deallocate TBE entry */
void
Directory_Controller::w_deallocateTBE(Directory_TBE*& m_tbe_ptr, Addr addr)
{
    DPRINTF(RubyGenerated, "executing w_deallocateTBE\n");
    (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

}

Directory_Entry*
Directory_Controller::getDirectoryEntry(const Addr& param_addr)
{
Directory_Entry* dir_entry
 = static_cast<Directory_Entry *>((((*m_directory_ptr)).lookup(param_addr)))
;
    if ((dir_entry != NULL)) {
        return dir_entry;
    }
    dir_entry = static_cast<Directory_Entry *>((((*m_directory_ptr)).allocate(param_addr, new Directory_Entry)))
    ;
    return dir_entry;

}
Directory_State
Directory_Controller::getState(Directory_TBE* param_tbe, const Addr& param_addr)
{
return (*(getDirectoryEntry(param_addr))).m_DirectoryState;

}
void
Directory_Controller::setState(Directory_TBE* param_tbe, const Addr& param_addr, const Directory_State& param_state)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
            if ((param_state == Directory_State_I)) {
                #ifndef NDEBUG
                if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (0)))) {
                    panic("Runtime Error at MOESI_CMP_directory-dir.sm:147: %s.\n", "assert failure");

                }
                #endif
                ;
                #ifndef NDEBUG
                if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).count()) == (0)))) {
                    panic("Runtime Error at MOESI_CMP_directory-dir.sm:148: %s.\n", "assert failure");

                }
                #endif
                ;
            }
                if ((param_state == Directory_State_S)) {
                    #ifndef NDEBUG
                    if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (0)))) {
                        panic("Runtime Error at MOESI_CMP_directory-dir.sm:152: %s.\n", "assert failure");

                    }
                    #endif
                    ;
                }
                    if ((param_state == Directory_State_O)) {
                        #ifndef NDEBUG
                        if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (1)))) {
                            panic("Runtime Error at MOESI_CMP_directory-dir.sm:156: %s.\n", "assert failure");

                        }
                        #endif
                        ;
                        #ifndef NDEBUG
                        if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).isSuperset((*(getDirectoryEntry(param_addr))).m_Owner)) == (false)))) {
                            panic("Runtime Error at MOESI_CMP_directory-dir.sm:157: %s.\n", "assert failure");

                        }
                        #endif
                        ;
                    }
                        if ((param_state == Directory_State_M)) {
                            #ifndef NDEBUG
                            if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (1)))) {
                                panic("Runtime Error at MOESI_CMP_directory-dir.sm:161: %s.\n", "assert failure");

                            }
                            #endif
                            ;
                            #ifndef NDEBUG
                            if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).count()) == (0)))) {
                                panic("Runtime Error at MOESI_CMP_directory-dir.sm:162: %s.\n", "assert failure");

                            }
                            #endif
                            ;
                        }
                            if (((param_state != Directory_State_SS) && (param_state != Directory_State_OO))) {
                                #ifndef NDEBUG
                                if (!(((*(getDirectoryEntry(param_addr))).m_WaitingUnblocks == (0)))) {
                                    panic("Runtime Error at MOESI_CMP_directory-dir.sm:166: %s.\n", "assert failure");

                                }
                                #endif
                                ;
                            }
                                if ((((*(getDirectoryEntry(param_addr))).m_DirectoryState != Directory_State_I) && (param_state == Directory_State_I))) {
                                    (*(getDirectoryEntry(param_addr))).m_DirectoryState = param_state;
                                } else {
                                    (*(getDirectoryEntry(param_addr))).m_DirectoryState = param_state;
                                }
                            }

}
AccessPermission
Directory_Controller::getAccessPermission(const Addr& param_addr)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
        DPRINTF(RubySlicc, "MOESI_CMP_directory-dir.sm:182: %s\n", (Directory_State_to_permission((*(getDirectoryEntry(param_addr))).m_DirectoryState)));
        return (Directory_State_to_permission((*(getDirectoryEntry(param_addr))).m_DirectoryState));
    }
    DPRINTF(RubySlicc, "MOESI_CMP_directory-dir.sm:186: AccessPermission_NotPresent\n");
    return AccessPermission_NotPresent;

}
void
Directory_Controller::setAccessPermission(const Addr& param_addr, const Directory_State& param_state)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
        ((*((getDirectoryEntry(param_addr)))).changePermission((Directory_State_to_permission(param_state))));
    }

}
void
Directory_Controller::functionalRead(const Addr& param_addr, Packet* param_pkt)
{
(functionalMemoryRead(param_pkt));

}
int
Directory_Controller::functionalWrite(const Addr& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
num_functional_writes = (num_functional_writes + (functionalMemoryWrite(param_pkt)));
return num_functional_writes;

}
bool
Directory_Controller::isBlockShared(const Addr& param_addr)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
            if (((*(getDirectoryEntry(param_addr))).m_DirectoryState == Directory_State_I)) {
                return (true);
            }
        }
        return (false);

}
bool
Directory_Controller::isBlockExclusive(const Addr& param_addr)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
            if (((*(getDirectoryEntry(param_addr))).m_DirectoryState == Directory_State_I)) {
                return (true);
            }
        }
        return (false);

}
int
Directory_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_requestToDir_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToDir_ptr->functionalWrite(pkt);
num_functional_writes += m_forwardFromDir_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromDir_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromMemory_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
