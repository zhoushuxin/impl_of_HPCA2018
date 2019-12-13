#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Switch.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/simple/Switch.hh"

#include <vector>
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Switch");
    py::class_<SwitchParams, BasicRouterParams, std::unique_ptr<SwitchParams, py::nodelete>>(m, "SwitchParams")
        .def(py::init<>())
        .def("create", &SwitchParams::create)
        .def_readwrite("port_buffers", &SwitchParams::port_buffers)
        .def_readwrite("virt_nets", &SwitchParams::virt_nets)
        ;

    py::class_<Switch, BasicRouter, std::unique_ptr<Switch, py::nodelete>>(m, "Switch")
        ;

}

static EmbeddedPyBind embed_obj("Switch", module_init, "BasicRouter");
