#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntSourcePin.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/intdev.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntSourcePin");
    py::class_<X86IntSourcePinParams, SimObjectParams, std::unique_ptr<X86IntSourcePinParams, py::nodelete>>(m, "X86IntSourcePinParams")
        .def(py::init<>())
        .def("create", &X86IntSourcePinParams::create)
        ;

    py::class_<X86ISA::IntSourcePin, SimObject, std::unique_ptr<X86ISA::IntSourcePin, py::nodelete>>(m, "X86ISA_COLONS_IntSourcePin")
        ;

}

static EmbeddedPyBind embed_obj("X86IntSourcePin", module_init, "SimObject");
