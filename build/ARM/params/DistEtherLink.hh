#ifndef __PARAMS__DistEtherLink__
#define __PARAMS__DistEtherLink__

class DistEtherLink;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/EtherDump.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/EtherObject.hh"

struct DistEtherLinkParams
    : public EtherObjectParams
{
    DistEtherLink * create();
    Tick delay;
    Tick delay_var;
    uint32_t dist_rank;
    uint32_t dist_size;
    bool dist_sync_on_pseudo_op;
    EtherDump * dump;
    bool is_switch;
    uint32_t num_nodes;
    std::string server_name;
    uint32_t server_port;
    float speed;
    Tick sync_repeat;
    Tick sync_start;
    unsigned int port_int0_connection_count;
};

#endif // __PARAMS__DistEtherLink__
