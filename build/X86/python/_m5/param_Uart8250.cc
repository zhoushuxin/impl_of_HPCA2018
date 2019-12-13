#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Uart8250.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/uart8250.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Uart8250");
    py::class_<Uart8250Params, UartParams, std::unique_ptr<Uart8250Params, py::nodelete>>(m, "Uart8250Params")
        .def(py::init<>())
        .def("create", &Uart8250Params::create)
        ;

    py::class_<Uart8250, Uart, std::unique_ptr<Uart8250, py::nodelete>>(m, "Uart8250")
        ;

}

static EmbeddedPyBind embed_obj("Uart8250", module_init, "Uart");
