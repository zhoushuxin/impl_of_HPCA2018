#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/StackDistProbe.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/probes/stack_dist.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_StackDistProbe");
    py::class_<StackDistProbeParams, BaseMemProbeParams, std::unique_ptr<StackDistProbeParams, py::nodelete>>(m, "StackDistProbeParams")
        .def(py::init<>())
        .def("create", &StackDistProbeParams::create)
        .def_readwrite("disable_linear_hists", &StackDistProbeParams::disable_linear_hists)
        .def_readwrite("disable_log_hists", &StackDistProbeParams::disable_log_hists)
        .def_readwrite("line_size", &StackDistProbeParams::line_size)
        .def_readwrite("linear_hist_bins", &StackDistProbeParams::linear_hist_bins)
        .def_readwrite("log_hist_bins", &StackDistProbeParams::log_hist_bins)
        .def_readwrite("system", &StackDistProbeParams::system)
        .def_readwrite("verify", &StackDistProbeParams::verify)
        ;

    py::class_<StackDistProbe, BaseMemProbe, std::unique_ptr<StackDistProbe, py::nodelete>>(m, "StackDistProbe")
        ;

}

static EmbeddedPyBind embed_obj("StackDistProbe", module_init, "BaseMemProbe");
