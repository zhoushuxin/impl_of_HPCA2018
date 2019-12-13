#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleNetwork.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/simple/SimpleNetwork.hh"

#include "base/types.hh"
#include "base/types.hh"
#include <vector>
#include "mem/ruby/network/MessageBuffer.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleNetwork");
    py::class_<SimpleNetworkParams, RubyNetworkParams, std::unique_ptr<SimpleNetworkParams, py::nodelete>>(m, "SimpleNetworkParams")
        .def(py::init<>())
        .def("create", &SimpleNetworkParams::create)
        .def_readwrite("adaptive_routing", &SimpleNetworkParams::adaptive_routing)
        .def_readwrite("buffer_size", &SimpleNetworkParams::buffer_size)
        .def_readwrite("endpoint_bandwidth", &SimpleNetworkParams::endpoint_bandwidth)
        .def_readwrite("int_link_buffers", &SimpleNetworkParams::int_link_buffers)
        ;

    py::class_<SimpleNetwork, Network, std::unique_ptr<SimpleNetwork, py::nodelete>>(m, "SimpleNetwork")
        ;

}

static EmbeddedPyBind embed_obj("SimpleNetwork", module_init, "RubyNetwork");
