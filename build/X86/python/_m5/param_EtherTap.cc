#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherTap.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/ethertap.hh"

#include <string>
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherTap");
    py::class_<EtherTapParams, EtherTapBaseParams, std::unique_ptr<EtherTapParams, py::nodelete>>(m, "EtherTapParams")
        .def(py::init<>())
        .def("create", &EtherTapParams::create)
        .def_readwrite("tap_device_name", &EtherTapParams::tap_device_name)
        .def_readwrite("tun_clone_device", &EtherTapParams::tun_clone_device)
        ;

    py::class_<EtherTap, EtherTapBase, std::unique_ptr<EtherTap, py::nodelete>>(m, "EtherTap")
        ;

}

static EmbeddedPyBind embed_obj("EtherTap", module_init, "EtherTapBase");
