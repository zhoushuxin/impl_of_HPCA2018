#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SouthBridge.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/south_bridge.hh"

#include "dev/x86/cmos.hh"
#include "dev/x86/i8237.hh"
#include "dev/x86/i82094aa.hh"
#include "dev/x86/i8042.hh"
#include "dev/x86/i8259.hh"
#include "dev/x86/i8259.hh"
#include "dev/x86/i8254.hh"
#include "dev/platform.hh"
#include "dev/x86/speaker.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SouthBridge");
    py::class_<SouthBridgeParams, SimObjectParams, std::unique_ptr<SouthBridgeParams, py::nodelete>>(m, "SouthBridgeParams")
        .def(py::init<>())
        .def("create", &SouthBridgeParams::create)
        .def_readwrite("cmos", &SouthBridgeParams::cmos)
        .def_readwrite("dma1", &SouthBridgeParams::dma1)
        .def_readwrite("io_apic", &SouthBridgeParams::io_apic)
        .def_readwrite("keyboard", &SouthBridgeParams::keyboard)
        .def_readwrite("pic1", &SouthBridgeParams::pic1)
        .def_readwrite("pic2", &SouthBridgeParams::pic2)
        .def_readwrite("pit", &SouthBridgeParams::pit)
        .def_readwrite("platform", &SouthBridgeParams::platform)
        .def_readwrite("speaker", &SouthBridgeParams::speaker)
        ;

    py::class_<SouthBridge, SimObject, std::unique_ptr<SouthBridge, py::nodelete>>(m, "SouthBridge")
        ;

}

static EmbeddedPyBind embed_obj("SouthBridge", module_init, "SimObject");
