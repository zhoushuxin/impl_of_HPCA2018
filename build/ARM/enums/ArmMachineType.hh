#ifndef __ENUM__Enums__ArmMachineType__
#define __ENUM__Enums__ArmMachineType__

namespace Enums {
    enum ArmMachineType {
        DTOnly = -1,
        RealViewEB = 827,
        RealViewPBX = 1901,
        VExpress_EMM = 2272,
        VExpress_EMM64 = 2272,
        Num_ArmMachineType = 5
    };
extern const char *ArmMachineTypeStrings[Num_ArmMachineType];
}

#endif // __ENUM__Enums__ArmMachineType__
