#ifndef __PARAMS__EtherSwitch__
#define __PARAMS__EtherSwitch__

class EtherSwitch;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/EtherDump.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/EtherObject.hh"

struct EtherSwitchParams
    : public EtherObjectParams
{
    EtherSwitch * create();
    Tick delay;
    Tick delay_var;
    EtherDump * dump;
    float fabric_speed;
    uint64_t output_buffer_size;
    Tick time_to_live;
    unsigned int port_interface_connection_count;
};

#endif // __PARAMS__EtherSwitch__
