#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseXBar.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/xbar.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseXBar");
    py::class_<BaseXBarParams, MemObjectParams, std::unique_ptr<BaseXBarParams, py::nodelete>>(m, "BaseXBarParams")
        .def_readwrite("forward_latency", &BaseXBarParams::forward_latency)
        .def_readwrite("frontend_latency", &BaseXBarParams::frontend_latency)
        .def_readwrite("response_latency", &BaseXBarParams::response_latency)
        .def_readwrite("use_default_range", &BaseXBarParams::use_default_range)
        .def_readwrite("width", &BaseXBarParams::width)
        .def_readwrite("port_default_connection_count", &BaseXBarParams::port_default_connection_count)
        .def_readwrite("port_master_connection_count", &BaseXBarParams::port_master_connection_count)
        .def_readwrite("port_slave_connection_count", &BaseXBarParams::port_slave_connection_count)
        ;

    py::class_<BaseXBar, MemObject, std::unique_ptr<BaseXBar, py::nodelete>>(m, "BaseXBar")
        ;

}

static EmbeddedPyBind embed_obj("BaseXBar", module_init, "MemObject");
