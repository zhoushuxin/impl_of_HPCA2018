#ifndef __PARAMS__BaseCPU__
#define __PARAMS__BaseCPU__

class BaseCPU;

#include <cstddef>
#include "params/BaseCPU.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "params/BaseTLB.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/X86LocalApic.hh"
#include <vector>
#include "params/X86ISA.hh"
#include <cstddef>
#include "params/BaseTLB.hh"
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
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "params/InstTracer.hh"
#include <cstddef>
#include <vector>
#include "params/Process.hh"

#include "params/MemObject.hh"

struct BaseCPUParams
    : public MemObjectParams
{
    BaseCPU * checker;
    int cpu_id;
    bool do_checkpoint_insts;
    bool do_quiesce;
    bool do_statistics_insts;
    BaseTLB * dtb;
    bool function_trace;
    Tick function_trace_start;
    std::vector< X86ISA::Interrupts * > interrupts;
    std::vector< X86ISA::ISA * > isa;
    BaseTLB * itb;
    Counter max_insts_all_threads;
    Counter max_insts_any_thread;
    Counter max_loads_all_threads;
    Counter max_loads_any_thread;
    unsigned numThreads;
    bool power_gating_on_idle;
    Tick profile;
    Tick progress_interval;
    Cycles pwr_gating_latency;
    std::vector< Counter > simpoint_start_insts;
    unsigned socket_id;
    bool switched_out;
    Cycles syscallRetryLatency;
    System * system;
    Trace::InstTracer * tracer;
    bool wait_for_remote_gdb;
    std::vector< Process * > workload;
    unsigned int port_icache_port_connection_count;
    unsigned int port_dcache_port_connection_count;
};

#endif // __PARAMS__BaseCPU__
