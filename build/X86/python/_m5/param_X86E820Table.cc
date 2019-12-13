#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86E820Table.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/e820.hh"

#include <vector>
#include "arch/x86/bios/e820.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86E820Table");
    py::class_<X86E820TableParams, SimObjectParams, std::unique_ptr<X86E820TableParams, py::nodelete>>(m, "X86E820TableParams")
        .def(py::init<>())
        .def("create", &X86E820TableParams::create)
        .def_readwrite("entries", &X86E820TableParams::entries)
        ;

    py::class_<X86ISA::E820Table, SimObject, std::unique_ptr<X86ISA::E820Table, py::nodelete>>(m, "X86ISA_COLONS_E820Table")
        ;

}

static EmbeddedPyBind embed_obj("X86E820Table", module_init, "SimObject");
