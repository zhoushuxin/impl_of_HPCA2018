#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/LocalBP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/2bit_local.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_LocalBP");
    py::class_<LocalBPParams, BranchPredictorParams, std::unique_ptr<LocalBPParams, py::nodelete>>(m, "LocalBPParams")
        .def(py::init<>())
        .def("create", &LocalBPParams::create)
        .def_readwrite("localCtrBits", &LocalBPParams::localCtrBits)
        .def_readwrite("localPredictorSize", &LocalBPParams::localPredictorSize)
        ;

    py::class_<LocalBP, BPredUnit, std::unique_ptr<LocalBP, py::nodelete>>(m, "LocalBP")
        ;

}

static EmbeddedPyBind embed_obj("LocalBP", module_init, "BranchPredictor");
