#ifndef __PARAMS__SerialNullDevice__
#define __PARAMS__SerialNullDevice__

class SerialNullDevice;


#include "params/SerialDevice.hh"

struct SerialNullDeviceParams
    : public SerialDeviceParams
{
    SerialNullDevice * create();
};

#endif // __PARAMS__SerialNullDevice__
