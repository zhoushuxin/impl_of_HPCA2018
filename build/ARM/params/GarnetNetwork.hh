#ifndef __PARAMS__GarnetNetwork__
#define __PARAMS__GarnetNetwork__

class GarnetNetwork;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/FaultModel.hh"
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

#include "params/RubyNetwork.hh"

struct GarnetNetworkParams
    : public RubyNetworkParams
{
    GarnetNetwork * create();
    uint32_t buffers_per_ctrl_vc;
    uint32_t buffers_per_data_vc;
    bool enable_fault_model;
    FaultModel * fault_model;
    uint32_t garnet_deadlock_threshold;
    uint32_t ni_flit_size;
    int num_rows;
    int routing_algorithm;
    uint32_t vcs_per_vnet;
};

#endif // __PARAMS__GarnetNetwork__
