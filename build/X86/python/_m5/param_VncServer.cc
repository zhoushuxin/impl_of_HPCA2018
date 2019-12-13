#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VncServer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "base/vnc/vncserver.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VncServer");
    py::class_<VncServerParams, VncInputParams, std::unique_ptr<VncServerParams, py::nodelete>>(m, "VncServerParams")
        .def(py::init<>())
        .def("create", &VncServerParams::create)
        .def_readwrite("number", &VncServerParams::number)
        .def_readwrite("port", &VncServerParams::port)
        ;

    py::class_<VncServer, VncInput, std::unique_ptr<VncServer, py::nodelete>>(m, "VncServer")
        ;

}

static EmbeddedPyBind embed_obj("VncServer", module_init, "VncInput");
