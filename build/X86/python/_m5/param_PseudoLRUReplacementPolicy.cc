#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PseudoLRUReplacementPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/PseudoLRUPolicy.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PseudoLRUReplacementPolicy");
    py::class_<PseudoLRUReplacementPolicyParams, ReplacementPolicyParams, std::unique_ptr<PseudoLRUReplacementPolicyParams, py::nodelete>>(m, "PseudoLRUReplacementPolicyParams")
        .def(py::init<>())
        .def("create", &PseudoLRUReplacementPolicyParams::create)
        ;

    py::class_<PseudoLRUPolicy, AbstractReplacementPolicy, std::unique_ptr<PseudoLRUPolicy, py::nodelete>>(m, "PseudoLRUPolicy")
        ;

}

static EmbeddedPyBind embed_obj("PseudoLRUReplacementPolicy", module_init, "ReplacementPolicy");
