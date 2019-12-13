#include "sim/init.hh"

namespace {

const uint8_t data_m5_ext[] = {
    120,156,75,102,128,2,70,32,118,80,96,100,40,102,1,50,
    82,24,24,130,53,64,34,126,26,32,57,52,162,216,24,72,
    232,103,228,231,166,234,87,101,228,151,22,103,148,86,100,230,
    233,167,167,230,154,234,23,23,37,235,23,84,150,100,228,231,
    233,3,121,169,21,37,250,241,241,153,121,153,37,241,241,122,
    64,97,14,160,62,155,220,252,148,210,156,84,59,144,233,197,
    32,211,0,70,219,26,185,
};

EmbeddedPython embedded_m5_ext(
    "m5/ext/__init__.py",
    "/home/zhoushuxin/gem5/src/python/m5/ext/__init__.py",
    "m5.ext",
    data_m5_ext,
    103,
    130);

} // anonymous namespace
