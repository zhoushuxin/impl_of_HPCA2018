#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/FIFORP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/fifo_rp.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_FIFORP");
    py::class_<FIFORPParams, BaseReplacementPolicyParams, std::unique_ptr<FIFORPParams, py::nodelete>>(m, "FIFORPParams")
        .def(py::init<>())
        .def("create", &FIFORPParams::create)
        ;

    py::class_<FIFORP, BaseReplacementPolicy, std::unique_ptr<FIFORP, py::nodelete>>(m, "FIFORP")
        ;

}

static EmbeddedPyBind embed_obj("FIFORP", module_init, "BaseReplacementPolicy");
