#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RawDiskImage.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/disk_image.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RawDiskImage");
    py::class_<RawDiskImageParams, DiskImageParams, std::unique_ptr<RawDiskImageParams, py::nodelete>>(m, "RawDiskImageParams")
        .def(py::init<>())
        .def("create", &RawDiskImageParams::create)
        ;

    py::class_<RawDiskImage, DiskImage, std::unique_ptr<RawDiskImage, py::nodelete>>(m, "RawDiskImage")
        ;

}

static EmbeddedPyBind embed_obj("RawDiskImage", module_init, "DiskImage");
