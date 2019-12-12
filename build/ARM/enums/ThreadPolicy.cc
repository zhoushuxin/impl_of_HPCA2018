#include "enums/ThreadPolicy.hh"
namespace Enums {
     const char *ThreadPolicyStrings[Num_ThreadPolicy] =
    {
        "SingleThreaded",
        "RoundRobin",
        "Random",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_ThreadPolicy");

    py::enum_<Enums::ThreadPolicy>(m, "enum_ThreadPolicy")
        .value("SingleThreaded", Enums::SingleThreaded)
        .value("RoundRobin", Enums::RoundRobin)
        .value("Random", Enums::Random)
        .value("Num_ThreadPolicy", Enums::Num_ThreadPolicy)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_ThreadPolicy", module_init);
