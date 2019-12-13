#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/IGbE.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/i8254xGBe.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/inet.hh"
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
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_IGbE");
    py::class_<IGbEParams, EtherDeviceParams, std::unique_ptr<IGbEParams, py::nodelete>>(m, "IGbEParams")
        .def(py::init<>())
        .def("create", &IGbEParams::create)
        .def_readwrite("fetch_comp_delay", &IGbEParams::fetch_comp_delay)
        .def_readwrite("fetch_delay", &IGbEParams::fetch_delay)
        .def_readwrite("hardware_address", &IGbEParams::hardware_address)
        .def_readwrite("phy_epid", &IGbEParams::phy_epid)
        .def_readwrite("phy_pid", &IGbEParams::phy_pid)
        .def_readwrite("rx_desc_cache_size", &IGbEParams::rx_desc_cache_size)
        .def_readwrite("rx_fifo_size", &IGbEParams::rx_fifo_size)
        .def_readwrite("rx_write_delay", &IGbEParams::rx_write_delay)
        .def_readwrite("tx_desc_cache_size", &IGbEParams::tx_desc_cache_size)
        .def_readwrite("tx_fifo_size", &IGbEParams::tx_fifo_size)
        .def_readwrite("tx_read_delay", &IGbEParams::tx_read_delay)
        .def_readwrite("wb_comp_delay", &IGbEParams::wb_comp_delay)
        .def_readwrite("wb_delay", &IGbEParams::wb_delay)
        ;

    py::class_<IGbE, EtherDevice, std::unique_ptr<IGbE, py::nodelete>>(m, "IGbE")
        ;

}

static EmbeddedPyBind embed_obj("IGbE", module_init, "EtherDevice");
