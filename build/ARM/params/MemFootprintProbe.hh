#ifndef __PARAMS__MemFootprintProbe__
#define __PARAMS__MemFootprintProbe__

class MemFootprintProbe;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/BaseMemProbe.hh"

struct MemFootprintProbeParams
    : public BaseMemProbeParams
{
    MemFootprintProbe * create();
    unsigned page_size;
    System * system;
};

#endif // __PARAMS__MemFootprintProbe__
