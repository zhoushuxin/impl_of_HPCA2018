#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ThermalResistor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_model.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ThermalResistor");
    py::class_<ThermalResistorParams, SimObjectParams, std::unique_ptr<ThermalResistorParams, py::nodelete>>(m, "ThermalResistorParams")
        .def(py::init<>())
        .def("create", &ThermalResistorParams::create)
        .def_readwrite("resistance", &ThermalResistorParams::resistance)
        ;

    py::class_<ThermalResistor, SimObject, std::unique_ptr<ThermalResistor, py::nodelete>>(m, "ThermalResistor")
        .def("setNodes", &ThermalResistor::setNodes)
        ;

}

static EmbeddedPyBind embed_obj("ThermalResistor", module_init, "SimObject");
