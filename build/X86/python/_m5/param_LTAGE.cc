#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/LTAGE.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/ltage.hh"

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
    py::module m = m_internal.def_submodule("param_LTAGE");
    py::class_<LTAGEParams, BranchPredictorParams, std::unique_ptr<LTAGEParams, py::nodelete>>(m, "LTAGEParams")
        .def(py::init<>())
        .def("create", &LTAGEParams::create)
        .def_readwrite("histBufferSize", &LTAGEParams::histBufferSize)
        .def_readwrite("logSizeBiMP", &LTAGEParams::logSizeBiMP)
        .def_readwrite("logSizeLoopPred", &LTAGEParams::logSizeLoopPred)
        .def_readwrite("logSizeTagTables", &LTAGEParams::logSizeTagTables)
        .def_readwrite("maxHist", &LTAGEParams::maxHist)
        .def_readwrite("minHist", &LTAGEParams::minHist)
        .def_readwrite("minTagWidth", &LTAGEParams::minTagWidth)
        .def_readwrite("nHistoryTables", &LTAGEParams::nHistoryTables)
        .def_readwrite("tagTableCounterBits", &LTAGEParams::tagTableCounterBits)
        ;

    py::class_<LTAGE, BPredUnit, std::unique_ptr<LTAGE, py::nodelete>>(m, "LTAGE")
        ;

}

static EmbeddedPyBind embed_obj("LTAGE", module_init, "BranchPredictor");
