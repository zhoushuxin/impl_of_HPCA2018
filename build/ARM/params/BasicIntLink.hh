#ifndef __PARAMS__BasicIntLink__
#define __PARAMS__BasicIntLink__

class BasicIntLink;

#include <cstddef>
#include <string>
#include <cstddef>
#include "params/BasicRouter.hh"
#include <cstddef>
#include "params/BasicRouter.hh"
#include <cstddef>
#include <string>

#include "params/BasicLink.hh"

struct BasicIntLinkParams
    : public BasicLinkParams
{
    BasicIntLink * create();
    std::string dst_inport;
    BasicRouter * dst_node;
    BasicRouter * src_node;
    std::string src_outport;
};

#endif // __PARAMS__BasicIntLink__
