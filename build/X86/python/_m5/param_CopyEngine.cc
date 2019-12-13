#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/CopyEngine.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/pci/copy_engine.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_CopyEngine");
    py::class_<CopyEngineParams, PciDeviceParams, std::unique_ptr<CopyEngineParams, py::nodelete>>(m, "CopyEngineParams")
        .def(py::init<>())
        .def("create", &CopyEngineParams::create)
        .def_readwrite("ChanCnt", &CopyEngineParams::ChanCnt)
        .def_readwrite("XferCap", &CopyEngineParams::XferCap)
        .def_readwrite("latAfterCompletion", &CopyEngineParams::latAfterCompletion)
        .def_readwrite("latBeforeBegin", &CopyEngineParams::latBeforeBegin)
        .def_readwrite("port_dma_connection_count", &CopyEngineParams::port_dma_connection_count)
        ;

    py::class_<CopyEngine, PciDevice, std::unique_ptr<CopyEngine, py::nodelete>>(m, "CopyEngine")
        ;

}

static EmbeddedPyBind embed_obj("CopyEngine", module_init, "PciDevice");
