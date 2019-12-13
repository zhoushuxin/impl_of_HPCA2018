#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I8259.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/i8259.hh"

#include "enums/X86I8259CascadeMode.hh"
#include "dev/x86/intdev.hh"
#include "dev/x86/i8259.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I8259");
    py::class_<I8259Params, BasicPioDeviceParams, std::unique_ptr<I8259Params, py::nodelete>>(m, "I8259Params")
        .def(py::init<>())
        .def("create", &I8259Params::create)
        .def_readwrite("mode", &I8259Params::mode)
        .def_readwrite("output", &I8259Params::output)
        .def_readwrite("slave", &I8259Params::slave)
        ;

    py::class_<X86ISA::I8259, BasicPioDevice, std::unique_ptr<X86ISA::I8259, py::nodelete>>(m, "X86ISA_COLONS_I8259")
        ;

}

static EmbeddedPyBind embed_obj("I8259", module_init, "BasicPioDevice");
