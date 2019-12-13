#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/CowDiskImage.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/disk_image.hh"

#include "dev/storage/disk_image.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_CowDiskImage");
    py::class_<CowDiskImageParams, DiskImageParams, std::unique_ptr<CowDiskImageParams, py::nodelete>>(m, "CowDiskImageParams")
        .def(py::init<>())
        .def("create", &CowDiskImageParams::create)
        .def_readwrite("child", &CowDiskImageParams::child)
        .def_readwrite("table_size", &CowDiskImageParams::table_size)
        ;

    py::class_<CowDiskImage, DiskImage, std::unique_ptr<CowDiskImage, py::nodelete>>(m, "CowDiskImage")
        ;

}

static EmbeddedPyBind embed_obj("CowDiskImage", module_init, "DiskImage");
