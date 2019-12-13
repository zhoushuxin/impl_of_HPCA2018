/** \file TransitionResult.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:457
 */

#ifndef __TransitionResult_HH__
#define __TransitionResult_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum TransitionResult
 *  \brief ...
 */
enum TransitionResult {
    TransitionResult_FIRST,
    TransitionResult_Valid = TransitionResult_FIRST, /**< Valid transition */
    TransitionResult_ResourceStall, /**< Stalled due to insufficient resources */
    TransitionResult_ProtocolStall, /**< Protocol specified stall */
    TransitionResult_Reject, /**< Rejected because of a type mismatch */
    TransitionResult_NUM
};

// Code to convert from a string to the enumeration
TransitionResult string_to_TransitionResult(const std::string& str);

// Code to convert state to a string
std::string TransitionResult_to_string(const TransitionResult& obj);

// Code to increment an enumeration type
TransitionResult &operator++(TransitionResult &e);
std::ostream& operator<<(std::ostream& out, const TransitionResult& obj);

#endif // __TransitionResult_HH__
