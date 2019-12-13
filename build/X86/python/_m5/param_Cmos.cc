#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Cmos.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/cmos.hh"

#include "dev/x86/intdev.hh"
#include <time.h>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Cmos");
    py::class_<CmosParams, BasicPioDeviceParams, std::unique_ptr<CmosParams, py::nodelete>>(m, "CmosParams")
        .def(py::init<>())
        .def("create", &CmosParams::create)
        .def_readwrite("int_pin", &CmosParams::int_pin)
        .def_readwrite("time", &CmosParams::time)
        ;

    py::class_<X86ISA::Cmos, BasicPioDevice, std::unique_ptr<X86ISA::Cmos, py::nodelete>>(m, "X86ISA_COLONS_Cmos")
        ;

}

static EmbeddedPyBind embed_obj("Cmos", module_init, "BasicPioDevice");
