#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TournamentBP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/tournament.hh"

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
    py::module m = m_internal.def_submodule("param_TournamentBP");
    py::class_<TournamentBPParams, BranchPredictorParams, std::unique_ptr<TournamentBPParams, py::nodelete>>(m, "TournamentBPParams")
        .def(py::init<>())
        .def("create", &TournamentBPParams::create)
        .def_readwrite("choiceCtrBits", &TournamentBPParams::choiceCtrBits)
        .def_readwrite("choicePredictorSize", &TournamentBPParams::choicePredictorSize)
        .def_readwrite("globalCtrBits", &TournamentBPParams::globalCtrBits)
        .def_readwrite("globalPredictorSize", &TournamentBPParams::globalPredictorSize)
        .def_readwrite("localCtrBits", &TournamentBPParams::localCtrBits)
        .def_readwrite("localHistoryTableSize", &TournamentBPParams::localHistoryTableSize)
        .def_readwrite("localPredictorSize", &TournamentBPParams::localPredictorSize)
        ;

    py::class_<TournamentBP, BPredUnit, std::unique_ptr<TournamentBP, py::nodelete>>(m, "TournamentBP")
        ;

}

static EmbeddedPyBind embed_obj("TournamentBP", module_init, "BranchPredictor");
