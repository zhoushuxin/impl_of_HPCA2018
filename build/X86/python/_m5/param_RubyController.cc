#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyController.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/slicc_interface/AbstractController.hh"

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "mem/ruby/system/RubySystem.hh"
#include "sim/system.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyController");
    py::class_<RubyControllerParams, MemObjectParams, std::unique_ptr<RubyControllerParams, py::nodelete>>(m, "RubyControllerParams")
        .def_readwrite("addr_ranges", &RubyControllerParams::addr_ranges)
        .def_readwrite("buffer_size", &RubyControllerParams::buffer_size)
        .def_readwrite("cluster_id", &RubyControllerParams::cluster_id)
        .def_readwrite("number_of_TBEs", &RubyControllerParams::number_of_TBEs)
        .def_readwrite("recycle_latency", &RubyControllerParams::recycle_latency)
        .def_readwrite("ruby_system", &RubyControllerParams::ruby_system)
        .def_readwrite("system", &RubyControllerParams::system)
        .def_readwrite("transitions_per_cycle", &RubyControllerParams::transitions_per_cycle)
        .def_readwrite("version", &RubyControllerParams::version)
        .def_readwrite("port_memory_connection_count", &RubyControllerParams::port_memory_connection_count)
        ;

    py::class_<AbstractController, MemObject, std::unique_ptr<AbstractController, py::nodelete>>(m, "AbstractController")
        ;

}

static EmbeddedPyBind embed_obj("RubyController", module_init, "MemObject");
