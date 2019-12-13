#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I8254.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/i8254.hh"

#include "dev/x86/intdev.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I8254");
    py::class_<I8254Params, BasicPioDeviceParams, std::unique_ptr<I8254Params, py::nodelete>>(m, "I8254Params")
        .def(py::init<>())
        .def("create", &I8254Params::create)
        .def_readwrite("int_pin", &I8254Params::int_pin)
        ;

    py::class_<X86ISA::I8254, BasicPioDevice, std::unique_ptr<X86ISA::I8254, py::nodelete>>(m, "X86ISA_COLONS_I8254")
        ;

}

static EmbeddedPyBind embed_obj("I8254", module_init, "BasicPioDevice");
