#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ThermalCapacitor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_model.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ThermalCapacitor");
    py::class_<ThermalCapacitorParams, SimObjectParams, std::unique_ptr<ThermalCapacitorParams, py::nodelete>>(m, "ThermalCapacitorParams")
        .def(py::init<>())
        .def("create", &ThermalCapacitorParams::create)
        .def_readwrite("capacitance", &ThermalCapacitorParams::capacitance)
        ;

    py::class_<ThermalCapacitor, SimObject, std::unique_ptr<ThermalCapacitor, py::nodelete>>(m, "ThermalCapacitor")
        .def("setNodes", &ThermalCapacitor::setNodes)
        ;

}

static EmbeddedPyBind embed_obj("ThermalCapacitor", module_init, "SimObject");
