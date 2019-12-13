#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VoltageDomain.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/voltage_domain.hh"

#include <vector>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VoltageDomain");
    py::class_<VoltageDomainParams, SimObjectParams, std::unique_ptr<VoltageDomainParams, py::nodelete>>(m, "VoltageDomainParams")
        .def(py::init<>())
        .def("create", &VoltageDomainParams::create)
        .def_readwrite("voltage", &VoltageDomainParams::voltage)
        ;

    py::class_<VoltageDomain, SimObject, std::unique_ptr<VoltageDomain, py::nodelete>>(m, "VoltageDomain")
        ;

}

static EmbeddedPyBind embed_obj("VoltageDomain", module_init, "SimObject");
