#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/IdeController.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/ide_ctrl.hh"

#include "base/types.hh"
#include <vector>
#include "dev/storage/ide_disk.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_IdeController");
    py::class_<IdeControllerParams, PciDeviceParams, std::unique_ptr<IdeControllerParams, py::nodelete>>(m, "IdeControllerParams")
        .def(py::init<>())
        .def("create", &IdeControllerParams::create)
        .def_readwrite("ctrl_offset", &IdeControllerParams::ctrl_offset)
        .def_readwrite("disks", &IdeControllerParams::disks)
        .def_readwrite("io_shift", &IdeControllerParams::io_shift)
        ;

    py::class_<IdeController, PciDevice, std::unique_ptr<IdeController, py::nodelete>>(m, "IdeController")
        ;

}

static EmbeddedPyBind embed_obj("IdeController", module_init, "PciDevice");
