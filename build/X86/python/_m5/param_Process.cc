#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Process.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/process.hh"

#include <vector>
#include <string>
#include <string>
#include <vector>
#include "sim/emul_driver.hh"
#include "base/types.hh"
#include <vector>
#include <string>
#include <string>
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Process");
    py::class_<ProcessParams, SimObjectParams, std::unique_ptr<ProcessParams, py::nodelete>>(m, "ProcessParams")
        .def(py::init<>())
        .def("create", &ProcessParams::create)
        .def_readwrite("cmd", &ProcessParams::cmd)
        .def_readwrite("cwd", &ProcessParams::cwd)
        .def_readwrite("drivers", &ProcessParams::drivers)
        .def_readwrite("egid", &ProcessParams::egid)
        .def_readwrite("env", &ProcessParams::env)
        .def_readwrite("errout", &ProcessParams::errout)
        .def_readwrite("euid", &ProcessParams::euid)
        .def_readwrite("executable", &ProcessParams::executable)
        .def_readwrite("gid", &ProcessParams::gid)
        .def_readwrite("input", &ProcessParams::input)
        .def_readwrite("kvmInSE", &ProcessParams::kvmInSE)
        .def_readwrite("maxStackSize", &ProcessParams::maxStackSize)
        .def_readwrite("output", &ProcessParams::output)
        .def_readwrite("pgid", &ProcessParams::pgid)
        .def_readwrite("pid", &ProcessParams::pid)
        .def_readwrite("ppid", &ProcessParams::ppid)
        .def_readwrite("simpoint", &ProcessParams::simpoint)
        .def_readwrite("system", &ProcessParams::system)
        .def_readwrite("uid", &ProcessParams::uid)
        .def_readwrite("useArchPT", &ProcessParams::useArchPT)
        ;

    py::class_<Process, SimObject, std::unique_ptr<Process, py::nodelete>>(m, "Process")
        .def("map", &Process::map, 
            py::arg("vaddr"), py::arg("paddr"), py::arg("size"), py::arg("cacheable") = false)
        ;

}

static EmbeddedPyBind embed_obj("Process", module_init, "SimObject");
