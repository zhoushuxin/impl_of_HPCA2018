#include "enums/ArmMachineType.hh"
namespace Enums {
     const char *ArmMachineTypeStrings[Num_ArmMachineType] =
    {
        "DTOnly",
        "RealViewEB",
        "RealViewPBX",
        "VExpress_EMM",
        "VExpress_EMM64",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_ArmMachineType");

    py::enum_<Enums::ArmMachineType>(m, "enum_ArmMachineType")
        .value("DTOnly", Enums::DTOnly)
        .value("RealViewEB", Enums::RealViewEB)
        .value("RealViewPBX", Enums::RealViewPBX)
        .value("VExpress_EMM", Enums::VExpress_EMM)
        .value("VExpress_EMM64", Enums::VExpress_EMM64)
        .value("Num_ArmMachineType", Enums::Num_ArmMachineType)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_ArmMachineType", module_init);
