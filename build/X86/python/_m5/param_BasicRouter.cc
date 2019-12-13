#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BasicRouter.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/BasicRouter.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BasicRouter");
    py::class_<BasicRouterParams, ClockedObjectParams, std::unique_ptr<BasicRouterParams, py::nodelete>>(m, "BasicRouterParams")
        .def(py::init<>())
        .def("create", &BasicRouterParams::create)
        .def_readwrite("latency", &BasicRouterParams::latency)
        .def_readwrite("router_id", &BasicRouterParams::router_id)
        ;

    py::class_<BasicRouter, ClockedObject, std::unique_ptr<BasicRouter, py::nodelete>>(m, "BasicRouter")
        ;

}

static EmbeddedPyBind embed_obj("BasicRouter", module_init, "ClockedObject");
