#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/GenericPciHost.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/pci/host.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "dev/platform.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_GenericPciHost");
    py::class_<GenericPciHostParams, PciHostParams, std::unique_ptr<GenericPciHostParams, py::nodelete>>(m, "GenericPciHostParams")
        .def(py::init<>())
        .def("create", &GenericPciHostParams::create)
        .def_readwrite("conf_base", &GenericPciHostParams::conf_base)
        .def_readwrite("conf_device_bits", &GenericPciHostParams::conf_device_bits)
        .def_readwrite("conf_size", &GenericPciHostParams::conf_size)
        .def_readwrite("pci_dma_base", &GenericPciHostParams::pci_dma_base)
        .def_readwrite("pci_mem_base", &GenericPciHostParams::pci_mem_base)
        .def_readwrite("pci_pio_base", &GenericPciHostParams::pci_pio_base)
        .def_readwrite("platform", &GenericPciHostParams::platform)
        ;

    py::class_<GenericPciHost, PciHost, std::unique_ptr<GenericPciHost, py::nodelete>>(m, "GenericPciHost")
        ;

}

static EmbeddedPyBind embed_obj("GenericPciHost", module_init, "PciHost");
