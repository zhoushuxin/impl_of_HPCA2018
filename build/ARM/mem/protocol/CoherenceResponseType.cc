/** \file CoherenceResponseType.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/CoherenceResponseType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const CoherenceResponseType& obj)
{
    out << CoherenceResponseType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
CoherenceResponseType_to_string(const CoherenceResponseType& obj)
{
    switch(obj) {
      case CoherenceResponseType_ACK:
        return "ACK";
      case CoherenceResponseType_DATA:
        return "DATA";
      case CoherenceResponseType_DATA_EXCLUSIVE:
        return "DATA_EXCLUSIVE";
      case CoherenceResponseType_UNBLOCK:
        return "UNBLOCK";
      case CoherenceResponseType_UNBLOCK_EXCLUSIVE:
        return "UNBLOCK_EXCLUSIVE";
      case CoherenceResponseType_WRITEBACK_CLEAN_DATA:
        return "WRITEBACK_CLEAN_DATA";
      case CoherenceResponseType_WRITEBACK_CLEAN_ACK:
        return "WRITEBACK_CLEAN_ACK";
      case CoherenceResponseType_WRITEBACK_DIRTY_DATA:
        return "WRITEBACK_DIRTY_DATA";
      case CoherenceResponseType_DMA_ACK:
        return "DMA_ACK";
      default:
        panic("Invalid range for type CoherenceResponseType");
    }
}

// Code to convert from a string to the enumeration
CoherenceResponseType
string_to_CoherenceResponseType(const string& str)
{
    if (str == "ACK") {
        return CoherenceResponseType_ACK;
    } else if (str == "DATA") {
        return CoherenceResponseType_DATA;
    } else if (str == "DATA_EXCLUSIVE") {
        return CoherenceResponseType_DATA_EXCLUSIVE;
    } else if (str == "UNBLOCK") {
        return CoherenceResponseType_UNBLOCK;
    } else if (str == "UNBLOCK_EXCLUSIVE") {
        return CoherenceResponseType_UNBLOCK_EXCLUSIVE;
    } else if (str == "WRITEBACK_CLEAN_DATA") {
        return CoherenceResponseType_WRITEBACK_CLEAN_DATA;
    } else if (str == "WRITEBACK_CLEAN_ACK") {
        return CoherenceResponseType_WRITEBACK_CLEAN_ACK;
    } else if (str == "WRITEBACK_DIRTY_DATA") {
        return CoherenceResponseType_WRITEBACK_DIRTY_DATA;
    } else if (str == "DMA_ACK") {
        return CoherenceResponseType_DMA_ACK;
    } else {
        panic("Invalid string conversion for %s, type CoherenceResponseType", str);
    }
}

// Code to increment an enumeration type
CoherenceResponseType&
operator++(CoherenceResponseType& e)
{
    assert(e < CoherenceResponseType_NUM);
    return e = CoherenceResponseType(e+1);
}
