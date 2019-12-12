#ifndef __PARAMS__LRURP__
#define __PARAMS__LRURP__

class LRURP;


#include "params/BaseReplacementPolicy.hh"

struct LRURPParams
    : public BaseReplacementPolicyParams
{
    LRURP * create();
};

#endif // __PARAMS__LRURP__
