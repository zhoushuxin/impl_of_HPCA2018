#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VncInput.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "base/vnc/vncinput.hh"

#include "enums/ImageFormat.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VncInput");
    py::class_<VncInputParams, SimObjectParams, std::unique_ptr<VncInputParams, py::nodelete>>(m, "VncInputParams")
        .def(py::init<>())
        .def("create", &VncInputParams::create)
        .def_readwrite("frame_capture", &VncInputParams::frame_capture)
        .def_readwrite("img_format", &VncInputParams::img_format)
        ;

    py::class_<VncInput, SimObject, std::unique_ptr<VncInput, py::nodelete>>(m, "VncInput")
        ;

}

static EmbeddedPyBind embed_obj("VncInput", module_init, "SimObject");
