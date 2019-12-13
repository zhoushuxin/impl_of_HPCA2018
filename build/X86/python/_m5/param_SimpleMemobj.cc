#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleMemobj.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/simple_memobj.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleMemobj");
    py::class_<SimpleMemobjParams, MemObjectParams, std::unique_ptr<SimpleMemobjParams, py::nodelete>>(m, "SimpleMemobjParams")
        .def(py::init<>())
        .def("create", &SimpleMemobjParams::create)
        .def_readwrite("port_mem_side_connection_count", &SimpleMemobjParams::port_mem_side_connection_count)
        .def_readwrite("port_data_port_connection_count", &SimpleMemobjParams::port_data_port_connection_count)
        .def_readwrite("port_inst_port_connection_count", &SimpleMemobjParams::port_inst_port_connection_count)
        ;

    py::class_<SimpleMemobj, MemObject, std::unique_ptr<SimpleMemobj, py::nodelete>>(m, "SimpleMemobj")
        ;

}

static EmbeddedPyBind embed_obj("SimpleMemobj", module_init, "MemObject");
