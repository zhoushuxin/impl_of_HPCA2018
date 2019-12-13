#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Pc.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/pc.hh"

#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Pc");
    py::class_<PcParams, PlatformParams, std::unique_ptr<PcParams, py::nodelete>>(m, "PcParams")
        .def(py::init<>())
        .def("create", &PcParams::create)
        .def_readwrite("system", &PcParams::system)
        ;

    py::class_<Pc, Platform, std::unique_ptr<Pc, py::nodelete>>(m, "Pc")
        ;

}

static EmbeddedPyBind embed_obj("Pc", module_init, "Platform");
