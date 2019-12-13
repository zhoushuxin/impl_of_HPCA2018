#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleDisk.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/simple_disk.hh"

#include "dev/storage/disk_image.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleDisk");
    py::class_<SimpleDiskParams, SimObjectParams, std::unique_ptr<SimpleDiskParams, py::nodelete>>(m, "SimpleDiskParams")
        .def(py::init<>())
        .def("create", &SimpleDiskParams::create)
        .def_readwrite("disk", &SimpleDiskParams::disk)
        .def_readwrite("system", &SimpleDiskParams::system)
        ;

    py::class_<SimpleDisk, SimObject, std::unique_ptr<SimpleDisk, py::nodelete>>(m, "SimpleDisk")
        ;

}

static EmbeddedPyBind embed_obj("SimpleDisk", module_init, "SimObject");
