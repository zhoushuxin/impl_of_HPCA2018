#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/MemFootprintProbe.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/probes/mem_footprint.hh"

#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_MemFootprintProbe");
    py::class_<MemFootprintProbeParams, BaseMemProbeParams, std::unique_ptr<MemFootprintProbeParams, py::nodelete>>(m, "MemFootprintProbeParams")
        .def(py::init<>())
        .def("create", &MemFootprintProbeParams::create)
        .def_readwrite("page_size", &MemFootprintProbeParams::page_size)
        .def_readwrite("system", &MemFootprintProbeParams::system)
        ;

    py::class_<MemFootprintProbe, BaseMemProbe, std::unique_ptr<MemFootprintProbe, py::nodelete>>(m, "MemFootprintProbe")
        ;

}

static EmbeddedPyBind embed_obj("MemFootprintProbe", module_init, "BaseMemProbe");
