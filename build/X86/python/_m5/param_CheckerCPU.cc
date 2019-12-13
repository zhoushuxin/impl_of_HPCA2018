#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/CheckerCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/checker/cpu.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_CheckerCPU");
    py::class_<CheckerCPUParams, BaseCPUParams, std::unique_ptr<CheckerCPUParams, py::nodelete>>(m, "CheckerCPUParams")
        .def_readwrite("exitOnError", &CheckerCPUParams::exitOnError)
        .def_readwrite("updateOnError", &CheckerCPUParams::updateOnError)
        .def_readwrite("warnOnlyOnLoadError", &CheckerCPUParams::warnOnlyOnLoadError)
        ;

    py::class_<CheckerCPU, BaseCPU, std::unique_ptr<CheckerCPU, py::nodelete>>(m, "CheckerCPU")
        ;

}

static EmbeddedPyBind embed_obj("CheckerCPU", module_init, "BaseCPU");
