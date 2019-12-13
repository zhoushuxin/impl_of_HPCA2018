#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/HelloObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/hello_object.hh"

#include "learning_gem5/part2/goodbye_object.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_HelloObject");
    py::class_<HelloObjectParams, SimObjectParams, std::unique_ptr<HelloObjectParams, py::nodelete>>(m, "HelloObjectParams")
        .def(py::init<>())
        .def("create", &HelloObjectParams::create)
        .def_readwrite("goodbye_object", &HelloObjectParams::goodbye_object)
        .def_readwrite("number_of_fires", &HelloObjectParams::number_of_fires)
        .def_readwrite("time_to_wait", &HelloObjectParams::time_to_wait)
        ;

    py::class_<HelloObject, SimObject, std::unique_ptr<HelloObject, py::nodelete>>(m, "HelloObject")
        ;

}

static EmbeddedPyBind embed_obj("HelloObject", module_init, "SimObject");
