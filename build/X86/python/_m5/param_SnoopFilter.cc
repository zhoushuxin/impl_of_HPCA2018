#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/SnoopFilter.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/snoop_filter.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_SnoopFilter");
    py::class_<SnoopFilterParams, SimObjectParams, std::unique_ptr<SnoopFilterParams, py::nodelete>>(m, "SnoopFilterParams")
        .def(py::init<>())
        .def("create", &SnoopFilterParams::create)
        .def_readwrite("lookup_latency", &SnoopFilterParams::lookup_latency)
        .def_readwrite("max_capacity", &SnoopFilterParams::max_capacity)
        .def_readwrite("system", &SnoopFilterParams::system)
        ;

    py::class_<SnoopFilter, SimObject, std::unique_ptr<SnoopFilter, py::nodelete>>(m, "SnoopFilter")
        ;

}

static EmbeddedPyBind embed_obj("SnoopFilter", module_init, "SimObject");
