#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BiModeBP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/bi_mode.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BiModeBP");
    py::class_<BiModeBPParams, BranchPredictorParams, std::unique_ptr<BiModeBPParams, py::nodelete>>(m, "BiModeBPParams")
        .def(py::init<>())
        .def("create", &BiModeBPParams::create)
        .def_readwrite("choiceCtrBits", &BiModeBPParams::choiceCtrBits)
        .def_readwrite("choicePredictorSize", &BiModeBPParams::choicePredictorSize)
        .def_readwrite("globalCtrBits", &BiModeBPParams::globalCtrBits)
        .def_readwrite("globalPredictorSize", &BiModeBPParams::globalPredictorSize)
        ;

    py::class_<BiModeBP, BPredUnit, std::unique_ptr<BiModeBP, py::nodelete>>(m, "BiModeBP")
        ;

}

static EmbeddedPyBind embed_obj("BiModeBP", module_init, "BranchPredictor");
