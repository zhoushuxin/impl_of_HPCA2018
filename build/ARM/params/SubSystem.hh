#ifndef __PARAMS__SubSystem__
#define __PARAMS__SubSystem__

class SubSystem;

#include <cstddef>
#include "params/ThermalDomain.hh"

#include "params/SimObject.hh"

struct SubSystemParams
    : public SimObjectParams
{
    SubSystem * create();
    ThermalDomain * thermal_domain;
};

#endif // __PARAMS__SubSystem__
