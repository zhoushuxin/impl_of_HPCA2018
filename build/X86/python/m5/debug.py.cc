#include "sim/init.hh"

namespace {

const uint8_t data_m5_debug[] = {
    120,156,173,86,93,111,220,68,20,189,99,123,63,179,77,66,
    75,18,130,132,154,134,22,246,1,117,251,210,7,74,132,74,
    8,69,66,16,33,71,180,194,162,181,54,246,108,214,27,219,
    187,177,199,85,138,146,167,240,202,27,111,168,63,131,127,193,
    127,130,123,174,237,124,32,190,212,236,238,122,246,206,120,62,
    206,156,123,142,199,1,85,31,155,175,199,27,138,242,95,56,
    8,249,167,40,38,74,20,121,138,20,234,22,197,22,37,54,
    121,118,89,183,41,118,200,107,72,95,7,113,210,36,175,73,
    73,139,188,86,217,163,33,173,109,242,218,148,116,200,235,148,
    173,77,138,187,148,44,144,183,192,245,22,253,68,228,245,40,
    108,147,182,105,164,40,236,160,229,140,232,123,239,6,233,27,
    136,188,69,44,182,215,239,50,176,232,15,254,244,21,71,102,
    145,139,89,22,165,198,31,21,105,96,162,105,90,182,119,184,
    216,137,2,243,77,116,28,165,187,125,11,109,24,186,23,37,
    179,88,63,137,135,7,166,199,213,207,167,201,108,90,164,33,
    26,46,58,229,193,88,135,219,153,30,30,154,101,84,181,113,
    117,50,53,250,203,157,237,111,167,153,185,88,65,86,254,58,
    202,77,0,242,28,190,26,152,20,4,126,204,157,140,16,120,
    198,212,29,103,100,20,25,11,149,157,231,33,157,18,157,8,
    155,135,22,101,3,58,90,163,148,112,155,27,215,79,21,29,
    240,109,69,19,27,27,223,121,222,163,83,190,99,209,11,139,
    142,158,208,169,77,39,54,229,107,50,187,141,17,232,234,160,
    235,200,162,85,172,198,211,241,239,153,17,10,149,145,212,8,
    138,95,47,163,248,249,42,138,223,232,232,245,255,69,241,123,
    133,34,123,253,47,40,76,67,102,176,121,236,205,106,236,164,
    137,14,152,161,173,88,24,172,130,51,165,20,175,203,191,26,
    46,171,99,175,223,98,26,119,243,5,46,183,135,185,222,64,
    122,242,71,6,234,252,44,142,115,228,104,131,63,247,242,71,
    124,229,75,151,18,89,119,109,66,38,105,168,83,19,181,57,
    148,9,77,163,78,153,220,206,57,149,58,148,198,17,6,25,
    228,239,48,10,203,32,212,121,224,162,155,212,210,97,162,251,
    8,220,197,186,9,99,12,148,16,24,172,16,140,163,56,204,
    116,218,135,18,164,200,63,226,98,48,158,38,122,240,227,120,
    90,228,227,130,165,56,56,208,201,195,65,158,5,131,217,43,
    51,158,166,3,174,133,122,191,56,184,207,117,76,59,214,241,
    236,3,140,70,65,170,171,110,169,158,106,242,255,109,46,239,
    168,214,95,90,222,85,15,148,172,207,188,200,214,131,218,202,
    128,182,13,37,238,115,160,9,14,102,106,97,52,11,170,68,
    96,35,247,8,28,228,16,65,3,82,65,208,132,113,17,180,
    144,37,4,109,170,124,218,129,79,17,116,43,159,178,135,221,
    210,152,129,170,22,182,106,27,172,146,120,128,245,225,115,66,
    68,111,190,0,217,19,187,237,150,86,22,231,97,23,254,75,
    157,229,108,98,201,138,31,178,129,75,179,57,98,195,120,116,
    29,118,101,126,63,74,35,227,251,91,152,193,17,154,58,74,
    80,59,213,37,168,167,36,230,157,176,164,45,136,242,84,118,
    192,78,96,145,195,43,155,178,3,52,57,52,105,136,108,143,
    31,212,35,68,227,147,86,233,154,117,250,193,130,248,75,191,
    148,35,216,8,91,71,95,208,179,147,146,23,187,164,3,32,
    118,251,0,41,58,247,147,135,66,130,192,55,55,57,58,208,
    166,78,242,211,146,37,247,109,40,114,165,150,118,16,235,97,
    38,219,28,86,253,164,57,50,58,201,75,241,34,27,6,118,
    9,138,140,181,106,106,186,69,213,238,82,205,237,27,18,12,
    143,249,197,44,28,26,253,24,19,44,10,191,75,252,117,172,
    27,106,83,189,165,2,171,210,198,185,62,214,72,52,49,41,
    189,95,50,194,36,30,54,207,25,65,87,247,118,189,209,178,
    186,90,107,2,123,187,14,228,158,104,34,96,193,13,163,52,
    247,253,175,46,116,209,253,27,180,43,87,209,10,84,198,188,
    254,95,88,221,141,107,82,187,32,56,89,1,216,176,239,239,
    94,129,89,155,78,253,3,169,151,132,92,3,181,175,0,45,
    159,124,250,85,46,119,5,241,53,192,186,239,99,146,57,35,
    196,147,248,229,48,46,244,156,48,222,229,1,79,231,139,209,
    125,15,112,230,130,14,51,121,115,102,176,93,218,37,155,95,
    158,239,241,128,23,115,70,217,173,80,206,51,215,56,73,247,
    231,140,179,83,225,44,31,174,115,129,249,33,15,24,93,134,
    217,239,213,121,243,125,188,128,248,190,208,227,251,201,52,44,
    98,174,186,107,231,160,238,160,216,68,33,238,187,91,235,81,
    146,36,12,200,252,23,248,222,16,228,45,30,240,9,70,226,
    232,105,170,142,211,233,242,117,233,219,95,170,211,232,243,43,
    185,41,50,224,164,122,35,223,229,58,195,107,185,123,254,10,
    205,231,220,125,153,221,125,7,32,229,145,41,92,203,129,133,
    243,75,206,21,238,85,152,40,150,55,50,23,167,161,32,113,
    23,230,176,39,1,182,85,114,250,41,56,203,241,210,191,108,
    45,91,61,181,202,223,101,171,179,178,58,248,19,61,94,109,
    172,
};

EmbeddedPython embedded_m5_debug(
    "m5/debug.py",
    "/home/zhoushuxin/gem5/src/python/m5/debug.py",
    "m5.debug",
    data_m5_debug,
    1169,
    3363);

} // anonymous namespace