#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86KvmCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/kvm/x86_cpu.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86KvmCPU");
    py::class_<X86KvmCPUParams, BaseKvmCPUParams, std::unique_ptr<X86KvmCPUParams, py::nodelete>>(m, "X86KvmCPUParams")
        .def(py::init<>())
        .def("create", &X86KvmCPUParams::create)
        .def_readwrite("useXSave", &X86KvmCPUParams::useXSave)
        ;

    py::class_<X86KvmCPU, BaseKvmCPU, std::unique_ptr<X86KvmCPU, py::nodelete>>(m, "X86KvmCPU")
        .def("dumpFpuRegs", &X86KvmCPU::dumpFpuRegs)
        .def("dumpIntRegs", &X86KvmCPU::dumpIntRegs)
        .def("dumpSpecRegs", &X86KvmCPU::dumpSpecRegs)
        .def("dumpXCRs", &X86KvmCPU::dumpXCRs)
        .def("dumpXSave", &X86KvmCPU::dumpXSave)
        .def("dumpVCpuEvents", &X86KvmCPU::dumpVCpuEvents)
        ;

}

static EmbeddedPyBind embed_obj("X86KvmCPU", module_init, "BaseKvmCPU");
