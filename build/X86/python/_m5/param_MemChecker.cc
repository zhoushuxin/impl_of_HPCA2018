#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MemChecker.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/mem_checker.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MemChecker");
    py::class_<MemCheckerParams, SimObjectParams, std::unique_ptr<MemCheckerParams, py::nodelete>>(m, "MemCheckerParams")
        .def(py::init<>())
        .def("create", &MemCheckerParams::create)
        ;

    py::class_<MemChecker, SimObject, std::unique_ptr<MemChecker, py::nodelete>>(m, "MemChecker")
        ;

}

static EmbeddedPyBind embed_obj("MemChecker", module_init, "SimObject");
