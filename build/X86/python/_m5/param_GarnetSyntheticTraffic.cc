#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GarnetSyntheticTraffic.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/garnet_synthetic_traffic/GarnetSyntheticTraffic.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GarnetSyntheticTraffic");
    py::class_<GarnetSyntheticTrafficParams, MemObjectParams, std::unique_ptr<GarnetSyntheticTrafficParams, py::nodelete>>(m, "GarnetSyntheticTrafficParams")
        .def(py::init<>())
        .def("create", &GarnetSyntheticTrafficParams::create)
        .def_readwrite("block_offset", &GarnetSyntheticTrafficParams::block_offset)
        .def_readwrite("inj_rate", &GarnetSyntheticTrafficParams::inj_rate)
        .def_readwrite("inj_vnet", &GarnetSyntheticTrafficParams::inj_vnet)
        .def_readwrite("memory_size", &GarnetSyntheticTrafficParams::memory_size)
        .def_readwrite("num_dest", &GarnetSyntheticTrafficParams::num_dest)
        .def_readwrite("num_packets_max", &GarnetSyntheticTrafficParams::num_packets_max)
        .def_readwrite("precision", &GarnetSyntheticTrafficParams::precision)
        .def_readwrite("response_limit", &GarnetSyntheticTrafficParams::response_limit)
        .def_readwrite("sim_cycles", &GarnetSyntheticTrafficParams::sim_cycles)
        .def_readwrite("single_dest", &GarnetSyntheticTrafficParams::single_dest)
        .def_readwrite("single_sender", &GarnetSyntheticTrafficParams::single_sender)
        .def_readwrite("system", &GarnetSyntheticTrafficParams::system)
        .def_readwrite("traffic_type", &GarnetSyntheticTrafficParams::traffic_type)
        .def_readwrite("port_test_connection_count", &GarnetSyntheticTrafficParams::port_test_connection_count)
        ;

    py::class_<GarnetSyntheticTraffic, MemObject, std::unique_ptr<GarnetSyntheticTraffic, py::nodelete>>(m, "GarnetSyntheticTraffic")
        ;

}

static EmbeddedPyBind embed_obj("GarnetSyntheticTraffic", module_init, "MemObject");
