#include "enums/AddrMap.hh"
namespace Enums {
     const char *AddrMapStrings[Num_AddrMap] =
    {
        "RoRaBaChCo",
        "RoRaBaCoCh",
        "RoCoRaBaCh",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_AddrMap");

    py::enum_<Enums::AddrMap>(m, "enum_AddrMap")
        .value("RoRaBaChCo", Enums::RoRaBaChCo)
        .value("RoRaBaCoCh", Enums::RoRaBaCoCh)
        .value("RoCoRaBaCh", Enums::RoCoRaBaCh)
        .value("Num_AddrMap", Enums::Num_AddrMap)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_AddrMap", module_init);
