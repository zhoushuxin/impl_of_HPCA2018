#ifndef __PARAMS__DMASequencer__
#define __PARAMS__DMASequencer__

class DMASequencer;

#include <cstddef>
#include "base/types.hh"

#include "params/RubyPort.hh"

struct DMASequencerParams
    : public RubyPortParams
{
    DMASequencer * create();
    int max_outstanding_requests;
};

#endif // __PARAMS__DMASequencer__
