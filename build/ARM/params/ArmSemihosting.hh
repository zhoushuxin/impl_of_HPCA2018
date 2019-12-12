#ifndef __PARAMS__ArmSemihosting__
#define __PARAMS__ArmSemihosting__

class ArmSemihosting;

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <time.h>

#include "params/SimObject.hh"

struct ArmSemihostingParams
    : public SimObjectParams
{
    ArmSemihosting * create();
    std::string cmd_line;
    uint64_t mem_reserve;
    uint64_t stack_size;
    tm time;
};

#endif // __PARAMS__ArmSemihosting__
