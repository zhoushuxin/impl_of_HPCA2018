#ifndef __ENUM__Enums__Clusivity__
#define __ENUM__Enums__Clusivity__

namespace Enums {
    enum Clusivity {
        mostly_incl = 0,
        mostly_excl = 1,
        Num_Clusivity = 2
    };
extern const char *ClusivityStrings[Num_Clusivity];
}

#endif // __ENUM__Enums__Clusivity__
