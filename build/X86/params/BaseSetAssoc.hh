#ifndef __PARAMS__BaseSetAssoc__
#define __PARAMS__BaseSetAssoc__

class BaseSetAssoc;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseReplacementPolicy.hh"

#include "params/BaseTags.hh"

struct BaseSetAssocParams
    : public BaseTagsParams
{
    BaseSetAssoc * create();
    int assoc;
    BaseReplacementPolicy * replacement_policy;
};

#endif // __PARAMS__BaseSetAssoc__
