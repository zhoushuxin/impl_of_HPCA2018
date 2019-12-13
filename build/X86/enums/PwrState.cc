#include "enums/PwrState.hh"
namespace Enums {
     const char *PwrStateStrings[Num_PwrState] =
    {
        "UNDEFINED",
        "ON",
        "CLK_GATED",
        "SRAM_RETENTION",
        "OFF",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_PwrState");

    py::enum_<Enums::PwrState>(m, "enum_PwrState")
        .value("UNDEFINED", Enums::UNDEFINED)
        .value("ON", Enums::ON)
        .value("CLK_GATED", Enums::CLK_GATED)
        .value("SRAM_RETENTION", Enums::SRAM_RETENTION)
        .value("OFF", Enums::OFF)
        .value("Num_PwrState", Enums::Num_PwrState)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_PwrState", module_init);
