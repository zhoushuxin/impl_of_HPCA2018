#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPCompatAddrSpaceMod.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "enums/X86IntelMPRangeList.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPCompatAddrSpaceMod");
    py::class_<X86IntelMPCompatAddrSpaceModParams, X86IntelMPExtConfigEntryParams, std::unique_ptr<X86IntelMPCompatAddrSpaceModParams, py::nodelete>>(m, "X86IntelMPCompatAddrSpaceModParams")
        .def(py::init<>())
        .def("create", &X86IntelMPCompatAddrSpaceModParams::create)
        .def_readwrite("add", &X86IntelMPCompatAddrSpaceModParams::add)
        .def_readwrite("bus_id", &X86IntelMPCompatAddrSpaceModParams::bus_id)
        .def_readwrite("range_list", &X86IntelMPCompatAddrSpaceModParams::range_list)
        ;

    py::class_<X86ISA::IntelMP::CompatAddrSpaceMod, X86ISA::IntelMP::ExtConfigEntry, std::unique_ptr<X86ISA::IntelMP::CompatAddrSpaceMod, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_CompatAddrSpaceMod")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPCompatAddrSpaceMod", module_init, "X86IntelMPExtConfigEntry");
