#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Directory_Controller.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/protocol/Directory_Controller.hh"

#include "mem/ruby/structures/DirectoryMemory.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Directory_Controller");
    py::class_<Directory_ControllerParams, RubyControllerParams, std::unique_ptr<Directory_ControllerParams, py::nodelete>>(m, "Directory_ControllerParams")
        .def(py::init<>())
        .def("create", &Directory_ControllerParams::create)
        .def_readwrite("directory", &Directory_ControllerParams::directory)
        .def_readwrite("directory_latency", &Directory_ControllerParams::directory_latency)
        .def_readwrite("dmaRequestToDir", &Directory_ControllerParams::dmaRequestToDir)
        .def_readwrite("dmaResponseFromDir", &Directory_ControllerParams::dmaResponseFromDir)
        .def_readwrite("forwardFromDir", &Directory_ControllerParams::forwardFromDir)
        .def_readwrite("requestToDir", &Directory_ControllerParams::requestToDir)
        .def_readwrite("responseFromDir", &Directory_ControllerParams::responseFromDir)
        .def_readwrite("responseFromMemory", &Directory_ControllerParams::responseFromMemory)
        .def_readwrite("to_memory_controller_latency", &Directory_ControllerParams::to_memory_controller_latency)
        ;

    py::class_<Directory_Controller, AbstractController, std::unique_ptr<Directory_Controller, py::nodelete>>(m, "Directory_Controller")
        ;

}

static EmbeddedPyBind embed_obj("Directory_Controller", module_init, "RubyController");
