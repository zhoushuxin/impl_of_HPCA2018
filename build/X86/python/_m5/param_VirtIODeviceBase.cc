#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIODeviceBase.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/base.hh"

#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIODeviceBase");
    py::class_<VirtIODeviceBaseParams, SimObjectParams, std::unique_ptr<VirtIODeviceBaseParams, py::nodelete>>(m, "VirtIODeviceBaseParams")
        .def_readwrite("subsystem", &VirtIODeviceBaseParams::subsystem)
        .def_readwrite("system", &VirtIODeviceBaseParams::system)
        ;

    py::class_<VirtIODeviceBase, SimObject, std::unique_ptr<VirtIODeviceBase, py::nodelete>>(m, "VirtIODeviceBase")
        ;

}

static EmbeddedPyBind embed_obj("VirtIODeviceBase", module_init, "SimObject");
