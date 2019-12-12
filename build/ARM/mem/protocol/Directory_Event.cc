/** \file Directory_Event.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/Directory_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const Directory_Event& obj)
{
    out << Directory_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
Directory_Event_to_string(const Directory_Event& obj)
{
    switch(obj) {
      case Directory_Event_GETX:
        return "GETX";
      case Directory_Event_GETS:
        return "GETS";
      case Directory_Event_PUTX:
        return "PUTX";
      case Directory_Event_PUTO:
        return "PUTO";
      case Directory_Event_PUTO_SHARERS:
        return "PUTO_SHARERS";
      case Directory_Event_Unblock:
        return "Unblock";
      case Directory_Event_Last_Unblock:
        return "Last_Unblock";
      case Directory_Event_Exclusive_Unblock:
        return "Exclusive_Unblock";
      case Directory_Event_Clean_Writeback:
        return "Clean_Writeback";
      case Directory_Event_Dirty_Writeback:
        return "Dirty_Writeback";
      case Directory_Event_Memory_Data:
        return "Memory_Data";
      case Directory_Event_Memory_Ack:
        return "Memory_Ack";
      case Directory_Event_DMA_READ:
        return "DMA_READ";
      case Directory_Event_DMA_WRITE:
        return "DMA_WRITE";
      case Directory_Event_DMA_ACK:
        return "DMA_ACK";
      case Directory_Event_Data:
        return "Data";
      default:
        panic("Invalid range for type Directory_Event");
    }
}

// Code to convert from a string to the enumeration
Directory_Event
string_to_Directory_Event(const string& str)
{
    if (str == "GETX") {
        return Directory_Event_GETX;
    } else if (str == "GETS") {
        return Directory_Event_GETS;
    } else if (str == "PUTX") {
        return Directory_Event_PUTX;
    } else if (str == "PUTO") {
        return Directory_Event_PUTO;
    } else if (str == "PUTO_SHARERS") {
        return Directory_Event_PUTO_SHARERS;
    } else if (str == "Unblock") {
        return Directory_Event_Unblock;
    } else if (str == "Last_Unblock") {
        return Directory_Event_Last_Unblock;
    } else if (str == "Exclusive_Unblock") {
        return Directory_Event_Exclusive_Unblock;
    } else if (str == "Clean_Writeback") {
        return Directory_Event_Clean_Writeback;
    } else if (str == "Dirty_Writeback") {
        return Directory_Event_Dirty_Writeback;
    } else if (str == "Memory_Data") {
        return Directory_Event_Memory_Data;
    } else if (str == "Memory_Ack") {
        return Directory_Event_Memory_Ack;
    } else if (str == "DMA_READ") {
        return Directory_Event_DMA_READ;
    } else if (str == "DMA_WRITE") {
        return Directory_Event_DMA_WRITE;
    } else if (str == "DMA_ACK") {
        return Directory_Event_DMA_ACK;
    } else if (str == "Data") {
        return Directory_Event_Data;
    } else {
        panic("Invalid string conversion for %s, type Directory_Event", str);
    }
}

// Code to increment an enumeration type
Directory_Event&
operator++(Directory_Event& e)
{
    assert(e < Directory_Event_NUM);
    return e = Directory_Event(e+1);
}
