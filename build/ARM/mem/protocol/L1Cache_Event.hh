/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __L1Cache_Event_HH__
#define __L1Cache_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum L1Cache_Event
 *  \brief Cache events
 */
enum L1Cache_Event {
    L1Cache_Event_FIRST,
    L1Cache_Event_Load = L1Cache_Event_FIRST, /**< Load request from the processor */
    L1Cache_Event_Ifetch, /**< I-fetch request from the processor */
    L1Cache_Event_Store, /**< Store request from the processor */
    L1Cache_Event_L1_Replacement, /**< Replacement */
    L1Cache_Event_Own_GETX, /**< We observe our own GetX forwarded back to us */
    L1Cache_Event_Fwd_GETX, /**< A GetX from another processor */
    L1Cache_Event_Fwd_GETS, /**< A GetS from another processor */
    L1Cache_Event_Fwd_DMA, /**< A GetS from another processor */
    L1Cache_Event_Inv, /**< Invalidations from the directory */
    L1Cache_Event_Ack, /**< Received an ack message */
    L1Cache_Event_Data, /**< Received a data message, responder has a shared copy */
    L1Cache_Event_Exclusive_Data, /**< Received a data message */
    L1Cache_Event_Writeback_Ack, /**< Writeback O.K. from directory */
    L1Cache_Event_Writeback_Ack_Data, /**< Writeback O.K. from directory */
    L1Cache_Event_Writeback_Nack, /**< Writeback not O.K. from directory */
    L1Cache_Event_All_acks, /**< Received all required data and message acks */
    L1Cache_Event_Use_Timeout, /**< lockout period ended */
    L1Cache_Event_NUM
};

// Code to convert from a string to the enumeration
L1Cache_Event string_to_L1Cache_Event(const std::string& str);

// Code to convert state to a string
std::string L1Cache_Event_to_string(const L1Cache_Event& obj);

// Code to increment an enumeration type
L1Cache_Event &operator++(L1Cache_Event &e);
std::ostream& operator<<(std::ostream& out, const L1Cache_Event& obj);

#endif // __L1Cache_Event_HH__
