#ifndef __PARAMS__Directory_Controller__
#define __PARAMS__Directory_Controller__

class Directory_Controller;

#include <cstddef>
#include "params/RubyDirectoryMemory.hh"
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
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/RubyController.hh"

struct Directory_ControllerParams
    : public RubyControllerParams
{
    Directory_Controller * create();
    DirectoryMemory * directory;
    Cycles directory_latency;
    MessageBuffer * dmaRequestToDir;
    MessageBuffer * dmaResponseFromDir;
    MessageBuffer * forwardFromDir;
    MessageBuffer * requestToDir;
    MessageBuffer * responseFromDir;
    MessageBuffer * responseFromMemory;
    Cycles to_memory_controller_latency;
};

#endif // __PARAMS__Directory_Controller__
