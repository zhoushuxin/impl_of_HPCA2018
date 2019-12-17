#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_X86KvmCPU[] = {
    120,156,165,82,77,111,211,64,16,157,181,19,231,3,4,136,
    59,146,185,89,32,197,167,86,61,160,10,37,80,169,66,133,
    200,110,80,201,197,114,237,33,118,201,122,45,239,58,114,122,
    13,255,27,102,215,222,242,3,216,181,71,239,141,71,59,111,
    222,58,131,97,185,244,126,244,25,200,75,2,57,61,12,246,
    0,183,3,98,61,114,96,239,0,119,96,235,0,203,93,64,
    7,126,50,200,71,240,27,224,4,240,99,235,66,62,134,56,
    240,232,136,242,15,173,128,17,82,58,188,235,225,156,194,50,
    149,248,229,192,87,235,141,154,17,189,187,56,239,89,102,165,
    76,116,145,150,114,79,0,1,182,76,11,162,158,164,132,90,
    224,72,11,57,49,3,92,11,70,22,140,45,240,44,152,104,
    176,243,96,59,6,244,224,97,2,56,133,124,10,39,154,99,
    6,81,28,104,21,145,67,65,190,166,144,213,109,248,235,192,
    195,238,226,60,33,188,40,10,245,76,91,210,242,250,170,110,
    35,220,201,39,126,93,41,195,159,15,60,174,49,51,137,233,
    144,184,91,69,210,12,105,72,156,30,80,189,24,216,247,85,
    221,126,62,96,165,164,124,79,169,141,68,223,20,248,74,248,
    242,88,101,69,35,170,242,17,253,171,245,38,140,175,111,62,
    249,13,238,74,169,176,145,129,54,209,180,72,146,42,229,152,
    36,198,214,36,225,34,111,247,154,142,116,193,177,70,147,207,
    186,46,41,48,205,177,49,58,215,199,101,89,229,55,168,10,
    145,155,65,244,119,236,106,209,40,169,198,186,32,109,82,110,
    142,88,10,177,55,224,182,105,209,52,108,37,26,145,129,190,
    166,127,65,46,40,132,133,224,24,62,22,162,149,69,219,149,
    85,184,67,126,22,202,38,11,173,163,79,55,189,168,143,198,
    239,183,214,115,143,209,118,103,204,238,151,238,215,192,12,161,
    189,227,103,139,90,107,234,125,38,22,151,252,219,253,3,102,
    42,98,246,230,254,95,144,153,239,67,111,225,229,27,125,134,
    254,139,231,108,206,94,57,127,1,59,194,178,153,
};

EmbeddedPython embedded_m5_objects_X86KvmCPU(
    "m5/objects/X86KvmCPU.py",
    "/home/zhoushuxin/gem5/src/cpu/kvm/X86KvmCPU.py",
    "m5.objects.X86KvmCPU",
    data_m5_objects_X86KvmCPU,
    461,
    805);

} // anonymous namespace