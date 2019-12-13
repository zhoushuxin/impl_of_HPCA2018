#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/NSGigE.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/ns_gige.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_NSGigE");
    py::class_<NSGigEParams, EtherDevBaseParams, std::unique_ptr<NSGigEParams, py::nodelete>>(m, "NSGigEParams")
        .def(py::init<>())
        .def("create", &NSGigEParams::create)
        .def_readwrite("dma_data_free", &NSGigEParams::dma_data_free)
        .def_readwrite("dma_desc_free", &NSGigEParams::dma_desc_free)
        .def_readwrite("dma_no_allocate", &NSGigEParams::dma_no_allocate)
        ;

    py::class_<NSGigE, EtherDevBase, std::unique_ptr<NSGigE, py::nodelete>>(m, "NSGigE")
        ;

}

static EmbeddedPyBind embed_obj("NSGigE", module_init, "EtherDevBase");
