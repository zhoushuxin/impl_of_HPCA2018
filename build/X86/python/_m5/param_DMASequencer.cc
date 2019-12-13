#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DMASequencer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/system/DMASequencer.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DMASequencer");
    py::class_<DMASequencerParams, RubyPortParams, std::unique_ptr<DMASequencerParams, py::nodelete>>(m, "DMASequencerParams")
        .def(py::init<>())
        .def("create", &DMASequencerParams::create)
        .def_readwrite("max_outstanding_requests", &DMASequencerParams::max_outstanding_requests)
        ;

    py::class_<DMASequencer, RubyPort, std::unique_ptr<DMASequencer, py::nodelete>>(m, "DMASequencer")
        ;

}

static EmbeddedPyBind embed_obj("DMASequencer", module_init, "RubyPort");
