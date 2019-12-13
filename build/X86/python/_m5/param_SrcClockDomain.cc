#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SrcClockDomain.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/clock_domain.hh"

#include <vector>
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/voltage_domain.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SrcClockDomain");
    py::class_<SrcClockDomainParams, ClockDomainParams, std::unique_ptr<SrcClockDomainParams, py::nodelete>>(m, "SrcClockDomainParams")
        .def(py::init<>())
        .def("create", &SrcClockDomainParams::create)
        .def_readwrite("clock", &SrcClockDomainParams::clock)
        .def_readwrite("domain_id", &SrcClockDomainParams::domain_id)
        .def_readwrite("init_perf_level", &SrcClockDomainParams::init_perf_level)
        .def_readwrite("voltage_domain", &SrcClockDomainParams::voltage_domain)
        ;

    py::class_<SrcClockDomain, ClockDomain, std::unique_ptr<SrcClockDomain, py::nodelete>>(m, "SrcClockDomain")
        ;

}

static EmbeddedPyBind embed_obj("SrcClockDomain", module_init, "ClockDomain");
