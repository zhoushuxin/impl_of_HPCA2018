#ifndef __PARAMS__RubyCache__
#define __PARAMS__RubyCache__

class CacheMemory;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/ReplacementPolicy.hh"
#include <cstddef>
#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct RubyCacheParams
    : public SimObjectParams
{
    CacheMemory * create();
    int assoc;
    uint64_t block_size;
    Cycles dataAccessLatency;
    int dataArrayBanks;
    bool is_icache;
    AbstractReplacementPolicy * replacement_policy;
    bool resourceStalls;
    RubySystem * ruby_system;
    uint64_t size;
    int start_index_bit;
    Cycles tagAccessLatency;
    int tagArrayBanks;
};

#endif // __PARAMS__RubyCache__
