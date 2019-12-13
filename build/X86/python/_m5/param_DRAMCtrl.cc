#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DRAMCtrl.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/dram_ctrl.hh"

#include "base/types.hh"
#include "enums/AddrMap.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "enums/MemSched.hh"
#include "base/types.hh"
#include "enums/PageManage.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DRAMCtrl");
    py::class_<DRAMCtrlParams, AbstractMemoryParams, std::unique_ptr<DRAMCtrlParams, py::nodelete>>(m, "DRAMCtrlParams")
        .def(py::init<>())
        .def("create", &DRAMCtrlParams::create)
        .def_readwrite("IDD0", &DRAMCtrlParams::IDD0)
        .def_readwrite("IDD02", &DRAMCtrlParams::IDD02)
        .def_readwrite("IDD2N", &DRAMCtrlParams::IDD2N)
        .def_readwrite("IDD2N2", &DRAMCtrlParams::IDD2N2)
        .def_readwrite("IDD2P0", &DRAMCtrlParams::IDD2P0)
        .def_readwrite("IDD2P02", &DRAMCtrlParams::IDD2P02)
        .def_readwrite("IDD2P1", &DRAMCtrlParams::IDD2P1)
        .def_readwrite("IDD2P12", &DRAMCtrlParams::IDD2P12)
        .def_readwrite("IDD3N", &DRAMCtrlParams::IDD3N)
        .def_readwrite("IDD3N2", &DRAMCtrlParams::IDD3N2)
        .def_readwrite("IDD3P0", &DRAMCtrlParams::IDD3P0)
        .def_readwrite("IDD3P02", &DRAMCtrlParams::IDD3P02)
        .def_readwrite("IDD3P1", &DRAMCtrlParams::IDD3P1)
        .def_readwrite("IDD3P12", &DRAMCtrlParams::IDD3P12)
        .def_readwrite("IDD4R", &DRAMCtrlParams::IDD4R)
        .def_readwrite("IDD4R2", &DRAMCtrlParams::IDD4R2)
        .def_readwrite("IDD4W", &DRAMCtrlParams::IDD4W)
        .def_readwrite("IDD4W2", &DRAMCtrlParams::IDD4W2)
        .def_readwrite("IDD5", &DRAMCtrlParams::IDD5)
        .def_readwrite("IDD52", &DRAMCtrlParams::IDD52)
        .def_readwrite("IDD6", &DRAMCtrlParams::IDD6)
        .def_readwrite("IDD62", &DRAMCtrlParams::IDD62)
        .def_readwrite("VDD", &DRAMCtrlParams::VDD)
        .def_readwrite("VDD2", &DRAMCtrlParams::VDD2)
        .def_readwrite("activation_limit", &DRAMCtrlParams::activation_limit)
        .def_readwrite("addr_mapping", &DRAMCtrlParams::addr_mapping)
        .def_readwrite("bank_groups_per_rank", &DRAMCtrlParams::bank_groups_per_rank)
        .def_readwrite("banks_per_rank", &DRAMCtrlParams::banks_per_rank)
        .def_readwrite("burst_length", &DRAMCtrlParams::burst_length)
        .def_readwrite("channels", &DRAMCtrlParams::channels)
        .def_readwrite("device_bus_width", &DRAMCtrlParams::device_bus_width)
        .def_readwrite("device_rowbuffer_size", &DRAMCtrlParams::device_rowbuffer_size)
        .def_readwrite("device_size", &DRAMCtrlParams::device_size)
        .def_readwrite("devices_per_rank", &DRAMCtrlParams::devices_per_rank)
        .def_readwrite("dll", &DRAMCtrlParams::dll)
        .def_readwrite("max_accesses_per_row", &DRAMCtrlParams::max_accesses_per_row)
        .def_readwrite("mem_sched_policy", &DRAMCtrlParams::mem_sched_policy)
        .def_readwrite("min_writes_per_switch", &DRAMCtrlParams::min_writes_per_switch)
        .def_readwrite("page_policy", &DRAMCtrlParams::page_policy)
        .def_readwrite("ranks_per_channel", &DRAMCtrlParams::ranks_per_channel)
        .def_readwrite("read_buffer_size", &DRAMCtrlParams::read_buffer_size)
        .def_readwrite("static_backend_latency", &DRAMCtrlParams::static_backend_latency)
        .def_readwrite("static_frontend_latency", &DRAMCtrlParams::static_frontend_latency)
        .def_readwrite("tBURST", &DRAMCtrlParams::tBURST)
        .def_readwrite("tCCD_L", &DRAMCtrlParams::tCCD_L)
        .def_readwrite("tCK", &DRAMCtrlParams::tCK)
        .def_readwrite("tCL", &DRAMCtrlParams::tCL)
        .def_readwrite("tCS", &DRAMCtrlParams::tCS)
        .def_readwrite("tRAS", &DRAMCtrlParams::tRAS)
        .def_readwrite("tRCD", &DRAMCtrlParams::tRCD)
        .def_readwrite("tREFI", &DRAMCtrlParams::tREFI)
        .def_readwrite("tRFC", &DRAMCtrlParams::tRFC)
        .def_readwrite("tRP", &DRAMCtrlParams::tRP)
        .def_readwrite("tRRD", &DRAMCtrlParams::tRRD)
        .def_readwrite("tRRD_L", &DRAMCtrlParams::tRRD_L)
        .def_readwrite("tRTP", &DRAMCtrlParams::tRTP)
        .def_readwrite("tRTW", &DRAMCtrlParams::tRTW)
        .def_readwrite("tWR", &DRAMCtrlParams::tWR)
        .def_readwrite("tWTR", &DRAMCtrlParams::tWTR)
        .def_readwrite("tXAW", &DRAMCtrlParams::tXAW)
        .def_readwrite("tXP", &DRAMCtrlParams::tXP)
        .def_readwrite("tXPDLL", &DRAMCtrlParams::tXPDLL)
        .def_readwrite("tXS", &DRAMCtrlParams::tXS)
        .def_readwrite("tXSDLL", &DRAMCtrlParams::tXSDLL)
        .def_readwrite("write_buffer_size", &DRAMCtrlParams::write_buffer_size)
        .def_readwrite("write_high_thresh_perc", &DRAMCtrlParams::write_high_thresh_perc)
        .def_readwrite("write_low_thresh_perc", &DRAMCtrlParams::write_low_thresh_perc)
        .def_readwrite("port_port_connection_count", &DRAMCtrlParams::port_port_connection_count)
        ;

    py::class_<DRAMCtrl, AbstractMemory, std::unique_ptr<DRAMCtrl, py::nodelete>>(m, "DRAMCtrl")
        ;

}

static EmbeddedPyBind embed_obj("DRAMCtrl", module_init, "AbstractMemory");
