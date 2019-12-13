#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MemObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/mem_object.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MemObject");
    py::class_<MemObjectParams, ClockedObjectParams, std::unique_ptr<MemObjectParams, py::nodelete>>(m, "MemObjectParams")
        ;

    py::class_<MemObject, ClockedObject, std::unique_ptr<MemObject, py::nodelete>>(m, "MemObject")
        ;

}

static EmbeddedPyBind embed_obj("MemObject", module_init, "ClockedObject");
