#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GoodbyeObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/goodbye_object.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GoodbyeObject");
    py::class_<GoodbyeObjectParams, SimObjectParams, std::unique_ptr<GoodbyeObjectParams, py::nodelete>>(m, "GoodbyeObjectParams")
        .def(py::init<>())
        .def("create", &GoodbyeObjectParams::create)
        .def_readwrite("buffer_size", &GoodbyeObjectParams::buffer_size)
        .def_readwrite("write_bandwidth", &GoodbyeObjectParams::write_bandwidth)
        ;

    py::class_<GoodbyeObject, SimObject, std::unique_ptr<GoodbyeObject, py::nodelete>>(m, "GoodbyeObject")
        ;

}

static EmbeddedPyBind embed_obj("GoodbyeObject", module_init, "SimObject");
