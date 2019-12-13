#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPConfigTable.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include <vector>
#include "arch/x86/bios/intelmp.hh"
#include <vector>
#include "arch/x86/bios/intelmp.hh"
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include <string>
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPConfigTable");
    py::class_<X86IntelMPConfigTableParams, SimObjectParams, std::unique_ptr<X86IntelMPConfigTableParams, py::nodelete>>(m, "X86IntelMPConfigTableParams")
        .def(py::init<>())
        .def("create", &X86IntelMPConfigTableParams::create)
        .def_readwrite("base_entries", &X86IntelMPConfigTableParams::base_entries)
        .def_readwrite("ext_entries", &X86IntelMPConfigTableParams::ext_entries)
        .def_readwrite("local_apic", &X86IntelMPConfigTableParams::local_apic)
        .def_readwrite("oem_id", &X86IntelMPConfigTableParams::oem_id)
        .def_readwrite("oem_table_addr", &X86IntelMPConfigTableParams::oem_table_addr)
        .def_readwrite("oem_table_size", &X86IntelMPConfigTableParams::oem_table_size)
        .def_readwrite("product_id", &X86IntelMPConfigTableParams::product_id)
        .def_readwrite("spec_rev", &X86IntelMPConfigTableParams::spec_rev)
        ;

    py::class_<X86ISA::IntelMP::ConfigTable, SimObject, std::unique_ptr<X86ISA::IntelMP::ConfigTable, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_ConfigTable")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPConfigTable", module_init, "SimObject");
