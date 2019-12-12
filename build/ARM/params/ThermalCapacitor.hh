#ifndef __PARAMS__ThermalCapacitor__
#define __PARAMS__ThermalCapacitor__

class ThermalCapacitor;

#include <cstddef>

#include "params/SimObject.hh"

struct ThermalCapacitorParams
    : public SimObjectParams
{
    ThermalCapacitor * create();
    double capacitance;
};

#endif // __PARAMS__ThermalCapacitor__
