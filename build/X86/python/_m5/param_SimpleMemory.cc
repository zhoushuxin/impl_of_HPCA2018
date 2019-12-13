#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleMemory.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/simple_mem.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleMemory");
    py::class_<SimpleMemoryParams, AbstractMemoryParams, std::unique_ptr<SimpleMemoryParams, py::nodelete>>(m, "SimpleMemoryParams")
        .def(py::init<>())
        .def("create", &SimpleMemoryParams::create)
        .def_readwrite("bandwidth", &SimpleMemoryParams::bandwidth)
        .def_readwrite("latency", &SimpleMemoryParams::latency)
        .def_readwrite("latency_var", &SimpleMemoryParams::latency_var)
        .def_readwrite("port_port_connection_count", &SimpleMemoryParams::port_port_connection_count)
        ;

    py::class_<SimpleMemory, AbstractMemory, std::unique_ptr<SimpleMemory, py::nodelete>>(m, "SimpleMemory")
        ;

}

static EmbeddedPyBind embed_obj("SimpleMemory", module_init, "AbstractMemory");
