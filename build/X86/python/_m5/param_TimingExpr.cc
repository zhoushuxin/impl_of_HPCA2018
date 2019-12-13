#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExpr.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExpr");
    py::class_<TimingExprParams, SimObjectParams, std::unique_ptr<TimingExprParams, py::nodelete>>(m, "TimingExprParams")
        ;

    py::class_<TimingExpr, SimObject, std::unique_ptr<TimingExpr, py::nodelete>>(m, "TimingExpr")
        ;

}

static EmbeddedPyBind embed_obj("TimingExpr", module_init, "SimObject");
