#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/CreditLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/CreditLink.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_CreditLink");
    py::class_<CreditLinkParams, NetworkLinkParams, std::unique_ptr<CreditLinkParams, py::nodelete>>(m, "CreditLinkParams")
        .def(py::init<>())
        .def("create", &CreditLinkParams::create)
        ;

    py::class_<CreditLink, NetworkLink, std::unique_ptr<CreditLink, py::nodelete>>(m, "CreditLink")
        ;

}

static EmbeddedPyBind embed_obj("CreditLink", module_init, "NetworkLink");
