#include "enums/TimingExprOp.hh"
namespace Enums {
     const char *TimingExprOpStrings[Num_TimingExprOp] =
    {
        "timingExprAdd",
        "timingExprSub",
        "timingExprUMul",
        "timingExprUDiv",
        "timingExprSMul",
        "timingExprSDiv",
        "timingExprUCeilDiv",
        "timingExprEqual",
        "timingExprNotEqual",
        "timingExprULessThan",
        "timingExprUGreaterThan",
        "timingExprSLessThan",
        "timingExprSGreaterThan",
        "timingExprInvert",
        "timingExprNot",
        "timingExprAnd",
        "timingExprOr",
        "timingExprSizeInBits",
        "timingExprSignExtend32To64",
        "timingExprAbs",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_TimingExprOp");

    py::enum_<Enums::TimingExprOp>(m, "enum_TimingExprOp")
        .value("timingExprAdd", Enums::timingExprAdd)
        .value("timingExprSub", Enums::timingExprSub)
        .value("timingExprUMul", Enums::timingExprUMul)
        .value("timingExprUDiv", Enums::timingExprUDiv)
        .value("timingExprSMul", Enums::timingExprSMul)
        .value("timingExprSDiv", Enums::timingExprSDiv)
        .value("timingExprUCeilDiv", Enums::timingExprUCeilDiv)
        .value("timingExprEqual", Enums::timingExprEqual)
        .value("timingExprNotEqual", Enums::timingExprNotEqual)
        .value("timingExprULessThan", Enums::timingExprULessThan)
        .value("timingExprUGreaterThan", Enums::timingExprUGreaterThan)
        .value("timingExprSLessThan", Enums::timingExprSLessThan)
        .value("timingExprSGreaterThan", Enums::timingExprSGreaterThan)
        .value("timingExprInvert", Enums::timingExprInvert)
        .value("timingExprNot", Enums::timingExprNot)
        .value("timingExprAnd", Enums::timingExprAnd)
        .value("timingExprOr", Enums::timingExprOr)
        .value("timingExprSizeInBits", Enums::timingExprSizeInBits)
        .value("timingExprSignExtend32To64", Enums::timingExprSignExtend32To64)
        .value("timingExprAbs", Enums::timingExprAbs)
        .value("Num_TimingExprOp", Enums::Num_TimingExprOp)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_TimingExprOp", module_init);
