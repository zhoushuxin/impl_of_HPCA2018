#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherTapStub.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/ethertap.hh"

#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherTapStub");
    py::class_<EtherTapStubParams, EtherTapBaseParams, std::unique_ptr<EtherTapStubParams, py::nodelete>>(m, "EtherTapStubParams")
        .def(py::init<>())
        .def("create", &EtherTapStubParams::create)
        .def_readwrite("port", &EtherTapStubParams::port)
        ;

    py::class_<EtherTapStub, EtherTapBase, std::unique_ptr<EtherTapStub, py::nodelete>>(m, "EtherTapStub")
        ;

}

static EmbeddedPyBind embed_obj("EtherTapStub", module_init, "EtherTapBase");
