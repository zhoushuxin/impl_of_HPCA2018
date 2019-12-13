#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/VirtIO9PDiod.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/fs9p.hh"

#include <string>
#include <string>
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_VirtIO9PDiod");
    py::class_<VirtIO9PDiodParams, VirtIO9PProxyParams, std::unique_ptr<VirtIO9PDiodParams, py::nodelete>>(m, "VirtIO9PDiodParams")
        .def(py::init<>())
        .def("create", &VirtIO9PDiodParams::create)
        .def_readwrite("diod", &VirtIO9PDiodParams::diod)
        .def_readwrite("root", &VirtIO9PDiodParams::root)
        .def_readwrite("socketPath", &VirtIO9PDiodParams::socketPath)
        ;

    py::class_<VirtIO9PDiod, VirtIO9PProxy, std::unique_ptr<VirtIO9PDiod, py::nodelete>>(m, "VirtIO9PDiod")
        ;

}

static EmbeddedPyBind embed_obj("VirtIO9PDiod", module_init, "VirtIO9PProxy");
