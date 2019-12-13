#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/NativeTrace.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/nativetrace.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_NativeTrace");
    py::class_<NativeTraceParams, ExeTracerParams, std::unique_ptr<NativeTraceParams, py::nodelete>>(m, "NativeTraceParams")
        ;

    py::class_<Trace::NativeTrace, Trace::ExeTracer, std::unique_ptr<Trace::NativeTrace, py::nodelete>>(m, "Trace_COLONS_NativeTrace")
        ;

}

static EmbeddedPyBind embed_obj("NativeTrace", module_init, "ExeTracer");
