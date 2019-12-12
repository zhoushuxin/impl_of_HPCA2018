#ifndef __PARAMS__EtherTapBase__
#define __PARAMS__EtherTapBase__

class EtherTapBase;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/EtherDump.hh"

#include "params/EtherObject.hh"

struct EtherTapBaseParams
    : public EtherObjectParams
{
    int bufsz;
    EtherDump * dump;
    unsigned int port_tap_connection_count;
};

#endif // __PARAMS__EtherTapBase__
