#include "enums/X86IntelMPRangeList.hh"
namespace Enums {
     const char *X86IntelMPRangeListStrings[Num_X86IntelMPRangeList] =
    {
        "ISACompatible",
        "VGACompatible",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_X86IntelMPRangeList");

    py::enum_<Enums::X86IntelMPRangeList>(m, "enum_X86IntelMPRangeList")
        .value("ISACompatible", Enums::ISACompatible)
        .value("VGACompatible", Enums::VGACompatible)
        .value("Num_X86IntelMPRangeList", Enums::Num_X86IntelMPRangeList)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_X86IntelMPRangeList", module_init);
