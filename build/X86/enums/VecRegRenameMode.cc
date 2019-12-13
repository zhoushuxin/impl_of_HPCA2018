#include "enums/VecRegRenameMode.hh"
namespace Enums {
     const char *VecRegRenameModeStrings[Num_VecRegRenameMode] =
    {
        "Full",
        "Elem",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_VecRegRenameMode");

    py::enum_<Enums::VecRegRenameMode>(m, "enum_VecRegRenameMode")
        .value("Full", Enums::Full)
        .value("Elem", Enums::Elem)
        .value("Num_VecRegRenameMode", Enums::Num_VecRegRenameMode)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_VecRegRenameMode", module_init);
