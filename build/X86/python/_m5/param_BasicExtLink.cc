#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BasicExtLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/BasicLink.hh"

#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "mem/ruby/network/BasicRouter.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BasicExtLink");
    py::class_<BasicExtLinkParams, BasicLinkParams, std::unique_ptr<BasicExtLinkParams, py::nodelete>>(m, "BasicExtLinkParams")
        .def(py::init<>())
        .def("create", &BasicExtLinkParams::create)
        .def_readwrite("ext_node", &BasicExtLinkParams::ext_node)
        .def_readwrite("int_node", &BasicExtLinkParams::int_node)
        ;

    py::class_<BasicExtLink, BasicLink, std::unique_ptr<BasicExtLink, py::nodelete>>(m, "BasicExtLink")
        ;

}

static EmbeddedPyBind embed_obj("BasicExtLink", module_init, "BasicLink");
