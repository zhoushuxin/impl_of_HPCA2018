#ifndef __PARAMS__LTAGE__
#define __PARAMS__LTAGE__

class LTAGE;

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
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BranchPredictor.hh"

struct LTAGEParams
    : public BranchPredictorParams
{
    LTAGE * create();
    unsigned histBufferSize;
    unsigned logSizeBiMP;
    unsigned logSizeLoopPred;
    unsigned logSizeTagTables;
    unsigned maxHist;
    unsigned minHist;
    unsigned minTagWidth;
    unsigned nHistoryTables;
    unsigned tagTableCounterBits;
};

#endif // __PARAMS__LTAGE__
