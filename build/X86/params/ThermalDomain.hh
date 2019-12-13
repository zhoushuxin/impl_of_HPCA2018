#ifndef __PARAMS__ThermalDomain__
#define __PARAMS__ThermalDomain__

class ThermalDomain;

#include <cstddef>

#include "params/SimObject.hh"

struct ThermalDomainParams
    : public SimObjectParams
{
    ThermalDomain * create();
    double initial_temperature;
};

#endif // __PARAMS__ThermalDomain__
