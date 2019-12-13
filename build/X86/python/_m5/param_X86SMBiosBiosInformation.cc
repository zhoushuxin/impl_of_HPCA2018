#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/X86SMBiosBiosInformation.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/x86/bios/smbios.hh"

#include <vector>
#include "enums/ExtCharacteristic.hh"
#include <vector>
#include "enums/Characteristic.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include <string>
#include "base/types.hh"
#include "base/types.hh"
#include <string>
#include <string>
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_X86SMBiosBiosInformation");
    py::class_<X86SMBiosBiosInformationParams, X86SMBiosSMBiosStructureParams, std::unique_ptr<X86SMBiosBiosInformationParams, py::nodelete>>(m, "X86SMBiosBiosInformationParams")
        .def(py::init<>())
        .def("create", &X86SMBiosBiosInformationParams::create)
        .def_readwrite("characteristic_ext_bytes", &X86SMBiosBiosInformationParams::characteristic_ext_bytes)
        .def_readwrite("characteristics", &X86SMBiosBiosInformationParams::characteristics)
        .def_readwrite("emb_cont_firmware_major", &X86SMBiosBiosInformationParams::emb_cont_firmware_major)
        .def_readwrite("emb_cont_firmware_minor", &X86SMBiosBiosInformationParams::emb_cont_firmware_minor)
        .def_readwrite("major", &X86SMBiosBiosInformationParams::major)
        .def_readwrite("minor", &X86SMBiosBiosInformationParams::minor)
        .def_readwrite("release_date", &X86SMBiosBiosInformationParams::release_date)
        .def_readwrite("rom_size", &X86SMBiosBiosInformationParams::rom_size)
        .def_readwrite("starting_addr_segment", &X86SMBiosBiosInformationParams::starting_addr_segment)
        .def_readwrite("vendor", &X86SMBiosBiosInformationParams::vendor)
        .def_readwrite("version", &X86SMBiosBiosInformationParams::version)
        ;

    py::class_<X86ISA::SMBios::BiosInformation, X86ISA::SMBios::SMBiosStructure, std::unique_ptr<X86ISA::SMBios::BiosInformation, py::nodelete>>(m, "X86ISA_COLONS_SMBios_COLONS_BiosInformation")
        ;

}

static EmbeddedPyBind embed_obj("X86SMBiosBiosInformation", module_init, "X86SMBiosSMBiosStructure");
