#ifndef __PARAMS__MRURP__
#define __PARAMS__MRURP__

class MRURP;


#include "params/BaseReplacementPolicy.hh"

struct MRURPParams
    : public BaseReplacementPolicyParams
{
    MRURP * create();
};

#endif // __PARAMS__MRURP__
