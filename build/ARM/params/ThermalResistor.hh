#ifndef __PARAMS__ThermalResistor__
#define __PARAMS__ThermalResistor__

class ThermalResistor;

#include <cstddef>

#include "params/SimObject.hh"

struct ThermalResistorParams
    : public SimObjectParams
{
    ThermalResistor * create();
    double resistance;
};

#endif // __PARAMS__ThermalResistor__
