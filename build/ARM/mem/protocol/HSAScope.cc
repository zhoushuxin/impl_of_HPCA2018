/** \file HSAScope.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/HSAScope.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const HSAScope& obj)
{
    out << HSAScope_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
HSAScope_to_string(const HSAScope& obj)
{
    switch(obj) {
      case HSAScope_UNSPECIFIED:
        return "UNSPECIFIED";
      case HSAScope_NOSCOPE:
        return "NOSCOPE";
      case HSAScope_WAVEFRONT:
        return "WAVEFRONT";
      case HSAScope_WORKGROUP:
        return "WORKGROUP";
      case HSAScope_DEVICE:
        return "DEVICE";
      case HSAScope_SYSTEM:
        return "SYSTEM";
      default:
        panic("Invalid range for type HSAScope");
    }
}

// Code to convert from a string to the enumeration
HSAScope
string_to_HSAScope(const string& str)
{
    if (str == "UNSPECIFIED") {
        return HSAScope_UNSPECIFIED;
    } else if (str == "NOSCOPE") {
        return HSAScope_NOSCOPE;
    } else if (str == "WAVEFRONT") {
        return HSAScope_WAVEFRONT;
    } else if (str == "WORKGROUP") {
        return HSAScope_WORKGROUP;
    } else if (str == "DEVICE") {
        return HSAScope_DEVICE;
    } else if (str == "SYSTEM") {
        return HSAScope_SYSTEM;
    } else {
        panic("Invalid string conversion for %s, type HSAScope", str);
    }
}

// Code to increment an enumeration type
HSAScope&
operator++(HSAScope& e)
{
    assert(e < HSAScope_NUM);
    return e = HSAScope(e+1);
}
