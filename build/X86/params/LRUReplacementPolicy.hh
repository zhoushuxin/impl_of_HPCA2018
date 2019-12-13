#ifndef __PARAMS__LRUReplacementPolicy__
#define __PARAMS__LRUReplacementPolicy__

class LRUPolicy;


#include "params/ReplacementPolicy.hh"

struct LRUReplacementPolicyParams
    : public ReplacementPolicyParams
{
    LRUPolicy * create();
};

#endif // __PARAMS__LRUReplacementPolicy__
