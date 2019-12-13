#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntelMPFloatingPointer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/intelmp.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntelMPFloatingPointer");
    py::class_<X86IntelMPFloatingPointerParams, SimObjectParams, std::unique_ptr<X86IntelMPFloatingPointerParams, py::nodelete>>(m, "X86IntelMPFloatingPointerParams")
        .def(py::init<>())
        .def("create", &X86IntelMPFloatingPointerParams::create)
        .def_readwrite("default_config", &X86IntelMPFloatingPointerParams::default_config)
        .def_readwrite("imcr_present", &X86IntelMPFloatingPointerParams::imcr_present)
        .def_readwrite("spec_rev", &X86IntelMPFloatingPointerParams::spec_rev)
        ;

    py::class_<X86ISA::IntelMP::FloatingPointer, SimObject, std::unique_ptr<X86ISA::IntelMP::FloatingPointer, py::nodelete>>(m, "X86ISA_COLONS_IntelMP_COLONS_FloatingPointer")
        ;

}

static EmbeddedPyBind embed_obj("X86IntelMPFloatingPointer", module_init, "SimObject");
