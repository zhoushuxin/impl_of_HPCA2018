#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/EtherDump.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherdump.hh"

#include <string>
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_EtherDump");
    py::class_<EtherDumpParams, SimObjectParams, std::unique_ptr<EtherDumpParams, py::nodelete>>(m, "EtherDumpParams")
        .def(py::init<>())
        .def("create", &EtherDumpParams::create)
        .def_readwrite("file", &EtherDumpParams::file)
        .def_readwrite("maxlen", &EtherDumpParams::maxlen)
        ;

    py::class_<EtherDump, SimObject, std::unique_ptr<EtherDump, py::nodelete>>(m, "EtherDump")
        ;

}

static EmbeddedPyBind embed_obj("EtherDump", module_init, "SimObject");
