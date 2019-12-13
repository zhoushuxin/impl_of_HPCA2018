#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/AbstractMemory.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/abstract_mem.hh"

#include "base/types.hh"
#include "base/addr_range.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_AbstractMemory");
    py::class_<AbstractMemoryParams, MemObjectParams, std::unique_ptr<AbstractMemoryParams, py::nodelete>>(m, "AbstractMemoryParams")
        .def_readwrite("conf_table_reported", &AbstractMemoryParams::conf_table_reported)
        .def_readwrite("in_addr_map", &AbstractMemoryParams::in_addr_map)
        .def_readwrite("kvm_map", &AbstractMemoryParams::kvm_map)
        .def_readwrite("null", &AbstractMemoryParams::null)
        .def_readwrite("range", &AbstractMemoryParams::range)
        ;

    py::class_<AbstractMemory, MemObject, std::unique_ptr<AbstractMemory, py::nodelete>>(m, "AbstractMemory")
        ;

}

static EmbeddedPyBind embed_obj("AbstractMemory", module_init, "MemObject");
