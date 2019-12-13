#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/O3Checker.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/o3/checker.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_O3Checker");
    py::class_<O3CheckerParams, CheckerCPUParams, std::unique_ptr<O3CheckerParams, py::nodelete>>(m, "O3CheckerParams")
        .def(py::init<>())
        .def("create", &O3CheckerParams::create)
        ;

    py::class_<O3Checker, CheckerCPU, std::unique_ptr<O3Checker, py::nodelete>>(m, "O3Checker")
        ;

}

static EmbeddedPyBind embed_obj("O3Checker", module_init, "CheckerCPU");
