#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Terminal.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/terminal.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Terminal");
    py::class_<TerminalParams, SerialDeviceParams, std::unique_ptr<TerminalParams, py::nodelete>>(m, "TerminalParams")
        .def(py::init<>())
        .def("create", &TerminalParams::create)
        .def_readwrite("number", &TerminalParams::number)
        .def_readwrite("output", &TerminalParams::output)
        .def_readwrite("port", &TerminalParams::port)
        ;

    py::class_<Terminal, SerialDevice, std::unique_ptr<Terminal, py::nodelete>>(m, "Terminal")
        ;

}

static EmbeddedPyBind embed_obj("Terminal", module_init, "SerialDevice");
