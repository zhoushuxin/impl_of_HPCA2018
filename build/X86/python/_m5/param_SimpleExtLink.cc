#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleExtLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/simple/SimpleLink.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleExtLink");
    py::class_<SimpleExtLinkParams, BasicExtLinkParams, std::unique_ptr<SimpleExtLinkParams, py::nodelete>>(m, "SimpleExtLinkParams")
        .def(py::init<>())
        .def("create", &SimpleExtLinkParams::create)
        ;

    py::class_<SimpleExtLink, BasicExtLink, std::unique_ptr<SimpleExtLink, py::nodelete>>(m, "SimpleExtLink")
        ;

}

static EmbeddedPyBind embed_obj("SimpleExtLink", module_init, "BasicExtLink");
