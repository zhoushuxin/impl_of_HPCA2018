#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_FuncUnit[] = {
    120,156,165,85,223,111,219,70,12,166,108,199,113,28,103,77,
    187,46,251,221,222,186,182,115,139,205,6,6,116,216,195,48,
    52,77,231,161,192,218,20,114,179,161,126,113,21,241,92,41,
    144,116,154,116,242,146,61,13,200,254,239,141,164,100,89,46,
    48,96,64,44,235,64,242,78,188,79,223,71,158,124,168,126,
    109,186,31,43,7,242,55,100,32,253,29,136,0,98,7,102,
    14,56,236,183,32,106,193,43,108,131,110,195,194,1,236,192,
    223,0,151,0,175,103,29,192,45,208,142,68,187,117,116,11,
    112,123,21,237,213,209,46,224,14,76,135,125,218,36,252,135,
    126,67,135,44,187,67,195,52,140,143,79,207,180,111,203,16,
    15,15,237,54,141,199,233,81,228,229,185,191,66,122,159,238,
    39,140,244,47,50,52,48,192,18,47,65,36,120,40,112,8,
    8,109,79,27,211,118,216,7,220,5,28,0,238,1,190,7,
    120,13,112,31,240,58,224,13,192,247,1,111,2,126,0,120,
    0,248,33,224,71,128,31,3,126,2,248,41,224,103,128,159,
    3,222,2,188,13,168,0,191,0,188,3,248,37,224,93,192,
    123,240,246,62,204,90,224,78,135,140,198,242,235,188,48,243,
    10,169,237,146,251,44,177,135,81,33,47,64,230,243,34,178,
    171,240,211,112,105,123,100,78,34,227,217,67,196,181,115,20,
    167,13,103,105,133,23,113,228,249,65,211,59,244,253,245,90,
    78,185,94,27,230,254,218,155,254,158,89,65,65,252,34,239,
    214,95,219,156,163,158,170,192,178,205,56,106,155,96,244,42,
    91,50,215,14,67,218,109,56,156,173,18,18,167,65,184,40,
    1,215,222,10,176,4,24,212,106,182,230,97,51,64,120,54,
    2,12,106,51,176,124,39,7,179,176,215,12,8,222,205,8,
    131,222,127,55,194,208,54,150,213,164,61,215,177,171,189,82,
    34,178,127,203,66,171,27,58,84,179,123,141,64,185,132,121,
    120,150,102,148,88,83,61,12,68,248,220,190,204,244,66,91,
    63,24,114,179,73,206,249,60,241,98,61,159,139,42,243,121,
    108,176,136,216,237,144,187,244,162,124,200,5,191,30,242,7,
    52,140,3,19,235,241,159,129,41,242,160,56,15,147,241,91,
    29,63,26,231,153,63,246,211,98,60,41,18,255,36,9,237,
    40,189,112,91,180,250,107,126,236,38,13,93,231,26,93,229,
    56,160,171,75,183,148,228,113,250,84,231,126,221,94,237,85,
    123,253,220,108,47,42,118,234,176,25,117,127,7,206,182,184,
    213,46,201,237,138,187,93,181,221,101,11,102,61,137,236,128,
    238,115,23,114,100,151,187,132,247,113,5,10,147,207,56,23,
    132,115,94,48,208,32,200,175,51,31,23,169,86,102,161,76,
    170,51,207,134,38,9,249,8,200,21,175,191,240,35,157,171,
    34,177,97,164,50,157,147,100,42,204,149,183,244,194,200,59,
    165,41,205,43,181,85,214,40,155,21,90,253,17,232,68,217,
    64,43,222,133,115,121,145,226,189,212,194,100,54,160,71,77,
    202,9,22,69,20,93,168,52,76,117,20,38,26,71,106,66,
    148,107,21,107,47,201,85,98,236,122,74,121,86,121,81,52,
    26,178,148,46,171,224,62,100,204,157,10,184,232,231,159,159,
    207,3,170,7,157,217,45,114,95,122,153,23,139,6,82,74,
    166,113,56,28,201,11,201,42,147,254,226,89,201,243,196,152,
    72,140,87,244,10,82,65,245,246,87,43,3,230,253,123,126,
    172,47,101,208,149,34,184,81,138,63,57,217,16,191,181,18,
    255,219,255,37,254,54,156,245,88,124,118,119,88,103,134,239,
    126,247,159,58,223,162,96,82,196,167,58,99,165,73,32,98,
    123,114,242,85,83,202,59,194,73,85,2,202,103,202,72,122,
    210,77,137,112,147,19,197,124,203,7,100,173,131,251,13,15,
    35,30,198,204,119,187,60,105,133,96,223,80,221,200,65,245,
    43,125,92,76,86,202,194,156,8,1,196,127,152,219,171,17,
    204,47,252,152,31,235,53,8,126,49,100,213,165,247,227,71,
    163,250,235,230,114,126,81,151,162,41,99,201,69,244,159,136,
    23,41,22,129,38,41,175,4,74,142,151,31,202,3,229,199,
    7,43,112,251,78,191,117,48,56,232,253,11,185,126,221,149,
};

EmbeddedPython embedded_m5_objects_FuncUnit(
    "m5/objects/FuncUnit.py",
    "/home/zhoushuxin/gem5/src/cpu/FuncUnit.py",
    "m5.objects.FuncUnit",
    data_m5_objects_FuncUnit,
    944,
    2039);

} // anonymous namespace
