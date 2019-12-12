#include "enums/NoMaliGpuType.hh"
namespace Enums {
     const char *NoMaliGpuTypeStrings[Num_NoMaliGpuType] =
    {
        "T60x",
        "T62x",
        "T760",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_NoMaliGpuType");

    py::enum_<Enums::NoMaliGpuType>(m, "enum_NoMaliGpuType")
        .value("T60x", Enums::T60x)
        .value("T62x", Enums::T62x)
        .value("T760", Enums::T760)
        .value("Num_NoMaliGpuType", Enums::Num_NoMaliGpuType)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_NoMaliGpuType", module_init);
