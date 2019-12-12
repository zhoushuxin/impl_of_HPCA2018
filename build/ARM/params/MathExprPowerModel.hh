#ifndef __PARAMS__MathExprPowerModel__
#define __PARAMS__MathExprPowerModel__

class MathExprPowerModel;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/PowerModelState.hh"

struct MathExprPowerModelParams
    : public PowerModelStateParams
{
    MathExprPowerModel * create();
    std::string dyn;
    std::string st;
};

#endif // __PARAMS__MathExprPowerModel__
