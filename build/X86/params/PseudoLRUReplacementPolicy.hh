#ifndef __PARAMS__PseudoLRUReplacementPolicy__
#define __PARAMS__PseudoLRUReplacementPolicy__

class PseudoLRUPolicy;


#include "params/ReplacementPolicy.hh"

struct PseudoLRUReplacementPolicyParams
    : public ReplacementPolicyParams
{
    PseudoLRUPolicy * create();
};

#endif // __PARAMS__PseudoLRUReplacementPolicy__
