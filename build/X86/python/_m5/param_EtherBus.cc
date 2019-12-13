#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherBus.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherbus.hh"

#include "dev/net/etherdump.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherBus");
    py::class_<EtherBusParams, EtherObjectParams, std::unique_ptr<EtherBusParams, py::nodelete>>(m, "EtherBusParams")
        .def(py::init<>())
        .def("create", &EtherBusParams::create)
        .def_readwrite("dump", &EtherBusParams::dump)
        .def_readwrite("loopback", &EtherBusParams::loopback)
        .def_readwrite("speed", &EtherBusParams::speed)
        ;

    py::class_<EtherBus, EtherObject, std::unique_ptr<EtherBus, py::nodelete>>(m, "EtherBus")
        ;

}

static EmbeddedPyBind embed_obj("EtherBus", module_init, "EtherObject");
