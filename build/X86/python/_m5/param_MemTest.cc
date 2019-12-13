#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MemTest.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/memtest/memtest.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MemTest");
    py::class_<MemTestParams, MemObjectParams, std::unique_ptr<MemTestParams, py::nodelete>>(m, "MemTestParams")
        .def(py::init<>())
        .def("create", &MemTestParams::create)
        .def_readwrite("interval", &MemTestParams::interval)
        .def_readwrite("max_loads", &MemTestParams::max_loads)
        .def_readwrite("percent_functional", &MemTestParams::percent_functional)
        .def_readwrite("percent_reads", &MemTestParams::percent_reads)
        .def_readwrite("percent_uncacheable", &MemTestParams::percent_uncacheable)
        .def_readwrite("progress_check", &MemTestParams::progress_check)
        .def_readwrite("progress_interval", &MemTestParams::progress_interval)
        .def_readwrite("size", &MemTestParams::size)
        .def_readwrite("suppress_func_warnings", &MemTestParams::suppress_func_warnings)
        .def_readwrite("system", &MemTestParams::system)
        .def_readwrite("port_port_connection_count", &MemTestParams::port_port_connection_count)
        ;

    py::class_<MemTest, MemObject, std::unique_ptr<MemTest, py::nodelete>>(m, "MemTest")
        ;

}

static EmbeddedPyBind embed_obj("MemTest", module_init, "MemObject");
