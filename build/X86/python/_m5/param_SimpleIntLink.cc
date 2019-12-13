#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleIntLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/simple/SimpleLink.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleIntLink");
    py::class_<SimpleIntLinkParams, BasicIntLinkParams, std::unique_ptr<SimpleIntLinkParams, py::nodelete>>(m, "SimpleIntLinkParams")
        .def(py::init<>())
        .def("create", &SimpleIntLinkParams::create)
        ;

    py::class_<SimpleIntLink, BasicIntLink, std::unique_ptr<SimpleIntLink, py::nodelete>>(m, "SimpleIntLink")
        ;

}

static EmbeddedPyBind embed_obj("SimpleIntLink", module_init, "BasicIntLink");
