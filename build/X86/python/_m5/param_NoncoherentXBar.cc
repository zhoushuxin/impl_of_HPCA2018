#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/NoncoherentXBar.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/noncoherent_xbar.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_NoncoherentXBar");
    py::class_<NoncoherentXBarParams, BaseXBarParams, std::unique_ptr<NoncoherentXBarParams, py::nodelete>>(m, "NoncoherentXBarParams")
        .def(py::init<>())
        .def("create", &NoncoherentXBarParams::create)
        ;

    py::class_<NoncoherentXBar, BaseXBar, std::unique_ptr<NoncoherentXBar, py::nodelete>>(m, "NoncoherentXBar")
        ;

}

static EmbeddedPyBind embed_obj("NoncoherentXBar", module_init, "BaseXBar");
