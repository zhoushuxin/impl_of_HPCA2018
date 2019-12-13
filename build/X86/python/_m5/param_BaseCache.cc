#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseCache.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/base.hh"

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "mem/cache/prefetch/base.hh"
#include "mem/cache/replacement_policies/base.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "base/types.hh"
#include "mem/cache/tags/base.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseCache");
    py::class_<BaseCacheParams, MemObjectParams, std::unique_ptr<BaseCacheParams, py::nodelete>>(m, "BaseCacheParams")
        .def_readwrite("addr_ranges", &BaseCacheParams::addr_ranges)
        .def_readwrite("assoc", &BaseCacheParams::assoc)
        .def_readwrite("data_latency", &BaseCacheParams::data_latency)
        .def_readwrite("demand_mshr_reserve", &BaseCacheParams::demand_mshr_reserve)
        .def_readwrite("is_read_only", &BaseCacheParams::is_read_only)
        .def_readwrite("max_miss_count", &BaseCacheParams::max_miss_count)
        .def_readwrite("mshrs", &BaseCacheParams::mshrs)
        .def_readwrite("prefetch_on_access", &BaseCacheParams::prefetch_on_access)
        .def_readwrite("prefetcher", &BaseCacheParams::prefetcher)
        .def_readwrite("replacement_policy", &BaseCacheParams::replacement_policy)
        .def_readwrite("response_latency", &BaseCacheParams::response_latency)
        .def_readwrite("sequential_access", &BaseCacheParams::sequential_access)
        .def_readwrite("size", &BaseCacheParams::size)
        .def_readwrite("system", &BaseCacheParams::system)
        .def_readwrite("tag_latency", &BaseCacheParams::tag_latency)
        .def_readwrite("tags", &BaseCacheParams::tags)
        .def_readwrite("tgts_per_mshr", &BaseCacheParams::tgts_per_mshr)
        .def_readwrite("warmup_percentage", &BaseCacheParams::warmup_percentage)
        .def_readwrite("write_buffers", &BaseCacheParams::write_buffers)
        .def_readwrite("port_mem_side_connection_count", &BaseCacheParams::port_mem_side_connection_count)
        .def_readwrite("port_cpu_side_connection_count", &BaseCacheParams::port_cpu_side_connection_count)
        ;

    py::class_<BaseCache, MemObject, std::unique_ptr<BaseCache, py::nodelete>>(m, "BaseCache")
        ;

}

static EmbeddedPyBind embed_obj("BaseCache", module_init, "MemObject");
