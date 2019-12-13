#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/CommMonitor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/comm_monitor.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_CommMonitor");
    py::class_<CommMonitorParams, MemObjectParams, std::unique_ptr<CommMonitorParams, py::nodelete>>(m, "CommMonitorParams")
        .def(py::init<>())
        .def("create", &CommMonitorParams::create)
        .def_readwrite("bandwidth_bins", &CommMonitorParams::bandwidth_bins)
        .def_readwrite("burst_length_bins", &CommMonitorParams::burst_length_bins)
        .def_readwrite("disable_addr_dists", &CommMonitorParams::disable_addr_dists)
        .def_readwrite("disable_bandwidth_hists", &CommMonitorParams::disable_bandwidth_hists)
        .def_readwrite("disable_burst_length_hists", &CommMonitorParams::disable_burst_length_hists)
        .def_readwrite("disable_itt_dists", &CommMonitorParams::disable_itt_dists)
        .def_readwrite("disable_latency_hists", &CommMonitorParams::disable_latency_hists)
        .def_readwrite("disable_outstanding_hists", &CommMonitorParams::disable_outstanding_hists)
        .def_readwrite("disable_transaction_hists", &CommMonitorParams::disable_transaction_hists)
        .def_readwrite("itt_bins", &CommMonitorParams::itt_bins)
        .def_readwrite("itt_max_bin", &CommMonitorParams::itt_max_bin)
        .def_readwrite("latency_bins", &CommMonitorParams::latency_bins)
        .def_readwrite("outstanding_bins", &CommMonitorParams::outstanding_bins)
        .def_readwrite("read_addr_mask", &CommMonitorParams::read_addr_mask)
        .def_readwrite("sample_period", &CommMonitorParams::sample_period)
        .def_readwrite("system", &CommMonitorParams::system)
        .def_readwrite("transaction_bins", &CommMonitorParams::transaction_bins)
        .def_readwrite("write_addr_mask", &CommMonitorParams::write_addr_mask)
        .def_readwrite("port_slave_connection_count", &CommMonitorParams::port_slave_connection_count)
        .def_readwrite("port_master_connection_count", &CommMonitorParams::port_master_connection_count)
        ;

    py::class_<CommMonitor, MemObject, std::unique_ptr<CommMonitor, py::nodelete>>(m, "CommMonitor")
        ;

}

static EmbeddedPyBind embed_obj("CommMonitor", module_init, "MemObject");
