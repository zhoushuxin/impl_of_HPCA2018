#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/LRUReplacementPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/LRUPolicy.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_LRUReplacementPolicy");
    py::class_<LRUReplacementPolicyParams, ReplacementPolicyParams, std::unique_ptr<LRUReplacementPolicyParams, py::nodelete>>(m, "LRUReplacementPolicyParams")
        .def(py::init<>())
        .def("create", &LRUReplacementPolicyParams::create)
        ;

    py::class_<LRUPolicy, AbstractReplacementPolicy, std::unique_ptr<LRUPolicy, py::nodelete>>(m, "LRUPolicy")
        ;

}

static EmbeddedPyBind embed_obj("LRUReplacementPolicy", module_init, "ReplacementPolicy");
