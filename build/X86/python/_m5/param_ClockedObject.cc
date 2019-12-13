#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/ClockedObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/clocked_object.hh"

#include "sim/clock_domain.hh"
#include "enums/PwrState.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include <vector>
#include "sim/power/power_model.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_ClockedObject");
    py::class_<ClockedObjectParams, SimObjectParams, std::unique_ptr<ClockedObjectParams, py::nodelete>>(m, "ClockedObjectParams")
        .def_readwrite("clk_domain", &ClockedObjectParams::clk_domain)
        .def_readwrite("default_p_state", &ClockedObjectParams::default_p_state)
        .def_readwrite("p_state_clk_gate_bins", &ClockedObjectParams::p_state_clk_gate_bins)
        .def_readwrite("p_state_clk_gate_max", &ClockedObjectParams::p_state_clk_gate_max)
        .def_readwrite("p_state_clk_gate_min", &ClockedObjectParams::p_state_clk_gate_min)
        .def_readwrite("power_model", &ClockedObjectParams::power_model)
        ;

    py::class_<ClockedObject, SimObject, std::unique_ptr<ClockedObject, py::nodelete>>(m, "ClockedObject")
        ;

}

static EmbeddedPyBind embed_obj("ClockedObject", module_init, "SimObject");
