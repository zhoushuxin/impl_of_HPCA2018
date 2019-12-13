#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86ACPIRSDP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/acpi.hh"

#include <string>
#include "base/types.hh"
#include "arch/x86/bios/acpi.hh"
#include "arch/x86/bios/acpi.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86ACPIRSDP");
    py::class_<X86ACPIRSDPParams, SimObjectParams, std::unique_ptr<X86ACPIRSDPParams, py::nodelete>>(m, "X86ACPIRSDPParams")
        .def(py::init<>())
        .def("create", &X86ACPIRSDPParams::create)
        .def_readwrite("oem_id", &X86ACPIRSDPParams::oem_id)
        .def_readwrite("revision", &X86ACPIRSDPParams::revision)
        .def_readwrite("rsdt", &X86ACPIRSDPParams::rsdt)
        .def_readwrite("xsdt", &X86ACPIRSDPParams::xsdt)
        ;

    py::class_<X86ISA::ACPI::RSDP, SimObject, std::unique_ptr<X86ISA::ACPI::RSDP, py::nodelete>>(m, "X86ISA_COLONS_ACPI_COLONS_RSDP")
        ;

}

static EmbeddedPyBind embed_obj("X86ACPIRSDP", module_init, "SimObject");
