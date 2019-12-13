#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86IntSinkPin.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/intdev.hh"

#include "sim/sim_object.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86IntSinkPin");
    py::class_<X86IntSinkPinParams, SimObjectParams, std::unique_ptr<X86IntSinkPinParams, py::nodelete>>(m, "X86IntSinkPinParams")
        .def(py::init<>())
        .def("create", &X86IntSinkPinParams::create)
        .def_readwrite("device", &X86IntSinkPinParams::device)
        .def_readwrite("number", &X86IntSinkPinParams::number)
        ;

    py::class_<X86ISA::IntSinkPin, SimObject, std::unique_ptr<X86ISA::IntSinkPin, py::nodelete>>(m, "X86ISA_COLONS_IntSinkPin")
        ;

}

static EmbeddedPyBind embed_obj("X86IntSinkPin", module_init, "SimObject");
