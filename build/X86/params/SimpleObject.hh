#ifndef __PARAMS__SimpleObject__
#define __PARAMS__SimpleObject__

class SimpleObject;


#include "params/SimObject.hh"

struct SimpleObjectParams
    : public SimObjectParams
{
    SimpleObject * create();
};

#endif // __PARAMS__SimpleObject__
