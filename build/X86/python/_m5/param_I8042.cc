#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I8042.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/i8042.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "dev/x86/intdev.hh"
#include "dev/x86/intdev.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I8042");
    py::class_<I8042Params, BasicPioDeviceParams, std::unique_ptr<I8042Params, py::nodelete>>(m, "I8042Params")
        .def(py::init<>())
        .def("create", &I8042Params::create)
        .def_readwrite("command_port", &I8042Params::command_port)
        .def_readwrite("data_port", &I8042Params::data_port)
        .def_readwrite("keyboard_int_pin", &I8042Params::keyboard_int_pin)
        .def_readwrite("mouse_int_pin", &I8042Params::mouse_int_pin)
        ;

    py::class_<X86ISA::I8042, BasicPioDevice, std::unique_ptr<X86ISA::I8042, py::nodelete>>(m, "X86ISA_COLONS_I8042")
        ;

}

static EmbeddedPyBind embed_obj("I8042", module_init, "BasicPioDevice");
