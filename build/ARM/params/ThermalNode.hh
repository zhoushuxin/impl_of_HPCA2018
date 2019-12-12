#ifndef __PARAMS__ThermalNode__
#define __PARAMS__ThermalNode__

class ThermalNode;


#include "params/SimObject.hh"

struct ThermalNodeParams
    : public SimObjectParams
{
    ThermalNode * create();
};

#endif // __PARAMS__ThermalNode__
