#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ExeTracer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/exetrace.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ExeTracer");
    py::class_<ExeTracerParams, InstTracerParams, std::unique_ptr<ExeTracerParams, py::nodelete>>(m, "ExeTracerParams")
        .def(py::init<>())
        .def("create", &ExeTracerParams::create)
        ;

    py::class_<Trace::ExeTracer, Trace::InstTracer, std::unique_ptr<Trace::ExeTracer, py::nodelete>>(m, "Trace_COLONS_ExeTracer")
        ;

}

static EmbeddedPyBind embed_obj("ExeTracer", module_init, "InstTracer");
