#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/AddrMapper.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/addr_mapper.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_AddrMapper");
    py::class_<AddrMapperParams, MemObjectParams, std::unique_ptr<AddrMapperParams, py::nodelete>>(m, "AddrMapperParams")
        .def_readwrite("port_master_connection_count", &AddrMapperParams::port_master_connection_count)
        .def_readwrite("port_slave_connection_count", &AddrMapperParams::port_slave_connection_count)
        ;

    py::class_<AddrMapper, MemObject, std::unique_ptr<AddrMapper, py::nodelete>>(m, "AddrMapper")
        ;

}

static EmbeddedPyBind embed_obj("AddrMapper", module_init, "MemObject");
