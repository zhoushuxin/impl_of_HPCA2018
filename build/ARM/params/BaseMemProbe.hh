#ifndef __PARAMS__BaseMemProbe__
#define __PARAMS__BaseMemProbe__

class BaseMemProbe;

#include <vector>
#include "params/SimObject.hh"
#include <cstddef>
#include <string>

#include "params/SimObject.hh"

struct BaseMemProbeParams
    : public SimObjectParams
{
    std::vector< SimObject * > manager;
    std::string probe_name;
};

#endif // __PARAMS__BaseMemProbe__
