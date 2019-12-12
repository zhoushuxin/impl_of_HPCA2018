#ifndef __ENUM__Enums__OpClass__
#define __ENUM__Enums__OpClass__

namespace Enums {
    enum OpClass {
        No_OpClass = 0,
        IntAlu = 1,
        IntMult = 2,
        IntDiv = 3,
        FloatAdd = 4,
        FloatCmp = 5,
        FloatCvt = 6,
        FloatMult = 7,
        FloatMultAcc = 8,
        FloatDiv = 9,
        FloatMisc = 10,
        FloatSqrt = 11,
        SimdAdd = 12,
        SimdAddAcc = 13,
        SimdAlu = 14,
        SimdCmp = 15,
        SimdCvt = 16,
        SimdMisc = 17,
        SimdMult = 18,
        SimdMultAcc = 19,
        SimdShift = 20,
        SimdShiftAcc = 21,
        SimdSqrt = 22,
        SimdFloatAdd = 23,
        SimdFloatAlu = 24,
        SimdFloatCmp = 25,
        SimdFloatCvt = 26,
        SimdFloatDiv = 27,
        SimdFloatMisc = 28,
        SimdFloatMult = 29,
        SimdFloatMultAcc = 30,
        SimdFloatSqrt = 31,
        MemRead = 32,
        MemWrite = 33,
        FloatMemRead = 34,
        FloatMemWrite = 35,
        IprAccess = 36,
        InstPrefetch = 37,
        Num_OpClass = 38
    };
extern const char *OpClassStrings[Num_OpClass];
}

#endif // __ENUM__Enums__OpClass__
