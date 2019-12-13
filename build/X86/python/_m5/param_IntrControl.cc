#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/IntrControl.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/intr_control.hh"

#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_IntrControl");
    py::class_<IntrControlParams, SimObjectParams, std::unique_ptr<IntrControlParams, py::nodelete>>(m, "IntrControlParams")
        .def(py::init<>())
        .def("create", &IntrControlParams::create)
        .def_readwrite("sys", &IntrControlParams::sys)
        ;

    py::class_<IntrControl, SimObject, std::unique_ptr<IntrControl, py::nodelete>>(m, "IntrControl")
        ;

}

static EmbeddedPyBind embed_obj("IntrControl", module_init, "SimObject");
