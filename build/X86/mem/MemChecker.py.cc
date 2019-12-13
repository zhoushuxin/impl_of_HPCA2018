#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_MemChecker[] = {
    120,156,165,83,77,111,211,64,16,157,141,29,39,77,3,13,
    21,226,192,201,18,18,178,64,138,79,189,33,4,69,66,226,
    80,168,28,36,68,46,214,214,158,98,23,219,27,121,55,109,
    194,53,252,111,152,25,167,137,34,184,213,214,142,230,99,119,
    230,189,153,221,12,182,159,71,235,93,168,192,230,164,208,202,
    21,84,0,53,192,28,64,177,221,131,74,65,221,131,121,175,
    179,61,168,60,248,186,213,124,210,124,192,30,92,43,200,251,
    240,27,96,3,240,125,222,135,60,0,4,241,14,118,222,0,
    242,33,204,162,35,42,84,254,161,47,82,164,57,54,47,176,
    254,114,117,131,153,219,187,102,229,129,139,197,43,55,234,246,
    126,40,48,251,137,109,118,207,129,131,231,204,225,41,41,84,
    118,174,152,9,1,38,50,115,15,146,89,212,163,64,194,84,
    237,41,137,26,235,152,86,154,117,121,166,69,17,249,92,100,
    72,34,77,27,93,99,154,74,173,52,173,77,190,172,216,148,
    13,235,5,138,63,91,173,210,2,117,142,109,196,245,247,194,
    190,38,17,23,166,198,248,87,97,150,182,88,174,202,38,254,
    129,245,89,108,219,140,139,198,123,252,211,197,90,48,241,25,
    203,249,3,21,40,247,228,128,227,133,105,74,103,246,84,189,
    123,170,248,95,170,232,243,192,54,164,247,1,3,30,17,235,
    3,209,125,209,135,178,167,47,250,17,224,8,110,142,1,199,
    60,175,13,205,248,145,120,30,243,212,120,195,9,247,142,187,
    146,176,176,207,255,237,29,53,72,0,82,15,237,49,35,215,
    214,97,27,46,76,235,44,119,106,86,233,91,236,204,19,50,
    223,87,165,182,225,181,105,67,203,1,59,57,240,213,114,88,
    202,124,211,109,19,234,43,179,116,225,109,105,42,237,74,211,
    216,208,52,213,218,190,160,240,167,198,58,221,100,24,218,66,
    183,152,135,119,165,43,66,227,10,42,189,5,100,35,206,157,
    112,91,147,62,139,128,197,128,167,56,218,225,188,36,92,142,
    3,93,229,238,226,49,48,9,240,49,129,41,23,35,91,44,
    83,91,230,157,193,29,16,131,247,92,234,86,215,114,65,206,
    141,169,196,245,81,87,22,37,221,29,17,73,25,183,140,90,
    106,211,225,109,247,30,122,123,24,74,204,7,39,219,219,19,
    120,99,213,253,167,234,115,196,108,19,78,236,198,92,246,108,
    186,123,84,201,238,157,145,119,193,248,109,199,139,172,214,172,
    58,176,146,254,129,16,37,235,155,238,21,189,125,201,9,184,
    3,19,53,81,35,53,234,61,243,255,2,23,202,254,115,
};

EmbeddedPython embedded_m5_objects_MemChecker(
    "m5/objects/MemChecker.py",
    "/home/zhoushuxin/gem5/src/mem/MemChecker.py",
    "m5.objects.MemChecker",
    data_m5_objects_MemChecker,
    575,
    1160);

} // anonymous namespace
