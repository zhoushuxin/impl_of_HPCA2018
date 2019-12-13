#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RandomRP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/random_rp.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RandomRP");
    py::class_<RandomRPParams, BaseReplacementPolicyParams, std::unique_ptr<RandomRPParams, py::nodelete>>(m, "RandomRPParams")
        .def(py::init<>())
        .def("create", &RandomRPParams::create)
        ;

    py::class_<RandomRP, BaseReplacementPolicy, std::unique_ptr<RandomRP, py::nodelete>>(m, "RandomRP")
        ;

}

static EmbeddedPyBind embed_obj("RandomRP", module_init, "BaseReplacementPolicy");
