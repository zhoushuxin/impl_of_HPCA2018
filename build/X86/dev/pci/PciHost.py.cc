#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_PciHost[] = {
    120,156,165,85,75,111,35,69,16,174,241,251,21,219,73,88,
    180,28,128,145,64,194,90,65,124,64,139,144,64,193,73,86,
    64,14,36,145,179,28,240,197,26,207,244,196,29,230,97,77,
    183,151,100,101,159,178,63,136,43,7,126,219,82,95,141,103,
    243,144,2,18,235,25,215,84,213,84,87,85,87,125,83,237,
    211,230,87,230,255,200,117,200,88,102,2,190,29,138,136,98,
    135,38,14,57,144,75,20,149,232,229,134,43,231,92,153,162,
    10,197,85,154,84,115,155,10,69,53,138,107,52,169,177,92,
    37,85,165,208,161,160,70,111,136,110,136,126,155,212,41,168,
    147,170,139,182,241,78,219,160,160,73,231,131,22,7,214,111,
    249,55,112,152,179,77,38,231,58,62,157,93,42,223,230,42,
    144,103,183,111,207,116,250,66,189,210,190,202,85,13,168,34,
    207,134,105,22,219,58,4,95,255,156,26,235,23,91,132,213,
    33,182,232,50,163,8,59,227,164,39,37,161,101,236,120,82,
    65,206,156,253,248,124,80,98,163,113,133,137,233,161,34,234,
    213,112,225,235,225,156,29,238,205,231,131,122,17,113,58,77,
    188,88,77,167,182,37,66,156,6,203,8,34,86,218,235,133,
    146,76,253,171,171,169,31,121,198,136,21,164,185,242,2,149,
    137,213,203,108,169,196,149,55,51,54,243,120,179,72,246,150,
    152,47,153,112,224,88,13,95,207,211,165,153,47,175,116,50,
    188,80,241,243,161,201,252,97,145,217,102,183,123,139,107,201,
    250,43,172,132,215,154,147,95,182,203,194,79,42,81,153,246,
    31,86,166,85,84,230,175,127,175,204,101,13,221,187,108,0,
    3,55,37,154,52,69,217,2,16,110,216,166,125,95,236,136,
    184,5,88,48,24,96,223,45,12,106,0,2,52,189,59,154,
    134,104,250,119,52,77,209,108,11,255,216,221,162,55,77,154,
    236,160,101,109,180,172,243,72,203,204,39,119,240,225,218,212,
    93,26,229,50,239,234,196,170,44,91,46,172,49,31,177,201,
    81,154,132,250,194,53,11,207,87,238,204,99,35,47,8,50,
    101,140,70,53,205,119,76,78,150,241,76,101,110,26,186,51,
    109,13,28,5,112,232,25,215,75,88,27,26,101,93,207,13,
    4,155,166,88,158,123,212,210,81,0,240,240,142,107,201,227,
    236,232,216,61,62,117,61,159,23,25,190,63,127,204,40,86,
    113,154,93,255,135,225,139,95,14,30,26,250,104,243,147,205,
    183,126,36,31,2,127,18,43,7,253,29,173,91,180,42,161,
    175,163,117,155,86,101,244,112,180,238,208,170,146,191,221,162,
    85,21,141,28,173,187,180,170,161,159,163,117,143,86,245,156,
    235,211,170,145,115,219,180,106,193,229,239,101,50,127,210,170,
    13,167,27,190,3,183,27,126,11,142,55,124,23,174,55,124,
    15,206,55,124,31,238,55,252,54,2,48,159,253,77,60,159,
    184,237,140,47,39,33,113,212,1,150,246,15,57,22,35,136,
    159,45,224,134,159,93,96,131,159,61,10,218,120,246,41,232,
    224,185,141,93,238,31,174,119,104,213,164,96,139,147,222,21,
    174,75,63,136,244,1,173,248,21,211,93,186,40,243,92,2,
    150,78,244,91,76,167,79,65,240,233,107,148,80,99,160,152,
    111,152,156,38,10,104,176,115,70,148,86,81,144,183,0,34,
    250,85,180,69,27,55,93,90,129,77,186,76,130,28,80,26,
    160,213,125,144,167,32,31,131,0,170,199,24,133,64,139,6,
    90,242,17,87,101,18,122,214,139,6,104,163,76,15,163,162,
    208,34,155,217,210,216,90,14,123,134,157,12,148,112,153,248,
    86,167,137,8,153,186,208,134,145,46,78,4,139,50,36,189,
    72,51,116,2,139,207,102,145,169,80,89,127,238,205,34,101,
    219,178,38,74,125,142,7,25,193,176,19,97,56,88,40,203,
    243,104,161,76,185,34,92,46,21,241,66,201,74,2,134,249,
    152,203,35,134,118,235,65,200,80,146,184,19,51,15,177,41,
    159,172,141,210,63,166,146,4,34,204,245,197,92,164,247,152,
    149,50,144,89,245,99,96,15,216,211,17,124,60,147,243,176,
    229,220,187,74,29,231,254,181,85,217,47,181,156,110,105,176,
    139,169,131,162,142,177,209,49,82,30,35,215,113,179,104,217,
    153,151,121,241,24,77,146,90,176,168,18,43,77,243,146,107,
    217,215,162,56,183,80,220,131,98,131,62,215,114,138,17,116,
    43,25,253,90,137,207,95,143,19,251,173,237,23,250,188,15,
    83,204,163,188,149,190,158,46,116,154,175,46,20,60,15,238,
    43,130,216,19,197,248,179,123,39,206,255,60,118,224,245,107,
    172,124,122,123,236,148,158,148,122,78,207,217,41,239,56,124,
    49,127,50,144,178,192,54,126,190,247,238,128,31,35,164,108,
    147,181,11,212,43,111,56,164,44,189,186,150,194,229,167,253,
    88,78,102,84,79,14,58,9,251,190,185,75,172,239,243,195,
    123,255,11,120,128,215,190,180,190,239,244,75,31,214,254,1,
    83,140,5,78,
};

EmbeddedPython embedded_m5_objects_PciHost(
    "m5/objects/PciHost.py",
    "/home/zhoushuxin/gem5/src/dev/pci/PciHost.py",
    "m5.objects.PciHost",
    data_m5_objects_PciHost,
    1108,
    2345);

} // anonymous namespace