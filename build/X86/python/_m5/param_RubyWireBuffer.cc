#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/RubyWireBuffer.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/structures/WireBuffer.hh"

#include "mem/ruby/system/RubySystem.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_RubyWireBuffer");
    py::class_<RubyWireBufferParams, SimObjectParams, std::unique_ptr<RubyWireBufferParams, py::nodelete>>(m, "RubyWireBufferParams")
        .def(py::init<>())
        .def("create", &RubyWireBufferParams::create)
        .def_readwrite("ruby_system", &RubyWireBufferParams::ruby_system)
        ;

    py::class_<WireBuffer, SimObject, std::unique_ptr<WireBuffer, py::nodelete>>(m, "WireBuffer")
        ;

}

static EmbeddedPyBind embed_obj("RubyWireBuffer", module_init, "SimObject");
