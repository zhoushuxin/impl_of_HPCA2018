#include "enums/MemoryMode.hh"
namespace Enums {
     const char *MemoryModeStrings[Num_MemoryMode] =
    {
        "invalid",
        "atomic",
        "timing",
        "atomic_noncaching",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_MemoryMode");

    py::enum_<Enums::MemoryMode>(m, "enum_MemoryMode")
        .value("invalid", Enums::invalid)
        .value("atomic", Enums::atomic)
        .value("timing", Enums::timing)
        .value("atomic_noncaching", Enums::atomic_noncaching)
        .value("Num_MemoryMode", Enums::Num_MemoryMode)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_MemoryMode", module_init);
