#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIODummyDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/base.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIODummyDevice");
    py::class_<VirtIODummyDeviceParams, VirtIODeviceBaseParams, std::unique_ptr<VirtIODummyDeviceParams, py::nodelete>>(m, "VirtIODummyDeviceParams")
        .def(py::init<>())
        .def("create", &VirtIODummyDeviceParams::create)
        ;

    py::class_<VirtIODummyDevice, VirtIODeviceBase, std::unique_ptr<VirtIODummyDevice, py::nodelete>>(m, "VirtIODummyDevice")
        ;

}

static EmbeddedPyBind embed_obj("VirtIODummyDevice", module_init, "VirtIODeviceBase");
