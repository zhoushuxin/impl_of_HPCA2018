#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/sim_object.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimObject");
    py::class_<SimObjectParams, std::unique_ptr<SimObjectParams, py::nodelete>>(m, "SimObjectParams")
        .def_readwrite("name", &SimObjectParams::name)
        .def_readwrite("eventq_index", &SimObjectParams::eventq_index)
        ;

    py::class_<SimObject, Drainable, Serializable, std::unique_ptr<SimObject, py::nodelete>>(m, "SimObject")
        .def("init", &SimObject::init)
        .def("initState", &SimObject::initState)
        .def("memInvalidate", &SimObject::memInvalidate)
        .def("memWriteback", &SimObject::memWriteback)
        .def("regStats", &SimObject::regStats)
        .def("resetStats", &SimObject::resetStats)
        .def("regProbePoints", &SimObject::regProbePoints)
        .def("regProbeListeners", &SimObject::regProbeListeners)
        .def("startup", &SimObject::startup)
        .def("loadState", &SimObject::loadState, 
            py::arg("cp"))
        ;

}

static EmbeddedPyBind embed_obj("SimObject", module_init, "");
