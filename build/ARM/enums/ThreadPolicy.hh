#ifndef __ENUM__Enums__ThreadPolicy__
#define __ENUM__Enums__ThreadPolicy__

namespace Enums {
    enum ThreadPolicy {
        SingleThreaded = 0,
        RoundRobin = 1,
        Random = 2,
        Num_ThreadPolicy = 3
    };
extern const char *ThreadPolicyStrings[Num_ThreadPolicy];
}

#endif // __ENUM__Enums__ThreadPolicy__
