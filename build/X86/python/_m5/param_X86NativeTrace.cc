#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86NativeTrace.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/nativetrace.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86NativeTrace");
    py::class_<X86NativeTraceParams, NativeTraceParams, std::unique_ptr<X86NativeTraceParams, py::nodelete>>(m, "X86NativeTraceParams")
        .def(py::init<>())
        .def("create", &X86NativeTraceParams::create)
        ;

    py::class_<Trace::X86NativeTrace, Trace::NativeTrace, std::unique_ptr<Trace::X86NativeTrace, py::nodelete>>(m, "Trace_COLONS_X86NativeTrace")
        ;

}

static EmbeddedPyBind embed_obj("X86NativeTrace", module_init, "NativeTrace");
