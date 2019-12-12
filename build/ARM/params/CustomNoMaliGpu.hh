#ifndef __PARAMS__CustomNoMaliGpu__
#define __PARAMS__CustomNoMaliGpu__

class CustomNoMaliGpu;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/NoMaliGpu.hh"

struct CustomNoMaliGpuParams
    : public NoMaliGpuParams
{
    CustomNoMaliGpu * create();
    uint32_t as_present;
    uint32_t gpu_id;
    std::vector< uint32_t > js_features;
    uint32_t js_present;
    uint32_t l2_features;
    uint64_t l2_present;
    uint32_t mem_features;
    uint32_t mmu_features;
    uint64_t shader_present;
    std::vector< uint32_t > texture_features;
    uint32_t thread_features;
    uint32_t thread_max_barrier_size;
    uint32_t thread_max_threads;
    uint32_t thread_max_workgroup_size;
    uint32_t tiler_features;
    uint64_t tiler_present;
};

#endif // __PARAMS__CustomNoMaliGpu__
