#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I8237.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/i8237.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I8237");
    py::class_<I8237Params, BasicPioDeviceParams, std::unique_ptr<I8237Params, py::nodelete>>(m, "I8237Params")
        .def(py::init<>())
        .def("create", &I8237Params::create)
        ;

    py::class_<X86ISA::I8237, BasicPioDevice, std::unique_ptr<X86ISA::I8237, py::nodelete>>(m, "X86ISA_COLONS_I8237")
        ;

}

static EmbeddedPyBind embed_obj("I8237", module_init, "BasicPioDevice");
