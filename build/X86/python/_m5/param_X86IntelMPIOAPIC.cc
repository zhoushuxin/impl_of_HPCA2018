#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPIOAPIC.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPIOAPIC");
    py::class_<X86IntelMPIOAPICParams, X86IntelMPBaseConfigEntryParams, std::unique_ptr<X86IntelMPIOAPICParams, py::nodelete>>(m, "X86IntelMPIOAPICParams")
        .def(py::init<>())
        .def("create", &X86IntelMPIOAPICParams::create)
        .def_readwrite("address", &X86IntelMPIOAPICParams::address)
        .def_readwrite("enable", &X86IntelMPIOAPICParams::enable)
        .def_readwrite("id", &X86IntelMPIOAPICParams::id)
        .def_readwrite("version", &X86IntelMPIOAPICParams::version)
        ;

    py::class_<X86ISA::IntelMP::IOAPIC, X86ISA::IntelMP::BaseConfigEntry, std::unique_ptr<X86ISA::IntelMP::IOAPIC, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_IOAPIC")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPIOAPIC", module_init, "X86IntelMPBaseConfigEntry");
