#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleCache.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/simple_cache.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleCache");
    py::class_<SimpleCacheParams, MemObjectParams, std::unique_ptr<SimpleCacheParams, py::nodelete>>(m, "SimpleCacheParams")
        .def(py::init<>())
        .def("create", &SimpleCacheParams::create)
        .def_readwrite("latency", &SimpleCacheParams::latency)
        .def_readwrite("size", &SimpleCacheParams::size)
        .def_readwrite("system", &SimpleCacheParams::system)
        .def_readwrite("port_mem_side_connection_count", &SimpleCacheParams::port_mem_side_connection_count)
        .def_readwrite("port_cpu_side_connection_count", &SimpleCacheParams::port_cpu_side_connection_count)
        ;

    py::class_<SimpleCache, MemObject, std::unique_ptr<SimpleCache, py::nodelete>>(m, "SimpleCache")
        ;

}

static EmbeddedPyBind embed_obj("SimpleCache", module_init, "MemObject");
