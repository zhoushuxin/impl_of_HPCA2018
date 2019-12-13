#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprIf.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
#include "cpu/timing_expr.hh"
#include "cpu/timing_expr.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprIf");
    py::class_<TimingExprIfParams, TimingExprParams, std::unique_ptr<TimingExprIfParams, py::nodelete>>(m, "TimingExprIfParams")
        .def(py::init<>())
        .def("create", &TimingExprIfParams::create)
        .def_readwrite("cond", &TimingExprIfParams::cond)
        .def_readwrite("falseExpr", &TimingExprIfParams::falseExpr)
        .def_readwrite("trueExpr", &TimingExprIfParams::trueExpr)
        ;

    py::class_<TimingExprIf, TimingExpr, std::unique_ptr<TimingExprIf, py::nodelete>>(m, "TimingExprIf")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprIf", module_init, "TimingExpr");
