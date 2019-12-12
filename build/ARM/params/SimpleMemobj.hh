#ifndef __PARAMS__SimpleMemobj__
#define __PARAMS__SimpleMemobj__

class SimpleMemobj;


#include "params/MemObject.hh"

struct SimpleMemobjParams
    : public MemObjectParams
{
    SimpleMemobj * create();
    unsigned int port_mem_side_connection_count;
    unsigned int port_data_port_connection_count;
    unsigned int port_inst_port_connection_count;
};

#endif // __PARAMS__SimpleMemobj__
