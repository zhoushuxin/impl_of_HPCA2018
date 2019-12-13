#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SeriesRequestGenerator.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/directedtest/SeriesRequestGenerator.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SeriesRequestGenerator");
    py::class_<SeriesRequestGeneratorParams, DirectedGeneratorParams, std::unique_ptr<SeriesRequestGeneratorParams, py::nodelete>>(m, "SeriesRequestGeneratorParams")
        .def(py::init<>())
        .def("create", &SeriesRequestGeneratorParams::create)
        .def_readwrite("addr_increment_size", &SeriesRequestGeneratorParams::addr_increment_size)
        .def_readwrite("num_series", &SeriesRequestGeneratorParams::num_series)
        .def_readwrite("percent_writes", &SeriesRequestGeneratorParams::percent_writes)
        ;

    py::class_<SeriesRequestGenerator, DirectedGenerator, std::unique_ptr<SeriesRequestGenerator, py::nodelete>>(m, "SeriesRequestGenerator")
        ;

}

static EmbeddedPyBind embed_obj("SeriesRequestGenerator", module_init, "DirectedGenerator");
