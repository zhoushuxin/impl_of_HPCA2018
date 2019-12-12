/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/L1Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_Event& obj)
{
    out << L1Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_Event_to_string(const L1Cache_Event& obj)
{
    switch(obj) {
      case L1Cache_Event_Load:
        return "Load";
      case L1Cache_Event_Ifetch:
        return "Ifetch";
      case L1Cache_Event_Store:
        return "Store";
      case L1Cache_Event_L1_Replacement:
        return "L1_Replacement";
      case L1Cache_Event_Own_GETX:
        return "Own_GETX";
      case L1Cache_Event_Fwd_GETX:
        return "Fwd_GETX";
      case L1Cache_Event_Fwd_GETS:
        return "Fwd_GETS";
      case L1Cache_Event_Fwd_DMA:
        return "Fwd_DMA";
      case L1Cache_Event_Inv:
        return "Inv";
      case L1Cache_Event_Ack:
        return "Ack";
      case L1Cache_Event_Data:
        return "Data";
      case L1Cache_Event_Exclusive_Data:
        return "Exclusive_Data";
      case L1Cache_Event_Writeback_Ack:
        return "Writeback_Ack";
      case L1Cache_Event_Writeback_Ack_Data:
        return "Writeback_Ack_Data";
      case L1Cache_Event_Writeback_Nack:
        return "Writeback_Nack";
      case L1Cache_Event_All_acks:
        return "All_acks";
      case L1Cache_Event_Use_Timeout:
        return "Use_Timeout";
      default:
        panic("Invalid range for type L1Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L1Cache_Event
string_to_L1Cache_Event(const string& str)
{
    if (str == "Load") {
        return L1Cache_Event_Load;
    } else if (str == "Ifetch") {
        return L1Cache_Event_Ifetch;
    } else if (str == "Store") {
        return L1Cache_Event_Store;
    } else if (str == "L1_Replacement") {
        return L1Cache_Event_L1_Replacement;
    } else if (str == "Own_GETX") {
        return L1Cache_Event_Own_GETX;
    } else if (str == "Fwd_GETX") {
        return L1Cache_Event_Fwd_GETX;
    } else if (str == "Fwd_GETS") {
        return L1Cache_Event_Fwd_GETS;
    } else if (str == "Fwd_DMA") {
        return L1Cache_Event_Fwd_DMA;
    } else if (str == "Inv") {
        return L1Cache_Event_Inv;
    } else if (str == "Ack") {
        return L1Cache_Event_Ack;
    } else if (str == "Data") {
        return L1Cache_Event_Data;
    } else if (str == "Exclusive_Data") {
        return L1Cache_Event_Exclusive_Data;
    } else if (str == "Writeback_Ack") {
        return L1Cache_Event_Writeback_Ack;
    } else if (str == "Writeback_Ack_Data") {
        return L1Cache_Event_Writeback_Ack_Data;
    } else if (str == "Writeback_Nack") {
        return L1Cache_Event_Writeback_Nack;
    } else if (str == "All_acks") {
        return L1Cache_Event_All_acks;
    } else if (str == "Use_Timeout") {
        return L1Cache_Event_Use_Timeout;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_Event", str);
    }
}

// Code to increment an enumeration type
L1Cache_Event&
operator++(L1Cache_Event& e)
{
    assert(e < L1Cache_Event_NUM);
    return e = L1Cache_Event(e+1);
}
