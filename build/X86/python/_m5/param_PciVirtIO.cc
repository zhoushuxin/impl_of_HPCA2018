#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PciVirtIO.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/pci.hh"

#include "dev/virtio/base.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PciVirtIO");
    py::class_<PciVirtIOParams, PciDeviceParams, std::unique_ptr<PciVirtIOParams, py::nodelete>>(m, "PciVirtIOParams")
        .def(py::init<>())
        .def("create", &PciVirtIOParams::create)
        .def_readwrite("vio", &PciVirtIOParams::vio)
        ;

    py::class_<PciVirtIO, PciDevice, std::unique_ptr<PciVirtIO, py::nodelete>>(m, "PciVirtIO")
        ;

}

static EmbeddedPyBind embed_obj("PciVirtIO", module_init, "PciDevice");
