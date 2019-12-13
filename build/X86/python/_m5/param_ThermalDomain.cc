#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ThermalDomain.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_domain.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ThermalDomain");
    py::class_<ThermalDomainParams, SimObjectParams, std::unique_ptr<ThermalDomainParams, py::nodelete>>(m, "ThermalDomainParams")
        .def(py::init<>())
        .def("create", &ThermalDomainParams::create)
        .def_readwrite("initial_temperature", &ThermalDomainParams::initial_temperature)
        ;

    py::class_<ThermalDomain, SimObject, std::unique_ptr<ThermalDomain, py::nodelete>>(m, "ThermalDomain")
        .def("setNode", &ThermalDomain::setNode)
        ;

}

static EmbeddedPyBind embed_obj("ThermalDomain", module_init, "SimObject");
