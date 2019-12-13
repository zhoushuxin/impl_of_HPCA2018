#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/FaultModel.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/fault_model/FaultModel.hh"

#include <vector>
#include <vector>
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_FaultModel");
    py::class_<FaultModelParams, SimObjectParams, std::unique_ptr<FaultModelParams, py::nodelete>>(m, "FaultModelParams")
        .def(py::init<>())
        .def("create", &FaultModelParams::create)
        .def_readwrite("baseline_fault_vector_database", &FaultModelParams::baseline_fault_vector_database)
        .def_readwrite("temperature_weights_database", &FaultModelParams::temperature_weights_database)
        ;

    py::class_<FaultModel, SimObject, std::unique_ptr<FaultModel, py::nodelete>>(m, "FaultModel")
        ;

}

static EmbeddedPyBind embed_obj("FaultModel", module_init, "SimObject");
