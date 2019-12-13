#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PciHost.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/pci/host.hh"

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PciHost");
    py::class_<PciHostParams, PioDeviceParams, std::unique_ptr<PciHostParams, py::nodelete>>(m, "PciHostParams")
        ;

    py::class_<PciHost, PioDevice, std::unique_ptr<PciHost, py::nodelete>>(m, "PciHost")
        ;

}

static EmbeddedPyBind embed_obj("PciHost", module_init, "PioDevice");
