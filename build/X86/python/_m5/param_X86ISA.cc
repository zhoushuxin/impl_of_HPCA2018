#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86ISA.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/isa.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86ISA");
    py::class_<X86ISAParams, SimObjectParams, std::unique_ptr<X86ISAParams, py::nodelete>>(m, "X86ISAParams")
        .def(py::init<>())
        .def("create", &X86ISAParams::create)
        ;

    py::class_<X86ISA::ISA, SimObject, std::unique_ptr<X86ISA::ISA, py::nodelete>>(m, "X86ISA_COLONS_ISA")
        ;

}

static EmbeddedPyBind embed_obj("X86ISA", module_init, "SimObject");
