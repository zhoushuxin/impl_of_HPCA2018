#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/IsaFake.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/isa_fake.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_IsaFake");
    py::class_<IsaFakeParams, BasicPioDeviceParams, std::unique_ptr<IsaFakeParams, py::nodelete>>(m, "IsaFakeParams")
        .def(py::init<>())
        .def("create", &IsaFakeParams::create)
        .def_readwrite("fake_mem", &IsaFakeParams::fake_mem)
        .def_readwrite("pio_size", &IsaFakeParams::pio_size)
        .def_readwrite("ret_bad_addr", &IsaFakeParams::ret_bad_addr)
        .def_readwrite("ret_data16", &IsaFakeParams::ret_data16)
        .def_readwrite("ret_data32", &IsaFakeParams::ret_data32)
        .def_readwrite("ret_data64", &IsaFakeParams::ret_data64)
        .def_readwrite("ret_data8", &IsaFakeParams::ret_data8)
        .def_readwrite("update_data", &IsaFakeParams::update_data)
        .def_readwrite("warn_access", &IsaFakeParams::warn_access)
        ;

    py::class_<IsaFake, BasicPioDevice, std::unique_ptr<IsaFake, py::nodelete>>(m, "IsaFake")
        ;

}

static EmbeddedPyBind embed_obj("IsaFake", module_init, "BasicPioDevice");
