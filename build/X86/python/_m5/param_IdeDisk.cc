#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/IdeDisk.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/ide_disk.hh"

#include "base/types.hh"
#include "enums/IdeID.hh"
#include "dev/storage/disk_image.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_IdeDisk");
    py::class_<IdeDiskParams, SimObjectParams, std::unique_ptr<IdeDiskParams, py::nodelete>>(m, "IdeDiskParams")
        .def(py::init<>())
        .def("create", &IdeDiskParams::create)
        .def_readwrite("delay", &IdeDiskParams::delay)
        .def_readwrite("driveID", &IdeDiskParams::driveID)
        .def_readwrite("image", &IdeDiskParams::image)
        ;

    py::class_<IdeDisk, SimObject, std::unique_ptr<IdeDisk, py::nodelete>>(m, "IdeDisk")
        ;

}

static EmbeddedPyBind embed_obj("IdeDisk", module_init, "SimObject");
