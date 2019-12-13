#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIOBlock.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/block.hh"

#include "dev/storage/disk_image.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIOBlock");
    py::class_<VirtIOBlockParams, VirtIODeviceBaseParams, std::unique_ptr<VirtIOBlockParams, py::nodelete>>(m, "VirtIOBlockParams")
        .def(py::init<>())
        .def("create", &VirtIOBlockParams::create)
        .def_readwrite("image", &VirtIOBlockParams::image)
        .def_readwrite("queueSize", &VirtIOBlockParams::queueSize)
        ;

    py::class_<VirtIOBlock, VirtIODeviceBase, std::unique_ptr<VirtIOBlock, py::nodelete>>(m, "VirtIOBlock")
        ;

}

static EmbeddedPyBind embed_obj("VirtIOBlock", module_init, "VirtIODeviceBase");
