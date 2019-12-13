#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPBus.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPBus");
    py::class_<X86IntelMPBusParams, X86IntelMPBaseConfigEntryParams, std::unique_ptr<X86IntelMPBusParams, py::nodelete>>(m, "X86IntelMPBusParams")
        .def(py::init<>())
        .def("create", &X86IntelMPBusParams::create)
        .def_readwrite("bus_id", &X86IntelMPBusParams::bus_id)
        .def_readwrite("bus_type", &X86IntelMPBusParams::bus_type)
        ;

    py::class_<X86ISA::IntelMP::Bus, X86ISA::IntelMP::BaseConfigEntry, std::unique_ptr<X86ISA::IntelMP::Bus, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_Bus")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPBus", module_init, "X86IntelMPBaseConfigEntry");
