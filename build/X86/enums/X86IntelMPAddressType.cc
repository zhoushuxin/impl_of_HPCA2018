#include "enums/X86IntelMPAddressType.hh"
namespace Enums {
     const char *X86IntelMPAddressTypeStrings[Num_X86IntelMPAddressType] =
    {
        "IOAddress",
        "MemoryAddress",
        "PrefetchAddress",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_X86IntelMPAddressType");

    py::enum_<Enums::X86IntelMPAddressType>(m, "enum_X86IntelMPAddressType")
        .value("IOAddress", Enums::IOAddress)
        .value("MemoryAddress", Enums::MemoryAddress)
        .value("PrefetchAddress", Enums::PrefetchAddress)
        .value("Num_X86IntelMPAddressType", Enums::Num_X86IntelMPAddressType)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_X86IntelMPAddressType", module_init);
