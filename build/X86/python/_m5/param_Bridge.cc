#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Bridge.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/bridge.hh"

#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Bridge");
    py::class_<BridgeParams, MemObjectParams, std::unique_ptr<BridgeParams, py::nodelete>>(m, "BridgeParams")
        .def(py::init<>())
        .def("create", &BridgeParams::create)
        .def_readwrite("delay", &BridgeParams::delay)
        .def_readwrite("ranges", &BridgeParams::ranges)
        .def_readwrite("req_size", &BridgeParams::req_size)
        .def_readwrite("resp_size", &BridgeParams::resp_size)
        .def_readwrite("port_master_connection_count", &BridgeParams::port_master_connection_count)
        .def_readwrite("port_slave_connection_count", &BridgeParams::port_slave_connection_count)
        ;

    py::class_<Bridge, MemObject, std::unique_ptr<Bridge, py::nodelete>>(m, "Bridge")
        ;

}

static EmbeddedPyBind embed_obj("Bridge", module_init, "MemObject");
