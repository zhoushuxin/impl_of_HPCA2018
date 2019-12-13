#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherlink.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "dev/net/etherdump.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherLink");
    py::class_<EtherLinkParams, EtherObjectParams, std::unique_ptr<EtherLinkParams, py::nodelete>>(m, "EtherLinkParams")
        .def(py::init<>())
        .def("create", &EtherLinkParams::create)
        .def_readwrite("delay", &EtherLinkParams::delay)
        .def_readwrite("delay_var", &EtherLinkParams::delay_var)
        .def_readwrite("dump", &EtherLinkParams::dump)
        .def_readwrite("speed", &EtherLinkParams::speed)
        .def_readwrite("port_int1_connection_count", &EtherLinkParams::port_int1_connection_count)
        .def_readwrite("port_int0_connection_count", &EtherLinkParams::port_int0_connection_count)
        ;

    py::class_<EtherLink, EtherObject, std::unique_ptr<EtherLink, py::nodelete>>(m, "EtherLink")
        ;

}

static EmbeddedPyBind embed_obj("EtherLink", module_init, "EtherObject");
