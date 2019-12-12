/** \file HSASegment.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/HSASegment.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const HSASegment& obj)
{
    out << HSASegment_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
HSASegment_to_string(const HSASegment& obj)
{
    switch(obj) {
      case HSASegment_GLOBAL:
        return "GLOBAL";
      case HSASegment_GROUP:
        return "GROUP";
      case HSASegment_PRIVATE:
        return "PRIVATE";
      case HSASegment_KERNARG:
        return "KERNARG";
      case HSASegment_READONLY:
        return "READONLY";
      case HSASegment_SPILL:
        return "SPILL";
      case HSASegment_ARG:
        return "ARG";
      default:
        panic("Invalid range for type HSASegment");
    }
}

// Code to convert from a string to the enumeration
HSASegment
string_to_HSASegment(const string& str)
{
    if (str == "GLOBAL") {
        return HSASegment_GLOBAL;
    } else if (str == "GROUP") {
        return HSASegment_GROUP;
    } else if (str == "PRIVATE") {
        return HSASegment_PRIVATE;
    } else if (str == "KERNARG") {
        return HSASegment_KERNARG;
    } else if (str == "READONLY") {
        return HSASegment_READONLY;
    } else if (str == "SPILL") {
        return HSASegment_SPILL;
    } else if (str == "ARG") {
        return HSASegment_ARG;
    } else {
        panic("Invalid string conversion for %s, type HSASegment", str);
    }
}

// Code to increment an enumeration type
HSASegment&
operator++(HSASegment& e)
{
    assert(e < HSASegment_NUM);
    return e = HSASegment(e+1);
}
