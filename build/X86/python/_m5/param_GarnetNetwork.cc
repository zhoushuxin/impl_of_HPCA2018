#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GarnetNetwork.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet2.0/GarnetNetwork.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "mem/ruby/network/fault_model/FaultModel.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GarnetNetwork");
    py::class_<GarnetNetworkParams, RubyNetworkParams, std::unique_ptr<GarnetNetworkParams, py::nodelete>>(m, "GarnetNetworkParams")
        .def(py::init<>())
        .def("create", &GarnetNetworkParams::create)
        .def_readwrite("buffers_per_ctrl_vc", &GarnetNetworkParams::buffers_per_ctrl_vc)
        .def_readwrite("buffers_per_data_vc", &GarnetNetworkParams::buffers_per_data_vc)
        .def_readwrite("enable_fault_model", &GarnetNetworkParams::enable_fault_model)
        .def_readwrite("fault_model", &GarnetNetworkParams::fault_model)
        .def_readwrite("garnet_deadlock_threshold", &GarnetNetworkParams::garnet_deadlock_threshold)
        .def_readwrite("ni_flit_size", &GarnetNetworkParams::ni_flit_size)
        .def_readwrite("num_rows", &GarnetNetworkParams::num_rows)
        .def_readwrite("routing_algorithm", &GarnetNetworkParams::routing_algorithm)
        .def_readwrite("vcs_per_vnet", &GarnetNetworkParams::vcs_per_vnet)
        ;

    py::class_<GarnetNetwork, Network, std::unique_ptr<GarnetNetwork, py::nodelete>>(m, "GarnetNetwork")
        ;

}

static EmbeddedPyBind embed_obj("GarnetNetwork", module_init, "RubyNetwork");
