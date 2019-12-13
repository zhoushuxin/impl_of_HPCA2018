#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Uart.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/uart.hh"

#include "dev/serial/serial.hh"
#include "dev/platform.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Uart");
    py::class_<UartParams, BasicPioDeviceParams, std::unique_ptr<UartParams, py::nodelete>>(m, "UartParams")
        .def_readwrite("device", &UartParams::device)
        .def_readwrite("platform", &UartParams::platform)
        ;

    py::class_<Uart, BasicPioDevice, std::unique_ptr<Uart, py::nodelete>>(m, "Uart")
        ;

}

static EmbeddedPyBind embed_obj("Uart", module_init, "BasicPioDevice");
