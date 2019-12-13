#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/TimingSimpleCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/simple/timing.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_TimingSimpleCPU");
    py::class_<TimingSimpleCPUParams, BaseSimpleCPUParams, std::unique_ptr<TimingSimpleCPUParams, py::nodelete>>(m, "TimingSimpleCPUParams")
        .def(py::init<>())
        .def("create", &TimingSimpleCPUParams::create)
        ;

    py::class_<TimingSimpleCPU, BaseSimpleCPU, std::unique_ptr<TimingSimpleCPU, py::nodelete>>(m, "TimingSimpleCPU")
        ;

}

static EmbeddedPyBind embed_obj("TimingSimpleCPU", module_init, "BaseSimpleCPU");
