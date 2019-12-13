#ifndef __PARAMS__BaseCache__
#define __PARAMS__BaseCache__

class BaseCache;

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "base/types.hh"
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
#include <cstddef>
#include "params/BasePrefetcher.hh"
#include <cstddef>
#include "params/BaseReplacementPolicy.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseTags.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct BaseCacheParams
    : public MemObjectParams
{
    std::vector< AddrRange > addr_ranges;
    unsigned assoc;
    Cycles data_latency;
    unsigned demand_mshr_reserve;
    bool is_read_only;
    Counter max_miss_count;
    unsigned mshrs;
    bool prefetch_on_access;
    BasePrefetcher * prefetcher;
    BaseReplacementPolicy * replacement_policy;
    Cycles response_latency;
    bool sequential_access;
    uint64_t size;
    System * system;
    Cycles tag_latency;
    BaseTags * tags;
    unsigned tgts_per_mshr;
    int warmup_percentage;
    unsigned write_buffers;
    unsigned int port_mem_side_connection_count;
    unsigned int port_cpu_side_connection_count;
};

#endif // __PARAMS__BaseCache__
