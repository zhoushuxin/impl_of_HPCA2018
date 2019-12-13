#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPBusHierarchy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPBusHierarchy");
    py::class_<X86IntelMPBusHierarchyParams, X86IntelMPExtConfigEntryParams, std::unique_ptr<X86IntelMPBusHierarchyParams, py::nodelete>>(m, "X86IntelMPBusHierarchyParams")
        .def(py::init<>())
        .def("create", &X86IntelMPBusHierarchyParams::create)
        .def_readwrite("bus_id", &X86IntelMPBusHierarchyParams::bus_id)
        .def_readwrite("parent_bus", &X86IntelMPBusHierarchyParams::parent_bus)
        .def_readwrite("subtractive_decode", &X86IntelMPBusHierarchyParams::subtractive_decode)
        ;

    py::class_<X86ISA::IntelMP::BusHierarchy, X86ISA::IntelMP::ExtConfigEntry, std::unique_ptr<X86ISA::IntelMP::BusHierarchy, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_BusHierarchy")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPBusHierarchy", module_init, "X86IntelMPExtConfigEntry");
