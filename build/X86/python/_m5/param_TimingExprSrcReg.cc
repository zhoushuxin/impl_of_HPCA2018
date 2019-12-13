#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprSrcReg.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprSrcReg");
    py::class_<TimingExprSrcRegParams, TimingExprParams, std::unique_ptr<TimingExprSrcRegParams, py::nodelete>>(m, "TimingExprSrcRegParams")
        .def(py::init<>())
        .def("create", &TimingExprSrcRegParams::create)
        .def_readwrite("index", &TimingExprSrcRegParams::index)
        ;

    py::class_<TimingExprSrcReg, TimingExpr, std::unique_ptr<TimingExprSrcReg, py::nodelete>>(m, "TimingExprSrcReg")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprSrcReg", module_init, "TimingExpr");
