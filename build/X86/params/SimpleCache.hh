#ifndef __PARAMS__SimpleCache__
#define __PARAMS__SimpleCache__

class SimpleCache;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/MemObject.hh"

struct SimpleCacheParams
    : public MemObjectParams
{
    SimpleCache * create();
    Cycles latency;
    uint64_t size;
    System * system;
    unsigned int port_mem_side_connection_count;
    unsigned int port_cpu_side_connection_count;
};

#endif // __PARAMS__SimpleCache__
