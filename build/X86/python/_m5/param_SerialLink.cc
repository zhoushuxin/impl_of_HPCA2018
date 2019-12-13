#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SerialLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/serial_link.hh"

#include "base/types.hh"
#include "base/types.hh"
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
    py::module m = m_internal.def_submodule("param_SerialLink");
    py::class_<SerialLinkParams, MemObjectParams, std::unique_ptr<SerialLinkParams, py::nodelete>>(m, "SerialLinkParams")
        .def(py::init<>())
        .def("create", &SerialLinkParams::create)
        .def_readwrite("delay", &SerialLinkParams::delay)
        .def_readwrite("link_speed", &SerialLinkParams::link_speed)
        .def_readwrite("num_lanes", &SerialLinkParams::num_lanes)
        .def_readwrite("ranges", &SerialLinkParams::ranges)
        .def_readwrite("req_size", &SerialLinkParams::req_size)
        .def_readwrite("resp_size", &SerialLinkParams::resp_size)
        .def_readwrite("port_master_connection_count", &SerialLinkParams::port_master_connection_count)
        .def_readwrite("port_slave_connection_count", &SerialLinkParams::port_slave_connection_count)
        ;

    py::class_<SerialLink, MemObject, std::unique_ptr<SerialLink, py::nodelete>>(m, "SerialLink")
        ;

}

static EmbeddedPyBind embed_obj("SerialLink", module_init, "MemObject");
