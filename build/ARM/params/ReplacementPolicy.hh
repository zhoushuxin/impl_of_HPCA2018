#ifndef __PARAMS__ReplacementPolicy__
#define __PARAMS__ReplacementPolicy__

class AbstractReplacementPolicy;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct ReplacementPolicyParams
    : public SimObjectParams
{
    AbstractReplacementPolicy * create();
    int assoc;
    int block_size;
    uint64_t size;
};

#endif // __PARAMS__ReplacementPolicy__
