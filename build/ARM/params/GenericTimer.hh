#ifndef __PARAMS__GenericTimer__
#define __PARAMS__GenericTimer__

class GenericTimer;

#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ArmSystem.hh"

#include "params/ClockedObject.hh"

struct GenericTimerParams
    : public ClockedObjectParams
{
    GenericTimer * create();
    BaseGic * gic;
    uint32_t int_phys;
    uint32_t int_virt;
    ArmSystem * system;
};

#endif // __PARAMS__GenericTimer__
