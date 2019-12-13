#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TickedObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/ticked_object.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TickedObject");
    py::class_<TickedObjectParams, ClockedObjectParams, std::unique_ptr<TickedObjectParams, py::nodelete>>(m, "TickedObjectParams")
        ;

    py::class_<TickedObject, ClockedObject, std::unique_ptr<TickedObject, py::nodelete>>(m, "TickedObject")
        ;

}

static EmbeddedPyBind embed_obj("TickedObject", module_init, "ClockedObject");
