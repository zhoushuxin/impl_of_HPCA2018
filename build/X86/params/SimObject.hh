#ifndef __PARAMS__SimObject__
#define __PARAMS__SimObject__

#include <string>
class SimObject;

#include <cstddef>
#include "base/types.hh"

struct SimObjectParams
{
        SimObjectParams() {}
        virtual ~SimObjectParams() {}

        std::string name;
                
    uint32_t eventq_index;
};

#endif // __PARAMS__SimObject__
