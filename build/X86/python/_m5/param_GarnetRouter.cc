#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GarnetRouter.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/Router.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GarnetRouter");
    py::class_<GarnetRouterParams, BasicRouterParams, std::unique_ptr<GarnetRouterParams, py::nodelete>>(m, "GarnetRouterParams")
        .def(py::init<>())
        .def("create", &GarnetRouterParams::create)
        .def_readwrite("vcs_per_vnet", &GarnetRouterParams::vcs_per_vnet)
        .def_readwrite("virt_nets", &GarnetRouterParams::virt_nets)
        ;

    py::class_<Router, BasicRouter, std::unique_ptr<Router, py::nodelete>>(m, "Router")
        ;

}

static EmbeddedPyBind embed_obj("GarnetRouter", module_init, "BasicRouter");
