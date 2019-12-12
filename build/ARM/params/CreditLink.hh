#ifndef __PARAMS__CreditLink__
#define __PARAMS__CreditLink__

class CreditLink;


#include "params/NetworkLink.hh"

struct CreditLinkParams
    : public NetworkLinkParams
{
    CreditLink * create();
};

#endif // __PARAMS__CreditLink__
