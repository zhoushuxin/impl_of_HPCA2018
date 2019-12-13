#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprLiteral.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprLiteral");
    py::class_<TimingExprLiteralParams, TimingExprParams, std::unique_ptr<TimingExprLiteralParams, py::nodelete>>(m, "TimingExprLiteralParams")
        .def(py::init<>())
        .def("create", &TimingExprLiteralParams::create)
        .def_readwrite("value", &TimingExprLiteralParams::value)
        ;

    py::class_<TimingExprLiteral, TimingExpr, std::unique_ptr<TimingExprLiteral, py::nodelete>>(m, "TimingExprLiteral")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprLiteral", module_init, "TimingExpr");
