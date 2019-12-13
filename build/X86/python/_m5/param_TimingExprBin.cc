#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprBin.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
#include "enums/TimingExprOp.hh"
#include "cpu/timing_expr.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprBin");
    py::class_<TimingExprBinParams, TimingExprParams, std::unique_ptr<TimingExprBinParams, py::nodelete>>(m, "TimingExprBinParams")
        .def(py::init<>())
        .def("create", &TimingExprBinParams::create)
        .def_readwrite("left", &TimingExprBinParams::left)
        .def_readwrite("op", &TimingExprBinParams::op)
        .def_readwrite("right", &TimingExprBinParams::right)
        ;

    py::class_<TimingExprBin, TimingExpr, std::unique_ptr<TimingExprBin, py::nodelete>>(m, "TimingExprBin")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprBin", module_init, "TimingExpr");
