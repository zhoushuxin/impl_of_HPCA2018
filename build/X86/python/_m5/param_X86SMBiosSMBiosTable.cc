#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86SMBiosSMBiosTable.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/smbios.hh"

#include "base/types.hh"
#include "base/types.hh"
#include <vector>
#include "arch/x86/bios/smbios.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86SMBiosSMBiosTable");
    py::class_<X86SMBiosSMBiosTableParams, SimObjectParams, std::unique_ptr<X86SMBiosSMBiosTableParams, py::nodelete>>(m, "X86SMBiosSMBiosTableParams")
        .def(py::init<>())
        .def("create", &X86SMBiosSMBiosTableParams::create)
        .def_readwrite("major_version", &X86SMBiosSMBiosTableParams::major_version)
        .def_readwrite("minor_version", &X86SMBiosSMBiosTableParams::minor_version)
        .def_readwrite("structures", &X86SMBiosSMBiosTableParams::structures)
        ;

    py::class_<X86ISA::SMBios::SMBiosTable, SimObject, std::unique_ptr<X86ISA::SMBios::SMBiosTable, py::nodelete>>(m, "X86ISA_COLONS_SMBios_COLONS_SMBiosTable")
        ;

}

static EmbeddedPyBind embed_obj("X86SMBiosSMBiosTable", module_init, "SimObject");
