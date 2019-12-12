/** \file L2Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/L2Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L2Cache_Event& obj)
{
    out << L2Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L2Cache_Event_to_string(const L2Cache_Event& obj)
{
    switch(obj) {
      case L2Cache_Event_L1_GETS:
        return "L1_GETS";
      case L2Cache_Event_L1_GETX:
        return "L1_GETX";
      case L2Cache_Event_L1_PUTO:
        return "L1_PUTO";
      case L2Cache_Event_L1_PUTX:
        return "L1_PUTX";
      case L2Cache_Event_L1_PUTS_only:
        return "L1_PUTS_only";
      case L2Cache_Event_L1_PUTS:
        return "L1_PUTS";
      case L2Cache_Event_Fwd_GETX:
        return "Fwd_GETX";
      case L2Cache_Event_Fwd_GETS:
        return "Fwd_GETS";
      case L2Cache_Event_Fwd_DMA:
        return "Fwd_DMA";
      case L2Cache_Event_Own_GETX:
        return "Own_GETX";
      case L2Cache_Event_Inv:
        return "Inv";
      case L2Cache_Event_IntAck:
        return "IntAck";
      case L2Cache_Event_ExtAck:
        return "ExtAck";
      case L2Cache_Event_All_Acks:
        return "All_Acks";
      case L2Cache_Event_Data:
        return "Data";
      case L2Cache_Event_Data_Exclusive:
        return "Data_Exclusive";
      case L2Cache_Event_L1_WBCLEANDATA:
        return "L1_WBCLEANDATA";
      case L2Cache_Event_L1_WBDIRTYDATA:
        return "L1_WBDIRTYDATA";
      case L2Cache_Event_Writeback_Ack:
        return "Writeback_Ack";
      case L2Cache_Event_Writeback_Nack:
        return "Writeback_Nack";
      case L2Cache_Event_Unblock:
        return "Unblock";
      case L2Cache_Event_Exclusive_Unblock:
        return "Exclusive_Unblock";
      case L2Cache_Event_DmaAck:
        return "DmaAck";
      case L2Cache_Event_L2_Replacement:
        return "L2_Replacement";
      default:
        panic("Invalid range for type L2Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L2Cache_Event
string_to_L2Cache_Event(const string& str)
{
    if (str == "L1_GETS") {
        return L2Cache_Event_L1_GETS;
    } else if (str == "L1_GETX") {
        return L2Cache_Event_L1_GETX;
    } else if (str == "L1_PUTO") {
        return L2Cache_Event_L1_PUTO;
    } else if (str == "L1_PUTX") {
        return L2Cache_Event_L1_PUTX;
    } else if (str == "L1_PUTS_only") {
        return L2Cache_Event_L1_PUTS_only;
    } else if (str == "L1_PUTS") {
        return L2Cache_Event_L1_PUTS;
    } else if (str == "Fwd_GETX") {
        return L2Cache_Event_Fwd_GETX;
    } else if (str == "Fwd_GETS") {
        return L2Cache_Event_Fwd_GETS;
    } else if (str == "Fwd_DMA") {
        return L2Cache_Event_Fwd_DMA;
    } else if (str == "Own_GETX") {
        return L2Cache_Event_Own_GETX;
    } else if (str == "Inv") {
        return L2Cache_Event_Inv;
    } else if (str == "IntAck") {
        return L2Cache_Event_IntAck;
    } else if (str == "ExtAck") {
        return L2Cache_Event_ExtAck;
    } else if (str == "All_Acks") {
        return L2Cache_Event_All_Acks;
    } else if (str == "Data") {
        return L2Cache_Event_Data;
    } else if (str == "Data_Exclusive") {
        return L2Cache_Event_Data_Exclusive;
    } else if (str == "L1_WBCLEANDATA") {
        return L2Cache_Event_L1_WBCLEANDATA;
    } else if (str == "L1_WBDIRTYDATA") {
        return L2Cache_Event_L1_WBDIRTYDATA;
    } else if (str == "Writeback_Ack") {
        return L2Cache_Event_Writeback_Ack;
    } else if (str == "Writeback_Nack") {
        return L2Cache_Event_Writeback_Nack;
    } else if (str == "Unblock") {
        return L2Cache_Event_Unblock;
    } else if (str == "Exclusive_Unblock") {
        return L2Cache_Event_Exclusive_Unblock;
    } else if (str == "DmaAck") {
        return L2Cache_Event_DmaAck;
    } else if (str == "L2_Replacement") {
        return L2Cache_Event_L2_Replacement;
    } else {
        panic("Invalid string conversion for %s, type L2Cache_Event", str);
    }
}

// Code to increment an enumeration type
L2Cache_Event&
operator++(L2Cache_Event& e)
{
    assert(e < L2Cache_Event_NUM);
    return e = L2Cache_Event(e+1);
}
