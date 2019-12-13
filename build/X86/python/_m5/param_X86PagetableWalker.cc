#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86PagetableWalker.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/pagetable_walker.hh"

#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86PagetableWalker");
    py::class_<X86PagetableWalkerParams, MemObjectParams, std::unique_ptr<X86PagetableWalkerParams, py::nodelete>>(m, "X86PagetableWalkerParams")
        .def(py::init<>())
        .def("create", &X86PagetableWalkerParams::create)
        .def_readwrite("num_squash_per_cycle", &X86PagetableWalkerParams::num_squash_per_cycle)
        .def_readwrite("system", &X86PagetableWalkerParams::system)
        .def_readwrite("port_port_connection_count", &X86PagetableWalkerParams::port_port_connection_count)
        ;

    py::class_<X86ISA::Walker, MemObject, std::unique_ptr<X86ISA::Walker, py::nodelete>>(m, "X86ISA_COLONS_Walker")
        ;

}

static EmbeddedPyBind embed_obj("X86PagetableWalker", module_init, "MemObject");
