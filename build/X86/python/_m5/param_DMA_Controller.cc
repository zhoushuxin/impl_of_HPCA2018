#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DMA_Controller.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/protocol/DMA_Controller.hh"

#include "mem/ruby/system/DMASequencer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DMA_Controller");
    py::class_<DMA_ControllerParams, RubyControllerParams, std::unique_ptr<DMA_ControllerParams, py::nodelete>>(m, "DMA_ControllerParams")
        .def(py::init<>())
        .def("create", &DMA_ControllerParams::create)
        .def_readwrite("dma_sequencer", &DMA_ControllerParams::dma_sequencer)
        .def_readwrite("mandatoryQueue", &DMA_ControllerParams::mandatoryQueue)
        .def_readwrite("requestToDir", &DMA_ControllerParams::requestToDir)
        .def_readwrite("request_latency", &DMA_ControllerParams::request_latency)
        .def_readwrite("responseFromDir", &DMA_ControllerParams::responseFromDir)
        ;

    py::class_<DMA_Controller, AbstractController, std::unique_ptr<DMA_Controller, py::nodelete>>(m, "DMA_Controller")
        ;

}

static EmbeddedPyBind embed_obj("DMA_Controller", module_init, "RubyController");
