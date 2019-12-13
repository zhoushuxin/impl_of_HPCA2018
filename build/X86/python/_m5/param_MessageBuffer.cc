#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MessageBuffer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/MessageBuffer.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MessageBuffer");
    py::class_<MessageBufferParams, SimObjectParams, std::unique_ptr<MessageBufferParams, py::nodelete>>(m, "MessageBufferParams")
        .def(py::init<>())
        .def("create", &MessageBufferParams::create)
        .def_readwrite("buffer_size", &MessageBufferParams::buffer_size)
        .def_readwrite("ordered", &MessageBufferParams::ordered)
        .def_readwrite("randomization", &MessageBufferParams::randomization)
        .def_readwrite("port_master_connection_count", &MessageBufferParams::port_master_connection_count)
        .def_readwrite("port_slave_connection_count", &MessageBufferParams::port_slave_connection_count)
        ;

    py::class_<MessageBuffer, SimObject, std::unique_ptr<MessageBuffer, py::nodelete>>(m, "MessageBuffer")
        ;

}

static EmbeddedPyBind embed_obj("MessageBuffer", module_init, "SimObject");
