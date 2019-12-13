#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86ACPISysDescTable.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/acpi.hh"

#include <string>
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86ACPISysDescTable");
    py::class_<X86ACPISysDescTableParams, SimObjectParams, std::unique_ptr<X86ACPISysDescTableParams, py::nodelete>>(m, "X86ACPISysDescTableParams")
        .def_readwrite("creator_id", &X86ACPISysDescTableParams::creator_id)
        .def_readwrite("creator_revision", &X86ACPISysDescTableParams::creator_revision)
        .def_readwrite("oem_id", &X86ACPISysDescTableParams::oem_id)
        .def_readwrite("oem_revision", &X86ACPISysDescTableParams::oem_revision)
        .def_readwrite("oem_table_id", &X86ACPISysDescTableParams::oem_table_id)
        ;

    py::class_<X86ISA::ACPI::SysDescTable, SimObject, std::unique_ptr<X86ISA::ACPI::SysDescTable, py::nodelete>>(m, "X86ISA_COLONS_ACPI_COLONS_SysDescTable")
        ;

}

static EmbeddedPyBind embed_obj("X86ACPISysDescTable", module_init, "SimObject");
