#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/DistEtherLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/dist_etherlink.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "dev/net/etherdump.hh"
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_DistEtherLink");
    py::class_<DistEtherLinkParams, EtherObjectParams, std::unique_ptr<DistEtherLinkParams, py::nodelete>>(m, "DistEtherLinkParams")
        .def(py::init<>())
        .def("create", &DistEtherLinkParams::create)
        .def_readwrite("delay", &DistEtherLinkParams::delay)
        .def_readwrite("delay_var", &DistEtherLinkParams::delay_var)
        .def_readwrite("dist_rank", &DistEtherLinkParams::dist_rank)
        .def_readwrite("dist_size", &DistEtherLinkParams::dist_size)
        .def_readwrite("dist_sync_on_pseudo_op", &DistEtherLinkParams::dist_sync_on_pseudo_op)
        .def_readwrite("dump", &DistEtherLinkParams::dump)
        .def_readwrite("is_switch", &DistEtherLinkParams::is_switch)
        .def_readwrite("num_nodes", &DistEtherLinkParams::num_nodes)
        .def_readwrite("server_name", &DistEtherLinkParams::server_name)
        .def_readwrite("server_port", &DistEtherLinkParams::server_port)
        .def_readwrite("speed", &DistEtherLinkParams::speed)
        .def_readwrite("sync_repeat", &DistEtherLinkParams::sync_repeat)
        .def_readwrite("sync_start", &DistEtherLinkParams::sync_start)
        .def_readwrite("port_int0_connection_count", &DistEtherLinkParams::port_int0_connection_count)
        ;

    py::class_<DistEtherLink, EtherObject, std::unique_ptr<DistEtherLink, py::nodelete>>(m, "DistEtherLink")
        ;

}

static EmbeddedPyBind embed_obj("DistEtherLink", module_init, "EtherObject");
