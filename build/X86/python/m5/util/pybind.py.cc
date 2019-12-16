#include "sim/init.hh"

namespace {

const uint8_t data_m5_util_pybind[] = {
    120,156,173,86,93,111,27,69,20,189,51,187,206,135,73,99,
    41,52,41,60,84,172,66,82,57,16,197,168,82,4,53,80,
    32,165,66,125,168,21,173,195,3,81,97,181,222,29,199,27,
    109,118,205,238,184,196,164,126,161,8,248,215,112,239,157,29,
    219,164,125,0,217,150,51,153,143,157,59,247,158,115,246,140,
    35,168,62,14,254,125,237,9,40,79,177,19,227,87,64,10,
    112,22,75,80,2,250,2,98,7,126,7,120,13,240,195,185,
    132,216,5,37,121,182,54,157,117,32,94,177,179,171,211,89,
    23,226,53,232,54,215,49,104,242,55,126,154,2,123,154,154,
    143,244,6,182,167,227,147,36,139,159,94,15,243,66,71,54,
    23,137,127,39,148,203,125,236,40,128,115,65,129,241,4,229,
    82,106,20,91,192,121,13,252,46,135,139,156,42,127,26,60,
    161,125,174,169,193,44,119,154,20,179,73,15,104,90,40,85,
    218,231,78,148,199,74,215,168,147,133,87,202,60,69,77,249,
    16,155,214,32,191,82,173,95,7,249,168,28,140,174,147,172,
    117,161,174,142,91,101,17,181,134,99,61,200,179,22,142,70,
    58,73,113,216,195,10,142,112,118,133,178,229,74,62,166,40,
    146,75,105,210,172,94,195,38,8,232,152,32,208,117,30,92,
    229,241,40,165,225,42,14,191,57,121,242,92,233,80,223,49,
    75,216,141,210,176,44,113,117,19,103,194,94,169,139,48,210,
    56,63,200,99,191,102,19,93,56,101,95,84,1,24,177,21,
    177,34,249,60,67,202,105,145,15,85,161,199,83,90,28,75,
    139,55,165,133,228,225,48,39,200,143,75,162,65,114,12,51,
    244,116,68,97,221,138,81,102,134,144,121,37,224,21,150,137,
    29,9,197,54,181,153,99,39,177,117,184,35,231,9,156,114,
    71,8,50,152,209,245,117,48,29,252,82,36,58,236,165,170,
    73,143,248,116,150,79,218,242,9,77,127,115,25,64,85,4,
    38,89,162,131,224,19,138,67,180,130,88,23,219,130,229,247,
    175,34,63,164,34,1,46,1,138,6,97,130,229,33,80,19,
    46,18,223,35,20,175,224,226,104,83,135,57,143,85,63,40,
    84,24,83,37,138,95,12,59,147,103,233,184,252,28,39,142,
    246,110,140,184,38,205,221,189,155,27,82,241,17,33,48,153,
    236,30,122,15,246,110,88,196,147,118,219,174,89,132,38,147,
    3,70,209,0,49,67,136,178,246,121,88,91,6,66,28,229,
    216,74,9,16,151,14,75,223,231,102,213,18,216,201,51,197,
    157,179,98,164,252,198,155,199,47,148,195,59,180,109,38,231,
    70,109,206,99,158,243,203,243,166,152,15,102,98,118,248,107,
    196,236,88,49,187,196,221,84,213,238,146,85,61,19,42,163,
    18,22,23,229,91,85,188,189,20,124,8,239,246,45,245,202,
    170,16,215,22,243,140,146,225,122,208,167,95,99,49,247,169,
    95,188,79,128,116,17,139,110,181,40,65,163,150,29,40,30,
    81,238,56,131,186,238,162,159,26,133,255,38,96,78,227,212,
    106,100,156,237,182,31,166,165,42,247,177,247,125,86,142,134,
    164,105,21,123,134,37,15,117,31,142,82,237,189,12,211,145,
    242,244,120,168,140,131,146,105,38,101,146,149,58,204,34,35,
    161,94,158,167,38,96,154,135,90,19,156,73,166,121,169,80,
    195,66,211,165,115,134,1,158,22,69,94,52,165,69,149,183,
    112,248,197,109,129,142,8,162,60,123,25,32,115,95,81,160,
    58,35,219,16,155,98,75,212,37,123,3,157,71,47,128,67,
    232,162,41,192,95,198,27,94,192,159,192,215,165,128,63,192,
    218,131,100,123,48,70,129,215,236,165,128,11,187,225,219,31,
    183,96,226,178,148,92,122,234,39,9,63,127,70,157,123,120,
    13,223,163,109,89,157,99,172,204,44,134,206,237,68,162,18,
    60,65,243,46,101,241,184,226,24,44,199,15,169,255,2,77,
    74,192,68,82,70,24,135,78,149,36,100,140,214,151,176,67,
    228,227,83,248,159,34,83,188,78,185,133,237,112,220,110,99,
    249,205,221,253,114,247,192,251,210,219,47,203,59,183,167,141,
    216,223,179,240,235,209,48,85,254,7,96,239,101,199,104,159,
    5,207,23,98,37,3,227,92,114,81,154,40,236,133,210,68,
    82,16,171,40,125,54,207,212,134,112,196,93,201,161,143,240,
    216,255,230,174,102,237,208,99,167,241,240,195,215,253,161,199,
    63,109,14,202,227,255,21,108,222,170,165,125,219,89,199,151,
    121,146,53,107,111,241,108,186,98,248,172,208,136,120,138,211,
    34,246,253,29,237,223,168,172,161,177,86,71,96,62,149,183,
    109,220,39,202,141,115,19,127,203,180,239,187,184,237,145,181,
    39,178,239,245,181,14,87,111,244,209,139,248,39,86,222,187,
    84,145,230,159,46,108,248,188,109,57,25,240,53,255,133,249,
    101,246,248,129,205,164,46,119,86,119,234,255,0,149,229,66,
    175,
};

EmbeddedPython embedded_m5_util_pybind(
    "m5/util/pybind.py",
    "/home/zhoushuxin/gem5/src/python/m5/util/pybind.py",
    "m5.util.pybind",
    data_m5_util_pybind,
    1089,
    2858);

} // anonymous namespace