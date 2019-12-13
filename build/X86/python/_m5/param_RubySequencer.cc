#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubySequencer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/system/Sequencer.hh"

#include "base/types.hh"
#include "mem/ruby/structures/CacheMemory.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "mem/ruby/structures/CacheMemory.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubySequencer");
    py::class_<RubySequencerParams, RubyPortParams, std::unique_ptr<RubySequencerParams, py::nodelete>>(m, "RubySequencerParams")
        .def(py::init<>())
        .def("create", &RubySequencerParams::create)
        .def_readwrite("coreid", &RubySequencerParams::coreid)
        .def_readwrite("dcache", &RubySequencerParams::dcache)
        .def_readwrite("dcache_hit_latency", &RubySequencerParams::dcache_hit_latency)
        .def_readwrite("deadlock_threshold", &RubySequencerParams::deadlock_threshold)
        .def_readwrite("garnet_standalone", &RubySequencerParams::garnet_standalone)
        .def_readwrite("icache", &RubySequencerParams::icache)
        .def_readwrite("icache_hit_latency", &RubySequencerParams::icache_hit_latency)
        .def_readwrite("max_outstanding_requests", &RubySequencerParams::max_outstanding_requests)
        ;

    py::class_<Sequencer, RubyPort, std::unique_ptr<Sequencer, py::nodelete>>(m, "Sequencer")
        ;

}

static EmbeddedPyBind embed_obj("RubySequencer", module_init, "RubyPort");
