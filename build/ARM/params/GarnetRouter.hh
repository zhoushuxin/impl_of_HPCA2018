#ifndef __PARAMS__GarnetRouter__
#define __PARAMS__GarnetRouter__

class Router;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicRouter.hh"

struct GarnetRouterParams
    : public BasicRouterParams
{
    Router * create();
    uint32_t vcs_per_vnet;
    uint32_t virt_nets;
};

#endif // __PARAMS__GarnetRouter__
