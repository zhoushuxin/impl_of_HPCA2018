#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIO9PBase.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/fs9p.hh"

#include "base/types.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIO9PBase");
    py::class_<VirtIO9PBaseParams, VirtIODeviceBaseParams, std::unique_ptr<VirtIO9PBaseParams, py::nodelete>>(m, "VirtIO9PBaseParams")
        .def_readwrite("queueSize", &VirtIO9PBaseParams::queueSize)
        .def_readwrite("tag", &VirtIO9PBaseParams::tag)
        ;

    py::class_<VirtIO9PBase, VirtIODeviceBase, std::unique_ptr<VirtIO9PBase, py::nodelete>>(m, "VirtIO9PBase")
        ;

}

static EmbeddedPyBind embed_obj("VirtIO9PBase", module_init, "VirtIODeviceBase");
