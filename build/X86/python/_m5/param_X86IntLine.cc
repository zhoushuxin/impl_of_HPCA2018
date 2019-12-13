#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntLine.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/intdev.hh"

#include "dev/x86/intdev.hh"
#include "dev/x86/intdev.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntLine");
    py::class_<X86IntLineParams, SimObjectParams, std::unique_ptr<X86IntLineParams, py::nodelete>>(m, "X86IntLineParams")
        .def(py::init<>())
        .def("create", &X86IntLineParams::create)
        .def_readwrite("sink", &X86IntLineParams::sink)
        .def_readwrite("source", &X86IntLineParams::source)
        ;

    py::class_<X86ISA::IntLine, SimObject, std::unique_ptr<X86ISA::IntLine, py::nodelete>>(m, "X86ISA_COLONS_IntLine")
        ;

}

static EmbeddedPyBind embed_obj("X86IntLine", module_init, "SimObject");
