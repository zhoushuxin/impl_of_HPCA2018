#ifndef __PARAMS__BranchPredictor__
#define __PARAMS__BranchPredictor__

class BPredUnit;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

struct BranchPredictorParams
    : public SimObjectParams
{
    unsigned BTBEntries;
    unsigned BTBTagSize;
    unsigned RASSize;
    bool indirectHashGHR;
    bool indirectHashTargets;
    unsigned indirectPathLength;
    unsigned indirectSets;
    unsigned indirectTagSize;
    unsigned indirectWays;
    unsigned instShiftAmt;
    unsigned numThreads;
    bool useIndirect;
};

#endif // __PARAMS__BranchPredictor__
