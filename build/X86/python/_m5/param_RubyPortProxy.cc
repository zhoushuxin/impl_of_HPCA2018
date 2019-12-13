#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyPortProxy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/system/RubyPortProxy.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyPortProxy");
    py::class_<RubyPortProxyParams, RubyPortParams, std::unique_ptr<RubyPortProxyParams, py::nodelete>>(m, "RubyPortProxyParams")
        .def(py::init<>())
        .def("create", &RubyPortProxyParams::create)
        ;

    py::class_<RubyPortProxy, RubyPort, std::unique_ptr<RubyPortProxy, py::nodelete>>(m, "RubyPortProxy")
        ;

}

static EmbeddedPyBind embed_obj("RubyPortProxy", module_init, "RubyPort");
