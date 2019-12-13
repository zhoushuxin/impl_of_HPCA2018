#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprReadIntReg.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprReadIntReg");
    py::class_<TimingExprReadIntRegParams, TimingExprParams, std::unique_ptr<TimingExprReadIntRegParams, py::nodelete>>(m, "TimingExprReadIntRegParams")
        .def(py::init<>())
        .def("create", &TimingExprReadIntRegParams::create)
        .def_readwrite("reg", &TimingExprReadIntRegParams::reg)
        ;

    py::class_<TimingExprReadIntReg, TimingExpr, std::unique_ptr<TimingExprReadIntReg, py::nodelete>>(m, "TimingExprReadIntReg")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprReadIntReg", module_init, "TimingExpr");
