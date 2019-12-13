#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/QueuedPrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/queued.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_QueuedPrefetcher");
    py::class_<QueuedPrefetcherParams, BasePrefetcherParams, std::unique_ptr<QueuedPrefetcherParams, py::nodelete>>(m, "QueuedPrefetcherParams")
        .def_readwrite("cache_snoop", &QueuedPrefetcherParams::cache_snoop)
        .def_readwrite("latency", &QueuedPrefetcherParams::latency)
        .def_readwrite("queue_filter", &QueuedPrefetcherParams::queue_filter)
        .def_readwrite("queue_size", &QueuedPrefetcherParams::queue_size)
        .def_readwrite("queue_squash", &QueuedPrefetcherParams::queue_squash)
        .def_readwrite("tag_prefetch", &QueuedPrefetcherParams::tag_prefetch)
        ;

    py::class_<QueuedPrefetcher, BasePrefetcher, std::unique_ptr<QueuedPrefetcher, py::nodelete>>(m, "QueuedPrefetcher")
        ;

}

static EmbeddedPyBind embed_obj("QueuedPrefetcher", module_init, "BasePrefetcher");
