#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseKvmCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/kvm/base.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseKvmCPU");
    py::class_<BaseKvmCPUParams, BaseCPUParams, std::unique_ptr<BaseKvmCPUParams, py::nodelete>>(m, "BaseKvmCPUParams")
        .def_readwrite("alwaysSyncTC", &BaseKvmCPUParams::alwaysSyncTC)
        .def_readwrite("hostFactor", &BaseKvmCPUParams::hostFactor)
        .def_readwrite("hostFreq", &BaseKvmCPUParams::hostFreq)
        .def_readwrite("useCoalescedMMIO", &BaseKvmCPUParams::useCoalescedMMIO)
        .def_readwrite("usePerfOverflow", &BaseKvmCPUParams::usePerfOverflow)
        ;

    py::class_<BaseKvmCPU, BaseCPU, std::unique_ptr<BaseKvmCPU, py::nodelete>>(m, "BaseKvmCPU")
        .def("dump", &BaseKvmCPU::dump)
        ;

}

static EmbeddedPyBind embed_obj("BaseKvmCPU", module_init, "BaseCPU");
