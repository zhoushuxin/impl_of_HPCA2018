#include "enums/DataDistribution.hh"
namespace Enums {
     const char *DataDistributionStrings[Num_DataDistribution] =
    {
        "sequential",
        "stripe",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_DataDistribution");

    py::enum_<Enums::DataDistribution>(m, "enum_DataDistribution")
        .value("sequential", Enums::sequential)
        .value("stripe", Enums::stripe)
        .value("Num_DataDistribution", Enums::Num_DataDistribution)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_DataDistribution", module_init);
