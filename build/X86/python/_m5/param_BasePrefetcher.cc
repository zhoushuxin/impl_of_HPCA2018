#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BasePrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/base.hh"

#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BasePrefetcher");
    py::class_<BasePrefetcherParams, ClockedObjectParams, std::unique_ptr<BasePrefetcherParams, py::nodelete>>(m, "BasePrefetcherParams")
        .def_readwrite("on_data", &BasePrefetcherParams::on_data)
        .def_readwrite("on_inst", &BasePrefetcherParams::on_inst)
        .def_readwrite("on_miss", &BasePrefetcherParams::on_miss)
        .def_readwrite("on_read", &BasePrefetcherParams::on_read)
        .def_readwrite("on_write", &BasePrefetcherParams::on_write)
        .def_readwrite("sys", &BasePrefetcherParams::sys)
        ;

    py::class_<BasePrefetcher, ClockedObject, std::unique_ptr<BasePrefetcher, py::nodelete>>(m, "BasePrefetcher")
        ;

}

static EmbeddedPyBind embed_obj("BasePrefetcher", module_init, "ClockedObject");
