#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MathExprPowerModel.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/mathexpr_powermodel.hh"

#include <string>
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MathExprPowerModel");
    py::class_<MathExprPowerModelParams, PowerModelStateParams, std::unique_ptr<MathExprPowerModelParams, py::nodelete>>(m, "MathExprPowerModelParams")
        .def(py::init<>())
        .def("create", &MathExprPowerModelParams::create)
        .def_readwrite("dyn", &MathExprPowerModelParams::dyn)
        .def_readwrite("st", &MathExprPowerModelParams::st)
        ;

    py::class_<MathExprPowerModel, PowerModelState, std::unique_ptr<MathExprPowerModel, py::nodelete>>(m, "MathExprPowerModel")
        ;

}

static EmbeddedPyBind embed_obj("MathExprPowerModel", module_init, "PowerModelState");
