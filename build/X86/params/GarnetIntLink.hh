#ifndef __PARAMS__GarnetIntLink__
#define __PARAMS__GarnetIntLink__

class GarnetIntLink;

#include <cstddef>
#include "params/CreditLink.hh"
#include <cstddef>
#include "params/NetworkLink.hh"

#include "params/BasicIntLink.hh"

struct GarnetIntLinkParams
    : public BasicIntLinkParams
{
    GarnetIntLink * create();
    CreditLink * credit_link;
    NetworkLink * network_link;
};

#endif // __PARAMS__GarnetIntLink__
