#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SerialNullDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/serial.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SerialNullDevice");
    py::class_<SerialNullDeviceParams, SerialDeviceParams, std::unique_ptr<SerialNullDeviceParams, py::nodelete>>(m, "SerialNullDeviceParams")
        .def(py::init<>())
        .def("create", &SerialNullDeviceParams::create)
        ;

    py::class_<SerialNullDevice, SerialDevice, std::unique_ptr<SerialNullDevice, py::nodelete>>(m, "SerialNullDevice")
        ;

}

static EmbeddedPyBind embed_obj("SerialNullDevice", module_init, "SerialDevice");
