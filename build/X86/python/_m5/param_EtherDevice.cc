#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherdevice.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherDevice");
    py::class_<EtherDeviceParams, PciDeviceParams, std::unique_ptr<EtherDeviceParams, py::nodelete>>(m, "EtherDeviceParams")
        .def_readwrite("port_interface_connection_count", &EtherDeviceParams::port_interface_connection_count)
        ;

    py::class_<EtherDevice, PciDevice, std::unique_ptr<EtherDevice, py::nodelete>>(m, "EtherDevice")
        ;

}

static EmbeddedPyBind embed_obj("EtherDevice", module_init, "PciDevice");
