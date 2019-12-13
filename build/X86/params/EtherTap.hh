#ifndef __PARAMS__EtherTap__
#define __PARAMS__EtherTap__

class EtherTap;

#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/EtherTapBase.hh"

struct EtherTapParams
    : public EtherTapBaseParams
{
    EtherTap * create();
    std::string tap_device_name;
    std::string tun_clone_device;
};

#endif // __PARAMS__EtherTap__
