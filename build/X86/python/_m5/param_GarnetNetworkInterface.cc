#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GarnetNetworkInterface.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/NetworkInterface.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GarnetNetworkInterface");
    py::class_<GarnetNetworkInterfaceParams, ClockedObjectParams, std::unique_ptr<GarnetNetworkInterfaceParams, py::nodelete>>(m, "GarnetNetworkInterfaceParams")
        .def(py::init<>())
        .def("create", &GarnetNetworkInterfaceParams::create)
        .def_readwrite("garnet_deadlock_threshold", &GarnetNetworkInterfaceParams::garnet_deadlock_threshold)
        .def_readwrite("id", &GarnetNetworkInterfaceParams::id)
        .def_readwrite("vcs_per_vnet", &GarnetNetworkInterfaceParams::vcs_per_vnet)
        .def_readwrite("virt_nets", &GarnetNetworkInterfaceParams::virt_nets)
        ;

    py::class_<NetworkInterface, ClockedObject, std::unique_ptr<NetworkInterface, py::nodelete>>(m, "NetworkInterface")
        ;

}

static EmbeddedPyBind embed_obj("GarnetNetworkInterface", module_init, "ClockedObject");
