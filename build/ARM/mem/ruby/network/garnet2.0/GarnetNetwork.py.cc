#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_GarnetNetwork[] = {
    120,156,181,85,219,146,219,68,16,109,249,126,219,75,118,83,
    91,16,10,50,15,164,48,33,107,133,133,188,108,81,20,108,
    150,80,169,10,75,74,73,10,226,23,149,44,141,45,57,35,
    141,75,51,114,214,121,13,79,124,16,63,192,135,65,247,72,
    178,189,54,21,246,33,177,236,182,250,104,52,234,62,125,186,
    229,67,241,169,226,239,7,102,129,250,19,79,2,252,90,32,
    0,158,23,103,86,126,86,1,81,129,184,10,195,42,88,228,
    87,65,212,32,174,193,176,150,251,53,16,117,136,235,48,172,
    163,95,7,94,133,177,5,65,3,254,0,120,11,240,114,216,
    128,160,9,188,110,208,214,18,109,66,208,6,94,51,104,103,
    137,182,32,232,194,179,126,15,195,137,254,193,79,223,194,51,
    77,230,110,126,218,69,227,100,163,197,5,215,175,101,250,106,
    5,158,121,42,242,29,153,105,158,230,224,14,154,135,66,250,
    175,120,240,235,104,202,125,109,144,159,189,52,225,186,184,219,
    95,231,225,140,120,248,11,79,56,192,208,34,54,134,21,162,
    1,211,198,48,167,117,34,2,115,127,91,1,204,136,144,38,
    165,142,9,19,210,42,17,147,44,33,237,53,164,101,144,78,
    137,180,41,99,66,186,107,59,119,13,210,51,200,14,240,93,
    8,122,6,217,51,200,62,240,27,16,236,24,228,160,220,7,
    215,236,25,228,16,156,103,253,125,98,166,134,70,125,133,38,
    230,177,157,34,79,118,146,167,106,79,76,226,39,131,251,246,
    21,10,6,97,24,17,3,234,24,77,146,197,35,158,50,57,
    102,169,124,173,88,52,102,39,231,172,31,115,21,218,90,166,
    153,178,7,131,47,153,150,51,41,228,100,17,209,3,213,231,
    116,91,190,21,139,18,36,127,236,249,156,141,69,164,153,138,
    222,112,196,216,104,161,185,138,106,229,234,121,148,234,204,19,
    204,15,189,36,225,66,177,25,62,178,4,139,173,20,195,133,
    163,108,60,230,105,126,61,240,180,199,54,238,140,168,204,91,
    43,125,157,138,205,149,234,11,92,116,255,148,253,198,163,73,
    168,143,71,158,226,1,123,238,141,4,191,199,190,62,101,191,
    191,188,199,78,78,217,195,76,105,25,171,91,36,129,132,46,
    150,209,176,177,151,9,205,98,25,224,86,135,107,9,175,225,
    209,211,191,139,96,138,139,199,130,207,185,96,1,247,2,18,
    33,211,97,138,60,74,17,244,111,146,58,91,104,92,55,241,
    98,238,186,186,99,28,220,39,19,228,18,85,122,49,227,6,
    247,47,47,221,16,55,225,169,174,163,251,212,75,189,88,147,
    94,31,39,218,236,130,69,115,169,92,186,129,206,11,68,191,
    57,209,212,63,73,228,82,25,92,42,131,1,230,190,114,145,
    33,119,142,17,234,195,21,109,6,36,130,221,185,191,133,19,
    157,132,223,64,60,197,238,138,146,137,235,137,137,76,35,29,
    198,38,210,51,41,133,9,237,145,39,20,215,7,75,250,92,
    67,143,107,232,49,169,60,34,255,23,227,210,141,23,47,158,
    60,49,173,187,190,238,99,244,115,169,186,37,117,238,138,58,
    82,234,202,168,159,208,216,161,140,185,253,38,148,153,10,179,
    203,40,177,39,60,126,96,171,212,183,175,221,2,179,133,233,
    155,59,180,37,85,191,97,209,113,176,60,218,120,228,255,250,
    104,115,132,60,46,53,191,61,75,194,255,156,37,216,235,56,
    56,113,28,78,27,102,156,32,216,44,92,222,130,105,155,134,
    74,49,63,150,96,167,28,51,221,53,176,71,163,37,159,25,
    216,253,77,234,126,34,79,83,91,110,6,167,6,239,30,9,
    155,235,113,42,168,187,164,177,115,106,224,148,11,79,71,50,
    193,214,103,82,135,216,100,91,29,175,174,223,218,183,174,12,
    154,205,171,215,107,33,154,228,14,105,206,33,209,59,148,188,
    110,23,205,226,11,79,41,135,58,195,33,200,33,233,235,10,
    189,80,2,211,34,216,65,60,209,206,46,193,171,88,92,57,
    118,139,88,220,50,22,179,37,129,132,40,231,163,43,226,123,
    223,10,164,218,125,75,91,222,92,42,176,81,217,179,122,168,
    186,252,103,122,56,191,45,127,205,109,43,238,252,127,21,199,
    155,48,109,149,175,177,214,26,184,212,93,135,212,100,168,165,
    74,24,198,242,199,153,10,191,35,163,124,21,41,231,61,73,
    161,223,221,174,178,243,9,153,171,197,117,62,37,67,245,116,
    62,35,115,251,131,214,137,88,249,145,182,220,93,213,169,168,
    208,69,191,93,10,49,126,48,152,209,164,86,102,68,147,151,
    202,203,133,110,174,122,211,161,183,151,67,186,116,168,126,102,
    2,25,17,152,39,124,176,248,77,60,223,229,175,154,239,111,
    151,121,116,172,142,181,79,71,229,104,239,104,231,95,192,99,
    126,16,
};

EmbeddedPython embedded_m5_objects_GarnetNetwork(
    "m5/objects/GarnetNetwork.py",
    "/home/zhoushuxin/gem5/src/mem/ruby/network/garnet2.0/GarnetNetwork.py",
    "m5.objects.GarnetNetwork",
    data_m5_objects_GarnetNetwork,
    1058,
    2591);

} // anonymous namespace
