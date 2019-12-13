#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ReplacementPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/AbstractReplacementPolicy.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ReplacementPolicy");
    py::class_<ReplacementPolicyParams, SimObjectParams, std::unique_ptr<ReplacementPolicyParams, py::nodelete>>(m, "ReplacementPolicyParams")
        .def(py::init<>())
        .def("create", &ReplacementPolicyParams::create)
        .def_readwrite("assoc", &ReplacementPolicyParams::assoc)
        .def_readwrite("block_size", &ReplacementPolicyParams::block_size)
        .def_readwrite("size", &ReplacementPolicyParams::size)
        ;

    py::class_<AbstractReplacementPolicy, SimObject, std::unique_ptr<AbstractReplacementPolicy, py::nodelete>>(m, "AbstractReplacementPolicy")
        ;

}

static EmbeddedPyBind embed_obj("ReplacementPolicy", module_init, "SimObject");
