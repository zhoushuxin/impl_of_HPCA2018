#ifndef __PARAMS__L1Cache_Controller__
#define __PARAMS__L1Cache_Controller__

class L1Cache_Controller;

#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include <cstddef>
#include "params/RubySequencer.hh"

#include "params/RubyController.hh"

struct L1Cache_ControllerParams
    : public RubyControllerParams
{
    L1Cache_Controller * create();
    CacheMemory * cacheMemory;
    Cycles cache_response_latency;
    MessageBuffer * forwardToCache;
    Cycles issue_latency;
    MessageBuffer * mandatoryQueue;
    MessageBuffer * requestFromCache;
    MessageBuffer * responseFromCache;
    MessageBuffer * responseToCache;
    bool send_evictions;
    Sequencer * sequencer;
};

#endif // __PARAMS__L1Cache_Controller__
