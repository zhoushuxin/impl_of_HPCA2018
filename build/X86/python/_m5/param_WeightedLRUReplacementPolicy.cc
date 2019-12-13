#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/WeightedLRUReplacementPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/system/WeightedLRUPolicy.hh"

#include "mem/ruby/structures/CacheMemory.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_WeightedLRUReplacementPolicy");
    py::class_<WeightedLRUReplacementPolicyParams, ReplacementPolicyParams, std::unique_ptr<WeightedLRUReplacementPolicyParams, py::nodelete>>(m, "WeightedLRUReplacementPolicyParams")
        .def(py::init<>())
        .def("create", &WeightedLRUReplacementPolicyParams::create)
        .def_readwrite("cache", &WeightedLRUReplacementPolicyParams::cache)
        ;

    py::class_<WeightedLRUPolicy, AbstractReplacementPolicy, std::unique_ptr<WeightedLRUPolicy, py::nodelete>>(m, "WeightedLRUPolicy")
        ;

}

static EmbeddedPyBind embed_obj("WeightedLRUReplacementPolicy", module_init, "ReplacementPolicy");
