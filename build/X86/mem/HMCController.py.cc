#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_HMCController[] = {
    120,156,165,79,177,78,195,48,16,61,39,165,130,72,136,5,
    70,164,142,129,33,158,186,33,132,218,1,22,58,180,12,144,
    197,138,156,3,87,138,227,200,113,164,150,21,254,27,238,220,
    22,196,204,201,126,122,119,246,221,123,167,97,31,41,221,187,
    137,128,190,32,82,211,17,208,0,60,237,153,32,150,0,38,
    240,42,160,78,225,19,224,3,224,165,76,161,30,193,42,63,
    162,150,245,23,69,46,136,5,134,235,112,74,248,240,56,159,
    187,54,120,215,52,232,245,65,138,223,103,44,117,78,4,1,
    74,193,130,101,194,74,52,114,185,202,19,122,88,242,183,254,
    130,192,162,149,198,106,165,127,70,21,198,228,35,150,58,38,
    80,170,173,44,42,21,178,152,88,87,15,13,167,241,195,182,
    195,88,215,155,141,50,88,213,232,115,182,240,11,113,95,105,
    156,69,249,110,220,208,155,97,179,110,229,27,218,169,236,189,
    150,172,253,103,139,162,219,70,103,247,220,203,18,99,49,22,
    139,157,155,19,54,59,45,186,202,87,182,143,250,207,179,202,
    135,51,34,11,215,106,103,208,99,27,184,22,71,252,223,73,
    220,255,102,183,241,237,213,193,81,38,178,203,111,93,129,102,
    244,
};

EmbeddedPython embedded_m5_objects_HMCController(
    "m5/objects/HMCController.py",
    "/home/zhoushuxin/gem5/src/mem/HMCController.py",
    "m5.objects.HMCController",
    data_m5_objects_HMCController,
    273,
    472);

} // anonymous namespace
