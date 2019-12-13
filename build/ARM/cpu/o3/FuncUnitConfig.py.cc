#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_FuncUnitConfig[] = {
    120,156,189,87,109,111,219,54,16,166,108,73,126,79,92,39,
    117,219,15,11,250,209,43,134,24,104,155,174,3,134,109,94,
    94,134,12,205,90,200,201,138,249,195,12,87,84,28,110,122,
    155,37,25,93,191,102,191,123,219,221,73,164,41,55,195,2,
    44,179,157,16,199,199,58,146,247,240,225,29,229,178,226,83,
    133,255,111,30,27,44,249,19,12,14,127,6,243,25,11,12,
    54,49,152,129,253,10,243,43,44,168,178,73,53,239,87,153,
    111,178,243,194,178,192,50,153,103,179,75,131,113,139,253,193,
    216,53,99,63,77,106,140,219,18,173,41,180,206,120,93,162,
    13,133,54,24,111,74,180,165,208,38,227,109,137,118,20,218,
    98,124,75,162,219,10,109,51,222,149,232,61,133,118,24,239,
    73,116,71,161,91,140,239,74,244,190,66,183,25,239,179,241,
    224,1,80,32,254,130,207,192,0,43,109,64,51,22,193,235,
    119,191,120,110,154,67,117,104,222,101,194,231,199,225,50,71,
    176,121,146,218,208,158,134,233,232,213,133,171,19,251,45,18,
    251,24,12,143,33,159,94,165,96,248,154,25,115,3,25,5,
    118,39,38,115,198,3,124,58,173,65,19,197,135,254,44,73,
    212,136,126,38,208,28,88,114,250,233,52,156,5,222,116,154,
    54,169,19,68,60,243,177,139,79,189,142,143,188,196,37,51,
    138,95,137,36,77,209,205,141,178,48,29,224,154,86,77,242,
    20,154,225,85,20,120,195,15,87,81,150,92,101,239,69,56,
    156,123,193,193,48,89,184,67,55,206,134,209,179,225,73,22,
    186,23,161,72,15,163,240,82,204,247,227,223,29,92,231,62,
    250,155,208,216,70,207,160,101,192,66,207,50,63,61,18,75,
    21,126,93,134,255,243,199,225,67,212,32,158,107,86,41,16,
    147,16,139,68,131,120,117,78,180,120,22,170,231,17,136,230,
    87,155,45,126,68,209,120,38,182,143,166,54,11,25,234,6,
    148,6,228,181,96,10,199,148,12,22,139,161,208,129,133,89,
    42,136,220,130,80,88,163,216,149,187,27,139,216,243,69,232,
    113,138,226,124,228,124,119,124,62,61,29,143,82,244,120,255,
    242,133,192,221,21,21,36,13,227,113,112,12,7,231,112,176,
    75,51,156,204,252,196,115,112,48,7,31,118,58,216,52,75,
    92,255,39,194,49,54,116,77,154,5,225,123,118,215,232,86,
    40,156,147,55,83,93,113,53,73,249,247,183,165,92,71,172,
    21,50,167,211,14,187,145,107,179,166,232,197,168,79,252,104,
    150,142,56,167,72,137,155,21,124,24,196,90,103,153,10,83,
    74,119,141,186,156,176,59,164,105,7,220,190,70,255,122,65,
    83,207,120,152,107,19,72,90,215,102,75,18,245,225,246,218,
    92,33,54,33,53,13,169,19,146,39,50,210,111,129,183,8,
    111,175,240,185,133,148,66,66,155,88,72,236,150,34,182,33,
    73,195,165,230,204,18,222,214,241,145,235,10,171,252,180,72,
    220,92,221,138,117,212,55,122,57,219,165,39,199,191,45,82,
    241,80,169,217,190,97,75,122,255,199,190,96,74,61,70,255,
    182,218,23,220,153,61,35,207,174,167,103,71,83,116,80,91,
    211,151,91,99,26,55,101,205,194,174,104,118,85,179,77,205,
    182,52,219,214,236,154,102,215,53,187,161,217,77,205,110,105,
    118,91,179,59,154,189,165,217,219,154,221,213,236,123,154,221,
    211,236,29,205,222,165,202,176,75,167,239,126,113,250,250,165,
    228,6,245,136,195,225,35,101,23,54,200,98,245,147,159,41,
    27,15,163,178,151,41,73,4,109,20,205,170,131,153,178,165,
    117,112,180,162,240,241,241,149,184,76,73,131,170,135,63,75,
    95,212,148,250,85,166,133,53,0,214,83,2,112,81,101,96,
    185,54,6,8,56,237,232,0,173,183,140,224,162,187,235,8,
    46,173,244,24,105,126,99,25,232,19,112,59,67,255,39,164,
    244,246,173,190,80,63,105,49,222,140,191,137,22,171,99,96,
    202,99,240,217,199,25,106,237,24,96,173,172,226,49,200,229,
    98,150,228,114,230,5,56,182,150,71,114,64,176,77,209,130,
    110,28,253,237,130,150,94,126,244,223,46,68,234,221,121,204,
    245,60,102,26,156,196,32,131,38,100,115,81,31,96,166,93,
    139,154,38,226,111,23,165,160,109,25,244,209,191,6,253,79,
    249,110,110,18,25,86,65,134,45,201,112,158,97,243,2,155,
    231,216,124,206,138,170,178,17,6,94,130,91,184,98,128,82,
    62,221,206,226,50,1,234,210,114,195,174,231,181,24,95,48,
    242,234,105,80,245,180,138,234,169,2,37,61,193,184,144,0,
    188,36,201,171,39,22,69,42,129,116,133,219,92,189,251,2,
    125,153,186,31,239,25,63,12,48,81,209,1,12,14,246,213,
    235,132,131,147,80,22,7,148,123,151,112,9,77,28,245,214,
    1,88,60,91,204,130,36,175,235,197,44,249,157,239,2,175,
    248,116,15,167,187,33,221,124,168,204,82,6,162,243,70,242,
    163,29,160,245,220,77,104,180,148,47,243,215,141,175,62,197,
    113,240,58,1,119,81,163,105,52,43,125,179,223,233,219,253,
    122,255,65,223,194,239,223,182,248,161,132,
};

EmbeddedPython embedded_m5_objects_FuncUnitConfig(
    "m5/objects/FuncUnitConfig.py",
    "/home/zhoushuxin/gem5/src/cpu/o3/FuncUnitConfig.py",
    "m5.objects.FuncUnitConfig",
    data_m5_objects_FuncUnitConfig,
    1147,
    3680);

} // anonymous namespace