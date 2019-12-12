#include "enums/ArmPciIntRouting.hh"
namespace Enums {
     const char *ArmPciIntRoutingStrings[Num_ArmPciIntRouting] =
    {
        "ARM_PCI_INT_STATIC",
        "ARM_PCI_INT_DEV",
        "ARM_PCI_INT_PIN",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_ArmPciIntRouting");

    py::enum_<Enums::ArmPciIntRouting>(m, "enum_ArmPciIntRouting")
        .value("ARM_PCI_INT_STATIC", Enums::ARM_PCI_INT_STATIC)
        .value("ARM_PCI_INT_DEV", Enums::ARM_PCI_INT_DEV)
        .value("ARM_PCI_INT_PIN", Enums::ARM_PCI_INT_PIN)
        .value("Num_ArmPciIntRouting", Enums::Num_ArmPciIntRouting)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_ArmPciIntRouting", module_init);
