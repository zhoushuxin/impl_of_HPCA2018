#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimPoint.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/simple/probes/simpoint.hh"

#include "base/types.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimPoint");
    py::class_<SimPointParams, ProbeListenerObjectParams, std::unique_ptr<SimPointParams, py::nodelete>>(m, "SimPointParams")
        .def(py::init<>())
        .def("create", &SimPointParams::create)
        .def_readwrite("interval", &SimPointParams::interval)
        .def_readwrite("profile_file", &SimPointParams::profile_file)
        ;

    py::class_<SimPoint, ProbeListenerObject, std::unique_ptr<SimPoint, py::nodelete>>(m, "SimPoint")
        ;

}

static EmbeddedPyBind embed_obj("SimPoint", module_init, "ProbeListenerObject");
