// Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/StateMachine.py:1056
// L2Cache: Token protocol

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <typeinfo>

#include "base/logging.hh"

#include "debug/RubySlicc.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/L2Cache_Controller.hh"
#include "mem/protocol/L2Cache_Event.hh"
#include "mem/protocol/L2Cache_State.hh"

#include "mem/protocol/Types.hh"
#include "mem/ruby/system/RubySystem.hh"

#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;

void
L2Cache_Controller::wakeup()
{
    int counter = 0;
    while (true) {
        unsigned char rejected[4];
        memset(rejected, 0, sizeof(unsigned char)*4);
        // Some cases will put us into an infinite loop without this limit
        assert(counter <= m_transitions_per_cycle);
        if (counter == m_transitions_per_cycle) {
            // Count how often we are fully utilized
            m_fully_busy_cycles++;

            // Wakeup in another cycle and try again
            scheduleEvent(Cycles(1));
            break;
        }
            // L2CacheInPort triggerQueue_in
            m_cur_in_port = 0;
            try {
                            if ((((*m_triggerQueue_ptr)).isReady((clockEdge())))) {
                                {
                                    // Declare message
                                    const TriggerMsg* in_msg_ptr M5_VAR_USED;
                                    in_msg_ptr = dynamic_cast<const TriggerMsg *>(((*m_triggerQueue_ptr)).peek());
                                    if (in_msg_ptr == NULL) {
                                        // If the cast fails, this is the wrong inport (wrong message type).
                                        // Throw an exception, and the caller will decide to either try a
                                        // different inport or punt.
                                        throw RejectException();
                                    }
                                    if ((((*in_msg_ptr)).m_Type == TriggerType_ALL_ACKS)) {
                                        {

                                            TransitionResult result = doTransition(L2Cache_Event_All_Acks, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                            if (result == TransitionResult_Valid) {
                                                counter++;
                                                continue; // Check the first port again
                                            }

                                            if (result == TransitionResult_ResourceStall ||
                                                result == TransitionResult_ProtocolStall) {
                                                scheduleEvent(Cycles(1));

                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                            }
                                        }
                                        ;
                                    } else {
                                        panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:589: %s.\n", ("Unexpected message"));
                                        ;
                                    }
                                    }
                                }
                        } catch (const RejectException & e) {
                            rejected[0]++;
                        }
            // L2CacheInPort requestNetwork_in
            m_cur_in_port = 0;
            try {
                            if ((((*m_GlobalRequestToL2Cache_ptr)).isReady((clockEdge())))) {
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
                                    if (((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX) || (((*in_msg_ptr)).m_Type == CoherenceRequestType_DMA_WRITE))) {
                                            if ((((*in_msg_ptr)).m_Requestor == m_machineID)) {
                                                {

                                                    TransitionResult result = doTransition(L2Cache_Event_Own_GETX, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            } else {
                                                {

                                                    TransitionResult result = doTransition(L2Cache_Event_Fwd_GETX, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            }
                                        } else {
                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                                                    {

                                                        TransitionResult result = doTransition(L2Cache_Event_Fwd_GETS, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall ||
                                                            result == TransitionResult_ProtocolStall) {
                                                            scheduleEvent(Cycles(1));

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                } else {
                                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_DMA_READ)) {
                                                            {

                                                                TransitionResult result = doTransition(L2Cache_Event_Fwd_DMA, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                if (result == TransitionResult_Valid) {
                                                                    counter++;
                                                                    continue; // Check the first port again
                                                                }

                                                                if (result == TransitionResult_ResourceStall ||
                                                                    result == TransitionResult_ProtocolStall) {
                                                                    scheduleEvent(Cycles(1));

                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                }
                                                            }
                                                            ;
                                                        } else {
                                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_INV)) {
                                                                    {

                                                                        TransitionResult result = doTransition(L2Cache_Event_Inv, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                        if (result == TransitionResult_Valid) {
                                                                            counter++;
                                                                            continue; // Check the first port again
                                                                        }

                                                                        if (result == TransitionResult_ResourceStall ||
                                                                            result == TransitionResult_ProtocolStall) {
                                                                            scheduleEvent(Cycles(1));

                                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                        }
                                                                    }
                                                                    ;
                                                                } else {
                                                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_ACK)) {
                                                                            {

                                                                                TransitionResult result = doTransition(L2Cache_Event_Writeback_Ack, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                if (result == TransitionResult_Valid) {
                                                                                    counter++;
                                                                                    continue; // Check the first port again
                                                                                }

                                                                                if (result == TransitionResult_ResourceStall ||
                                                                                    result == TransitionResult_ProtocolStall) {
                                                                                    scheduleEvent(Cycles(1));

                                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                }
                                                                            }
                                                                            ;
                                                                        } else {
                                                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_NACK)) {
                                                                                    {

                                                                                        TransitionResult result = doTransition(L2Cache_Event_Writeback_Nack, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                        if (result == TransitionResult_Valid) {
                                                                                            counter++;
                                                                                            continue; // Check the first port again
                                                                                        }

                                                                                        if (result == TransitionResult_ResourceStall ||
                                                                                            result == TransitionResult_ProtocolStall) {
                                                                                            scheduleEvent(Cycles(1));

                                                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                        }
                                                                                    }
                                                                                    ;
                                                                                } else {
                                                                                    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:624: %s.\n", ("Unexpected message"));
                                                                                    ;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                            }
                                                        }
                        } catch (const RejectException & e) {
                            rejected[1]++;
                        }
            // L2CacheInPort L1requestNetwork_in
            m_cur_in_port = 0;
            try {
                            if ((((*m_L1RequestToL2Cache_ptr)).isReady((clockEdge())))) {
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
                                if (!(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
                                    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:633: %s.\n", "assert failure");

                                }
                                #endif
                                ;
                                    if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX)) {
                                        {

                                            TransitionResult result = doTransition(L2Cache_Event_L1_GETX, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                            if (result == TransitionResult_Valid) {
                                                counter++;
                                                continue; // Check the first port again
                                            }

                                            if (result == TransitionResult_ResourceStall ||
                                                result == TransitionResult_ProtocolStall) {
                                                scheduleEvent(Cycles(1));

                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                            }
                                        }
                                        ;
                                    } else {
                                            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                                                {

                                                    TransitionResult result = doTransition(L2Cache_Event_L1_GETS, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            } else {
                                                    if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTO)) {
                                                        {

                                                            TransitionResult result = doTransition(L2Cache_Event_L1_PUTO, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                            if (result == TransitionResult_Valid) {
                                                                counter++;
                                                                continue; // Check the first port again
                                                            }

                                                            if (result == TransitionResult_ResourceStall ||
                                                                result == TransitionResult_ProtocolStall) {
                                                                scheduleEvent(Cycles(1));

                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                            }
                                                        }
                                                        ;
                                                    } else {
                                                            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTX)) {
                                                                {

                                                                    TransitionResult result = doTransition(L2Cache_Event_L1_PUTX, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                    if (result == TransitionResult_Valid) {
                                                                        counter++;
                                                                        continue; // Check the first port again
                                                                    }

                                                                    if (result == TransitionResult_ResourceStall ||
                                                                        result == TransitionResult_ProtocolStall) {
                                                                        scheduleEvent(Cycles(1));

                                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                    }
                                                                }
                                                                ;
                                                            } else {
                                                                    if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTS)) {
                                                                        L2Cache_Entry* cache_entry
                                                                         = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                                                            if ((isOnlySharer(cache_entry, ((*in_msg_ptr)).m_addr, ((*in_msg_ptr)).m_Requestor))) {
                                                                                {

                                                                                    TransitionResult result = doTransition(L2Cache_Event_L1_PUTS_only, cache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                    if (result == TransitionResult_Valid) {
                                                                                        counter++;
                                                                                        continue; // Check the first port again
                                                                                    }

                                                                                    if (result == TransitionResult_ResourceStall ||
                                                                                        result == TransitionResult_ProtocolStall) {
                                                                                        scheduleEvent(Cycles(1));

                                                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                    }
                                                                                }
                                                                                ;
                                                                            } else {
                                                                                {

                                                                                    TransitionResult result = doTransition(L2Cache_Event_L1_PUTS, cache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                    if (result == TransitionResult_Valid) {
                                                                                        counter++;
                                                                                        continue; // Check the first port again
                                                                                    }

                                                                                    if (result == TransitionResult_ResourceStall ||
                                                                                        result == TransitionResult_ProtocolStall) {
                                                                                        scheduleEvent(Cycles(1));

                                                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                    }
                                                                                }
                                                                                ;
                                                                            }
                                                                        } else {
                                                                            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:657: %s.\n", ("Unexpected message"));
                                                                            ;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        }
                                                    }
                        } catch (const RejectException & e) {
                            rejected[2]++;
                        }
            // L2CacheInPort responseNetwork_in
            m_cur_in_port = 0;
            try {
                            if ((((*m_responseToL2Cache_ptr)).isReady((clockEdge())))) {
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
                                if (!(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
                                    panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:668: %s.\n", "assert failure");

                                }
                                #endif
                                ;
                                    if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_ACK)) {
                                            if ((((*in_msg_ptr)).m_SenderMachine == MachineType_L2Cache)) {
                                                {

                                                    TransitionResult result = doTransition(L2Cache_Event_ExtAck, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            } else {
                                                {

                                                    TransitionResult result = doTransition(L2Cache_Event_IntAck, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                    if (result == TransitionResult_Valid) {
                                                        counter++;
                                                        continue; // Check the first port again
                                                    }

                                                    if (result == TransitionResult_ResourceStall ||
                                                        result == TransitionResult_ProtocolStall) {
                                                        scheduleEvent(Cycles(1));

                                                        // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                    }
                                                }
                                                ;
                                            }
                                        } else {
                                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
                                                    {

                                                        TransitionResult result = doTransition(L2Cache_Event_Data, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall ||
                                                            result == TransitionResult_ProtocolStall) {
                                                            scheduleEvent(Cycles(1));

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                } else {
                                                        if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA_EXCLUSIVE)) {
                                                            {

                                                                TransitionResult result = doTransition(L2Cache_Event_Data_Exclusive, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                if (result == TransitionResult_Valid) {
                                                                    counter++;
                                                                    continue; // Check the first port again
                                                                }

                                                                if (result == TransitionResult_ResourceStall ||
                                                                    result == TransitionResult_ProtocolStall) {
                                                                    scheduleEvent(Cycles(1));

                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                }
                                                            }
                                                            ;
                                                        } else {
                                                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_UNBLOCK)) {
                                                                    {

                                                                        TransitionResult result = doTransition(L2Cache_Event_Unblock, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                        if (result == TransitionResult_Valid) {
                                                                            counter++;
                                                                            continue; // Check the first port again
                                                                        }

                                                                        if (result == TransitionResult_ResourceStall ||
                                                                            result == TransitionResult_ProtocolStall) {
                                                                            scheduleEvent(Cycles(1));

                                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                        }
                                                                    }
                                                                    ;
                                                                } else {
                                                                        if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_UNBLOCK_EXCLUSIVE)) {
                                                                            {

                                                                                TransitionResult result = doTransition(L2Cache_Event_Exclusive_Unblock, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                if (result == TransitionResult_Valid) {
                                                                                    counter++;
                                                                                    continue; // Check the first port again
                                                                                }

                                                                                if (result == TransitionResult_ResourceStall ||
                                                                                    result == TransitionResult_ProtocolStall) {
                                                                                    scheduleEvent(Cycles(1));

                                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                }
                                                                            }
                                                                            ;
                                                                        } else {
                                                                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_WRITEBACK_DIRTY_DATA)) {
                                                                                    L2Cache_Entry* cache_entry
                                                                                     = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                                                                        if (((cache_entry == NULL) && ((((*m_L2cache_ptr)).cacheAvail(((*in_msg_ptr)).m_addr)) == (false)))) {
                                                                                            {

                                                                                                TransitionResult result = doTransition(L2Cache_Event_L2_Replacement, (getCacheEntry((((*m_L2cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr)))), (((*m_TBEs_ptr)).lookup((((*m_L2cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr)))), (((*m_L2cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr)));

                                                                                                if (result == TransitionResult_Valid) {
                                                                                                    counter++;
                                                                                                    continue; // Check the first port again
                                                                                                }

                                                                                                if (result == TransitionResult_ResourceStall ||
                                                                                                    result == TransitionResult_ProtocolStall) {
                                                                                                    scheduleEvent(Cycles(1));

                                                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                                }
                                                                                            }
                                                                                            ;
                                                                                        } else {
                                                                                            {

                                                                                                TransitionResult result = doTransition(L2Cache_Event_L1_WBDIRTYDATA, cache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                                if (result == TransitionResult_Valid) {
                                                                                                    counter++;
                                                                                                    continue; // Check the first port again
                                                                                                }

                                                                                                if (result == TransitionResult_ResourceStall ||
                                                                                                    result == TransitionResult_ProtocolStall) {
                                                                                                    scheduleEvent(Cycles(1));

                                                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                                }
                                                                                            }
                                                                                            ;
                                                                                        }
                                                                                    } else {
                                                                                            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_WRITEBACK_CLEAN_DATA)) {
                                                                                                L2Cache_Entry* cache_entry
                                                                                                 = (getCacheEntry(((*in_msg_ptr)).m_addr));
                                                                                                    if (((cache_entry == NULL) && ((((*m_L2cache_ptr)).cacheAvail(((*in_msg_ptr)).m_addr)) == (false)))) {
                                                                                                        {

                                                                                                            TransitionResult result = doTransition(L2Cache_Event_L2_Replacement, (getCacheEntry((((*m_L2cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr)))), (((*m_TBEs_ptr)).lookup((((*m_L2cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr)))), (((*m_L2cache_ptr)).cacheProbe(((*in_msg_ptr)).m_addr)));

                                                                                                            if (result == TransitionResult_Valid) {
                                                                                                                counter++;
                                                                                                                continue; // Check the first port again
                                                                                                            }

                                                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                                                result == TransitionResult_ProtocolStall) {
                                                                                                                scheduleEvent(Cycles(1));

                                                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                                            }
                                                                                                        }
                                                                                                        ;
                                                                                                    } else {
                                                                                                        {

                                                                                                            TransitionResult result = doTransition(L2Cache_Event_L1_WBCLEANDATA, cache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                                            if (result == TransitionResult_Valid) {
                                                                                                                counter++;
                                                                                                                continue; // Check the first port again
                                                                                                            }

                                                                                                            if (result == TransitionResult_ResourceStall ||
                                                                                                                result == TransitionResult_ProtocolStall) {
                                                                                                                scheduleEvent(Cycles(1));

                                                                                                                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                                            }
                                                                                                        }
                                                                                                        ;
                                                                                                    }
                                                                                                } else {
                                                                                                        if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DMA_ACK)) {
                                                                                                            {

                                                                                                                TransitionResult result = doTransition(L2Cache_Event_DmaAck, (getCacheEntry(((*in_msg_ptr)).m_addr)), (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_addr)), ((*in_msg_ptr)).m_addr);

                                                                                                                if (result == TransitionResult_Valid) {
                                                                                                                    counter++;
                                                                                                                    continue; // Check the first port again
                                                                                                                }

                                                                                                                if (result == TransitionResult_ResourceStall ||
                                                                                                                    result == TransitionResult_ProtocolStall) {
                                                                                                                    scheduleEvent(Cycles(1));

                                                                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                                                                }
                                                                                                            }
                                                                                                            ;
                                                                                                        } else {
                                                                                                            panic("Runtime Error at MOESI_CMP_directory-L2cache.sm:718: %s.\n", ("Unexpected message"));
                                                                                                            ;
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                            }
                                                                        }
                        } catch (const RejectException & e) {
                            rejected[3]++;
                        }
        // If we got this far, we have nothing left todo or something went
        // wrong
        break;
    }
}
