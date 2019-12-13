#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/InstTracer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/insttracer.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_InstTracer");
    py::class_<InstTracerParams, SimObjectParams, std::unique_ptr<InstTracerParams, py::nodelete>>(m, "InstTracerParams")
        ;

    py::class_<Trace::InstTracer, SimObject, std::unique_ptr<Trace::InstTracer, py::nodelete>>(m, "Trace_COLONS_InstTracer")
        ;

}

static EmbeddedPyBind embed_obj("InstTracer", module_init, "SimObject");
