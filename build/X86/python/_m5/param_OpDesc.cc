#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/OpDesc.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/func_unit.hh"

#include "enums/OpClass.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_OpDesc");
    py::class_<OpDescParams, SimObjectParams, std::unique_ptr<OpDescParams, py::nodelete>>(m, "OpDescParams")
        .def(py::init<>())
        .def("create", &OpDescParams::create)
        .def_readwrite("opClass", &OpDescParams::opClass)
        .def_readwrite("opLat", &OpDescParams::opLat)
        .def_readwrite("pipelined", &OpDescParams::pipelined)
        ;

    py::class_<OpDesc, SimObject, std::unique_ptr<OpDesc, py::nodelete>>(m, "OpDesc")
        ;

}

static EmbeddedPyBind embed_obj("OpDesc", module_init, "SimObject");
