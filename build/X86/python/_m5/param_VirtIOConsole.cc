#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIOConsole.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/console.hh"

#include "dev/serial/serial.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIOConsole");
    py::class_<VirtIOConsoleParams, VirtIODeviceBaseParams, std::unique_ptr<VirtIOConsoleParams, py::nodelete>>(m, "VirtIOConsoleParams")
        .def(py::init<>())
        .def("create", &VirtIOConsoleParams::create)
        .def_readwrite("device", &VirtIOConsoleParams::device)
        .def_readwrite("qRecvSize", &VirtIOConsoleParams::qRecvSize)
        .def_readwrite("qTransSize", &VirtIOConsoleParams::qTransSize)
        ;

    py::class_<VirtIOConsole, VirtIODeviceBase, std::unique_ptr<VirtIOConsole, py::nodelete>>(m, "VirtIOConsole")
        ;

}

static EmbeddedPyBind embed_obj("VirtIOConsole", module_init, "VirtIODeviceBase");
