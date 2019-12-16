#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_SimpleLink[] = {
    120,156,181,82,77,75,195,64,16,157,205,87,211,162,224,65,
    122,20,65,196,224,161,123,234,77,84,4,15,130,40,164,94,
    204,37,164,201,106,210,102,147,144,77,48,241,170,255,91,119,
    54,233,135,55,11,186,36,143,153,151,205,236,188,217,23,66,
    191,116,249,94,31,19,16,11,25,68,242,33,144,2,60,245,
    17,233,34,13,82,13,184,14,158,14,4,115,29,82,3,184,
    9,158,9,220,2,207,146,172,1,204,130,23,2,145,9,159,
    0,31,0,207,222,0,34,11,152,169,216,193,154,181,33,178,
    97,230,12,229,113,201,151,92,14,145,81,133,112,222,133,248,
    101,150,240,199,249,130,133,149,163,33,181,39,225,38,16,73,
    120,151,85,247,73,182,220,16,183,77,71,236,119,63,21,41,
    235,153,112,37,16,107,222,160,192,67,25,48,0,143,160,76,
    79,67,125,82,143,59,83,71,184,134,4,113,42,129,51,78,
    203,122,222,210,140,85,111,121,185,164,66,149,165,93,117,44,
    61,137,99,7,183,87,182,4,223,207,2,206,124,191,26,169,
    132,231,81,157,98,170,54,180,5,83,124,216,52,126,204,130,
    136,149,14,182,180,1,113,37,129,198,57,103,244,61,206,107,
    17,215,77,146,209,87,198,167,84,148,33,253,69,47,69,171,
    90,63,193,98,24,88,196,34,91,211,232,7,182,235,52,134,
    187,79,195,53,17,44,132,1,130,253,67,232,223,169,197,214,
    206,182,213,62,40,47,41,219,240,233,164,8,202,128,11,117,
    53,152,149,121,211,42,183,200,100,109,42,119,237,51,229,33,
    172,236,42,217,250,202,9,234,148,127,232,94,245,117,209,153,
    228,242,8,139,162,61,70,100,68,14,200,88,27,27,223,195,
    154,204,156,
};

EmbeddedPython embedded_m5_objects_SimpleLink(
    "m5/objects/SimpleLink.py",
    "/home/zhoushuxin/gem5/src/mem/ruby/network/simple/SimpleLink.py",
    "m5.objects.SimpleLink",
    data_m5_objects_SimpleLink,
    387,
    919);

} // anonymous namespace