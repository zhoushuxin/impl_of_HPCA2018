#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/FUDesc.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/func_unit.hh"

#include "base/types.hh"
#include <vector>
#include "cpu/func_unit.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_FUDesc");
    py::class_<FUDescParams, SimObjectParams, std::unique_ptr<FUDescParams, py::nodelete>>(m, "FUDescParams")
        .def(py::init<>())
        .def("create", &FUDescParams::create)
        .def_readwrite("count", &FUDescParams::count)
        .def_readwrite("opList", &FUDescParams::opList)
        ;

    py::class_<FUDesc, SimObject, std::unique_ptr<FUDesc, py::nodelete>>(m, "FUDesc")
        ;

}

static EmbeddedPyBind embed_obj("FUDesc", module_init, "SimObject");
