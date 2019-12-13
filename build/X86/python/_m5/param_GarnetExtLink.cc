#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GarnetExtLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/GarnetLink.hh"

#include <vector>
#include "mem/ruby/network/garnet2.0/CreditLink.hh"
#include <vector>
#include "mem/ruby/network/garnet2.0/NetworkLink.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GarnetExtLink");
    py::class_<GarnetExtLinkParams, BasicExtLinkParams, std::unique_ptr<GarnetExtLinkParams, py::nodelete>>(m, "GarnetExtLinkParams")
        .def(py::init<>())
        .def("create", &GarnetExtLinkParams::create)
        .def_readwrite("credit_links", &GarnetExtLinkParams::credit_links)
        .def_readwrite("network_links", &GarnetExtLinkParams::network_links)
        ;

    py::class_<GarnetExtLink, BasicExtLink, std::unique_ptr<GarnetExtLink, py::nodelete>>(m, "GarnetExtLink")
        ;

}

static EmbeddedPyBind embed_obj("GarnetExtLink", module_init, "BasicExtLink");
