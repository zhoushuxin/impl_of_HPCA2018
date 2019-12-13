#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PowerModelState.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/power_model.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PowerModelState");
    py::class_<PowerModelStateParams, SimObjectParams, std::unique_ptr<PowerModelStateParams, py::nodelete>>(m, "PowerModelStateParams")
        ;

    py::class_<PowerModelState, SimObject, std::unique_ptr<PowerModelState, py::nodelete>>(m, "PowerModelState")
        .def("getDynamicPower", &PowerModelState::getDynamicPower)
        .def("getStaticPower", &PowerModelState::getStaticPower)
        ;

}

static EmbeddedPyBind embed_obj("PowerModelState", module_init, "SimObject");
