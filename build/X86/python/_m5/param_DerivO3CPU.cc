#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DerivO3CPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/o3/deriv.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "cpu/pred/bpred_unit.hh"
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
#include "cpu/o3/fu_pool.hh"
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
#include <string>
#include <string>
#include <string>
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DerivO3CPU");
    py::class_<DerivO3CPUParams, BaseCPUParams, std::unique_ptr<DerivO3CPUParams, py::nodelete>>(m, "DerivO3CPUParams")
        .def(py::init<>())
        .def("create", &DerivO3CPUParams::create)
        .def_readwrite("LFSTSize", &DerivO3CPUParams::LFSTSize)
        .def_readwrite("LQEntries", &DerivO3CPUParams::LQEntries)
        .def_readwrite("LSQCheckLoads", &DerivO3CPUParams::LSQCheckLoads)
        .def_readwrite("LSQDepCheckShift", &DerivO3CPUParams::LSQDepCheckShift)
        .def_readwrite("SQEntries", &DerivO3CPUParams::SQEntries)
        .def_readwrite("SSITSize", &DerivO3CPUParams::SSITSize)
        .def_readwrite("activity", &DerivO3CPUParams::activity)
        .def_readwrite("backComSize", &DerivO3CPUParams::backComSize)
        .def_readwrite("branchPred", &DerivO3CPUParams::branchPred)
        .def_readwrite("cacheStorePorts", &DerivO3CPUParams::cacheStorePorts)
        .def_readwrite("commitToDecodeDelay", &DerivO3CPUParams::commitToDecodeDelay)
        .def_readwrite("commitToFetchDelay", &DerivO3CPUParams::commitToFetchDelay)
        .def_readwrite("commitToIEWDelay", &DerivO3CPUParams::commitToIEWDelay)
        .def_readwrite("commitToRenameDelay", &DerivO3CPUParams::commitToRenameDelay)
        .def_readwrite("commitWidth", &DerivO3CPUParams::commitWidth)
        .def_readwrite("decodeToFetchDelay", &DerivO3CPUParams::decodeToFetchDelay)
        .def_readwrite("decodeToRenameDelay", &DerivO3CPUParams::decodeToRenameDelay)
        .def_readwrite("decodeWidth", &DerivO3CPUParams::decodeWidth)
        .def_readwrite("dispatchWidth", &DerivO3CPUParams::dispatchWidth)
        .def_readwrite("fetchBufferSize", &DerivO3CPUParams::fetchBufferSize)
        .def_readwrite("fetchQueueSize", &DerivO3CPUParams::fetchQueueSize)
        .def_readwrite("fetchToDecodeDelay", &DerivO3CPUParams::fetchToDecodeDelay)
        .def_readwrite("fetchTrapLatency", &DerivO3CPUParams::fetchTrapLatency)
        .def_readwrite("fetchWidth", &DerivO3CPUParams::fetchWidth)
        .def_readwrite("forwardComSize", &DerivO3CPUParams::forwardComSize)
        .def_readwrite("fuPool", &DerivO3CPUParams::fuPool)
        .def_readwrite("iewToCommitDelay", &DerivO3CPUParams::iewToCommitDelay)
        .def_readwrite("iewToDecodeDelay", &DerivO3CPUParams::iewToDecodeDelay)
        .def_readwrite("iewToFetchDelay", &DerivO3CPUParams::iewToFetchDelay)
        .def_readwrite("iewToRenameDelay", &DerivO3CPUParams::iewToRenameDelay)
        .def_readwrite("issueToExecuteDelay", &DerivO3CPUParams::issueToExecuteDelay)
        .def_readwrite("issueWidth", &DerivO3CPUParams::issueWidth)
        .def_readwrite("needsTSO", &DerivO3CPUParams::needsTSO)
        .def_readwrite("numIQEntries", &DerivO3CPUParams::numIQEntries)
        .def_readwrite("numPhysCCRegs", &DerivO3CPUParams::numPhysCCRegs)
        .def_readwrite("numPhysFloatRegs", &DerivO3CPUParams::numPhysFloatRegs)
        .def_readwrite("numPhysIntRegs", &DerivO3CPUParams::numPhysIntRegs)
        .def_readwrite("numPhysVecRegs", &DerivO3CPUParams::numPhysVecRegs)
        .def_readwrite("numROBEntries", &DerivO3CPUParams::numROBEntries)
        .def_readwrite("numRobs", &DerivO3CPUParams::numRobs)
        .def_readwrite("renameToDecodeDelay", &DerivO3CPUParams::renameToDecodeDelay)
        .def_readwrite("renameToFetchDelay", &DerivO3CPUParams::renameToFetchDelay)
        .def_readwrite("renameToIEWDelay", &DerivO3CPUParams::renameToIEWDelay)
        .def_readwrite("renameToROBDelay", &DerivO3CPUParams::renameToROBDelay)
        .def_readwrite("renameWidth", &DerivO3CPUParams::renameWidth)
        .def_readwrite("smtCommitPolicy", &DerivO3CPUParams::smtCommitPolicy)
        .def_readwrite("smtFetchPolicy", &DerivO3CPUParams::smtFetchPolicy)
        .def_readwrite("smtIQPolicy", &DerivO3CPUParams::smtIQPolicy)
        .def_readwrite("smtIQThreshold", &DerivO3CPUParams::smtIQThreshold)
        .def_readwrite("smtLSQPolicy", &DerivO3CPUParams::smtLSQPolicy)
        .def_readwrite("smtLSQThreshold", &DerivO3CPUParams::smtLSQThreshold)
        .def_readwrite("smtNumFetchingThreads", &DerivO3CPUParams::smtNumFetchingThreads)
        .def_readwrite("smtROBPolicy", &DerivO3CPUParams::smtROBPolicy)
        .def_readwrite("smtROBThreshold", &DerivO3CPUParams::smtROBThreshold)
        .def_readwrite("squashWidth", &DerivO3CPUParams::squashWidth)
        .def_readwrite("store_set_clear_period", &DerivO3CPUParams::store_set_clear_period)
        .def_readwrite("trapLatency", &DerivO3CPUParams::trapLatency)
        .def_readwrite("wbWidth", &DerivO3CPUParams::wbWidth)
        ;

    py::class_<DerivO3CPU, BaseCPU, std::unique_ptr<DerivO3CPU, py::nodelete>>(m, "DerivO3CPU")
        ;

}

static EmbeddedPyBind embed_obj("DerivO3CPU", module_init, "BaseCPU");
