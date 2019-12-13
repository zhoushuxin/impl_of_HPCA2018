#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/L1Cache_Controller.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/protocol/L1Cache_Controller.hh"

#include "mem/ruby/structures/CacheMemory.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/system/Sequencer.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_L1Cache_Controller");
    py::class_<L1Cache_ControllerParams, RubyControllerParams, std::unique_ptr<L1Cache_ControllerParams, py::nodelete>>(m, "L1Cache_ControllerParams")
        .def(py::init<>())
        .def("create", &L1Cache_ControllerParams::create)
        .def_readwrite("cacheMemory", &L1Cache_ControllerParams::cacheMemory)
        .def_readwrite("cache_response_latency", &L1Cache_ControllerParams::cache_response_latency)
        .def_readwrite("forwardToCache", &L1Cache_ControllerParams::forwardToCache)
        .def_readwrite("issue_latency", &L1Cache_ControllerParams::issue_latency)
        .def_readwrite("mandatoryQueue", &L1Cache_ControllerParams::mandatoryQueue)
        .def_readwrite("requestFromCache", &L1Cache_ControllerParams::requestFromCache)
        .def_readwrite("responseFromCache", &L1Cache_ControllerParams::responseFromCache)
        .def_readwrite("responseToCache", &L1Cache_ControllerParams::responseToCache)
        .def_readwrite("send_evictions", &L1Cache_ControllerParams::send_evictions)
        .def_readwrite("sequencer", &L1Cache_ControllerParams::sequencer)
        ;

    py::class_<L1Cache_Controller, AbstractController, std::unique_ptr<L1Cache_Controller, py::nodelete>>(m, "L1Cache_Controller")
        ;

}

static EmbeddedPyBind embed_obj("L1Cache_Controller", module_init, "RubyController");
