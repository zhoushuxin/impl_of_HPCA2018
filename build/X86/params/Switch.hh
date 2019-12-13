#ifndef __PARAMS__Switch__
#define __PARAMS__Switch__

class Switch;

#include <vector>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicRouter.hh"

struct SwitchParams
    : public BasicRouterParams
{
    Switch * create();
    std::vector< MessageBuffer * > port_buffers;
    int virt_nets;
};

#endif // __PARAMS__Switch__
