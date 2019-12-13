#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PowerModel.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/power_model.hh"

#include <vector>
#include "sim/power/power_model.hh"
#include "enums/PMType.hh"
#include "sim/sub_system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PowerModel");
    py::class_<PowerModelParams, SimObjectParams, std::unique_ptr<PowerModelParams, py::nodelete>>(m, "PowerModelParams")
        .def(py::init<>())
        .def("create", &PowerModelParams::create)
        .def_readwrite("ambient_temp", &PowerModelParams::ambient_temp)
        .def_readwrite("pm", &PowerModelParams::pm)
        .def_readwrite("pm_type", &PowerModelParams::pm_type)
        .def_readwrite("subsystem", &PowerModelParams::subsystem)
        ;

    py::class_<PowerModel, SimObject, std::unique_ptr<PowerModel, py::nodelete>>(m, "PowerModel")
        .def("getDynamicPower", &PowerModel::getDynamicPower)
        .def("getStaticPower", &PowerModel::getStaticPower)
        ;

}

static EmbeddedPyBind embed_obj("PowerModel", module_init, "SimObject");
