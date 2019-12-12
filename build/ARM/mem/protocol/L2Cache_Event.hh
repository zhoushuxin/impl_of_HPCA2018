/** \file L2Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __L2Cache_Event_HH__
#define __L2Cache_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum L2Cache_Event
 *  \brief Cache events
 */
enum L2Cache_Event {
    L2Cache_Event_FIRST,
    L2Cache_Event_L1_GETS = L2Cache_Event_FIRST, /**< local L1 GETS request */
    L2Cache_Event_L1_GETX, /**< local L1 GETX request */
    L2Cache_Event_L1_PUTO, /**< local owner wants to writeback */
    L2Cache_Event_L1_PUTX, /**< local exclusive wants to writeback */
    L2Cache_Event_L1_PUTS_only, /**< only local sharer wants to writeback */
    L2Cache_Event_L1_PUTS, /**< local sharer wants to writeback */
    L2Cache_Event_Fwd_GETX, /**< A GetX from another processor */
    L2Cache_Event_Fwd_GETS, /**< A GetS from another processor */
    L2Cache_Event_Fwd_DMA, /**< A request from DMA */
    L2Cache_Event_Own_GETX, /**< A GetX from this node */
    L2Cache_Event_Inv, /**< Invalidations from the directory */
    L2Cache_Event_IntAck, /**< Received an ack message */
    L2Cache_Event_ExtAck, /**< Received an ack message */
    L2Cache_Event_All_Acks, /**< Received all ack messages */
    L2Cache_Event_Data, /**< Received a data message, responder has a shared copy */
    L2Cache_Event_Data_Exclusive, /**< Received a data message */
    L2Cache_Event_L1_WBCLEANDATA, /**< Writeback from L1, with data */
    L2Cache_Event_L1_WBDIRTYDATA, /**< Writeback from L1, with data */
    L2Cache_Event_Writeback_Ack, /**< Writeback O.K. from directory */
    L2Cache_Event_Writeback_Nack, /**< Writeback not O.K. from directory */
    L2Cache_Event_Unblock, /**< Local L1 is telling L2 dir to unblock */
    L2Cache_Event_Exclusive_Unblock, /**< Local L1 is telling L2 dir to unblock */
    L2Cache_Event_DmaAck, /**< DMA ack from local L1 */
    L2Cache_Event_L2_Replacement, /**< L2 Replacement */
    L2Cache_Event_NUM
};

// Code to convert from a string to the enumeration
L2Cache_Event string_to_L2Cache_Event(const std::string& str);

// Code to convert state to a string
std::string L2Cache_Event_to_string(const L2Cache_Event& obj);

// Code to increment an enumeration type
L2Cache_Event &operator++(L2Cache_Event &e);
std::ostream& operator<<(std::ostream& out, const L2Cache_Event& obj);

#endif // __L2Cache_Event_HH__
