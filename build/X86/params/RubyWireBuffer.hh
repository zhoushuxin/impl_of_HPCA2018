#ifndef __PARAMS__RubyWireBuffer__
#define __PARAMS__RubyWireBuffer__

class WireBuffer;

#include <cstddef>
#include "params/RubySystem.hh"

#include "params/SimObject.hh"

struct RubyWireBufferParams
    : public SimObjectParams
{
    WireBuffer * create();
    RubySystem * ruby_system;
};

#endif // __PARAMS__RubyWireBuffer__
