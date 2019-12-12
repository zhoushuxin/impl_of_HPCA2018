#include "enums/Enum.hh"
namespace Enums {
     const char *EnumStrings[Num_Enum] =
    {
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_Enum");

    py::enum_<Enums::Enum>(m, "enum_Enum")
        .value("Num_Enum", Enums::Num_Enum)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_Enum", module_init);
