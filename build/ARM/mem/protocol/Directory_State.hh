/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __Directory_State_HH__
#define __Directory_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum Directory_State
 *  \brief Directory states
 */
enum Directory_State {
    Directory_State_FIRST,
    Directory_State_I = Directory_State_FIRST, /**< Invalid */
    Directory_State_S, /**< Shared */
    Directory_State_O, /**< Owner */
    Directory_State_M, /**< Modified */
    Directory_State_IS, /**< Blocked, was in idle */
    Directory_State_SS, /**< Blocked, was in shared */
    Directory_State_OO, /**< Blocked, was in owned */
    Directory_State_MO, /**< Blocked, going to owner or maybe modified */
    Directory_State_MM, /**< Blocked, going to modified */
    Directory_State_MM_DMA, /**< Blocked, going to I */
    Directory_State_MI, /**< Blocked on a writeback */
    Directory_State_MIS, /**< Blocked on a writeback, but don't remove from sharers when received */
    Directory_State_OS, /**< Blocked on a writeback */
    Directory_State_OSS, /**< Blocked on a writeback, but don't remove from sharers when received */
    Directory_State_XI_M, /**< In a stable state, going to I, waiting for the memory controller */
    Directory_State_XI_U, /**< In a stable state, going to I, waiting for an unblock */
    Directory_State_OI_D, /**< In O, going to I, waiting for data */
    Directory_State_OD, /**< In O, waiting for dma ack from L2 */
    Directory_State_MD, /**< In M, waiting for dma ack from L2 */
    Directory_State_NUM
};

// Code to convert from a string to the enumeration
Directory_State string_to_Directory_State(const std::string& str);

// Code to convert state to a string
std::string Directory_State_to_string(const Directory_State& obj);

// Code to increment an enumeration type
Directory_State &operator++(Directory_State &e);

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj);

std::ostream& operator<<(std::ostream& out, const Directory_State& obj);

#endif // __Directory_State_HH__
