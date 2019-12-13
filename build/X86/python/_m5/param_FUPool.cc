#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/FUPool.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/o3/fu_pool.hh"

#include <vector>
#include "cpu/func_unit.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_FUPool");
    py::class_<FUPoolParams, SimObjectParams, std::unique_ptr<FUPoolParams, py::nodelete>>(m, "FUPoolParams")
        .def(py::init<>())
        .def("create", &FUPoolParams::create)
        .def_readwrite("FUList", &FUPoolParams::FUList)
        ;

    py::class_<FUPool, SimObject, std::unique_ptr<FUPool, py::nodelete>>(m, "FUPool")
        ;

}

static EmbeddedPyBind embed_obj("FUPool", module_init, "SimObject");
