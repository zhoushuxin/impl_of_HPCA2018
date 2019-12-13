#ifndef __PARAMS__Uart__
#define __PARAMS__Uart__

class Uart;

#include <cstddef>
#include "params/SerialDevice.hh"
#include <cstddef>
#include "params/Platform.hh"

#include "params/BasicPioDevice.hh"

struct UartParams
    : public BasicPioDeviceParams
{
    SerialDevice * device;
    Platform * platform;
};

#endif // __PARAMS__Uart__
