#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Root.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/root.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Root");
    py::class_<RootParams, SimObjectParams, std::unique_ptr<RootParams, py::nodelete>>(m, "RootParams")
        .def(py::init<>())
        .def("create", &RootParams::create)
        .def_readwrite("full_system", &RootParams::full_system)
        .def_readwrite("sim_quantum", &RootParams::sim_quantum)
        .def_readwrite("time_sync_enable", &RootParams::time_sync_enable)
        .def_readwrite("time_sync_period", &RootParams::time_sync_period)
        .def_readwrite("time_sync_spin_threshold", &RootParams::time_sync_spin_threshold)
        ;

    py::class_<Root, SimObject, std::unique_ptr<Root, py::nodelete>>(m, "Root")
        ;

}

static EmbeddedPyBind embed_obj("Root", module_init, "SimObject");
