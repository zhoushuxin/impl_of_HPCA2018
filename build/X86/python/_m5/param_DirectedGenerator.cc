#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DirectedGenerator.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/directedtest/DirectedGenerator.hh"

#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DirectedGenerator");
    py::class_<DirectedGeneratorParams, SimObjectParams, std::unique_ptr<DirectedGeneratorParams, py::nodelete>>(m, "DirectedGeneratorParams")
        .def_readwrite("num_cpus", &DirectedGeneratorParams::num_cpus)
        .def_readwrite("system", &DirectedGeneratorParams::system)
        ;

    py::class_<DirectedGenerator, SimObject, std::unique_ptr<DirectedGenerator, py::nodelete>>(m, "DirectedGenerator")
        ;

}

static EmbeddedPyBind embed_obj("DirectedGenerator", module_init, "SimObject");
