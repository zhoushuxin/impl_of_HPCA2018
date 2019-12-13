#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/NetworkLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/NetworkLink.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_NetworkLink");
    py::class_<NetworkLinkParams, ClockedObjectParams, std::unique_ptr<NetworkLinkParams, py::nodelete>>(m, "NetworkLinkParams")
        .def(py::init<>())
        .def("create", &NetworkLinkParams::create)
        .def_readwrite("link_id", &NetworkLinkParams::link_id)
        .def_readwrite("link_latency", &NetworkLinkParams::link_latency)
        .def_readwrite("vcs_per_vnet", &NetworkLinkParams::vcs_per_vnet)
        .def_readwrite("virt_nets", &NetworkLinkParams::virt_nets)
        ;

    py::class_<NetworkLink, ClockedObject, std::unique_ptr<NetworkLink, py::nodelete>>(m, "NetworkLink")
        ;

}

static EmbeddedPyBind embed_obj("NetworkLink", module_init, "ClockedObject");
