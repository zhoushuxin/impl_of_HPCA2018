#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPBaseConfigEntry.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPBaseConfigEntry");
    py::class_<X86IntelMPBaseConfigEntryParams, SimObjectParams, std::unique_ptr<X86IntelMPBaseConfigEntryParams, py::nodelete>>(m, "X86IntelMPBaseConfigEntryParams")
        ;

    py::class_<X86ISA::IntelMP::BaseConfigEntry, SimObject, std::unique_ptr<X86ISA::IntelMP::BaseConfigEntry, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_BaseConfigEntry")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPBaseConfigEntry", module_init, "SimObject");
