/** \file HSASegment.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __HSASegment_HH__
#define __HSASegment_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum HSASegment
 *  \brief ...
 */
enum HSASegment {
    HSASegment_FIRST,
    HSASegment_GLOBAL = HSASegment_FIRST, /**< Global segment */
    HSASegment_GROUP, /**< Group segment */
    HSASegment_PRIVATE, /**< Private segment */
    HSASegment_KERNARG, /**< Kernarg segment */
    HSASegment_READONLY, /**< Readonly segment */
    HSASegment_SPILL, /**< Spill segment */
    HSASegment_ARG, /**< Arg segment */
    HSASegment_NUM
};

// Code to convert from a string to the enumeration
HSASegment string_to_HSASegment(const std::string& str);

// Code to convert state to a string
std::string HSASegment_to_string(const HSASegment& obj);

// Code to increment an enumeration type
HSASegment &operator++(HSASegment &e);
std::ostream& operator<<(std::ostream& out, const HSASegment& obj);

#endif // __HSASegment_HH__
