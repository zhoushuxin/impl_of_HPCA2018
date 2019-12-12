#ifndef __PARAMS__GenericArmPciHost__
#define __PARAMS__GenericArmPciHost__

class GenericArmPciHost;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/ArmPciIntRouting.hh"

#include "params/GenericPciHost.hh"

#include "enums/ArmPciIntRouting.hh"

struct GenericArmPciHostParams
    : public GenericPciHostParams
{
    GenericArmPciHost * create();
    unsigned int_base;
    unsigned int_count;
    Enums::ArmPciIntRouting int_policy;
};

#endif // __PARAMS__GenericArmPciHost__
