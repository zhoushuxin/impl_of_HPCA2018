#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BasicLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/BasicLink.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BasicLink");
    py::class_<BasicLinkParams, SimObjectParams, std::unique_ptr<BasicLinkParams, py::nodelete>>(m, "BasicLinkParams")
        .def(py::init<>())
        .def("create", &BasicLinkParams::create)
        .def_readwrite("bandwidth_factor", &BasicLinkParams::bandwidth_factor)
        .def_readwrite("latency", &BasicLinkParams::latency)
        .def_readwrite("link_id", &BasicLinkParams::link_id)
        .def_readwrite("weight", &BasicLinkParams::weight)
        ;

    py::class_<BasicLink, SimObject, std::unique_ptr<BasicLink, py::nodelete>>(m, "BasicLink")
        ;

}

static EmbeddedPyBind embed_obj("BasicLink", module_init, "SimObject");
