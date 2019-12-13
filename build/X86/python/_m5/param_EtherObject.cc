#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherobject.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherObject");
    py::class_<EtherObjectParams, SimObjectParams, std::unique_ptr<EtherObjectParams, py::nodelete>>(m, "EtherObjectParams")
        ;

    py::class_<EtherObject, SimObject, std::unique_ptr<EtherObject, py::nodelete>>(m, "EtherObject")
        ;

}

static EmbeddedPyBind embed_obj("EtherObject", module_init, "SimObject");
