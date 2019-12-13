#include "enums/ExtCharacteristic.hh"
namespace Enums {
     const char *ExtCharacteristicStrings[Num_ExtCharacteristic] =
    {
        "ACPI",
        "AGP",
        "BootSpec",
        "FirewireBoot",
        "I20Boot",
        "LS_120Boot",
        "NetServiceBoot",
        "SmartBattery",
        "TargetContent",
        "USBLegacy",
        "ZIPBoot",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_ExtCharacteristic");

    py::enum_<Enums::ExtCharacteristic>(m, "enum_ExtCharacteristic")
        .value("ACPI", Enums::ACPI)
        .value("AGP", Enums::AGP)
        .value("BootSpec", Enums::BootSpec)
        .value("FirewireBoot", Enums::FirewireBoot)
        .value("I20Boot", Enums::I20Boot)
        .value("LS_120Boot", Enums::LS_120Boot)
        .value("NetServiceBoot", Enums::NetServiceBoot)
        .value("SmartBattery", Enums::SmartBattery)
        .value("TargetContent", Enums::TargetContent)
        .value("USBLegacy", Enums::USBLegacy)
        .value("ZIPBoot", Enums::ZIPBoot)
        .value("Num_ExtCharacteristic", Enums::Num_ExtCharacteristic)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_ExtCharacteristic", module_init);
