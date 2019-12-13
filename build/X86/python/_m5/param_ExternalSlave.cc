#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ExternalSlave.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/external_slave.hh"

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <string>
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ExternalSlave");
    py::class_<ExternalSlaveParams, MemObjectParams, std::unique_ptr<ExternalSlaveParams, py::nodelete>>(m, "ExternalSlaveParams")
        .def(py::init<>())
        .def("create", &ExternalSlaveParams::create)
        .def_readwrite("addr_ranges", &ExternalSlaveParams::addr_ranges)
        .def_readwrite("port_data", &ExternalSlaveParams::port_data)
        .def_readwrite("port_type", &ExternalSlaveParams::port_type)
        .def_readwrite("port_port_connection_count", &ExternalSlaveParams::port_port_connection_count)
        ;

    py::class_<ExternalSlave, MemObject, std::unique_ptr<ExternalSlave, py::nodelete>>(m, "ExternalSlave")
        ;

}

static EmbeddedPyBind embed_obj("ExternalSlave", module_init, "MemObject");
