#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GarnetIntLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/GarnetLink.hh"

#include "mem/ruby/network/garnet2.0/CreditLink.hh"
#include "mem/ruby/network/garnet2.0/NetworkLink.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GarnetIntLink");
    py::class_<GarnetIntLinkParams, BasicIntLinkParams, std::unique_ptr<GarnetIntLinkParams, py::nodelete>>(m, "GarnetIntLinkParams")
        .def(py::init<>())
        .def("create", &GarnetIntLinkParams::create)
        .def_readwrite("credit_link", &GarnetIntLinkParams::credit_link)
        .def_readwrite("network_link", &GarnetIntLinkParams::network_link)
        ;

    py::class_<GarnetIntLink, BasicIntLink, std::unique_ptr<GarnetIntLink, py::nodelete>>(m, "GarnetIntLink")
        ;

}

static EmbeddedPyBind embed_obj("GarnetIntLink", module_init, "BasicIntLink");
