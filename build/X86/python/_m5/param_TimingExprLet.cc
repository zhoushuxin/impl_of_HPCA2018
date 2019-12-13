#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprLet.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include <vector>
#include "cpu/timing_expr.hh"
#include "cpu/timing_expr.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprLet");
    py::class_<TimingExprLetParams, TimingExprParams, std::unique_ptr<TimingExprLetParams, py::nodelete>>(m, "TimingExprLetParams")
        .def(py::init<>())
        .def("create", &TimingExprLetParams::create)
        .def_readwrite("defns", &TimingExprLetParams::defns)
        .def_readwrite("expr", &TimingExprLetParams::expr)
        ;

    py::class_<TimingExprLet, TimingExpr, std::unique_ptr<TimingExprLet, py::nodelete>>(m, "TimingExprLet")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprLet", module_init, "TimingExpr");
