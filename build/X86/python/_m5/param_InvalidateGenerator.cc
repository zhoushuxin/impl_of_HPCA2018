#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/InvalidateGenerator.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/directedtest/InvalidateGenerator.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_InvalidateGenerator");
    py::class_<InvalidateGeneratorParams, DirectedGeneratorParams, std::unique_ptr<InvalidateGeneratorParams, py::nodelete>>(m, "InvalidateGeneratorParams")
        .def(py::init<>())
        .def("create", &InvalidateGeneratorParams::create)
        .def_readwrite("addr_increment_size", &InvalidateGeneratorParams::addr_increment_size)
        ;

    py::class_<InvalidateGenerator, DirectedGenerator, std::unique_ptr<InvalidateGenerator, py::nodelete>>(m, "InvalidateGenerator")
        ;

}

static EmbeddedPyBind embed_obj("InvalidateGenerator", module_init, "DirectedGenerator");
