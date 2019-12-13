#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TaggedPrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/tagged.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TaggedPrefetcher");
    py::class_<TaggedPrefetcherParams, QueuedPrefetcherParams, std::unique_ptr<TaggedPrefetcherParams, py::nodelete>>(m, "TaggedPrefetcherParams")
        .def(py::init<>())
        .def("create", &TaggedPrefetcherParams::create)
        .def_readwrite("degree", &TaggedPrefetcherParams::degree)
        ;

    py::class_<TaggedPrefetcher, QueuedPrefetcher, std::unique_ptr<TaggedPrefetcher, py::nodelete>>(m, "TaggedPrefetcher")
        ;

}

static EmbeddedPyBind embed_obj("TaggedPrefetcher", module_init, "QueuedPrefetcher");
