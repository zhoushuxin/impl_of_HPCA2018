#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyDirectoryMemory.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/DirectoryMemory.hh"

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyDirectoryMemory");
    py::class_<RubyDirectoryMemoryParams, SimObjectParams, std::unique_ptr<RubyDirectoryMemoryParams, py::nodelete>>(m, "RubyDirectoryMemoryParams")
        .def(py::init<>())
        .def("create", &RubyDirectoryMemoryParams::create)
        .def_readwrite("addr_ranges", &RubyDirectoryMemoryParams::addr_ranges)
        ;

    py::class_<DirectoryMemory, SimObject, std::unique_ptr<DirectoryMemory, py::nodelete>>(m, "DirectoryMemory")
        ;

}

static EmbeddedPyBind embed_obj("RubyDirectoryMemory", module_init, "SimObject");
