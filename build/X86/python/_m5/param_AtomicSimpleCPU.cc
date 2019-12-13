#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/AtomicSimpleCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/simple/atomic.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_AtomicSimpleCPU");
    py::class_<AtomicSimpleCPUParams, BaseSimpleCPUParams, std::unique_ptr<AtomicSimpleCPUParams, py::nodelete>>(m, "AtomicSimpleCPUParams")
        .def(py::init<>())
        .def("create", &AtomicSimpleCPUParams::create)
        .def_readwrite("fastmem", &AtomicSimpleCPUParams::fastmem)
        .def_readwrite("simulate_data_stalls", &AtomicSimpleCPUParams::simulate_data_stalls)
        .def_readwrite("simulate_inst_stalls", &AtomicSimpleCPUParams::simulate_inst_stalls)
        .def_readwrite("width", &AtomicSimpleCPUParams::width)
        ;

    py::class_<AtomicSimpleCPU, BaseSimpleCPU, std::unique_ptr<AtomicSimpleCPU, py::nodelete>>(m, "AtomicSimpleCPU")
        ;

}

static EmbeddedPyBind embed_obj("AtomicSimpleCPU", module_init, "BaseSimpleCPU");
