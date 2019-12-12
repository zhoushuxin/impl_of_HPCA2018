#ifndef __PARAMS__ArmTLB__
#define __PARAMS__ArmTLB__

namespace ArmISA {
class TLB;
} // namespace ArmISA

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "params/ArmTableWalker.hh"

#include "params/BaseTLB.hh"

struct ArmTLBParams
    : public BaseTLBParams
{
    ArmISA::TLB * create();
    bool is_stage2;
    int size;
    System * sys;
    ArmISA::TableWalker * walker;
};

#endif // __PARAMS__ArmTLB__
