#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingExprRef.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingExprRef");
    py::class_<TimingExprRefParams, TimingExprParams, std::unique_ptr<TimingExprRefParams, py::nodelete>>(m, "TimingExprRefParams")
        .def(py::init<>())
        .def("create", &TimingExprRefParams::create)
        .def_readwrite("index", &TimingExprRefParams::index)
        ;

    py::class_<TimingExprRef, TimingExpr, std::unique_ptr<TimingExprRef, py::nodelete>>(m, "TimingExprRef")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprRef", module_init, "TimingExpr");
