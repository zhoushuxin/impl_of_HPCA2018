#ifndef __PARAMS__NoMaliGpu__
#define __PARAMS__NoMaliGpu__

class NoMaliGpu;

#include <cstddef>
#include "enums/NoMaliGpuType.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RealView.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

#include "enums/NoMaliGpuType.hh"

struct NoMaliGpuParams
    : public PioDeviceParams
{
    NoMaliGpu * create();
    Enums::NoMaliGpuType gpu_type;
    uint32_t int_gpu;
    uint32_t int_job;
    uint32_t int_mmu;
    Addr pio_addr;
    RealView * platform;
    uint32_t ver_maj;
    uint32_t ver_min;
    uint32_t ver_status;
};

#endif // __PARAMS__NoMaliGpu__
