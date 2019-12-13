#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Platform.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/platform.hh"

#include "cpu/intr_control.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Platform");
    py::class_<PlatformParams, SimObjectParams, std::unique_ptr<PlatformParams, py::nodelete>>(m, "PlatformParams")
        .def_readwrite("intrctrl", &PlatformParams::intrctrl)
        ;

    py::class_<Platform, SimObject, std::unique_ptr<Platform, py::nodelete>>(m, "Platform")
        ;

}

static EmbeddedPyBind embed_obj("Platform", module_init, "SimObject");
