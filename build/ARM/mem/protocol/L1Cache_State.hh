/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __L1Cache_State_HH__
#define __L1Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum L1Cache_State
 *  \brief Cache states
 */
enum L1Cache_State {
    L1Cache_State_FIRST,
    L1Cache_State_I = L1Cache_State_FIRST, /**< Idle */
    L1Cache_State_S, /**< Shared */
    L1Cache_State_O, /**< Owned */
    L1Cache_State_M, /**< Modified (dirty) */
    L1Cache_State_M_W, /**< Modified (dirty) */
    L1Cache_State_MM, /**< Modified (dirty and locally modified) */
    L1Cache_State_MM_W, /**< Modified (dirty and locally modified) */
    L1Cache_State_IM, /**< Issued GetX */
    L1Cache_State_SM, /**< Issued GetX, we still have an old copy of the line */
    L1Cache_State_OM, /**< Issued GetX, received data */
    L1Cache_State_IS, /**< Issued GetS */
    L1Cache_State_SI, /**< Issued PutS, waiting for ack */
    L1Cache_State_OI, /**< Issued PutO, waiting for ack */
    L1Cache_State_MI, /**< Issued PutX, waiting for ack */
    L1Cache_State_II, /**< Issued PutX/O, saw Fwd_GETS or Fwd_GETX, waiting for ack */
    L1Cache_State_NUM
};

// Code to convert from a string to the enumeration
L1Cache_State string_to_L1Cache_State(const std::string& str);

// Code to convert state to a string
std::string L1Cache_State_to_string(const L1Cache_State& obj);

// Code to increment an enumeration type
L1Cache_State &operator++(L1Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L1Cache_State& obj);

#endif // __L1Cache_State_HH__
