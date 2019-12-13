#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DVFSHandler.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/dvfs_handler.hh"

#include <vector>
#include "sim/clock_domain.hh"
#include "sim/clock_domain.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DVFSHandler");
    py::class_<DVFSHandlerParams, SimObjectParams, std::unique_ptr<DVFSHandlerParams, py::nodelete>>(m, "DVFSHandlerParams")
        .def(py::init<>())
        .def("create", &DVFSHandlerParams::create)
        .def_readwrite("domains", &DVFSHandlerParams::domains)
        .def_readwrite("enable", &DVFSHandlerParams::enable)
        .def_readwrite("sys_clk_domain", &DVFSHandlerParams::sys_clk_domain)
        .def_readwrite("transition_latency", &DVFSHandlerParams::transition_latency)
        ;

    py::class_<DVFSHandler, SimObject, std::unique_ptr<DVFSHandler, py::nodelete>>(m, "DVFSHandler")
        ;

}

static EmbeddedPyBind embed_obj("DVFSHandler", module_init, "SimObject");
