#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DiskImage.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/disk_image.hh"

#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DiskImage");
    py::class_<DiskImageParams, SimObjectParams, std::unique_ptr<DiskImageParams, py::nodelete>>(m, "DiskImageParams")
        .def_readwrite("image_file", &DiskImageParams::image_file)
        .def_readwrite("read_only", &DiskImageParams::read_only)
        ;

    py::class_<DiskImage, SimObject, std::unique_ptr<DiskImage, py::nodelete>>(m, "DiskImage")
        ;

}

static EmbeddedPyBind embed_obj("DiskImage", module_init, "SimObject");
