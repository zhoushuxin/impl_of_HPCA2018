#ifndef __PARAMS__ClockedObject__
#define __PARAMS__ClockedObject__

class ClockedObject;

#include <cstddef>
#include "params/ClockDomain.hh"
#include <cstddef>
#include "enums/PwrState.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/PowerModel.hh"

#include "params/SimObject.hh"

#include "enums/PwrState.hh"

struct ClockedObjectParams
    : public SimObjectParams
{
    ClockDomain * clk_domain;
    Enums::PwrState default_p_state;
    unsigned p_state_clk_gate_bins;
    Tick p_state_clk_gate_max;
    Tick p_state_clk_gate_min;
    std::vector< PowerModel * > power_model;
};

#endif // __PARAMS__ClockedObject__
