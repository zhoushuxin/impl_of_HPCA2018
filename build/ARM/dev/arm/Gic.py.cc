#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Gic[] = {
    120,156,165,85,95,111,27,69,16,159,243,127,59,118,226,20,
    18,120,65,108,121,64,6,137,216,77,233,3,18,160,18,74,
    163,72,208,70,151,22,9,191,156,206,119,107,123,163,187,219,
    211,237,58,177,121,66,42,159,128,79,192,55,133,153,57,223,
    217,73,8,82,21,59,222,236,204,206,238,252,249,253,102,55,
    128,245,167,138,191,231,194,1,243,55,78,66,252,115,32,2,
    120,179,158,57,249,172,2,81,5,226,42,140,171,224,144,92,
    133,168,6,113,29,198,245,92,174,65,212,128,184,1,227,6,
    202,117,144,117,152,58,16,54,224,79,128,119,0,191,141,155,
    16,54,65,54,89,219,42,181,45,8,219,32,171,172,237,148,
    218,54,132,59,197,9,221,82,219,129,176,7,23,131,93,12,
    82,253,131,159,129,131,51,75,195,151,249,180,141,195,133,138,
    95,79,46,101,96,55,170,115,165,95,200,43,21,200,92,213,
    34,85,228,219,169,206,98,219,68,225,196,55,242,84,5,193,
    118,57,78,168,28,67,156,72,128,177,67,69,25,87,40,206,
    113,141,106,130,57,203,6,92,98,62,45,184,108,83,109,222,
    85,0,227,115,47,6,180,217,173,225,96,62,160,98,202,171,
    161,159,197,195,9,186,240,102,42,56,154,207,141,216,242,47,
    236,92,25,17,114,116,2,103,169,159,89,161,167,71,131,157,
    34,82,207,75,252,88,122,158,237,176,16,235,112,17,145,72,
    46,236,42,149,60,121,147,45,36,91,251,19,99,51,63,176,
    108,29,44,151,222,92,250,161,204,108,157,124,250,153,31,187,
    20,159,109,228,162,76,172,37,217,79,86,188,59,93,71,53,
    160,42,108,6,67,227,112,174,99,57,252,125,174,23,102,190,
    88,170,100,56,147,241,179,161,201,130,97,145,35,150,240,40,
    93,113,238,95,209,46,58,177,225,240,183,146,7,16,61,253,
    102,116,183,202,127,221,170,50,213,183,10,178,6,151,117,170,
    44,18,141,138,219,40,52,8,64,157,53,77,214,180,136,99,
    200,44,210,180,183,52,173,53,36,27,77,155,53,59,172,233,
    18,219,144,99,164,233,177,102,23,228,30,145,141,52,125,2,
    178,71,64,238,81,34,31,110,1,137,24,122,41,229,129,72,
    42,232,195,167,230,35,92,253,33,12,51,105,140,192,226,137,
    80,33,4,106,178,176,58,83,224,160,193,222,45,131,32,93,
    48,104,79,70,137,97,50,188,144,145,191,226,165,243,179,215,
    34,27,94,11,171,183,143,49,159,221,103,132,71,9,149,88,
    153,77,253,64,154,199,55,204,88,159,45,82,75,134,51,201,
    255,126,60,127,171,254,160,148,70,56,188,90,196,19,153,33,
    219,182,76,35,149,72,35,204,34,77,117,102,101,40,6,177,
    191,20,223,137,39,163,227,209,23,230,16,55,253,148,248,147,
    72,10,2,95,200,165,149,137,81,58,49,131,125,42,22,97,
    236,18,181,92,234,42,151,40,232,50,143,107,235,10,112,55,
    82,98,158,79,18,17,4,51,200,5,218,242,179,143,7,6,
    43,187,91,152,165,74,123,33,101,100,123,107,219,141,134,78,
    198,192,189,104,189,137,28,191,61,75,236,211,99,62,88,225,
    10,37,195,206,79,180,142,152,130,47,253,200,72,75,136,80,
    6,222,86,6,15,161,60,157,247,53,237,122,84,80,190,242,
    200,217,124,57,84,52,189,58,142,95,98,11,202,187,45,112,
    250,126,45,80,161,46,184,209,2,216,17,14,241,31,121,203,
    0,124,82,68,179,205,91,244,207,172,165,181,3,42,6,5,
    35,46,206,207,4,93,79,34,97,62,48,202,155,21,171,173,
    31,21,75,7,183,152,60,101,51,228,227,160,243,127,248,187,
    31,23,151,153,73,149,71,190,24,109,18,34,153,184,251,5,
    69,136,7,15,194,129,178,126,78,187,58,229,213,195,245,111,
    148,245,191,91,250,95,222,163,244,229,125,95,43,46,151,29,
    186,74,102,80,92,73,189,18,128,199,247,3,224,246,105,109,
    255,191,122,154,59,29,35,21,58,17,215,115,21,204,169,105,
    241,26,152,205,228,86,67,27,67,137,158,235,235,188,123,237,
    181,94,3,68,18,99,98,248,145,188,31,16,186,209,184,25,
    203,118,226,107,219,237,210,64,173,198,207,2,134,204,212,253,
    21,95,83,157,229,207,7,121,230,122,174,253,60,4,46,170,
    209,233,13,184,176,109,14,156,87,249,227,71,225,197,207,142,
    82,114,107,152,61,36,101,122,185,178,221,92,40,159,122,215,
    41,162,202,223,121,183,66,121,148,47,49,247,39,71,206,46,
    31,18,51,199,241,109,254,8,127,255,57,237,38,48,59,78,
    199,233,87,250,248,59,108,30,118,15,155,255,2,70,60,255,
    59,
};

EmbeddedPython embedded_m5_objects_Gic(
    "m5/objects/Gic.py",
    "/home/zhoushuxin/gem5/src/dev/arm/Gic.py",
    "m5.objects.Gic",
    data_m5_objects_Gic,
    1041,
    2393);

} // anonymous namespace