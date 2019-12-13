#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyCache.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/CacheMemory.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "mem/ruby/structures/AbstractReplacementPolicy.hh"
#include "mem/ruby/system/RubySystem.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyCache");
    py::class_<RubyCacheParams, SimObjectParams, std::unique_ptr<RubyCacheParams, py::nodelete>>(m, "RubyCacheParams")
        .def(py::init<>())
        .def("create", &RubyCacheParams::create)
        .def_readwrite("assoc", &RubyCacheParams::assoc)
        .def_readwrite("block_size", &RubyCacheParams::block_size)
        .def_readwrite("dataAccessLatency", &RubyCacheParams::dataAccessLatency)
        .def_readwrite("dataArrayBanks", &RubyCacheParams::dataArrayBanks)
        .def_readwrite("is_icache", &RubyCacheParams::is_icache)
        .def_readwrite("replacement_policy", &RubyCacheParams::replacement_policy)
        .def_readwrite("resourceStalls", &RubyCacheParams::resourceStalls)
        .def_readwrite("ruby_system", &RubyCacheParams::ruby_system)
        .def_readwrite("size", &RubyCacheParams::size)
        .def_readwrite("start_index_bit", &RubyCacheParams::start_index_bit)
        .def_readwrite("tagAccessLatency", &RubyCacheParams::tagAccessLatency)
        .def_readwrite("tagArrayBanks", &RubyCacheParams::tagArrayBanks)
        ;

    py::class_<CacheMemory, SimObject, std::unique_ptr<CacheMemory, py::nodelete>>(m, "CacheMemory")
        ;

}

static EmbeddedPyBind embed_obj("RubyCache", module_init, "SimObject");
