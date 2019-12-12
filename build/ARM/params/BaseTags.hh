#ifndef __PARAMS__BaseTags__
#define __PARAMS__BaseTags__

class BaseTags;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct BaseTagsParams
    : public ClockedObjectParams
{
    int block_size;
    Cycles data_latency;
    bool sequential_access;
    uint64_t size;
    Cycles tag_latency;
    int warmup_percentage;
};

#endif // __PARAMS__BaseTags__
