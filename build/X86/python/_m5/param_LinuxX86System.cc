#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/LinuxX86System.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/linux/system.hh"

#include "arch/x86/bios/e820.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_LinuxX86System");
    py::class_<LinuxX86SystemParams, X86SystemParams, std::unique_ptr<LinuxX86SystemParams, py::nodelete>>(m, "LinuxX86SystemParams")
        .def(py::init<>())
        .def("create", &LinuxX86SystemParams::create)
        .def_readwrite("e820_table", &LinuxX86SystemParams::e820_table)
        ;

    py::class_<LinuxX86System, X86System, std::unique_ptr<LinuxX86System, py::nodelete>>(m, "LinuxX86System")
        ;

}

static EmbeddedPyBind embed_obj("LinuxX86System", module_init, "X86System");
