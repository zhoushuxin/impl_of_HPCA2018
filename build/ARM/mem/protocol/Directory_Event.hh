/** \file Directory_Event.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __Directory_Event_HH__
#define __Directory_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum Directory_Event
 *  \brief Directory events
 */
enum Directory_Event {
    Directory_Event_FIRST,
    Directory_Event_GETX = Directory_Event_FIRST, /**< A GETX arrives */
    Directory_Event_GETS, /**< A GETS arrives */
    Directory_Event_PUTX, /**< A PUTX arrives */
    Directory_Event_PUTO, /**< A PUTO arrives */
    Directory_Event_PUTO_SHARERS, /**< A PUTO arrives, but don't remove from sharers list */
    Directory_Event_Unblock, /**< An unblock message arrives */
    Directory_Event_Last_Unblock, /**< An unblock message arrives, we're not waiting for any additional unblocks */
    Directory_Event_Exclusive_Unblock, /**< The processor become the exclusive owner (E or M) of the line */
    Directory_Event_Clean_Writeback, /**< The final message as part of a PutX/PutS, no data */
    Directory_Event_Dirty_Writeback, /**< The final message as part of a PutX/PutS, contains data */
    Directory_Event_Memory_Data, /**< Fetched data from memory arrives */
    Directory_Event_Memory_Ack, /**< Writeback Ack from memory arrives */
    Directory_Event_DMA_READ, /**< DMA Read */
    Directory_Event_DMA_WRITE, /**< DMA Write */
    Directory_Event_DMA_ACK, /**< DMA Ack */
    Directory_Event_Data, /**< Data to directory */
    Directory_Event_NUM
};

// Code to convert from a string to the enumeration
Directory_Event string_to_Directory_Event(const std::string& str);

// Code to convert state to a string
std::string Directory_Event_to_string(const Directory_Event& obj);

// Code to increment an enumeration type
Directory_Event &operator++(Directory_Event &e);
std::ostream& operator<<(std::ostream& out, const Directory_Event& obj);

#endif // __Directory_Event_HH__
