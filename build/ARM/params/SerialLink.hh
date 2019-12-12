#ifndef __PARAMS__SerialLink__
#define __PARAMS__SerialLink__

class SerialLink;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct SerialLinkParams
    : public MemObjectParams
{
    SerialLink * create();
    Tick delay;
    uint64_t link_speed;
    unsigned num_lanes;
    std::vector< AddrRange > ranges;
    unsigned req_size;
    unsigned resp_size;
    unsigned int port_master_connection_count;
    unsigned int port_slave_connection_count;
};

#endif // __PARAMS__SerialLink__
