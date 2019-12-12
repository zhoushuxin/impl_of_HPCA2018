#ifndef __PARAMS__L2Cache_Controller__
#define __PARAMS__L2Cache_Controller__

class L2Cache_Controller;

#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"

#include "params/RubyController.hh"

struct L2Cache_ControllerParams
    : public RubyControllerParams
{
    L2Cache_Controller * create();
    MessageBuffer * GlobalRequestFromL2Cache;
    MessageBuffer * GlobalRequestToL2Cache;
    MessageBuffer * L1RequestFromL2Cache;
    MessageBuffer * L1RequestToL2Cache;
    CacheMemory * L2cache;
    Cycles request_latency;
    MessageBuffer * responseFromL2Cache;
    MessageBuffer * responseToL2Cache;
    Cycles response_latency;
    MessageBuffer * triggerQueue;
};

#endif // __PARAMS__L2Cache_Controller__
