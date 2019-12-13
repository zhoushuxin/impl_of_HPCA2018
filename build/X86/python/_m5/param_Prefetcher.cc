#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Prefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/Prefetcher.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Prefetcher");
    py::class_<PrefetcherParams, SimObjectParams, std::unique_ptr<PrefetcherParams, py::nodelete>>(m, "PrefetcherParams")
        .def(py::init<>())
        .def("create", &PrefetcherParams::create)
        .def_readwrite("cross_page", &PrefetcherParams::cross_page)
        .def_readwrite("nonunit_filter", &PrefetcherParams::nonunit_filter)
        .def_readwrite("num_startup_pfs", &PrefetcherParams::num_startup_pfs)
        .def_readwrite("num_streams", &PrefetcherParams::num_streams)
        .def_readwrite("pf_per_stream", &PrefetcherParams::pf_per_stream)
        .def_readwrite("sys", &PrefetcherParams::sys)
        .def_readwrite("train_misses", &PrefetcherParams::train_misses)
        .def_readwrite("unit_filter", &PrefetcherParams::unit_filter)
        ;

    py::class_<Prefetcher, SimObject, std::unique_ptr<Prefetcher, py::nodelete>>(m, "Prefetcher")
        ;

}

static EmbeddedPyBind embed_obj("Prefetcher", module_init, "SimObject");
