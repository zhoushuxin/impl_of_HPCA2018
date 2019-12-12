#ifndef __PARAMS__RubySequencer__
#define __PARAMS__RubySequencer__

class Sequencer;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/RubyPort.hh"

struct RubySequencerParams
    : public RubyPortParams
{
    Sequencer * create();
    int coreid;
    CacheMemory * dcache;
    Cycles dcache_hit_latency;
    Cycles deadlock_threshold;
    bool garnet_standalone;
    CacheMemory * icache;
    Cycles icache_hit_latency;
    int max_outstanding_requests;
};

#endif // __PARAMS__RubySequencer__
