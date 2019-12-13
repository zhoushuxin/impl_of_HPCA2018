#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I2CBus.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/i2c/bus.hh"

#include <vector>
#include "dev/i2c/device.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I2CBus");
    py::class_<I2CBusParams, BasicPioDeviceParams, std::unique_ptr<I2CBusParams, py::nodelete>>(m, "I2CBusParams")
        .def(py::init<>())
        .def("create", &I2CBusParams::create)
        .def_readwrite("devices", &I2CBusParams::devices)
        ;

    py::class_<I2CBus, BasicPioDevice, std::unique_ptr<I2CBus, py::nodelete>>(m, "I2CBus")
        ;

}

static EmbeddedPyBind embed_obj("I2CBus", module_init, "BasicPioDevice");
