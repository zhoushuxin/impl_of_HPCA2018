#ifndef __PARAMS__ThermalReference__
#define __PARAMS__ThermalReference__

class ThermalReference;

#include <cstddef>

#include "params/SimObject.hh"

struct ThermalReferenceParams
    : public SimObjectParams
{
    ThermalReference * create();
    double temperature;
};

#endif // __PARAMS__ThermalReference__
