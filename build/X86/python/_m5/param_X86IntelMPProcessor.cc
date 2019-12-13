#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPProcessor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPProcessor");
    py::class_<X86IntelMPProcessorParams, X86IntelMPBaseConfigEntryParams, std::unique_ptr<X86IntelMPProcessorParams, py::nodelete>>(m, "X86IntelMPProcessorParams")
        .def(py::init<>())
        .def("create", &X86IntelMPProcessorParams::create)
        .def_readwrite("bootstrap", &X86IntelMPProcessorParams::bootstrap)
        .def_readwrite("enable", &X86IntelMPProcessorParams::enable)
        .def_readwrite("family", &X86IntelMPProcessorParams::family)
        .def_readwrite("feature_flags", &X86IntelMPProcessorParams::feature_flags)
        .def_readwrite("local_apic_id", &X86IntelMPProcessorParams::local_apic_id)
        .def_readwrite("local_apic_version", &X86IntelMPProcessorParams::local_apic_version)
        .def_readwrite("model", &X86IntelMPProcessorParams::model)
        .def_readwrite("stepping", &X86IntelMPProcessorParams::stepping)
        ;

    py::class_<X86ISA::IntelMP::Processor, X86ISA::IntelMP::BaseConfigEntry, std::unique_ptr<X86ISA::IntelMP::Processor, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_Processor")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPProcessor", module_init, "X86IntelMPBaseConfigEntry");
