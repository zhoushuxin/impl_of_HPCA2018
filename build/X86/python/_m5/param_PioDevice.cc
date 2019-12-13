#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PioDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/io_device.hh"

#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PioDevice");
    py::class_<PioDeviceParams, MemObjectParams, std::unique_ptr<PioDeviceParams, py::nodelete>>(m, "PioDeviceParams")
        .def_readwrite("system", &PioDeviceParams::system)
        .def_readwrite("port_pio_connection_count", &PioDeviceParams::port_pio_connection_count)
        ;

    py::class_<PioDevice, MemObject, std::unique_ptr<PioDevice, py::nodelete>>(m, "PioDevice")
        ;

}

static EmbeddedPyBind embed_obj("PioDevice", module_init, "MemObject");
