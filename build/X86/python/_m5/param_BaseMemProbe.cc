#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseMemProbe.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/probes/base.hh"

#include <vector>
#include "sim/sim_object.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseMemProbe");
    py::class_<BaseMemProbeParams, SimObjectParams, std::unique_ptr<BaseMemProbeParams, py::nodelete>>(m, "BaseMemProbeParams")
        .def_readwrite("manager", &BaseMemProbeParams::manager)
        .def_readwrite("probe_name", &BaseMemProbeParams::probe_name)
        ;

    py::class_<BaseMemProbe, SimObject, std::unique_ptr<BaseMemProbe, py::nodelete>>(m, "BaseMemProbe")
        ;

}

static EmbeddedPyBind embed_obj("BaseMemProbe", module_init, "SimObject");
