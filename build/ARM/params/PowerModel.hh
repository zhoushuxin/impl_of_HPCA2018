#ifndef __PARAMS__PowerModel__
#define __PARAMS__PowerModel__

class PowerModel;

#include <cstddef>
#include <vector>
#include "params/PowerModelState.hh"
#include <cstddef>
#include "enums/PMType.hh"
#include <cstddef>
#include "params/SubSystem.hh"

#include "params/SimObject.hh"

#include "enums/PMType.hh"

struct PowerModelParams
    : public SimObjectParams
{
    PowerModel * create();
    double ambient_temp;
    std::vector< PowerModelState * > pm;
    Enums::PMType pm_type;
    SubSystem * subsystem;
};

#endif // __PARAMS__PowerModel__
