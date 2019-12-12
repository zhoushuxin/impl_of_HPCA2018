#ifndef __PARAMS__RealViewTemperatureSensor__
#define __PARAMS__RealViewTemperatureSensor__

class RealViewTemperatureSensor;

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
#include "params/System.hh"

#include "params/SimObject.hh"

struct RealViewTemperatureSensorParams
    : public SimObjectParams
{
    RealViewTemperatureSensor * create();
    uint8_t dcc;
    uint8_t device;
    RealViewCtrl * parent;
    uint8_t position;
    uint8_t site;
    System * system;
};

#endif // __PARAMS__RealViewTemperatureSensor__
