/** \file L2Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __L2Cache_State_HH__
#define __L2Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum L2Cache_State
 *  \brief L2 Cache states
 */
enum L2Cache_State {
    L2Cache_State_FIRST,
    L2Cache_State_NP = L2Cache_State_FIRST, /**< Not Present */
    L2Cache_State_I, /**< Invalid */
    L2Cache_State_ILS, /**< Idle/NP, but local sharers exist */
    L2Cache_State_ILX, /**< Idle/NP, but local exclusive exists */
    L2Cache_State_ILO, /**< Idle/NP, but local owner exists */
    L2Cache_State_ILOX, /**< Idle/NP, but local owner exists and chip is exclusive */
    L2Cache_State_ILOS, /**< Idle/NP, but local owner exists and local sharers as well */
    L2Cache_State_ILOSX, /**< Idle/NP, but local owner exists, local sharers exist, chip is exclusive  */
    L2Cache_State_S, /**< Shared, no local sharers */
    L2Cache_State_O, /**< Owned, no local sharers */
    L2Cache_State_OLS, /**< Owned with local sharers */
    L2Cache_State_OLSX, /**< Owned with local sharers, chip is exclusive */
    L2Cache_State_SLS, /**< Shared with local sharers */
    L2Cache_State_M, /**< Modified */
    L2Cache_State_IFGX, /**< Blocked, forwarded global GETX to local owner/exclusive.  No other on-chip invs needed */
    L2Cache_State_IFGS, /**< Blocked, forwarded global GETS to local owner */
    L2Cache_State_ISFGS, /**< Blocked, forwarded global GETS to local owner, local sharers exist */
    L2Cache_State_IFGXX, /**< Blocked, forwarded global GETX to local owner but may need acks from other sharers */
    L2Cache_State_OFGX, /**< Blocked, forwarded global GETX to owner and got data but may need acks */
    L2Cache_State_OLSF, /**< Blocked, got Fwd_GETX with local sharers, waiting for local inv acks */
    L2Cache_State_ILOW, /**< local WB request, was ILO */
    L2Cache_State_ILOXW, /**< local WB request, was ILOX */
    L2Cache_State_ILOSW, /**< local WB request, was ILOS */
    L2Cache_State_ILOSXW, /**< local WB request, was ILOSX */
    L2Cache_State_SLSW, /**< local WB request, was SLS */
    L2Cache_State_OLSW, /**< local WB request, was OLS */
    L2Cache_State_ILSW, /**< local WB request, was ILS */
    L2Cache_State_IW, /**< local WB request from only sharer, was ILS */
    L2Cache_State_OW, /**< local WB request from only sharer, was OLS */
    L2Cache_State_SW, /**< local WB request from only sharer, was SLS */
    L2Cache_State_OXW, /**< local WB request from only sharer, was OLSX */
    L2Cache_State_OLSXW, /**< local WB request from sharer, was OLSX */
    L2Cache_State_ILXW, /**< local WB request, was ILX */
    L2Cache_State_IFLS, /**< Blocked, forwarded local GETS to _some_ local sharer */
    L2Cache_State_IFLO, /**< Blocked, forwarded local GETS to local owner */
    L2Cache_State_IFLOX, /**< Blocked, forwarded local GETS to local owner but chip is exclusive */
    L2Cache_State_IFLOXX, /**< Blocked, forwarded local GETX to local owner/exclusive, chip is exclusive */
    L2Cache_State_IFLOSX, /**< Blocked, forwarded local GETS to local owner w/ other sharers, chip is exclusive */
    L2Cache_State_IFLXO, /**< Blocked, forwarded local GETX to local owner with other sharers, chip is exclusive */
    L2Cache_State_IGS, /**< Semi-blocked, issued local GETS to directory */
    L2Cache_State_IGM, /**< Blocked, issued local GETX to directory. Need global acks and data */
    L2Cache_State_IGMLS, /**< Blocked, issued local GETX to directory but may need to INV local sharers */
    L2Cache_State_IGMO, /**< Blocked, have data for local GETX but need all acks */
    L2Cache_State_IGMIO, /**< Blocked, issued local GETX, local owner with possible local sharer, may need to INV */
    L2Cache_State_OGMIO, /**< Blocked, issued local GETX, was owner, may need to INV */
    L2Cache_State_IGMIOF, /**< Blocked, issued local GETX, local owner, waiting for global acks, got Fwd_GETX */
    L2Cache_State_IGMIOFS, /**< Blocked, issued local GETX, local owner, waiting for global acks, got Fwd_GETS */
    L2Cache_State_OGMIOF, /**< Blocked, issued local GETX, was owner, waiting for global acks, got Fwd_GETX */
    L2Cache_State_II, /**< Blocked, handling invalidations */
    L2Cache_State_MM, /**< Blocked, was M satisfying local GETX */
    L2Cache_State_SS, /**< Blocked, was S satisfying local GETS */
    L2Cache_State_OO, /**< Blocked, was O satisfying local GETS */
    L2Cache_State_OLSS, /**< Blocked, satisfying local GETS */
    L2Cache_State_OLSXS, /**< Blocked, satisfying local GETS */
    L2Cache_State_SLSS, /**< Blocked, satisfying local GETS */
    L2Cache_State_OI, /**< Blocked, doing writeback, was O */
    L2Cache_State_MI, /**< Blocked, doing writeback, was M */
    L2Cache_State_MII, /**< Blocked, doing writeback, was M, got Fwd_GETX */
    L2Cache_State_OLSI, /**< Blocked, doing writeback, was OLS */
    L2Cache_State_ILSI, /**< Blocked, doing writeback, was OLS got Fwd_GETX */
    L2Cache_State_ILOSD, /**< Blocked, waiting for DMA ack */
    L2Cache_State_ILOSXD, /**< Blocked, waiting for DMA ack */
    L2Cache_State_ILOD, /**< Blocked, waiting for DMA ack */
    L2Cache_State_ILXD, /**< Blocked, waiting for DMA ack */
    L2Cache_State_ILOXD, /**< Blocked, waiting for DMA ack */
    L2Cache_State_NUM
};

// Code to convert from a string to the enumeration
L2Cache_State string_to_L2Cache_State(const std::string& str);

// Code to convert state to a string
std::string L2Cache_State_to_string(const L2Cache_State& obj);

// Code to increment an enumeration type
L2Cache_State &operator++(L2Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L2Cache_State_to_permission(const L2Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L2Cache_State& obj);

#endif // __L2Cache_State_HH__
