#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ThermalNode.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_node.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ThermalNode");
    py::class_<ThermalNodeParams, SimObjectParams, std::unique_ptr<ThermalNodeParams, py::nodelete>>(m, "ThermalNodeParams")
        .def(py::init<>())
        .def("create", &ThermalNodeParams::create)
        ;

    py::class_<ThermalNode, SimObject, std::unique_ptr<ThermalNode, py::nodelete>>(m, "ThermalNode")
        ;

}

static EmbeddedPyBind embed_obj("ThermalNode", module_init, "SimObject");
