#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseReplacementPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/base.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseReplacementPolicy");
    py::class_<BaseReplacementPolicyParams, SimObjectParams, std::unique_ptr<BaseReplacementPolicyParams, py::nodelete>>(m, "BaseReplacementPolicyParams")
        ;

    py::class_<BaseReplacementPolicy, SimObject, std::unique_ptr<BaseReplacementPolicy, py::nodelete>>(m, "BaseReplacementPolicy")
        ;

}

static EmbeddedPyBind embed_obj("BaseReplacementPolicy", module_init, "SimObject");
