#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DerivedClockDomain.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/clock_domain.hh"

#include "base/types.hh"
#include "sim/clock_domain.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DerivedClockDomain");
    py::class_<DerivedClockDomainParams, ClockDomainParams, std::unique_ptr<DerivedClockDomainParams, py::nodelete>>(m, "DerivedClockDomainParams")
        .def(py::init<>())
        .def("create", &DerivedClockDomainParams::create)
        .def_readwrite("clk_divider", &DerivedClockDomainParams::clk_divider)
        .def_readwrite("clk_domain", &DerivedClockDomainParams::clk_domain)
        ;

    py::class_<DerivedClockDomain, ClockDomain, std::unique_ptr<DerivedClockDomain, py::nodelete>>(m, "DerivedClockDomain")
        ;

}

static EmbeddedPyBind embed_obj("DerivedClockDomain", module_init, "ClockDomain");
