#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86E820Entry.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/e820.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86E820Entry");
    py::class_<X86E820EntryParams, SimObjectParams, std::unique_ptr<X86E820EntryParams, py::nodelete>>(m, "X86E820EntryParams")
        .def(py::init<>())
        .def("create", &X86E820EntryParams::create)
        .def_readwrite("addr", &X86E820EntryParams::addr)
        .def_readwrite("range_type", &X86E820EntryParams::range_type)
        .def_readwrite("size", &X86E820EntryParams::size)
        ;

    py::class_<X86ISA::E820Entry, SimObject, std::unique_ptr<X86ISA::E820Entry, py::nodelete>>(m, "X86ISA_COLONS_E820Entry")
        ;

}

static EmbeddedPyBind embed_obj("X86E820Entry", module_init, "SimObject");
