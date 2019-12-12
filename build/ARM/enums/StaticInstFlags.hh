#ifndef __ENUM__StaticInstFlags__Flags__
#define __ENUM__StaticInstFlags__Flags__

struct StaticInstFlags {
    enum Flags {
        IsNop = 0,
        IsInteger = 1,
        IsFloating = 2,
        IsCC = 3,
        IsVector = 4,
        IsVectorElem = 5,
        IsMemRef = 6,
        IsLoad = 7,
        IsStore = 8,
        IsStoreConditional = 9,
        IsIndexed = 10,
        IsInstPrefetch = 11,
        IsDataPrefetch = 12,
        IsControl = 13,
        IsDirectControl = 14,
        IsIndirectControl = 15,
        IsCondControl = 16,
        IsUncondControl = 17,
        IsCall = 18,
        IsReturn = 19,
        IsCondDelaySlot = 20,
        IsThreadSync = 21,
        IsSerializing = 22,
        IsSerializeBefore = 23,
        IsSerializeAfter = 24,
        IsMemBarrier = 25,
        IsWriteBarrier = 26,
        IsReadBarrier = 27,
        IsERET = 28,
        IsNonSpeculative = 29,
        IsQuiesce = 30,
        IsIprAccess = 31,
        IsUnverifiable = 32,
        IsSyscall = 33,
        IsMacroop = 34,
        IsMicroop = 35,
        IsDelayedCommit = 36,
        IsLastMicroop = 37,
        IsFirstMicroop = 38,
        IsMicroBranch = 39,
        IsDspOp = 40,
        IsSquashAfter = 41,
        Num_Flags = 42
    };
    static const char *FlagsStrings[Num_Flags];
};

#endif // __ENUM__StaticInstFlags__Flags__
