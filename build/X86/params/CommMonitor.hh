#ifndef __PARAMS__CommMonitor__
#define __PARAMS__CommMonitor__

class CommMonitor;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct CommMonitorParams
    : public MemObjectParams
{
    CommMonitor * create();
    unsigned bandwidth_bins;
    unsigned burst_length_bins;
    bool disable_addr_dists;
    bool disable_bandwidth_hists;
    bool disable_burst_length_hists;
    bool disable_itt_dists;
    bool disable_latency_hists;
    bool disable_outstanding_hists;
    bool disable_transaction_hists;
    unsigned itt_bins;
    Tick itt_max_bin;
    unsigned latency_bins;
    unsigned outstanding_bins;
    Addr read_addr_mask;
    Tick sample_period;
    System * system;
    unsigned transaction_bins;
    Addr write_addr_mask;
    unsigned int port_slave_connection_count;
    unsigned int port_master_connection_count;
};

#endif // __PARAMS__CommMonitor__
