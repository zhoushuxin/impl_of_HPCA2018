#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprUn.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
#include "enums/TimingExprOp.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprUn");
    py::class_<TimingExprUnParams, TimingExprParams, std::unique_ptr<TimingExprUnParams, py::nodelete>>(m, "TimingExprUnParams")
        .def(py::init<>())
        .def("create", &TimingExprUnParams::create)
        .def_readwrite("arg", &TimingExprUnParams::arg)
        .def_readwrite("op", &TimingExprUnParams::op)
        ;

    py::class_<TimingExprUn, TimingExpr, std::unique_ptr<TimingExprUn, py::nodelete>>(m, "TimingExprUn")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprUn", module_init, "TimingExpr");
