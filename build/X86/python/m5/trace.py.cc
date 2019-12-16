#include "sim/init.hh"

namespace {

const uint8_t data_m5_trace[] = {
    120,156,85,142,191,14,194,32,16,135,15,90,255,189,132,113,
    50,12,166,76,221,140,241,9,28,234,198,98,180,37,133,164,
    64,83,32,81,95,94,239,26,23,47,240,229,119,132,251,114,
    45,252,138,227,61,239,24,196,61,134,14,15,131,1,192,49,
    80,12,28,7,197,193,21,160,10,112,37,168,18,88,199,225,
    42,10,252,106,63,88,162,196,148,150,136,144,211,152,211,28,
    109,239,195,164,211,138,124,54,222,31,131,158,159,181,167,120,
    17,11,26,217,32,110,174,174,210,116,111,117,67,123,52,140,
    64,219,52,164,23,240,135,120,64,72,19,156,150,111,19,114,
    52,249,105,189,236,181,171,101,156,90,57,190,146,9,94,98,
    55,11,43,236,215,56,112,116,161,203,131,62,109,201,64,154,
    47,157,222,50,179,
};

EmbeddedPython embedded_m5_trace(
    "m5/trace.py",
    "/home/zhoushuxin/gem5/src/python/m5/trace.py",
    "m5.trace",
    data_m5_trace,
    181,
    246);

} // anonymous namespace