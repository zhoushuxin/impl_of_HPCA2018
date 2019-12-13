#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyTester.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/rubytest/RubyTester.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyTester");
    py::class_<RubyTesterParams, MemObjectParams, std::unique_ptr<RubyTesterParams, py::nodelete>>(m, "RubyTesterParams")
        .def(py::init<>())
        .def("create", &RubyTesterParams::create)
        .def_readwrite("check_flush", &RubyTesterParams::check_flush)
        .def_readwrite("checks_to_complete", &RubyTesterParams::checks_to_complete)
        .def_readwrite("deadlock_threshold", &RubyTesterParams::deadlock_threshold)
        .def_readwrite("num_cpus", &RubyTesterParams::num_cpus)
        .def_readwrite("system", &RubyTesterParams::system)
        .def_readwrite("wakeup_frequency", &RubyTesterParams::wakeup_frequency)
        .def_readwrite("port_cpuInstDataPort_connection_count", &RubyTesterParams::port_cpuInstDataPort_connection_count)
        .def_readwrite("port_cpuInstPort_connection_count", &RubyTesterParams::port_cpuInstPort_connection_count)
        .def_readwrite("port_cpuDataPort_connection_count", &RubyTesterParams::port_cpuDataPort_connection_count)
        ;

    py::class_<RubyTester, MemObject, std::unique_ptr<RubyTester, py::nodelete>>(m, "RubyTester")
        ;

}

static EmbeddedPyBind embed_obj("RubyTester", module_init, "MemObject");
