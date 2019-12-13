#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86ACPIXSDT.hh"
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
    py::module m = m_internal.def_submodule("param_X86ACPIXSDT");
    py::class_<X86ACPIXSDTParams, X86ACPISysDescTableParams, std::unique_ptr<X86ACPIXSDTParams, py::nodelete>>(m, "X86ACPIXSDTParams")
        .def(py::init<>())
        .def("create", &X86ACPIXSDTParams::create)
        .def_readwrite("entries", &X86ACPIXSDTParams::entries)
        ;

    py::class_<X86ISA::ACPI::XSDT, X86ISA::ACPI::SysDescTable, std::unique_ptr<X86ISA::ACPI::XSDT, py::nodelete>>(m, "X86ISA_COLONS_ACPI_COLONS_XSDT")
        ;

}

static EmbeddedPyBind embed_obj("X86ACPIXSDT", module_init, "X86ACPISysDescTable");
