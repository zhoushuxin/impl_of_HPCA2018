#include "enums/X86IntelMPTriggerMode.hh"
namespace Enums {
     const char *X86IntelMPTriggerModeStrings[Num_X86IntelMPTriggerMode] =
    {
        "ConformTrigger",
        "EdgeTrigger",
        "LevelTrigger",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_X86IntelMPTriggerMode");

    py::enum_<Enums::X86IntelMPTriggerMode>(m, "enum_X86IntelMPTriggerMode")
        .value("ConformTrigger", Enums::ConformTrigger)
        .value("EdgeTrigger", Enums::EdgeTrigger)
        .value("LevelTrigger", Enums::LevelTrigger)
        .value("Num_X86IntelMPTriggerMode", Enums::Num_X86IntelMPTriggerMode)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_X86IntelMPTriggerMode", module_init);
