#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/CoherentXBar.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/coherent_xbar.hh"

#include "mem/snoop_filter.hh"
#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_CoherentXBar");
    py::class_<CoherentXBarParams, BaseXBarParams, std::unique_ptr<CoherentXBarParams, py::nodelete>>(m, "CoherentXBarParams")
        .def(py::init<>())
        .def("create", &CoherentXBarParams::create)
        .def_readwrite("point_of_coherency", &CoherentXBarParams::point_of_coherency)
        .def_readwrite("point_of_unification", &CoherentXBarParams::point_of_unification)
        .def_readwrite("snoop_filter", &CoherentXBarParams::snoop_filter)
        .def_readwrite("snoop_response_latency", &CoherentXBarParams::snoop_response_latency)
        .def_readwrite("system", &CoherentXBarParams::system)
        ;

    py::class_<CoherentXBar, BaseXBar, std::unique_ptr<CoherentXBar, py::nodelete>>(m, "CoherentXBar")
        ;

}

static EmbeddedPyBind embed_obj("CoherentXBar", module_init, "BaseXBar");
