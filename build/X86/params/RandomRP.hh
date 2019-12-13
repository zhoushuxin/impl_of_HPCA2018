#ifndef __PARAMS__RandomRP__
#define __PARAMS__RandomRP__

class RandomRP;


#include "params/BaseReplacementPolicy.hh"

struct RandomRPParams
    : public BaseReplacementPolicyParams
{
    RandomRP * create();
};

#endif // __PARAMS__RandomRP__
