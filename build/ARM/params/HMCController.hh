#ifndef __PARAMS__HMCController__
#define __PARAMS__HMCController__

class HMCController;


#include "params/NoncoherentXBar.hh"

struct HMCControllerParams
    : public NoncoherentXBarParams
{
    HMCController * create();
};

#endif // __PARAMS__HMCController__
