#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherSwitch.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherswitch.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "dev/net/etherdump.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherSwitch");
    py::class_<EtherSwitchParams, EtherObjectParams, std::unique_ptr<EtherSwitchParams, py::nodelete>>(m, "EtherSwitchParams")
        .def(py::init<>())
        .def("create", &EtherSwitchParams::create)
        .def_readwrite("delay", &EtherSwitchParams::delay)
        .def_readwrite("delay_var", &EtherSwitchParams::delay_var)
        .def_readwrite("dump", &EtherSwitchParams::dump)
        .def_readwrite("fabric_speed", &EtherSwitchParams::fabric_speed)
        .def_readwrite("output_buffer_size", &EtherSwitchParams::output_buffer_size)
        .def_readwrite("time_to_live", &EtherSwitchParams::time_to_live)
        .def_readwrite("port_interface_connection_count", &EtherSwitchParams::port_interface_connection_count)
        ;

    py::class_<EtherSwitch, EtherObject, std::unique_ptr<EtherSwitch, py::nodelete>>(m, "EtherSwitch")
        ;

}

static EmbeddedPyBind embed_obj("EtherSwitch", module_init, "EtherObject");
