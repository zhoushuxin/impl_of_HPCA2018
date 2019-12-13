#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BadDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/baddev.hh"

#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BadDevice");
    py::class_<BadDeviceParams, BasicPioDeviceParams, std::unique_ptr<BadDeviceParams, py::nodelete>>(m, "BadDeviceParams")
        .def(py::init<>())
        .def("create", &BadDeviceParams::create)
        .def_readwrite("devicename", &BadDeviceParams::devicename)
        ;

    py::class_<BadDevice, BasicPioDevice, std::unique_ptr<BadDevice, py::nodelete>>(m, "BadDevice")
        ;

}

static EmbeddedPyBind embed_obj("BadDevice", module_init, "BasicPioDevice");
