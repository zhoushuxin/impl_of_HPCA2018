#ifndef __PARAMS__HelloObject__
#define __PARAMS__HelloObject__

class HelloObject;

#include <cstddef>
#include "params/GoodbyeObject.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct HelloObjectParams
    : public SimObjectParams
{
    HelloObject * create();
    GoodbyeObject * goodbye_object;
    int number_of_fires;
    Tick time_to_wait;
};

#endif // __PARAMS__HelloObject__
