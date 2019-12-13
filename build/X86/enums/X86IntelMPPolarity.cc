#include "enums/X86IntelMPPolarity.hh"
namespace Enums {
     const char *X86IntelMPPolarityStrings[Num_X86IntelMPPolarity] =
    {
        "ActiveHigh",
        "ActiveLow",
        "ConformPolarity",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_X86IntelMPPolarity");

    py::enum_<Enums::X86IntelMPPolarity>(m, "enum_X86IntelMPPolarity")
        .value("ActiveHigh", Enums::ActiveHigh)
        .value("ActiveLow", Enums::ActiveLow)
        .value("ConformPolarity", Enums::ConformPolarity)
        .value("Num_X86IntelMPPolarity", Enums::Num_X86IntelMPPolarity)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_X86IntelMPPolarity", module_init);
