#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ClockDomain.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/clock_domain.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ClockDomain");
    py::class_<ClockDomainParams, SimObjectParams, std::unique_ptr<ClockDomainParams, py::nodelete>>(m, "ClockDomainParams")
        ;

    py::class_<ClockDomain, SimObject, std::unique_ptr<ClockDomain, py::nodelete>>(m, "ClockDomain")
        ;

}

static EmbeddedPyBind embed_obj("ClockDomain", module_init, "SimObject");
