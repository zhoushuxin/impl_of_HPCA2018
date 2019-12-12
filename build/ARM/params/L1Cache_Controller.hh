#ifndef __PARAMS__L1Cache_Controller__
#define __PARAMS__L1Cache_Controller__

class L1Cache_Controller;

#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include <cstddef>
#include "params/RubySequencer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/RubyController.hh"

struct L1Cache_ControllerParams
    : public RubyControllerParams
{
    L1Cache_Controller * create();
    CacheMemory * L1Dcache;
    CacheMemory * L1Icache;
    int l2_select_num_bits;
    MessageBuffer * mandatoryQueue;
    MessageBuffer * requestFromL1Cache;
    MessageBuffer * requestToL1Cache;
    Cycles request_latency;
    MessageBuffer * responseFromL1Cache;
    MessageBuffer * responseToL1Cache;
    bool send_evictions;
    Sequencer * sequencer;
    MessageBuffer * triggerQueue;
    Cycles use_timeout_latency;
};

#endif // __PARAMS__L1Cache_Controller__
