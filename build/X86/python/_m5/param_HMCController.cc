#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/HMCController.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/hmc_controller.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_HMCController");
    py::class_<HMCControllerParams, NoncoherentXBarParams, std::unique_ptr<HMCControllerParams, py::nodelete>>(m, "HMCControllerParams")
        .def(py::init<>())
        .def("create", &HMCControllerParams::create)
        ;

    py::class_<HMCController, NoncoherentXBar, std::unique_ptr<HMCController, py::nodelete>>(m, "HMCController")
        ;

}

static EmbeddedPyBind embed_obj("HMCController", module_init, "NoncoherentXBar");
