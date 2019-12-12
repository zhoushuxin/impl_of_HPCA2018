#ifndef __PARAMS__A9GlobalTimer__
#define __PARAMS__A9GlobalTimer__

class A9GlobalTimer;

#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct A9GlobalTimerParams
    : public BasicPioDeviceParams
{
    A9GlobalTimer * create();
    BaseGic * gic;
    uint32_t int_num;
};

#endif // __PARAMS__A9GlobalTimer__
