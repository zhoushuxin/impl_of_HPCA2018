#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MemCheckerMonitor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/mem_checker_monitor.hh"

#include "mem/mem_checker.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MemCheckerMonitor");
    py::class_<MemCheckerMonitorParams, MemObjectParams, std::unique_ptr<MemCheckerMonitorParams, py::nodelete>>(m, "MemCheckerMonitorParams")
        .def(py::init<>())
        .def("create", &MemCheckerMonitorParams::create)
        .def_readwrite("memchecker", &MemCheckerMonitorParams::memchecker)
        .def_readwrite("warn_only", &MemCheckerMonitorParams::warn_only)
        .def_readwrite("port_master_connection_count", &MemCheckerMonitorParams::port_master_connection_count)
        .def_readwrite("port_mem_side_connection_count", &MemCheckerMonitorParams::port_mem_side_connection_count)
        .def_readwrite("port_slave_connection_count", &MemCheckerMonitorParams::port_slave_connection_count)
        .def_readwrite("port_cpu_side_connection_count", &MemCheckerMonitorParams::port_cpu_side_connection_count)
        ;

    py::class_<MemCheckerMonitor, MemObject, std::unique_ptr<MemCheckerMonitor, py::nodelete>>(m, "MemCheckerMonitor")
        ;

}

static EmbeddedPyBind embed_obj("MemCheckerMonitor", module_init, "MemObject");
