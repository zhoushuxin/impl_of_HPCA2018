#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIO9PSocket.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/fs9p.hh"

#include <string>
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIO9PSocket");
    py::class_<VirtIO9PSocketParams, VirtIO9PProxyParams, std::unique_ptr<VirtIO9PSocketParams, py::nodelete>>(m, "VirtIO9PSocketParams")
        .def(py::init<>())
        .def("create", &VirtIO9PSocketParams::create)
        .def_readwrite("port", &VirtIO9PSocketParams::port)
        .def_readwrite("server", &VirtIO9PSocketParams::server)
        ;

    py::class_<VirtIO9PSocket, VirtIO9PProxy, std::unique_ptr<VirtIO9PSocket, py::nodelete>>(m, "VirtIO9PSocket")
        ;

}

static EmbeddedPyBind embed_obj("VirtIO9PSocket", module_init, "VirtIO9PProxy");
