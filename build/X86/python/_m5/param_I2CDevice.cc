#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I2CDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/i2c/device.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I2CDevice");
    py::class_<I2CDeviceParams, SimObjectParams, std::unique_ptr<I2CDeviceParams, py::nodelete>>(m, "I2CDeviceParams")
        .def_readwrite("i2c_addr", &I2CDeviceParams::i2c_addr)
        ;

    py::class_<I2CDevice, SimObject, std::unique_ptr<I2CDevice, py::nodelete>>(m, "I2CDevice")
        ;

}

static EmbeddedPyBind embed_obj("I2CDevice", module_init, "SimObject");
