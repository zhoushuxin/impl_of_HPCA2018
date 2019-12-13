#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/base.hh"

#include "cpu/base.hh"
#include "base/types.hh"
#include "arch/generic/tlb.hh"
#include "base/types.hh"
#include <vector>
#include "arch/x86/interrupts.hh"
#include <vector>
#include "arch/x86/isa.hh"
#include "arch/generic/tlb.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "sim/insttracer.hh"
#include <vector>
#include "sim/process.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseCPU");
    py::class_<BaseCPUParams, MemObjectParams, std::unique_ptr<BaseCPUParams, py::nodelete>>(m, "BaseCPUParams")
        .def_readwrite("checker", &BaseCPUParams::checker)
        .def_readwrite("cpu_id", &BaseCPUParams::cpu_id)
        .def_readwrite("do_checkpoint_insts", &BaseCPUParams::do_checkpoint_insts)
        .def_readwrite("do_quiesce", &BaseCPUParams::do_quiesce)
        .def_readwrite("do_statistics_insts", &BaseCPUParams::do_statistics_insts)
        .def_readwrite("dtb", &BaseCPUParams::dtb)
        .def_readwrite("function_trace", &BaseCPUParams::function_trace)
        .def_readwrite("function_trace_start", &BaseCPUParams::function_trace_start)
        .def_readwrite("interrupts", &BaseCPUParams::interrupts)
        .def_readwrite("isa", &BaseCPUParams::isa)
        .def_readwrite("itb", &BaseCPUParams::itb)
        .def_readwrite("max_insts_all_threads", &BaseCPUParams::max_insts_all_threads)
        .def_readwrite("max_insts_any_thread", &BaseCPUParams::max_insts_any_thread)
        .def_readwrite("max_loads_all_threads", &BaseCPUParams::max_loads_all_threads)
        .def_readwrite("max_loads_any_thread", &BaseCPUParams::max_loads_any_thread)
        .def_readwrite("numThreads", &BaseCPUParams::numThreads)
        .def_readwrite("power_gating_on_idle", &BaseCPUParams::power_gating_on_idle)
        .def_readwrite("profile", &BaseCPUParams::profile)
        .def_readwrite("progress_interval", &BaseCPUParams::progress_interval)
        .def_readwrite("pwr_gating_latency", &BaseCPUParams::pwr_gating_latency)
        .def_readwrite("simpoint_start_insts", &BaseCPUParams::simpoint_start_insts)
        .def_readwrite("socket_id", &BaseCPUParams::socket_id)
        .def_readwrite("switched_out", &BaseCPUParams::switched_out)
        .def_readwrite("syscallRetryLatency", &BaseCPUParams::syscallRetryLatency)
        .def_readwrite("system", &BaseCPUParams::system)
        .def_readwrite("tracer", &BaseCPUParams::tracer)
        .def_readwrite("wait_for_remote_gdb", &BaseCPUParams::wait_for_remote_gdb)
        .def_readwrite("workload", &BaseCPUParams::workload)
        .def_readwrite("port_icache_port_connection_count", &BaseCPUParams::port_icache_port_connection_count)
        .def_readwrite("port_dcache_port_connection_count", &BaseCPUParams::port_dcache_port_connection_count)
        ;

    py::class_<BaseCPU, MemObject, std::unique_ptr<BaseCPU, py::nodelete>>(m, "BaseCPU")
        .def("switchOut", &BaseCPU::switchOut)
        .def("takeOverFrom", &BaseCPU::takeOverFrom)
        .def("switchedOut", &BaseCPU::switchedOut)
        .def("flushTLBs", &BaseCPU::flushTLBs)
        .def("totalInsts", &BaseCPU::totalInsts)
        .def("scheduleInstStop", &BaseCPU::scheduleInstStop)
        .def("scheduleLoadStop", &BaseCPU::scheduleLoadStop)
        .def("getCurrentInstCount", &BaseCPU::getCurrentInstCount)
        ;

}

static EmbeddedPyBind embed_obj("BaseCPU", module_init, "MemObject");
