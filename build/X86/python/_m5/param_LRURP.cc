#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/LRURP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/lru_rp.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_LRURP");
    py::class_<LRURPParams, BaseReplacementPolicyParams, std::unique_ptr<LRURPParams, py::nodelete>>(m, "LRURPParams")
        .def(py::init<>())
        .def("create", &LRURPParams::create)
        ;

    py::class_<LRURP, BaseReplacementPolicy, std::unique_ptr<LRURP, py::nodelete>>(m, "LRURP")
        ;

}

static EmbeddedPyBind embed_obj("LRURP", module_init, "BaseReplacementPolicy");
