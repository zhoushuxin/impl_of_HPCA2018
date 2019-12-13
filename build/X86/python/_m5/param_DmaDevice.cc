#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DmaDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/dma_device.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DmaDevice");
    py::class_<DmaDeviceParams, PioDeviceParams, std::unique_ptr<DmaDeviceParams, py::nodelete>>(m, "DmaDeviceParams")
        .def_readwrite("port_dma_connection_count", &DmaDeviceParams::port_dma_connection_count)
        ;

    py::class_<DmaDevice, PioDevice, std::unique_ptr<DmaDevice, py::nodelete>>(m, "DmaDevice")
        ;

}

static EmbeddedPyBind embed_obj("DmaDevice", module_init, "PioDevice");
