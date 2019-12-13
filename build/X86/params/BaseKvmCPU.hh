#ifndef __PARAMS__BaseKvmCPU__
#define __PARAMS__BaseKvmCPU__

class BaseKvmCPU;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>

#include "params/BaseCPU.hh"

struct BaseKvmCPUParams
    : public BaseCPUParams
{
    bool alwaysSyncTC;
    double hostFactor;
    Tick hostFreq;
    bool useCoalescedMMIO;
    bool usePerfOverflow;
};

#endif // __PARAMS__BaseKvmCPU__
