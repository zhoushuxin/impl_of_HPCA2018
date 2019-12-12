#ifndef __PARAMS__ArmISA__
#define __PARAMS__ArmISA__

namespace ArmISA {
class ISA;
} // namespace ArmISA

#include <cstddef>
#include "enums/DecoderFlavour.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ArmPMU.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "enums/VecRegRenameMode.hh"

#include "params/SimObject.hh"

#include "enums/DecoderFlavour.hh"

#include "enums/VecRegRenameMode.hh"

struct ArmISAParams
    : public SimObjectParams
{
    ArmISA::ISA * create();
    Enums::DecoderFlavour decoderFlavour;
    uint32_t fpsid;
    uint64_t id_aa64afr0_el1;
    uint64_t id_aa64afr1_el1;
    uint64_t id_aa64dfr0_el1;
    uint64_t id_aa64dfr1_el1;
    uint64_t id_aa64isar0_el1;
    uint64_t id_aa64isar1_el1;
    uint64_t id_aa64mmfr0_el1;
    uint64_t id_aa64mmfr1_el1;
    uint32_t id_isar0;
    uint32_t id_isar1;
    uint32_t id_isar2;
    uint32_t id_isar3;
    uint32_t id_isar4;
    uint32_t id_isar5;
    uint32_t id_mmfr0;
    uint32_t id_mmfr1;
    uint32_t id_mmfr2;
    uint32_t id_mmfr3;
    uint32_t midr;
    ArmISA::PMU * pmu;
    System * system;
    Enums::VecRegRenameMode vecRegRenameMode;
};

#endif // __PARAMS__ArmISA__
