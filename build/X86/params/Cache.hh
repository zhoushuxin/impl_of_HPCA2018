#ifndef __PARAMS__Cache__
#define __PARAMS__Cache__

class Cache;

#include <cstddef>
#include "enums/Clusivity.hh"
#include <cstddef>

#include "params/BaseCache.hh"

#include "enums/Clusivity.hh"

struct CacheParams
    : public BaseCacheParams
{
    Cache * create();
    Enums::Clusivity clusivity;
    bool writeback_clean;
};

#endif // __PARAMS__Cache__
