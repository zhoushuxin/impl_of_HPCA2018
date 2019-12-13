#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86TLB.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/tlb.hh"

#include "base/types.hh"
#include "arch/x86/pagetable_walker.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86TLB");
    py::class_<X86TLBParams, BaseTLBParams, std::unique_ptr<X86TLBParams, py::nodelete>>(m, "X86TLBParams")
        .def(py::init<>())
        .def("create", &X86TLBParams::create)
        .def_readwrite("size", &X86TLBParams::size)
        .def_readwrite("walker", &X86TLBParams::walker)
        ;

    py::class_<X86ISA::TLB, BaseTLB, std::unique_ptr<X86ISA::TLB, py::nodelete>>(m, "X86ISA_COLONS_TLB")
        ;

}

static EmbeddedPyBind embed_obj("X86TLB", module_init, "BaseTLB");
