#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DummyChecker.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/dummy_checker.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DummyChecker");
    py::class_<DummyCheckerParams, CheckerCPUParams, std::unique_ptr<DummyCheckerParams, py::nodelete>>(m, "DummyCheckerParams")
        .def(py::init<>())
        .def("create", &DummyCheckerParams::create)
        ;

    py::class_<DummyChecker, CheckerCPU, std::unique_ptr<DummyChecker, py::nodelete>>(m, "DummyChecker")
        ;

}

static EmbeddedPyBind embed_obj("DummyChecker", module_init, "CheckerCPU");
