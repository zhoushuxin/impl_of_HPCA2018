#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BasicIntLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/BasicLink.hh"

#include <string>
#include "mem/ruby/network/BasicRouter.hh"
#include "mem/ruby/network/BasicRouter.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BasicIntLink");
    py::class_<BasicIntLinkParams, BasicLinkParams, std::unique_ptr<BasicIntLinkParams, py::nodelete>>(m, "BasicIntLinkParams")
        .def(py::init<>())
        .def("create", &BasicIntLinkParams::create)
        .def_readwrite("dst_inport", &BasicIntLinkParams::dst_inport)
        .def_readwrite("dst_node", &BasicIntLinkParams::dst_node)
        .def_readwrite("src_node", &BasicIntLinkParams::src_node)
        .def_readwrite("src_outport", &BasicIntLinkParams::src_outport)
        ;

    py::class_<BasicIntLink, BasicLink, std::unique_ptr<BasicIntLink, py::nodelete>>(m, "BasicIntLink")
        ;

}

static EmbeddedPyBind embed_obj("BasicIntLink", module_init, "BasicLink");
