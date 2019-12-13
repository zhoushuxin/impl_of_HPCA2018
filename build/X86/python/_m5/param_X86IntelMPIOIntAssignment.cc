#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPIOIntAssignment.hh"
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
    py::module m = m_internal.def_submodule("param_X86IntelMPIOIntAssignment");
    py::class_<X86IntelMPIOIntAssignmentParams, X86IntelMPBaseConfigEntryParams, std::unique_ptr<X86IntelMPIOIntAssignmentParams, py::nodelete>>(m, "X86IntelMPIOIntAssignmentParams")
        .def(py::init<>())
        .def("create", &X86IntelMPIOIntAssignmentParams::create)
        .def_readwrite("dest_io_apic_id", &X86IntelMPIOIntAssignmentParams::dest_io_apic_id)
        .def_readwrite("dest_io_apic_intin", &X86IntelMPIOIntAssignmentParams::dest_io_apic_intin)
        .def_readwrite("interrupt_type", &X86IntelMPIOIntAssignmentParams::interrupt_type)
        .def_readwrite("polarity", &X86IntelMPIOIntAssignmentParams::polarity)
        .def_readwrite("source_bus_id", &X86IntelMPIOIntAssignmentParams::source_bus_id)
        .def_readwrite("source_bus_irq", &X86IntelMPIOIntAssignmentParams::source_bus_irq)
        .def_readwrite("trigger", &X86IntelMPIOIntAssignmentParams::trigger)
        ;

    py::class_<X86ISA::IntelMP::IOIntAssignment, X86ISA::IntelMP::BaseConfigEntry, std::unique_ptr<X86ISA::IntelMP::IOIntAssignment, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_IOIntAssignment")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPIOIntAssignment", module_init, "X86IntelMPBaseConfigEntry");
