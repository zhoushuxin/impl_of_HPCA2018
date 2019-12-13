#include "enums/StaticInstFlags.hh"
const char *StaticInstFlags::FlagsStrings[Num_Flags] =
{
    "IsNop",
    "IsInteger",
    "IsFloating",
    "IsCC",
    "IsVector",
    "IsVectorElem",
    "IsMemRef",
    "IsLoad",
    "IsStore",
    "IsStoreConditional",
    "IsIndexed",
    "IsInstPrefetch",
    "IsDataPrefetch",
    "IsControl",
    "IsDirectControl",
    "IsIndirectControl",
    "IsCondControl",
    "IsUncondControl",
    "IsCall",
    "IsReturn",
    "IsCondDelaySlot",
    "IsThreadSync",
    "IsSerializing",
    "IsSerializeBefore",
    "IsSerializeAfter",
    "IsMemBarrier",
    "IsWriteBarrier",
    "IsReadBarrier",
    "IsERET",
    "IsNonSpeculative",
    "IsQuiesce",
    "IsIprAccess",
    "IsUnverifiable",
    "IsSyscall",
    "IsMacroop",
    "IsMicroop",
    "IsDelayedCommit",
    "IsLastMicroop",
    "IsFirstMicroop",
    "IsMicroBranch",
    "IsDspOp",
    "IsSquashAfter",
};
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_StaticInstFlags");

    py::enum_<StaticInstFlags::Flags>(m, "enum_StaticInstFlags")
        .value("IsNop", StaticInstFlags::IsNop)
        .value("IsInteger", StaticInstFlags::IsInteger)
        .value("IsFloating", StaticInstFlags::IsFloating)
        .value("IsCC", StaticInstFlags::IsCC)
        .value("IsVector", StaticInstFlags::IsVector)
        .value("IsVectorElem", StaticInstFlags::IsVectorElem)
        .value("IsMemRef", StaticInstFlags::IsMemRef)
        .value("IsLoad", StaticInstFlags::IsLoad)
        .value("IsStore", StaticInstFlags::IsStore)
        .value("IsStoreConditional", StaticInstFlags::IsStoreConditional)
        .value("IsIndexed", StaticInstFlags::IsIndexed)
        .value("IsInstPrefetch", StaticInstFlags::IsInstPrefetch)
        .value("IsDataPrefetch", StaticInstFlags::IsDataPrefetch)
        .value("IsControl", StaticInstFlags::IsControl)
        .value("IsDirectControl", StaticInstFlags::IsDirectControl)
        .value("IsIndirectControl", StaticInstFlags::IsIndirectControl)
        .value("IsCondControl", StaticInstFlags::IsCondControl)
        .value("IsUncondControl", StaticInstFlags::IsUncondControl)
        .value("IsCall", StaticInstFlags::IsCall)
        .value("IsReturn", StaticInstFlags::IsReturn)
        .value("IsCondDelaySlot", StaticInstFlags::IsCondDelaySlot)
        .value("IsThreadSync", StaticInstFlags::IsThreadSync)
        .value("IsSerializing", StaticInstFlags::IsSerializing)
        .value("IsSerializeBefore", StaticInstFlags::IsSerializeBefore)
        .value("IsSerializeAfter", StaticInstFlags::IsSerializeAfter)
        .value("IsMemBarrier", StaticInstFlags::IsMemBarrier)
        .value("IsWriteBarrier", StaticInstFlags::IsWriteBarrier)
        .value("IsReadBarrier", StaticInstFlags::IsReadBarrier)
        .value("IsERET", StaticInstFlags::IsERET)
        .value("IsNonSpeculative", StaticInstFlags::IsNonSpeculative)
        .value("IsQuiesce", StaticInstFlags::IsQuiesce)
        .value("IsIprAccess", StaticInstFlags::IsIprAccess)
        .value("IsUnverifiable", StaticInstFlags::IsUnverifiable)
        .value("IsSyscall", StaticInstFlags::IsSyscall)
        .value("IsMacroop", StaticInstFlags::IsMacroop)
        .value("IsMicroop", StaticInstFlags::IsMicroop)
        .value("IsDelayedCommit", StaticInstFlags::IsDelayedCommit)
        .value("IsLastMicroop", StaticInstFlags::IsLastMicroop)
        .value("IsFirstMicroop", StaticInstFlags::IsFirstMicroop)
        .value("IsMicroBranch", StaticInstFlags::IsMicroBranch)
        .value("IsDspOp", StaticInstFlags::IsDspOp)
        .value("IsSquashAfter", StaticInstFlags::IsSquashAfter)
        .value("Num_StaticInstFlags", StaticInstFlags::Num_Flags)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_StaticInstFlags", module_init);
