#include "enums/X86I8259CascadeMode.hh"
namespace Enums {
     const char *X86I8259CascadeModeStrings[Num_X86I8259CascadeMode] =
    {
        "I8259Master",
        "I8259Single",
        "I8259Slave",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_X86I8259CascadeMode");

    py::enum_<Enums::X86I8259CascadeMode>(m, "enum_X86I8259CascadeMode")
        .value("I8259Master", Enums::I8259Master)
        .value("I8259Single", Enums::I8259Single)
        .value("I8259Slave", Enums::I8259Slave)
        .value("Num_X86I8259CascadeMode", Enums::Num_X86I8259CascadeMode)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_X86I8259CascadeMode", module_init);
