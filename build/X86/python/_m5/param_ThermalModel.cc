#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ThermalModel.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_model.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ThermalModel");
    py::class_<ThermalModelParams, ClockedObjectParams, std::unique_ptr<ThermalModelParams, py::nodelete>>(m, "ThermalModelParams")
        .def(py::init<>())
        .def("create", &ThermalModelParams::create)
        .def_readwrite("step", &ThermalModelParams::step)
        ;

    py::class_<ThermalModel, ClockedObject, std::unique_ptr<ThermalModel, py::nodelete>>(m, "ThermalModel")
        .def("addCapacitor", &ThermalModel::addCapacitor)
        .def("addResistor", &ThermalModel::addResistor)
        .def("addReference", &ThermalModel::addReference)
        .def("addDomain", &ThermalModel::addDomain)
        .def("addNode", &ThermalModel::addNode)
        .def("doStep", &ThermalModel::doStep)
        ;

}

static EmbeddedPyBind embed_obj("ThermalModel", module_init, "ClockedObject");
