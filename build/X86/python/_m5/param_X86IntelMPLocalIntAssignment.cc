#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPLocalIntAssignment.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "enums/X86IntelMPInterruptType.hh"
#include "enums/X86IntelMPPolarity.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "enums/X86IntelMPTriggerMode.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPLocalIntAssignment");
    py::class_<X86IntelMPLocalIntAssignmentParams, X86IntelMPBaseConfigEntryParams, std::unique_ptr<X86IntelMPLocalIntAssignmentParams, py::nodelete>>(m, "X86IntelMPLocalIntAssignmentParams")
        .def(py::init<>())
        .def("create", &X86IntelMPLocalIntAssignmentParams::create)
        .def_readwrite("dest_local_apic_id", &X86IntelMPLocalIntAssignmentParams::dest_local_apic_id)
        .def_readwrite("dest_local_apic_intin", &X86IntelMPLocalIntAssignmentParams::dest_local_apic_intin)
        .def_readwrite("interrupt_type", &X86IntelMPLocalIntAssignmentParams::interrupt_type)
        .def_readwrite("polarity", &X86IntelMPLocalIntAssignmentParams::polarity)
        .def_readwrite("source_bus_id", &X86IntelMPLocalIntAssignmentParams::source_bus_id)
        .def_readwrite("source_bus_irq", &X86IntelMPLocalIntAssignmentParams::source_bus_irq)
        .def_readwrite("trigger", &X86IntelMPLocalIntAssignmentParams::trigger)
        ;

    py::class_<X86ISA::IntelMP::LocalIntAssignment, X86ISA::IntelMP::BaseConfigEntry, std::unique_ptr<X86ISA::IntelMP::LocalIntAssignment, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_LocalIntAssignment")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPLocalIntAssignment", module_init, "X86IntelMPBaseConfigEntry");
