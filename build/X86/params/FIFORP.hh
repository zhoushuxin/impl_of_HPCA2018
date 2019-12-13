#ifndef __PARAMS__FIFORP__
#define __PARAMS__FIFORP__

class FIFORP;


#include "params/BaseReplacementPolicy.hh"

struct FIFORPParams
    : public BaseReplacementPolicyParams
{
    FIFORP * create();
};

#endif // __PARAMS__FIFORP__
