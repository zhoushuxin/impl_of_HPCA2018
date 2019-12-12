#ifndef __PARAMS__VirtIODummyDevice__
#define __PARAMS__VirtIODummyDevice__

class VirtIODummyDevice;


#include "params/VirtIODeviceBase.hh"

struct VirtIODummyDeviceParams
    : public VirtIODeviceBaseParams
{
    VirtIODummyDevice * create();
};

#endif // __PARAMS__VirtIODummyDevice__
