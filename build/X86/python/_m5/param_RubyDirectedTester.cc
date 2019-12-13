#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyDirectedTester.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/directedtest/RubyDirectedTester.hh"

#include "cpu/testers/directedtest/DirectedGenerator.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyDirectedTester");
    py::class_<RubyDirectedTesterParams, MemObjectParams, std::unique_ptr<RubyDirectedTesterParams, py::nodelete>>(m, "RubyDirectedTesterParams")
        .def(py::init<>())
        .def("create", &RubyDirectedTesterParams::create)
        .def_readwrite("generator", &RubyDirectedTesterParams::generator)
        .def_readwrite("requests_to_complete", &RubyDirectedTesterParams::requests_to_complete)
        .def_readwrite("port_cpuPort_connection_count", &RubyDirectedTesterParams::port_cpuPort_connection_count)
        ;

    py::class_<RubyDirectedTester, MemObject, std::unique_ptr<RubyDirectedTester, py::nodelete>>(m, "RubyDirectedTester")
        ;

}

static EmbeddedPyBind embed_obj("RubyDirectedTester", module_init, "MemObject");
