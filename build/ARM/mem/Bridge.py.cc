#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Bridge[] = {
    120,156,165,82,75,147,211,48,12,150,251,110,183,11,101,143,
    156,194,137,176,51,52,28,216,27,195,192,158,121,236,180,11,
    51,244,146,73,99,53,73,39,78,130,237,64,187,215,242,191,
    65,178,219,161,7,110,196,137,34,201,146,62,189,82,56,62,
    93,250,222,5,2,204,107,98,36,189,2,74,128,123,230,58,
    80,10,80,2,86,2,132,236,2,10,216,8,144,61,248,5,
    112,0,248,182,234,128,236,195,50,28,144,99,241,155,158,80,
    16,103,153,92,123,118,76,228,35,170,207,235,45,166,214,178,
    221,173,46,100,134,233,57,248,45,131,255,36,6,129,145,8,
    152,3,19,42,33,246,56,137,3,241,125,192,1,80,14,204,
    15,1,71,176,29,115,38,132,127,232,192,106,114,166,25,56,
    205,133,211,76,65,14,65,142,156,230,18,240,17,108,31,3,
    206,32,35,148,177,83,62,129,197,50,156,16,246,162,67,196,
    92,18,81,168,162,181,203,114,158,231,134,239,150,101,242,3,
    131,166,214,214,92,112,65,137,177,168,157,92,204,216,43,32,
    114,159,99,80,181,106,77,23,245,38,208,248,189,69,99,77,
    96,235,96,221,110,54,168,205,179,127,24,153,166,174,12,158,
    89,89,238,199,171,202,152,167,71,235,50,177,88,165,123,54,
    183,121,97,2,159,152,121,65,215,239,165,164,8,38,208,73,
    149,249,24,77,66,162,205,117,221,102,57,253,241,104,29,94,
    241,40,70,68,226,184,74,20,198,177,157,56,65,213,178,45,
    89,236,177,193,190,65,167,79,119,187,56,199,68,82,54,227,
    83,241,119,84,171,237,115,173,44,57,51,223,5,119,193,115,
    85,78,116,54,119,137,78,148,195,251,82,153,34,171,80,58,
    129,122,18,155,226,1,93,84,174,221,75,67,146,62,248,42,
    157,183,196,50,217,91,238,243,87,218,153,90,251,104,227,99,
    193,11,46,214,75,101,73,155,85,235,189,131,247,77,8,121,
    165,254,18,243,156,72,148,215,10,163,135,188,110,77,222,238,
    138,42,202,80,221,68,70,167,17,15,218,175,227,188,217,187,
    249,191,100,39,238,214,64,240,153,210,185,114,103,42,62,133,
    221,211,66,171,155,121,195,73,153,133,56,45,206,127,0,187,
    222,188,241,163,120,123,205,206,60,141,137,152,117,254,0,218,
    60,216,10,
};

EmbeddedPython embedded_m5_objects_Bridge(
    "m5/objects/Bridge.py",
    "/home/zhoushuxin/gem5/src/mem/Bridge.py",
    "m5.objects.Bridge",
    data_m5_objects_Bridge,
    515,
    930);

} // anonymous namespace
