#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPAddrSpaceMapping.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "enums/X86IntelMPAddressType.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPAddrSpaceMapping");
    py::class_<X86IntelMPAddrSpaceMappingParams, X86IntelMPExtConfigEntryParams, std::unique_ptr<X86IntelMPAddrSpaceMappingParams, py::nodelete>>(m, "X86IntelMPAddrSpaceMappingParams")
        .def(py::init<>())
        .def("create", &X86IntelMPAddrSpaceMappingParams::create)
        .def_readwrite("address", &X86IntelMPAddrSpaceMappingParams::address)
        .def_readwrite("address_type", &X86IntelMPAddrSpaceMappingParams::address_type)
        .def_readwrite("bus_id", &X86IntelMPAddrSpaceMappingParams::bus_id)
        .def_readwrite("length", &X86IntelMPAddrSpaceMappingParams::length)
        ;

    py::class_<X86ISA::IntelMP::AddrSpaceMapping, X86ISA::IntelMP::ExtConfigEntry, std::unique_ptr<X86ISA::IntelMP::AddrSpaceMapping, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_AddrSpaceMapping")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPAddrSpaceMapping", module_init, "X86IntelMPExtConfigEntry");
