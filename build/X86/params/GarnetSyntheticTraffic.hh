#ifndef __PARAMS__GarnetSyntheticTraffic__
#define __PARAMS__GarnetSyntheticTraffic__

class GarnetSyntheticTraffic;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include <string>

#include "params/MemObject.hh"

struct GarnetSyntheticTrafficParams
    : public MemObjectParams
{
    GarnetSyntheticTraffic * create();
    int block_offset;
    double inj_rate;
    int inj_vnet;
    int memory_size;
    int num_dest;
    int num_packets_max;
    int precision;
    Cycles response_limit;
    int sim_cycles;
    int single_dest;
    int single_sender;
    System * system;
    std::string traffic_type;
    unsigned int port_test_connection_count;
};

#endif // __PARAMS__GarnetSyntheticTraffic__
