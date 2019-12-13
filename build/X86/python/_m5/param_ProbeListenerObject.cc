#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ProbeListenerObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/probe/probe.hh"

#include "sim/sim_object.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ProbeListenerObject");
    py::class_<ProbeListenerObjectParams, SimObjectParams, std::unique_ptr<ProbeListenerObjectParams, py::nodelete>>(m, "ProbeListenerObjectParams")
        .def(py::init<>())
        .def("create", &ProbeListenerObjectParams::create)
        .def_readwrite("manager", &ProbeListenerObjectParams::manager)
        ;

    py::class_<ProbeListenerObject, SimObject, std::unique_ptr<ProbeListenerObject, py::nodelete>>(m, "ProbeListenerObject")
        ;

}

static EmbeddedPyBind embed_obj("ProbeListenerObject", module_init, "SimObject");
