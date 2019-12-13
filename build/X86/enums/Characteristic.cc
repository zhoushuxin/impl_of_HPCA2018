#include "enums/Characteristic.hh"
namespace Enums {
     const char *CharacteristicStrings[Num_Characteristic] =
    {
        "APM",
        "CDBoot",
        "CGA_Mono",
        "EDD",
        "EISA",
        "ESCD",
        "Flash",
        "Floppy_3_5_2_88MB",
        "Floppy_3_5_720KB",
        "Floppy_5_25_1_2MB",
        "Floppy_5_25_360KB",
        "ISA",
        "Keyboard8024",
        "MCA",
        "NEC9800",
        "NEC_PC_98",
        "PCI",
        "PCMCIA",
        "PCMCIABoot",
        "PnP",
        "PrintScreen",
        "Printer",
        "SelectBoot",
        "Serial",
        "Shadow",
        "Socketed",
        "Toshiba",
        "Unknown",
        "Unsupported",
        "VL_Vesa",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_Characteristic");

    py::enum_<Enums::Characteristic>(m, "enum_Characteristic")
        .value("APM", Enums::APM)
        .value("CDBoot", Enums::CDBoot)
        .value("CGA_Mono", Enums::CGA_Mono)
        .value("EDD", Enums::EDD)
        .value("EISA", Enums::EISA)
        .value("ESCD", Enums::ESCD)
        .value("Flash", Enums::Flash)
        .value("Floppy_3_5_2_88MB", Enums::Floppy_3_5_2_88MB)
        .value("Floppy_3_5_720KB", Enums::Floppy_3_5_720KB)
        .value("Floppy_5_25_1_2MB", Enums::Floppy_5_25_1_2MB)
        .value("Floppy_5_25_360KB", Enums::Floppy_5_25_360KB)
        .value("ISA", Enums::ISA)
        .value("Keyboard8024", Enums::Keyboard8024)
        .value("MCA", Enums::MCA)
        .value("NEC9800", Enums::NEC9800)
        .value("NEC_PC_98", Enums::NEC_PC_98)
        .value("PCI", Enums::PCI)
        .value("PCMCIA", Enums::PCMCIA)
        .value("PCMCIABoot", Enums::PCMCIABoot)
        .value("PnP", Enums::PnP)
        .value("PrintScreen", Enums::PrintScreen)
        .value("Printer", Enums::Printer)
        .value("SelectBoot", Enums::SelectBoot)
        .value("Serial", Enums::Serial)
        .value("Shadow", Enums::Shadow)
        .value("Socketed", Enums::Socketed)
        .value("Toshiba", Enums::Toshiba)
        .value("Unknown", Enums::Unknown)
        .value("Unsupported", Enums::Unsupported)
        .value("VL_Vesa", Enums::VL_Vesa)
        .value("Num_Characteristic", Enums::Num_Characteristic)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_Characteristic", module_init);
