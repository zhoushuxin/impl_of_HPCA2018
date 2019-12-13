#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/IntelTrace.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/inteltrace.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_IntelTrace");
    py::class_<IntelTraceParams, InstTracerParams, std::unique_ptr<IntelTraceParams, py::nodelete>>(m, "IntelTraceParams")
        .def(py::init<>())
        .def("create", &IntelTraceParams::create)
        ;

    py::class_<Trace::IntelTrace, Trace::InstTracer, std::unique_ptr<Trace::IntelTrace, py::nodelete>>(m, "Trace_COLONS_IntelTrace")
        ;

}

static EmbeddedPyBind embed_obj("IntelTrace", module_init, "InstTracer");
