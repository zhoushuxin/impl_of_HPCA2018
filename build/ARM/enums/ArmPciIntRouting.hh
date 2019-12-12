#ifndef __ENUM__Enums__ArmPciIntRouting__
#define __ENUM__Enums__ArmPciIntRouting__

namespace Enums {
    enum ArmPciIntRouting {
        ARM_PCI_INT_STATIC = 0,
        ARM_PCI_INT_DEV = 1,
        ARM_PCI_INT_PIN = 2,
        Num_ArmPciIntRouting = 3
    };
extern const char *ArmPciIntRoutingStrings[Num_ArmPciIntRouting];
}

#endif // __ENUM__Enums__ArmPciIntRouting__
