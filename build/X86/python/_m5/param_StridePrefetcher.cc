#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/StridePrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/stride.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_StridePrefetcher");
    py::class_<StridePrefetcherParams, QueuedPrefetcherParams, std::unique_ptr<StridePrefetcherParams, py::nodelete>>(m, "StridePrefetcherParams")
        .def(py::init<>())
        .def("create", &StridePrefetcherParams::create)
        .def_readwrite("degree", &StridePrefetcherParams::degree)
        .def_readwrite("max_conf", &StridePrefetcherParams::max_conf)
        .def_readwrite("min_conf", &StridePrefetcherParams::min_conf)
        .def_readwrite("start_conf", &StridePrefetcherParams::start_conf)
        .def_readwrite("table_assoc", &StridePrefetcherParams::table_assoc)
        .def_readwrite("table_sets", &StridePrefetcherParams::table_sets)
        .def_readwrite("thresh_conf", &StridePrefetcherParams::thresh_conf)
        .def_readwrite("use_master_id", &StridePrefetcherParams::use_master_id)
        ;

    py::class_<StridePrefetcher, QueuedPrefetcher, std::unique_ptr<StridePrefetcher, py::nodelete>>(m, "StridePrefetcher")
        ;

}

static EmbeddedPyBind embed_obj("StridePrefetcher", module_init, "QueuedPrefetcher");
