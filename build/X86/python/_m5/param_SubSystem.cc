#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SubSystem.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/sub_system.hh"

#include "sim/power/thermal_domain.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SubSystem");
    py::class_<SubSystemParams, SimObjectParams, std::unique_ptr<SubSystemParams, py::nodelete>>(m, "SubSystemParams")
        .def(py::init<>())
        .def("create", &SubSystemParams::create)
        .def_readwrite("thermal_domain", &SubSystemParams::thermal_domain)
        ;

    py::class_<SubSystem, SimObject, std::unique_ptr<SubSystem, py::nodelete>>(m, "SubSystem")
        ;

}

static EmbeddedPyBind embed_obj("SubSystem", module_init, "SimObject");
