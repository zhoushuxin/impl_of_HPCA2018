#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyPort.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/system/RubyPort.hh"

#include "mem/ruby/system/RubySystem.hh"
#include "sim/system.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyPort");
    py::class_<RubyPortParams, MemObjectParams, std::unique_ptr<RubyPortParams, py::nodelete>>(m, "RubyPortParams")
        .def_readwrite("is_cpu_sequencer", &RubyPortParams::is_cpu_sequencer)
        .def_readwrite("no_retry_on_stall", &RubyPortParams::no_retry_on_stall)
        .def_readwrite("ruby_system", &RubyPortParams::ruby_system)
        .def_readwrite("support_data_reqs", &RubyPortParams::support_data_reqs)
        .def_readwrite("support_inst_reqs", &RubyPortParams::support_inst_reqs)
        .def_readwrite("system", &RubyPortParams::system)
        .def_readwrite("using_ruby_tester", &RubyPortParams::using_ruby_tester)
        .def_readwrite("version", &RubyPortParams::version)
        .def_readwrite("port_slave_connection_count", &RubyPortParams::port_slave_connection_count)
        .def_readwrite("port_pio_slave_port_connection_count", &RubyPortParams::port_pio_slave_port_connection_count)
        .def_readwrite("port_mem_master_port_connection_count", &RubyPortParams::port_mem_master_port_connection_count)
        .def_readwrite("port_master_connection_count", &RubyPortParams::port_master_connection_count)
        .def_readwrite("port_pio_master_port_connection_count", &RubyPortParams::port_pio_master_port_connection_count)
        .def_readwrite("port_mem_slave_port_connection_count", &RubyPortParams::port_mem_slave_port_connection_count)
        ;

    py::class_<RubyPort, MemObject, std::unique_ptr<RubyPort, py::nodelete>>(m, "RubyPort")
        ;

}

static EmbeddedPyBind embed_obj("RubyPort", module_init, "MemObject");
