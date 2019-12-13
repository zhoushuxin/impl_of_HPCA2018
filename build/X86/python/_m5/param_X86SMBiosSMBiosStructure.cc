#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86SMBiosSMBiosStructure.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/smbios.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86SMBiosSMBiosStructure");
    py::class_<X86SMBiosSMBiosStructureParams, SimObjectParams, std::unique_ptr<X86SMBiosSMBiosStructureParams, py::nodelete>>(m, "X86SMBiosSMBiosStructureParams")
        ;

    py::class_<X86ISA::SMBios::SMBiosStructure, SimObject, std::unique_ptr<X86ISA::SMBios::SMBiosStructure, py::nodelete>>(m, "X86ISA_COLONS_SMBios_COLONS_SMBiosStructure")
        ;

}

static EmbeddedPyBind embed_obj("X86SMBiosSMBiosStructure", module_init, "SimObject");
