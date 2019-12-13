#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseTLB.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/generic/tlb.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseTLB");
    py::class_<BaseTLBParams, SimObjectParams, std::unique_ptr<BaseTLBParams, py::nodelete>>(m, "BaseTLBParams")
        ;

    py::class_<BaseTLB, SimObject, std::unique_ptr<BaseTLB, py::nodelete>>(m, "BaseTLB")
        ;

}

static EmbeddedPyBind embed_obj("BaseTLB", module_init, "SimObject");
