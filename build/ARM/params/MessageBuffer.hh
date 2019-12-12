#ifndef __PARAMS__MessageBuffer__
#define __PARAMS__MessageBuffer__

class MessageBuffer;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>

#include "params/SimObject.hh"

struct MessageBufferParams
    : public SimObjectParams
{
    MessageBuffer * create();
    unsigned buffer_size;
    bool ordered;
    bool randomization;
    unsigned int port_master_connection_count;
    unsigned int port_slave_connection_count;
};

#endif // __PARAMS__MessageBuffer__
