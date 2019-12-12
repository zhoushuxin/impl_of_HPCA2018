#ifndef __PARAMS__RealView__
#define __PARAMS__RealView__

class RealView;

#include <cstddef>
#include "params/System.hh"

#include "params/Platform.hh"

struct RealViewParams
    : public PlatformParams
{
    RealView * create();
    System * system;
};

#endif // __PARAMS__RealView__
