#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Sinic.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/sinic.hh"

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
    py::module m = m_internal.def_submodule("param_Sinic");
    py::class_<SinicParams, EtherDevBaseParams, std::unique_ptr<SinicParams, py::nodelete>>(m, "SinicParams")
        .def(py::init<>())
        .def("create", &SinicParams::create)
        .def_readwrite("delay_copy", &SinicParams::delay_copy)
        .def_readwrite("rx_fifo_low_mark", &SinicParams::rx_fifo_low_mark)
        .def_readwrite("rx_fifo_threshold", &SinicParams::rx_fifo_threshold)
        .def_readwrite("rx_max_copy", &SinicParams::rx_max_copy)
        .def_readwrite("rx_max_intr", &SinicParams::rx_max_intr)
        .def_readwrite("tx_fifo_high_mark", &SinicParams::tx_fifo_high_mark)
        .def_readwrite("tx_fifo_threshold", &SinicParams::tx_fifo_threshold)
        .def_readwrite("tx_max_copy", &SinicParams::tx_max_copy)
        .def_readwrite("virtual_addr", &SinicParams::virtual_addr)
        .def_readwrite("virtual_count", &SinicParams::virtual_count)
        .def_readwrite("zero_copy", &SinicParams::zero_copy)
        .def_readwrite("zero_copy_size", &SinicParams::zero_copy_size)
        .def_readwrite("zero_copy_threshold", &SinicParams::zero_copy_threshold)
        ;

    py::class_<Sinic::Device, EtherDevBase, std::unique_ptr<Sinic::Device, py::nodelete>>(m, "Sinic_COLONS_Device")
        ;

}

static EmbeddedPyBind embed_obj("Sinic", module_init, "EtherDevBase");
