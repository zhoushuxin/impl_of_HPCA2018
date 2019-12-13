#ifndef __PARAMS__GoodbyeObject__
#define __PARAMS__GoodbyeObject__

class GoodbyeObject;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

struct GoodbyeObjectParams
    : public SimObjectParams
{
    GoodbyeObject * create();
    uint64_t buffer_size;
    float write_bandwidth;
};

#endif // __PARAMS__GoodbyeObject__
