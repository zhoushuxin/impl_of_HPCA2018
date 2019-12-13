#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/KvmVM.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/kvm/vm.hh"

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_KvmVM");
    py::class_<KvmVMParams, SimObjectParams, std::unique_ptr<KvmVMParams, py::nodelete>>(m, "KvmVMParams")
        .def(py::init<>())
        .def("create", &KvmVMParams::create)
        .def_readwrite("coalescedMMIO", &KvmVMParams::coalescedMMIO)
        ;

    py::class_<KvmVM, SimObject, std::unique_ptr<KvmVM, py::nodelete>>(m, "KvmVM")
        ;

}

static EmbeddedPyBind embed_obj("KvmVM", module_init, "SimObject");
