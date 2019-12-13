#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SimpleObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/simple_object.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SimpleObject");
    py::class_<SimpleObjectParams, SimObjectParams, std::unique_ptr<SimpleObjectParams, py::nodelete>>(m, "SimpleObjectParams")
        .def(py::init<>())
        .def("create", &SimpleObjectParams::create)
        ;

    py::class_<SimpleObject, SimObject, std::unique_ptr<SimpleObject, py::nodelete>>(m, "SimpleObject")
        ;

}

static EmbeddedPyBind embed_obj("SimpleObject", module_init, "SimObject");
