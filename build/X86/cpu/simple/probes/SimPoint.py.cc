#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_SimPoint[] = {
    120,156,173,146,81,107,219,48,16,199,79,78,226,180,97,140,
    109,165,143,3,61,13,103,15,246,75,187,49,40,165,248,173,
    48,182,146,108,129,229,197,56,178,18,171,179,44,35,201,35,
    205,107,251,69,247,33,250,188,221,41,13,27,236,117,194,62,
    238,206,167,255,253,116,178,128,167,53,192,247,138,51,112,103,
    232,84,248,48,104,0,190,144,23,65,195,64,71,176,140,128,
    85,3,144,17,172,25,84,67,120,0,184,7,248,182,28,64,
    53,130,121,18,227,70,245,11,87,194,208,243,100,222,238,221,
    19,52,55,214,172,228,71,229,188,108,165,253,188,186,149,194,
    251,35,204,207,149,190,49,170,245,226,111,144,156,64,46,209,
    145,0,75,70,56,216,27,137,168,21,114,12,65,142,224,54,
    6,132,65,140,123,204,140,67,230,136,64,170,56,100,142,97,
    54,79,198,40,225,62,28,186,243,181,177,92,152,166,193,222,
    170,221,240,67,107,158,151,78,9,158,55,70,124,231,11,252,
    104,172,227,73,158,47,220,52,157,69,36,241,26,141,232,250,
    204,41,221,53,50,235,72,205,133,136,246,167,117,173,224,231,
    227,200,157,98,217,117,235,165,253,81,54,168,190,147,60,81,
    173,243,110,234,158,147,202,161,124,181,74,55,59,247,146,206,
    153,47,120,98,122,223,245,126,202,215,170,145,201,132,230,69,
    115,41,138,182,212,178,40,252,36,4,218,84,125,67,225,56,
    132,149,17,232,15,169,248,174,147,161,70,108,183,69,45,203,
    74,90,63,162,19,151,182,212,158,238,228,43,34,189,59,11,
    162,234,9,46,228,231,222,226,20,252,51,116,241,64,212,189,
    8,8,116,9,127,140,123,143,38,171,141,150,217,174,54,189,
    171,251,173,106,179,141,212,231,153,179,34,251,119,42,135,169,
    166,221,93,24,222,148,68,8,48,102,113,68,239,43,246,41,
    9,228,199,104,244,121,218,17,169,219,67,147,196,140,254,153,
    176,245,63,162,132,227,95,236,167,120,249,134,196,8,97,194,
    94,68,191,1,191,236,184,134,
};

EmbeddedPython embedded_m5_objects_SimPoint(
    "m5/objects/SimPoint.py",
    "/home/zhoushuxin/gem5/src/cpu/simple/probes/SimPoint.py",
    "m5.objects.SimPoint",
    data_m5_objects_SimPoint,
    456,
    770);

} // anonymous namespace
