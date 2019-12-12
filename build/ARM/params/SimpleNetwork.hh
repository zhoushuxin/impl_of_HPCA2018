#ifndef __PARAMS__SimpleNetwork__
#define __PARAMS__SimpleNetwork__

class SimpleNetwork;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/MessageBuffer.hh"

#include "params/RubyNetwork.hh"

struct SimpleNetworkParams
    : public RubyNetworkParams
{
    SimpleNetwork * create();
    bool adaptive_routing;
    int buffer_size;
    int endpoint_bandwidth;
    std::vector< MessageBuffer * > int_link_buffers;
};

#endif // __PARAMS__SimpleNetwork__
