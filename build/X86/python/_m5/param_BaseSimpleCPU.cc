#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseSimpleCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/simple/base.hh"

#include "cpu/pred/bpred_unit.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseSimpleCPU");
    py::class_<BaseSimpleCPUParams, BaseCPUParams, std::unique_ptr<BaseSimpleCPUParams, py::nodelete>>(m, "BaseSimpleCPUParams")
        .def_readwrite("branchPred", &BaseSimpleCPUParams::branchPred)
        ;

    py::class_<BaseSimpleCPU, BaseCPU, std::unique_ptr<BaseSimpleCPU, py::nodelete>>(m, "BaseSimpleCPU")
        ;

}

static EmbeddedPyBind embed_obj("BaseSimpleCPU", module_init, "BaseCPU");
