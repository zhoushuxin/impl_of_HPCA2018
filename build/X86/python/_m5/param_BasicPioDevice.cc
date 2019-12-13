#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BasicPioDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/io_device.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BasicPioDevice");
    py::class_<BasicPioDeviceParams, PioDeviceParams, std::unique_ptr<BasicPioDeviceParams, py::nodelete>>(m, "BasicPioDeviceParams")
        .def_readwrite("pio_addr", &BasicPioDeviceParams::pio_addr)
        .def_readwrite("pio_latency", &BasicPioDeviceParams::pio_latency)
        ;

    py::class_<BasicPioDevice, PioDevice, std::unique_ptr<BasicPioDevice, py::nodelete>>(m, "BasicPioDevice")
        ;

}

static EmbeddedPyBind embed_obj("BasicPioDevice", module_init, "PioDevice");
