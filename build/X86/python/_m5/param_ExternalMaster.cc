#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ExternalMaster.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/external_master.hh"

#include <string>
#include <string>
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ExternalMaster");
    py::class_<ExternalMasterParams, MemObjectParams, std::unique_ptr<ExternalMasterParams, py::nodelete>>(m, "ExternalMasterParams")
        .def(py::init<>())
        .def("create", &ExternalMasterParams::create)
        .def_readwrite("port_data", &ExternalMasterParams::port_data)
        .def_readwrite("port_type", &ExternalMasterParams::port_type)
        .def_readwrite("system", &ExternalMasterParams::system)
        .def_readwrite("port_port_connection_count", &ExternalMasterParams::port_port_connection_count)
        ;

    py::class_<ExternalMaster, MemObject, std::unique_ptr<ExternalMaster, py::nodelete>>(m, "ExternalMaster")
        ;

}

static EmbeddedPyBind embed_obj("ExternalMaster", module_init, "MemObject");
