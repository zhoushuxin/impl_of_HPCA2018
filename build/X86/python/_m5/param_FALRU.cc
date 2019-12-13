#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/FALRU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/tags/fa_lru.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_FALRU");
    py::class_<FALRUParams, BaseTagsParams, std::unique_ptr<FALRUParams, py::nodelete>>(m, "FALRUParams")
        .def(py::init<>())
        .def("create", &FALRUParams::create)
        ;

    py::class_<FALRU, BaseTags, std::unique_ptr<FALRU, py::nodelete>>(m, "FALRU")
        ;

}

static EmbeddedPyBind embed_obj("FALRU", module_init, "BaseTags");
