#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RangeAddrMapper.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/addr_mapper.hh"

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RangeAddrMapper");
    py::class_<RangeAddrMapperParams, AddrMapperParams, std::unique_ptr<RangeAddrMapperParams, py::nodelete>>(m, "RangeAddrMapperParams")
        .def(py::init<>())
        .def("create", &RangeAddrMapperParams::create)
        .def_readwrite("original_ranges", &RangeAddrMapperParams::original_ranges)
        .def_readwrite("remapped_ranges", &RangeAddrMapperParams::remapped_ranges)
        ;

    py::class_<RangeAddrMapper, AddrMapper, std::unique_ptr<RangeAddrMapper, py::nodelete>>(m, "RangeAddrMapper")
        ;

}

static EmbeddedPyBind embed_obj("RangeAddrMapper", module_init, "AddrMapper");
