#include "enums/X86IntelMPInterruptType.hh"
namespace Enums {
     const char *X86IntelMPInterruptTypeStrings[Num_X86IntelMPInterruptType] =
    {
        "ExtInt",
        "INT",
        "NMI",
        "SMI",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_X86IntelMPInterruptType");

    py::enum_<Enums::X86IntelMPInterruptType>(m, "enum_X86IntelMPInterruptType")
        .value("ExtInt", Enums::ExtInt)
        .value("INT", Enums::INT)
        .value("NMI", Enums::NMI)
        .value("SMI", Enums::SMI)
        .value("Num_X86IntelMPInterruptType", Enums::Num_X86IntelMPInterruptType)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_X86IntelMPInterruptType", module_init);
