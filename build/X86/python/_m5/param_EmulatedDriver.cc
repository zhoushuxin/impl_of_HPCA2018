#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EmulatedDriver.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/emul_driver.hh"

#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EmulatedDriver");
    py::class_<EmulatedDriverParams, SimObjectParams, std::unique_ptr<EmulatedDriverParams, py::nodelete>>(m, "EmulatedDriverParams")
        .def_readwrite("filename", &EmulatedDriverParams::filename)
        ;

    py::class_<EmulatedDriver, SimObject, std::unique_ptr<EmulatedDriver, py::nodelete>>(m, "EmulatedDriver")
        ;

}

static EmbeddedPyBind embed_obj("EmulatedDriver", module_init, "SimObject");
