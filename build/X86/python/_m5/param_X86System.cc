#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86System.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/system.hh"

#include "arch/x86/bios/acpi.hh"
#include "arch/x86/bios/intelmp.hh"
#include "arch/x86/bios/intelmp.hh"
#include "arch/x86/bios/smbios.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86System");
    py::class_<X86SystemParams, SystemParams, std::unique_ptr<X86SystemParams, py::nodelete>>(m, "X86SystemParams")
        .def(py::init<>())
        .def("create", &X86SystemParams::create)
        .def_readwrite("acpi_description_table_pointer", &X86SystemParams::acpi_description_table_pointer)
        .def_readwrite("intel_mp_pointer", &X86SystemParams::intel_mp_pointer)
        .def_readwrite("intel_mp_table", &X86SystemParams::intel_mp_table)
        .def_readwrite("smbios_table", &X86SystemParams::smbios_table)
        ;

    py::class_<X86System, System, std::unique_ptr<X86System, py::nodelete>>(m, "X86System")
        ;

}

static EmbeddedPyBind embed_obj("X86System", module_init, "System");
