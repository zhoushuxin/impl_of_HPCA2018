#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIO9PProxy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/fs9p.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIO9PProxy");
    py::class_<VirtIO9PProxyParams, VirtIO9PBaseParams, std::unique_ptr<VirtIO9PProxyParams, py::nodelete>>(m, "VirtIO9PProxyParams")
        ;

    py::class_<VirtIO9PProxy, VirtIO9PBase, std::unique_ptr<VirtIO9PProxy, py::nodelete>>(m, "VirtIO9PProxy")
        ;

}

static EmbeddedPyBind embed_obj("VirtIO9PProxy", module_init, "VirtIO9PBase");
