#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_FlashDevice[] = {
    120,156,173,84,219,110,211,64,16,93,59,105,210,244,66,47,
    130,194,227,190,17,120,32,109,80,36,68,17,130,94,168,144,
    104,84,37,92,68,36,100,109,188,147,122,169,47,193,187,110,
    155,190,150,79,225,63,97,102,156,164,121,224,177,182,179,153,
    57,59,241,158,115,102,55,161,152,94,21,252,188,147,158,176,
    93,12,52,62,158,136,133,248,60,141,188,121,228,99,228,11,
    168,136,145,39,116,69,252,22,226,86,136,239,131,170,208,85,
    1,62,163,75,115,116,73,232,154,232,55,235,248,74,243,23,
    175,166,135,145,163,225,185,219,196,241,72,57,117,100,172,203,
    205,176,112,38,75,195,25,27,31,63,7,196,230,33,6,32,
    196,192,155,114,58,247,197,192,23,189,126,147,42,220,10,14,
    22,126,21,144,58,163,98,87,163,20,95,54,134,38,201,113,
    203,56,4,65,170,18,8,2,174,13,130,36,211,69,76,105,
    21,211,75,21,219,38,45,119,55,216,93,28,90,81,150,64,
    235,38,202,10,27,21,215,38,109,157,67,210,105,217,60,108,
    105,184,108,169,60,105,125,136,149,141,142,224,210,132,240,98,
    60,233,145,162,22,253,154,88,213,132,91,197,175,133,146,185,
    172,202,76,214,159,69,89,40,8,149,13,42,2,170,226,39,
    90,230,147,177,183,40,180,54,67,170,100,42,33,117,70,150,
    201,86,93,103,164,193,200,138,208,8,54,24,89,157,33,248,
    172,50,178,54,67,214,132,94,103,100,157,145,7,66,227,179,
    193,200,6,35,155,66,227,179,197,200,22,217,188,141,68,123,
    212,63,251,152,246,197,84,254,136,180,5,186,212,31,69,110,
    9,231,246,218,175,46,14,236,14,70,125,115,3,50,27,201,
    44,5,169,141,189,144,195,56,11,47,28,137,111,99,201,163,
    255,149,140,213,57,152,54,173,243,3,135,51,200,67,236,41,
    98,84,228,34,144,206,36,32,155,38,149,87,81,22,131,76,
    139,100,8,185,125,38,103,151,139,148,227,194,147,67,105,172,
    84,161,51,151,202,129,150,102,36,85,73,128,240,81,17,199,
    220,250,118,167,176,118,141,196,129,210,242,19,150,166,225,132,
    117,180,119,119,113,106,29,163,111,185,113,48,159,163,205,181,
    215,225,73,106,239,113,174,44,200,35,136,213,196,80,251,237,
    19,28,186,76,139,56,143,99,149,130,149,99,204,180,129,30,
    237,11,59,161,29,191,176,219,231,228,167,26,53,158,6,137,
    18,41,86,58,7,107,165,83,195,24,246,101,159,55,181,76,
    1,52,74,26,101,185,76,138,216,153,49,58,49,189,202,245,
    246,101,134,63,206,175,12,82,43,44,188,150,119,135,163,236,
    36,73,239,145,74,54,193,77,198,192,231,34,188,190,14,34,
    52,2,114,182,224,76,229,42,225,137,83,72,178,124,66,221,
    226,195,52,140,47,2,75,73,3,19,106,89,153,213,239,90,
    198,51,39,135,1,55,160,156,153,25,72,47,200,113,145,32,
    86,101,217,21,249,59,207,128,12,229,140,156,254,242,49,117,
    47,219,204,1,123,29,148,242,248,156,185,45,218,136,104,85,
    160,23,188,188,151,99,76,108,247,102,189,172,121,120,87,182,
    241,110,120,141,202,182,135,183,143,177,223,109,18,63,166,156,
    116,94,140,201,42,203,218,40,203,179,235,9,159,254,247,67,
    228,134,38,116,191,158,178,213,199,168,130,233,243,34,247,193,
    150,215,124,83,254,159,189,125,74,111,33,96,197,195,187,182,
    227,255,3,50,72,97,124,
};

EmbeddedPython embedded_m5_objects_FlashDevice(
    "m5/objects/FlashDevice.py",
    "/home/zhoushuxin/gem5/src/dev/arm/FlashDevice.py",
    "m5.objects.FlashDevice",
    data_m5_objects_FlashDevice,
    775,
    1496);

} // anonymous namespace
