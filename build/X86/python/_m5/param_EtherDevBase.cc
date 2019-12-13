#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherDevBase.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherdevice.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/inet.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherDevBase");
    py::class_<EtherDevBaseParams, EtherDeviceParams, std::unique_ptr<EtherDevBaseParams, py::nodelete>>(m, "EtherDevBaseParams")
        .def_readwrite("dma_read_delay", &EtherDevBaseParams::dma_read_delay)
        .def_readwrite("dma_read_factor", &EtherDevBaseParams::dma_read_factor)
        .def_readwrite("dma_write_delay", &EtherDevBaseParams::dma_write_delay)
        .def_readwrite("dma_write_factor", &EtherDevBaseParams::dma_write_factor)
        .def_readwrite("hardware_address", &EtherDevBaseParams::hardware_address)
        .def_readwrite("intr_delay", &EtherDevBaseParams::intr_delay)
        .def_readwrite("rss", &EtherDevBaseParams::rss)
        .def_readwrite("rx_delay", &EtherDevBaseParams::rx_delay)
        .def_readwrite("rx_fifo_size", &EtherDevBaseParams::rx_fifo_size)
        .def_readwrite("rx_filter", &EtherDevBaseParams::rx_filter)
        .def_readwrite("rx_thread", &EtherDevBaseParams::rx_thread)
        .def_readwrite("tx_delay", &EtherDevBaseParams::tx_delay)
        .def_readwrite("tx_fifo_size", &EtherDevBaseParams::tx_fifo_size)
        .def_readwrite("tx_thread", &EtherDevBaseParams::tx_thread)
        ;

    py::class_<EtherDevBase, EtherDevice, std::unique_ptr<EtherDevBase, py::nodelete>>(m, "EtherDevBase")
        ;

}

static EmbeddedPyBind embed_obj("EtherDevBase", module_init, "EtherDevice");
