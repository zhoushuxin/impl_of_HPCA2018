#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_X86NativeTrace[] = {
    120,156,173,144,207,75,195,48,20,199,95,218,110,234,20,217,
    69,4,65,208,91,241,176,94,220,24,67,68,212,243,148,78,
    65,123,41,49,141,166,210,108,163,201,164,243,170,255,183,190,
    151,218,233,238,166,205,151,239,251,193,227,147,39,224,231,248,
    120,47,142,24,152,107,52,25,254,12,10,0,205,32,97,192,
    40,246,160,240,224,142,156,15,133,15,58,128,36,192,74,0,
    50,128,103,6,89,11,62,1,62,0,30,147,22,100,109,152,
    132,27,56,40,255,194,19,50,116,118,11,101,146,235,155,167,
    87,41,108,157,34,57,169,237,54,202,152,219,252,77,222,149,
    92,72,187,139,241,195,112,240,39,37,26,82,234,191,36,210,
    3,52,18,8,16,169,18,143,144,19,159,64,17,44,158,132,
    244,162,152,196,236,161,184,25,163,209,250,76,179,143,21,94,
    10,21,85,195,65,52,117,5,75,133,158,82,97,139,184,54,
    81,210,116,202,181,76,83,219,113,129,158,101,139,130,194,128,
    26,150,115,233,158,38,170,42,21,5,55,198,117,81,164,36,
    207,100,25,18,242,175,152,83,148,72,205,180,140,222,213,108,
    97,212,162,202,167,209,139,212,253,200,148,34,90,177,172,115,
    246,230,75,247,146,99,154,208,70,105,51,250,198,33,121,187,
    131,162,251,189,213,114,99,104,246,141,217,57,47,185,174,161,
    174,110,239,221,180,210,196,94,179,155,255,194,115,139,58,171,
    87,115,126,216,96,118,89,135,117,189,111,140,226,132,143,
};

EmbeddedPython embedded_m5_objects_X86NativeTrace(
    "m5/objects/X86NativeTrace.py",
    "/home/zhoushuxin/gem5/src/arch/x86/X86NativeTrace.py",
    "m5.objects.X86NativeTrace",
    data_m5_objects_X86NativeTrace,
    335,
    612);

} // anonymous namespace