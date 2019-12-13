#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86LocalApic.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/interrupts.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86LocalApic");
    py::class_<X86LocalApicParams, BasicPioDeviceParams, std::unique_ptr<X86LocalApicParams, py::nodelete>>(m, "X86LocalApicParams")
        .def(py::init<>())
        .def("create", &X86LocalApicParams::create)
        .def_readwrite("int_latency", &X86LocalApicParams::int_latency)
        .def_readwrite("port_int_slave_connection_count", &X86LocalApicParams::port_int_slave_connection_count)
        .def_readwrite("port_int_master_connection_count", &X86LocalApicParams::port_int_master_connection_count)
        ;

    py::class_<X86ISA::Interrupts, BasicPioDevice, std::unique_ptr<X86ISA::Interrupts, py::nodelete>>(m, "X86ISA_COLONS_Interrupts")
        ;

}

static EmbeddedPyBind embed_obj("X86LocalApic", module_init, "BasicPioDevice");
