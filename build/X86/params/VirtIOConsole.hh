#ifndef __PARAMS__VirtIOConsole__
#define __PARAMS__VirtIOConsole__

class VirtIOConsole;

#include <cstddef>
#include "params/SerialDevice.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/VirtIODeviceBase.hh"

struct VirtIOConsoleParams
    : public VirtIODeviceBaseParams
{
    VirtIOConsole * create();
    SerialDevice * device;
    unsigned qRecvSize;
    unsigned qTransSize;
};

#endif // __PARAMS__VirtIOConsole__
