#ifndef __PARAMS__RealViewOsc__
#define __PARAMS__RealViewOsc__

class RealViewOsc;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RealViewCtrl.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/VoltageDomain.hh"

#include "params/ClockDomain.hh"

struct RealViewOscParams
    : public ClockDomainParams
{
    RealViewOsc * create();
    uint8_t dcc;
    uint8_t device;
    Tick freq;
    RealViewCtrl * parent;
    uint8_t position;
    uint8_t site;
    VoltageDomain * voltage_domain;
};

#endif // __PARAMS__RealViewOsc__
