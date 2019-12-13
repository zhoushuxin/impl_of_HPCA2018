#include "enums/PMType.hh"
namespace Enums {
     const char *PMTypeStrings[Num_PMType] =
    {
        "All",
        "Static",
        "Dynamic",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_PMType");

    py::enum_<Enums::PMType>(m, "enum_PMType")
        .value("All", Enums::All)
        .value("Static", Enums::Static)
        .value("Dynamic", Enums::Dynamic)
        .value("Num_PMType", Enums::Num_PMType)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_PMType", module_init);
