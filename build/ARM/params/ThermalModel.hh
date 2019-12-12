#ifndef __PARAMS__ThermalModel__
#define __PARAMS__ThermalModel__

class ThermalModel;

#include <cstddef>

#include "params/ClockedObject.hh"

struct ThermalModelParams
    : public ClockedObjectParams
{
    ThermalModel * create();
    double step;
};

#endif // __PARAMS__ThermalModel__
