#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleTrace.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/o3/probe/simple_trace.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleTrace");
    py::class_<SimpleTraceParams, ProbeListenerObjectParams, std::unique_ptr<SimpleTraceParams, py::nodelete>>(m, "SimpleTraceParams")
        .def(py::init<>())
        .def("create", &SimpleTraceParams::create)
        ;

    py::class_<SimpleTrace, ProbeListenerObject, std::unique_ptr<SimpleTrace, py::nodelete>>(m, "SimpleTrace")
        ;

}

static EmbeddedPyBind embed_obj("SimpleTrace", module_init, "ProbeListenerObject");
