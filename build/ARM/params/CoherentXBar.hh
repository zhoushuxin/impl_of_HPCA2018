#ifndef __PARAMS__CoherentXBar__
#define __PARAMS__CoherentXBar__

class CoherentXBar;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "params/SnoopFilter.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/BaseXBar.hh"

struct CoherentXBarParams
    : public BaseXBarParams
{
    CoherentXBar * create();
    bool point_of_coherency;
    bool point_of_unification;
    SnoopFilter * snoop_filter;
    Cycles snoop_response_latency;
    System * system;
};

#endif // __PARAMS__CoherentXBar__
