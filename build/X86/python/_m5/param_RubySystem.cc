#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubySystem.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/system/RubySystem.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "mem/simple_mem.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubySystem");
    py::class_<RubySystemParams, ClockedObjectParams, std::unique_ptr<RubySystemParams, py::nodelete>>(m, "RubySystemParams")
        .def(py::init<>())
        .def("create", &RubySystemParams::create)
        .def_readwrite("access_backing_store", &RubySystemParams::access_backing_store)
        .def_readwrite("all_instructions", &RubySystemParams::all_instructions)
        .def_readwrite("block_size_bytes", &RubySystemParams::block_size_bytes)
        .def_readwrite("hot_lines", &RubySystemParams::hot_lines)
        .def_readwrite("memory_size_bits", &RubySystemParams::memory_size_bits)
        .def_readwrite("num_of_sequencers", &RubySystemParams::num_of_sequencers)
        .def_readwrite("number_of_virtual_networks", &RubySystemParams::number_of_virtual_networks)
        .def_readwrite("phys_mem", &RubySystemParams::phys_mem)
        .def_readwrite("randomization", &RubySystemParams::randomization)
        ;

    py::class_<RubySystem, ClockedObject, std::unique_ptr<RubySystem, py::nodelete>>(m, "RubySystem")
        ;

}

static EmbeddedPyBind embed_obj("RubySystem", module_init, "ClockedObject");
