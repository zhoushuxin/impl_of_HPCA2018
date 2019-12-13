#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BranchPredictor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

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
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BranchPredictor");
    py::class_<BranchPredictorParams, SimObjectParams, std::unique_ptr<BranchPredictorParams, py::nodelete>>(m, "BranchPredictorParams")
        .def_readwrite("BTBEntries", &BranchPredictorParams::BTBEntries)
        .def_readwrite("BTBTagSize", &BranchPredictorParams::BTBTagSize)
        .def_readwrite("RASSize", &BranchPredictorParams::RASSize)
        .def_readwrite("indirectHashGHR", &BranchPredictorParams::indirectHashGHR)
        .def_readwrite("indirectHashTargets", &BranchPredictorParams::indirectHashTargets)
        .def_readwrite("indirectPathLength", &BranchPredictorParams::indirectPathLength)
        .def_readwrite("indirectSets", &BranchPredictorParams::indirectSets)
        .def_readwrite("indirectTagSize", &BranchPredictorParams::indirectTagSize)
        .def_readwrite("indirectWays", &BranchPredictorParams::indirectWays)
        .def_readwrite("instShiftAmt", &BranchPredictorParams::instShiftAmt)
        .def_readwrite("numThreads", &BranchPredictorParams::numThreads)
        .def_readwrite("useIndirect", &BranchPredictorParams::useIndirect)
        ;

    py::class_<BPredUnit, SimObject, std::unique_ptr<BPredUnit, py::nodelete>>(m, "BPredUnit")
        ;

}

static EmbeddedPyBind embed_obj("BranchPredictor", module_init, "SimObject");
