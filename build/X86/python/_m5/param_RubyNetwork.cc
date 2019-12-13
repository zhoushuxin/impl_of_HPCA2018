#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyNetwork.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/Network.hh"

#include "base/types.hh"
#include <vector>
#include "mem/ruby/network/BasicLink.hh"
#include <vector>
#include "mem/ruby/network/BasicLink.hh"
#include <vector>
#include "sim/clocked_object.hh"
#include "base/types.hh"
#include <vector>
#include "mem/ruby/network/BasicRouter.hh"
#include "mem/ruby/system/RubySystem.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyNetwork");
    py::class_<RubyNetworkParams, ClockedObjectParams, std::unique_ptr<RubyNetworkParams, py::nodelete>>(m, "RubyNetworkParams")
        .def_readwrite("control_msg_size", &RubyNetworkParams::control_msg_size)
        .def_readwrite("ext_links", &RubyNetworkParams::ext_links)
        .def_readwrite("int_links", &RubyNetworkParams::int_links)
        .def_readwrite("netifs", &RubyNetworkParams::netifs)
        .def_readwrite("number_of_virtual_networks", &RubyNetworkParams::number_of_virtual_networks)
        .def_readwrite("routers", &RubyNetworkParams::routers)
        .def_readwrite("ruby_system", &RubyNetworkParams::ruby_system)
        .def_readwrite("topology", &RubyNetworkParams::topology)
        .def_readwrite("port_master_connection_count", &RubyNetworkParams::port_master_connection_count)
        .def_readwrite("port_slave_connection_count", &RubyNetworkParams::port_slave_connection_count)
        ;

    py::class_<Network, ClockedObject, std::unique_ptr<Network, py::nodelete>>(m, "Network")
        ;

}

static EmbeddedPyBind embed_obj("RubyNetwork", module_init, "ClockedObject");
