#ifndef __PARAMS__RubyDirectoryMemory__
#define __PARAMS__RubyDirectoryMemory__

class DirectoryMemory;

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"

#include "params/SimObject.hh"

struct RubyDirectoryMemoryParams
    : public SimObjectParams
{
    DirectoryMemory * create();
    std::vector< AddrRange > addr_ranges;
};

#endif // __PARAMS__RubyDirectoryMemory__
