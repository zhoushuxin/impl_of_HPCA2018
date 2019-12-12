#ifndef __PARAMS__DMA_Controller__
#define __PARAMS__DMA_Controller__

class DMA_Controller;

#include <cstddef>
#include "params/DMASequencer.hh"
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
#include "base/types.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"

#include "params/RubyController.hh"

struct DMA_ControllerParams
    : public RubyControllerParams
{
    DMA_Controller * create();
    DMASequencer * dma_sequencer;
    MessageBuffer * mandatoryQueue;
    MessageBuffer * reqToDir;
    Cycles request_latency;
    MessageBuffer * respToDir;
    MessageBuffer * responseFromDir;
    Cycles response_latency;
    MessageBuffer * triggerQueue;
};

#endif // __PARAMS__DMA_Controller__
