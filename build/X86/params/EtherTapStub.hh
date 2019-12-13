#ifndef __PARAMS__EtherTapStub__
#define __PARAMS__EtherTapStub__

class EtherTapStub;

#include <cstddef>
#include "base/types.hh"

#include "params/EtherTapBase.hh"

struct EtherTapStubParams
    : public EtherTapBaseParams
{
    EtherTapStub * create();
    uint16_t port;
};

#endif // __PARAMS__EtherTapStub__
