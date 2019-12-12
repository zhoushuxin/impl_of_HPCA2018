#include "enums/MemSched.hh"
namespace Enums {
     const char *MemSchedStrings[Num_MemSched] =
    {
        "fcfs",
        "frfcfs",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_MemSched");

    py::enum_<Enums::MemSched>(m, "enum_MemSched")
        .value("fcfs", Enums::fcfs)
        .value("frfcfs", Enums::frfcfs)
        .value("Num_MemSched", Enums::Num_MemSched)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_MemSched", module_init);
