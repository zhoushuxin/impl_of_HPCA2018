#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/System.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/system.hh"

#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include <string>
#include <vector>
#include <string>
#include "cpu/kvm/vm.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "enums/MemoryMode.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <vector>
#include "mem/abstract_mem.hh"
#include "base/types.hh"
#include <string>
#include <string>
#include <vector>
#include "sim/sim_object.hh"
#include "sim/power/thermal_model.hh"
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
    py::module m = m_internal.def_submodule("param_System");
    py::class_<SystemParams, MemObjectParams, std::unique_ptr<SystemParams, py::nodelete>>(m, "SystemParams")
        .def(py::init<>())
        .def("create", &SystemParams::create)
        .def_readwrite("boot_osflags", &SystemParams::boot_osflags)
        .def_readwrite("cache_line_size", &SystemParams::cache_line_size)
        .def_readwrite("exit_on_work_items", &SystemParams::exit_on_work_items)
        .def_readwrite("init_param", &SystemParams::init_param)
        .def_readwrite("kernel", &SystemParams::kernel)
        .def_readwrite("kernel_addr_check", &SystemParams::kernel_addr_check)
        .def_readwrite("kernel_extras", &SystemParams::kernel_extras)
        .def_readwrite("kvm_vm", &SystemParams::kvm_vm)
        .def_readwrite("load_addr_mask", &SystemParams::load_addr_mask)
        .def_readwrite("load_offset", &SystemParams::load_offset)
        .def_readwrite("mem_mode", &SystemParams::mem_mode)
        .def_readwrite("mem_ranges", &SystemParams::mem_ranges)
        .def_readwrite("memories", &SystemParams::memories)
        .def_readwrite("mmap_using_noreserve", &SystemParams::mmap_using_noreserve)
        .def_readwrite("multi_thread", &SystemParams::multi_thread)
        .def_readwrite("num_work_ids", &SystemParams::num_work_ids)
        .def_readwrite("readfile", &SystemParams::readfile)
        .def_readwrite("symbolfile", &SystemParams::symbolfile)
        .def_readwrite("thermal_components", &SystemParams::thermal_components)
        .def_readwrite("thermal_model", &SystemParams::thermal_model)
        .def_readwrite("work_begin_ckpt_count", &SystemParams::work_begin_ckpt_count)
        .def_readwrite("work_begin_cpu_id_exit", &SystemParams::work_begin_cpu_id_exit)
        .def_readwrite("work_begin_exit_count", &SystemParams::work_begin_exit_count)
        .def_readwrite("work_cpus_ckpt_count", &SystemParams::work_cpus_ckpt_count)
        .def_readwrite("work_end_ckpt_count", &SystemParams::work_end_ckpt_count)
        .def_readwrite("work_end_exit_count", &SystemParams::work_end_exit_count)
        .def_readwrite("work_item_id", &SystemParams::work_item_id)
        .def_readwrite("port_system_port_connection_count", &SystemParams::port_system_port_connection_count)
        ;

    py::class_<System, MemObject, std::unique_ptr<System, py::nodelete>>(m, "System")
        .def("getMemoryMode", &System::getMemoryMode)
        .def("setMemoryMode", &System::setMemoryMode)
        ;

}

static EmbeddedPyBind embed_obj("System", module_init, "MemObject");
