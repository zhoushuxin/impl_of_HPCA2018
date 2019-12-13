#include "enums/Clusivity.hh"
namespace Enums {
     const char *ClusivityStrings[Num_Clusivity] =
    {
        "mostly_incl",
        "mostly_excl",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_Clusivity");

    py::enum_<Enums::Clusivity>(m, "enum_Clusivity")
        .value("mostly_incl", Enums::mostly_incl)
        .value("mostly_excl", Enums::mostly_excl)
        .value("Num_Clusivity", Enums::Num_Clusivity)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_Clusivity", module_init);
