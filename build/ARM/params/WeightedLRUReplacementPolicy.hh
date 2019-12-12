#ifndef __PARAMS__WeightedLRUReplacementPolicy__
#define __PARAMS__WeightedLRUReplacementPolicy__

class WeightedLRUPolicy;

#include <cstddef>
#include "params/RubyCache.hh"

#include "params/ReplacementPolicy.hh"

struct WeightedLRUReplacementPolicyParams
    : public ReplacementPolicyParams
{
    WeightedLRUPolicy * create();
    CacheMemory * cache;
};

#endif // __PARAMS__WeightedLRUReplacementPolicy__
