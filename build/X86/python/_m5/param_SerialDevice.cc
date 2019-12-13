#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SerialDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/serial.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SerialDevice");
    py::class_<SerialDeviceParams, SimObjectParams, std::unique_ptr<SerialDeviceParams, py::nodelete>>(m, "SerialDeviceParams")
        ;

    py::class_<SerialDevice, SimObject, std::unique_ptr<SerialDevice, py::nodelete>>(m, "SerialDevice")
        ;

}

static EmbeddedPyBind embed_obj("SerialDevice", module_init, "SimObject");
