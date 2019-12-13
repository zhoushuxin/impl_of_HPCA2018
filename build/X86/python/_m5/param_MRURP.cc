#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MRURP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/mru_rp.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MRURP");
    py::class_<MRURPParams, BaseReplacementPolicyParams, std::unique_ptr<MRURPParams, py::nodelete>>(m, "MRURPParams")
        .def(py::init<>())
        .def("create", &MRURPParams::create)
        ;

    py::class_<MRURP, BaseReplacementPolicy, std::unique_ptr<MRURP, py::nodelete>>(m, "MRURP")
        ;

}

static EmbeddedPyBind embed_obj("MRURP", module_init, "BaseReplacementPolicy");
