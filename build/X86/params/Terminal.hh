#ifndef __PARAMS__Terminal__
#define __PARAMS__Terminal__

class Terminal;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/SerialDevice.hh"

struct TerminalParams
    : public SerialDeviceParams
{
    Terminal * create();
    int number;
    bool output;
    uint16_t port;
};

#endif // __PARAMS__Terminal__
