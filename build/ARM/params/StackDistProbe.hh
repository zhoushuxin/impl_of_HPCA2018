#ifndef __PARAMS__StackDistProbe__
#define __PARAMS__StackDistProbe__

class StackDistProbe;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>

#include "params/BaseMemProbe.hh"

struct StackDistProbeParams
    : public BaseMemProbeParams
{
    StackDistProbe * create();
    bool disable_linear_hists;
    bool disable_log_hists;
    unsigned line_size;
    unsigned linear_hist_bins;
    unsigned log_hist_bins;
    System * system;
    bool verify;
};

#endif // __PARAMS__StackDistProbe__
