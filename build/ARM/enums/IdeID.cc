#include "enums/IdeID.hh"
namespace Enums {
     const char *IdeIDStrings[Num_IdeID] =
    {
        "master",
        "slave",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_IdeID");

    py::enum_<Enums::IdeID>(m, "enum_IdeID")
        .value("master", Enums::master)
        .value("slave", Enums::slave)
        .value("Num_IdeID", Enums::Num_IdeID)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_IdeID", module_init);
