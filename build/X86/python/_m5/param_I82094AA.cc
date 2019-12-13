#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/I82094AA.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/i82094aa.hh"

#include "base/types.hh"
#include "dev/x86/i8259.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_I82094AA");
    py::class_<I82094AAParams, BasicPioDeviceParams, std::unique_ptr<I82094AAParams, py::nodelete>>(m, "I82094AAParams")
        .def(py::init<>())
        .def("create", &I82094AAParams::create)
        .def_readwrite("apic_id", &I82094AAParams::apic_id)
        .def_readwrite("external_int_pic", &I82094AAParams::external_int_pic)
        .def_readwrite("int_latency", &I82094AAParams::int_latency)
        .def_readwrite("port_int_master_connection_count", &I82094AAParams::port_int_master_connection_count)
        ;

    py::class_<X86ISA::I82094AA, BasicPioDevice, std::unique_ptr<X86ISA::I82094AA, py::nodelete>>(m, "X86ISA_COLONS_I82094AA")
        ;

}

static EmbeddedPyBind embed_obj("I82094AA", module_init, "BasicPioDevice");
