#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ThermalReference.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_model.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ThermalReference");
    py::class_<ThermalReferenceParams, SimObjectParams, std::unique_ptr<ThermalReferenceParams, py::nodelete>>(m, "ThermalReferenceParams")
        .def(py::init<>())
        .def("create", &ThermalReferenceParams::create)
        .def_readwrite("temperature", &ThermalReferenceParams::temperature)
        ;

    py::class_<ThermalReference, SimObject, std::unique_ptr<ThermalReference, py::nodelete>>(m, "ThermalReference")
        .def("setNode", &ThermalReference::setNode)
        ;

}

static EmbeddedPyBind embed_obj("ThermalReference", module_init, "SimObject");
