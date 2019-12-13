#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86ACPIRSDT.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/acpi.hh"

#include <vector>
#include "arch/x86/bios/acpi.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86ACPIRSDT");
    py::class_<X86ACPIRSDTParams, X86ACPISysDescTableParams, std::unique_ptr<X86ACPIRSDTParams, py::nodelete>>(m, "X86ACPIRSDTParams")
        .def(py::init<>())
        .def("create", &X86ACPIRSDTParams::create)
        .def_readwrite("entries", &X86ACPIRSDTParams::entries)
        ;

    py::class_<X86ISA::ACPI::RSDT, X86ISA::ACPI::SysDescTable, std::unique_ptr<X86ISA::ACPI::RSDT, py::nodelete>>(m, "X86ISA_COLONS_ACPI_COLONS_RSDT")
        ;

}

static EmbeddedPyBind embed_obj("X86ACPIRSDT", module_init, "X86ACPISysDescTable");
