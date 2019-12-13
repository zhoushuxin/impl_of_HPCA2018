#include "enums/OpClass.hh"
namespace Enums {
     const char *OpClassStrings[Num_OpClass] =
    {
        "No_OpClass",
        "IntAlu",
        "IntMult",
        "IntDiv",
        "FloatAdd",
        "FloatCmp",
        "FloatCvt",
        "FloatMult",
        "FloatMultAcc",
        "FloatDiv",
        "FloatMisc",
        "FloatSqrt",
        "SimdAdd",
        "SimdAddAcc",
        "SimdAlu",
        "SimdCmp",
        "SimdCvt",
        "SimdMisc",
        "SimdMult",
        "SimdMultAcc",
        "SimdShift",
        "SimdShiftAcc",
        "SimdSqrt",
        "SimdFloatAdd",
        "SimdFloatAlu",
        "SimdFloatCmp",
        "SimdFloatCvt",
        "SimdFloatDiv",
        "SimdFloatMisc",
        "SimdFloatMult",
        "SimdFloatMultAcc",
        "SimdFloatSqrt",
        "MemRead",
        "MemWrite",
        "FloatMemRead",
        "FloatMemWrite",
        "IprAccess",
        "InstPrefetch",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_OpClass");

    py::enum_<Enums::OpClass>(m, "enum_OpClass")
        .value("No_OpClass", Enums::No_OpClass)
        .value("IntAlu", Enums::IntAlu)
        .value("IntMult", Enums::IntMult)
        .value("IntDiv", Enums::IntDiv)
        .value("FloatAdd", Enums::FloatAdd)
        .value("FloatCmp", Enums::FloatCmp)
        .value("FloatCvt", Enums::FloatCvt)
        .value("FloatMult", Enums::FloatMult)
        .value("FloatMultAcc", Enums::FloatMultAcc)
        .value("FloatDiv", Enums::FloatDiv)
        .value("FloatMisc", Enums::FloatMisc)
        .value("FloatSqrt", Enums::FloatSqrt)
        .value("SimdAdd", Enums::SimdAdd)
        .value("SimdAddAcc", Enums::SimdAddAcc)
        .value("SimdAlu", Enums::SimdAlu)
        .value("SimdCmp", Enums::SimdCmp)
        .value("SimdCvt", Enums::SimdCvt)
        .value("SimdMisc", Enums::SimdMisc)
        .value("SimdMult", Enums::SimdMult)
        .value("SimdMultAcc", Enums::SimdMultAcc)
        .value("SimdShift", Enums::SimdShift)
        .value("SimdShiftAcc", Enums::SimdShiftAcc)
        .value("SimdSqrt", Enums::SimdSqrt)
        .value("SimdFloatAdd", Enums::SimdFloatAdd)
        .value("SimdFloatAlu", Enums::SimdFloatAlu)
        .value("SimdFloatCmp", Enums::SimdFloatCmp)
        .value("SimdFloatCvt", Enums::SimdFloatCvt)
        .value("SimdFloatDiv", Enums::SimdFloatDiv)
        .value("SimdFloatMisc", Enums::SimdFloatMisc)
        .value("SimdFloatMult", Enums::SimdFloatMult)
        .value("SimdFloatMultAcc", Enums::SimdFloatMultAcc)
        .value("SimdFloatSqrt", Enums::SimdFloatSqrt)
        .value("MemRead", Enums::MemRead)
        .value("MemWrite", Enums::MemWrite)
        .value("FloatMemRead", Enums::FloatMemRead)
        .value("FloatMemWrite", Enums::FloatMemWrite)
        .value("IprAccess", Enums::IprAccess)
        .value("InstPrefetch", Enums::InstPrefetch)
        .value("Num_OpClass", Enums::Num_OpClass)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_OpClass", module_init);
