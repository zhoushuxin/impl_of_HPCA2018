#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPExtConfigEntry.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPExtConfigEntry");
    py::class_<X86IntelMPExtConfigEntryParams, SimObjectParams, std::unique_ptr<X86IntelMPExtConfigEntryParams, py::nodelete>>(m, "X86IntelMPExtConfigEntryParams")
        ;

    py::class_<X86ISA::IntelMP::ExtConfigEntry, SimObject, std::unique_ptr<X86ISA::IntelMP::ExtConfigEntry, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_ExtConfigEntry")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPExtConfigEntry", module_init, "SimObject");
