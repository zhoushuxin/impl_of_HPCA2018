#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherTapBase.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/ethertap.hh"

#include "base/types.hh"
#include "dev/net/etherdump.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherTapBase");
    py::class_<EtherTapBaseParams, EtherObjectParams, std::unique_ptr<EtherTapBaseParams, py::nodelete>>(m, "EtherTapBaseParams")
        .def_readwrite("bufsz", &EtherTapBaseParams::bufsz)
        .def_readwrite("dump", &EtherTapBaseParams::dump)
        .def_readwrite("port_tap_connection_count", &EtherTapBaseParams::port_tap_connection_count)
        ;

    py::class_<EtherTapBase, EtherObject, std::unique_ptr<EtherTapBase, py::nodelete>>(m, "EtherTapBase")
        ;

}

static EmbeddedPyBind embed_obj("EtherTapBase", module_init, "EtherObject");
