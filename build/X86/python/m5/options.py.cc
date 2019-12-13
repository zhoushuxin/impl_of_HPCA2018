#include "sim/init.hh"

namespace {

const uint8_t data_m5_options[] = {
    120,156,173,88,221,83,220,84,20,191,55,217,175,44,180,212,
    86,24,80,234,68,45,227,214,74,209,7,29,235,208,78,167,
    182,90,157,14,197,80,71,101,218,102,66,114,97,3,75,178,
    77,238,182,224,192,131,131,47,117,70,223,125,244,193,191,83,
    207,239,220,36,187,64,235,131,203,46,201,158,251,125,62,126,
    231,227,18,138,226,99,211,115,219,149,34,239,18,17,209,159,
    20,61,33,214,43,90,138,117,201,180,133,254,71,145,45,148,
    37,54,169,171,38,126,21,226,72,136,159,214,109,17,213,203,
    222,70,213,91,19,81,83,168,58,247,182,170,222,6,54,93,
    235,56,116,88,252,15,125,86,58,146,72,141,215,135,26,189,
    73,26,169,205,96,208,211,97,201,33,198,238,128,195,22,17,
    74,128,31,111,173,131,145,142,133,181,232,246,253,36,216,85,
    190,175,219,220,216,77,163,65,143,154,102,86,245,202,175,211,
    107,169,155,238,170,165,159,187,233,32,239,14,246,226,100,105,
    75,237,126,186,148,103,225,82,127,95,119,211,100,137,90,105,
    95,199,105,146,95,239,239,123,56,253,61,172,197,89,13,115,
    90,222,239,197,90,171,236,52,139,111,85,44,146,202,72,230,
    117,11,242,130,176,193,52,246,8,241,42,159,47,177,232,28,
    17,7,82,28,16,231,172,246,53,214,73,161,153,122,121,158,
    17,182,134,166,234,109,122,245,113,37,43,244,22,39,177,246,
    253,133,82,66,33,67,236,220,164,167,86,242,247,4,252,217,
    98,91,128,69,122,31,73,113,88,135,205,14,106,98,219,2,
    235,219,182,56,178,196,97,67,28,52,32,192,78,75,100,15,
    192,250,232,132,131,186,56,178,133,76,206,97,210,118,131,219,
    82,200,17,121,113,40,203,165,65,109,41,29,104,157,233,6,
    209,207,131,222,64,229,44,124,68,191,76,172,164,137,226,137,
    249,200,68,181,167,85,18,153,157,208,230,78,35,51,207,37,
    210,207,105,110,189,220,148,39,244,131,44,87,153,7,248,121,
    237,51,210,107,24,244,122,190,255,1,246,104,179,94,47,202,
    105,57,41,231,172,14,152,247,160,107,15,190,231,49,175,23,
    143,157,250,191,193,138,173,175,96,45,136,134,116,44,61,73,
    196,67,158,176,202,66,86,144,181,74,200,62,254,15,200,146,
    211,131,32,87,182,153,168,23,110,15,55,174,51,209,44,92,
    126,189,5,119,7,225,136,200,97,143,167,200,49,1,208,67,
    252,80,22,161,6,207,67,28,251,29,64,101,1,78,116,26,
    97,137,112,66,1,130,80,36,181,129,139,196,240,31,140,57,
    191,198,200,35,48,213,49,73,198,166,183,81,244,130,110,26,
    199,129,84,43,28,71,54,211,108,55,128,147,118,96,15,142,
    11,4,148,34,182,176,141,72,111,108,120,125,137,26,143,98,
    221,83,209,125,213,235,127,85,46,244,208,207,123,249,213,212,
    57,32,48,206,131,13,138,46,113,66,147,242,62,61,42,242,
    131,108,43,55,150,39,187,211,244,156,129,229,111,101,233,160,
    223,177,43,56,194,46,60,21,173,157,23,32,199,179,56,208,
    243,241,16,100,51,4,178,115,150,99,159,214,55,132,49,238,
    187,45,135,202,45,93,143,225,56,11,14,39,141,162,252,66,
    83,249,144,121,111,30,175,203,99,131,244,29,90,242,197,72,
    188,57,197,234,13,19,15,39,179,203,224,146,127,68,17,125,
    124,41,146,217,82,14,235,56,72,164,73,45,216,53,159,55,
    82,184,186,171,220,112,144,101,42,209,174,97,193,101,147,172,
    24,177,32,177,247,54,196,190,0,195,68,145,111,38,157,180,
    219,25,137,206,96,130,114,121,251,155,104,52,216,23,207,203,
    41,139,245,208,24,213,195,223,163,46,66,30,69,206,65,14,
    185,99,137,44,130,67,210,208,78,3,52,230,88,232,65,96,
    182,197,22,175,34,71,93,38,31,5,213,32,170,201,148,20,
    203,218,70,44,63,98,197,81,239,114,34,134,190,85,169,243,
    176,198,161,187,129,56,79,113,26,19,154,98,167,41,178,191,
    208,111,154,212,207,139,107,69,58,207,111,26,21,186,65,82,
    170,90,167,175,53,192,71,110,154,185,91,189,116,35,232,185,
    9,69,114,151,212,194,78,17,132,28,172,153,236,247,41,152,
    15,51,66,233,188,24,163,32,30,39,91,236,79,122,191,175,
    216,245,16,114,55,130,112,103,197,184,60,244,72,73,196,155,
    40,27,253,180,207,17,210,88,188,125,204,226,28,247,61,164,
    239,78,227,180,213,153,7,239,188,56,139,252,224,93,165,37,
    119,177,118,6,59,52,174,200,41,217,230,239,37,107,90,58,
    212,186,96,133,96,19,124,67,16,206,193,127,10,70,1,89,
    104,134,140,19,89,134,98,147,1,31,54,236,93,164,96,194,
    199,173,34,162,30,54,97,236,195,150,72,166,152,104,150,253,
    45,54,162,13,235,17,72,8,33,5,64,168,191,73,224,176,
    15,157,114,66,157,39,80,68,111,115,114,167,9,45,158,64,
    77,154,211,22,155,22,217,31,172,114,1,201,246,119,55,210,
    180,167,134,48,128,93,84,228,46,46,162,70,35,120,48,153,
    114,235,122,219,45,62,119,99,170,114,130,125,183,75,33,216,
    141,20,44,79,6,118,105,249,139,110,28,118,221,56,103,44,
    149,97,9,10,90,92,92,200,243,38,19,180,221,66,206,85,
    228,34,191,125,239,221,42,234,235,52,83,190,206,6,202,123,
    191,12,193,56,68,79,84,131,155,65,47,87,198,178,181,18,
    108,153,34,118,66,229,193,72,26,21,218,218,247,171,171,222,
    189,181,53,255,254,189,7,171,108,68,22,123,24,215,33,15,
    31,225,45,138,162,112,211,232,99,106,147,71,219,213,0,115,
    192,3,76,241,177,164,46,38,54,137,24,47,206,128,49,24,
    161,0,247,143,216,6,216,22,53,224,236,162,164,210,128,138,
    3,20,8,179,68,209,99,85,85,169,93,34,238,161,137,194,
    38,250,80,188,200,22,0,30,109,1,24,132,52,147,162,169,
    127,205,148,174,8,69,55,64,80,115,110,237,213,51,77,122,
    246,174,85,138,54,246,9,50,157,191,136,117,215,212,186,131,
    126,153,122,17,147,125,191,168,3,227,141,129,70,69,111,29,
    211,57,70,198,87,85,117,8,221,28,68,149,75,167,228,140,
    53,41,91,86,8,149,212,70,85,243,251,73,213,92,123,133,
    106,200,157,80,205,36,79,139,218,158,66,44,116,212,23,49,
    143,81,231,103,20,172,49,80,135,111,210,158,114,168,201,151,
    60,133,79,89,126,246,82,36,115,175,63,96,88,247,24,197,
    114,228,66,10,245,144,100,141,38,141,144,121,41,36,199,57,
    206,195,166,24,229,37,203,120,65,229,28,75,171,244,63,86,
    168,187,69,75,158,99,237,133,66,163,243,244,156,163,239,36,
    130,28,28,181,46,70,46,26,79,197,72,141,66,133,222,99,
    138,84,148,210,44,177,119,135,245,205,146,83,255,221,39,159,
    240,152,93,36,42,92,57,28,145,127,3,61,66,129,77,128,
    213,36,42,234,89,126,182,32,232,239,135,3,171,42,119,56,
    156,207,150,8,228,210,110,164,130,243,163,56,164,59,17,103,
    235,152,106,60,122,118,115,78,35,102,97,133,62,212,121,156,
    36,56,189,236,168,125,254,165,123,197,120,90,187,77,75,126,
    25,226,112,218,154,39,23,125,195,58,125,113,92,60,161,47,
    0,200,232,34,187,10,158,80,27,51,64,101,114,236,98,121,
    66,124,202,164,218,71,24,26,166,202,124,223,220,182,212,94,
    113,241,52,66,183,138,174,144,46,233,227,185,29,88,24,228,
    193,150,250,77,148,85,16,195,98,165,131,2,244,228,245,8,
    80,245,92,188,16,119,189,207,241,66,185,193,0,99,125,49,
    235,222,183,226,76,174,81,240,153,37,172,197,181,140,162,100,
    219,177,157,166,243,166,51,237,56,206,132,227,152,235,37,18,
    131,247,181,40,239,152,27,219,42,212,252,223,2,174,49,204,
    93,149,112,196,155,141,207,19,171,126,217,252,95,227,214,229,
    18,28,147,114,210,106,91,51,214,204,196,191,183,140,130,144,
};

EmbeddedPython embedded_m5_options(
    "m5/options.py",
    "/home/zhoushuxin/gem5/src/python/m5/options.py",
    "m5.options",
    data_m5_options,
    1792,
    4560);

} // anonymous namespace
