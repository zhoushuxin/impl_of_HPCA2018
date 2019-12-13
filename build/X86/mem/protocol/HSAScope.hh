/** \file HSAScope.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __HSAScope_HH__
#define __HSAScope_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum HSAScope
 *  \brief ...
 */
enum HSAScope {
    HSAScope_FIRST,
    HSAScope_UNSPECIFIED = HSAScope_FIRST, /**< Unspecified scope */
    HSAScope_NOSCOPE, /**< Explictly unscoped */
    HSAScope_WAVEFRONT, /**< Wavefront scope */
    HSAScope_WORKGROUP, /**< Workgroup scope */
    HSAScope_DEVICE, /**< Device scope */
    HSAScope_SYSTEM, /**< System scope */
    HSAScope_NUM
};

// Code to convert from a string to the enumeration
HSAScope string_to_HSAScope(const std::string& str);

// Code to convert state to a string
std::string HSAScope_to_string(const HSAScope& obj);

// Code to increment an enumeration type
HSAScope &operator++(HSAScope &e);
std::ostream& operator<<(std::ostream& out, const HSAScope& obj);

#endif // __HSAScope_HH__
