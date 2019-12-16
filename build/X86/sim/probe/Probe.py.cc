#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Probe[] = {
    120,156,165,144,77,79,195,48,12,134,157,174,235,62,196,1,
    193,31,224,88,16,90,79,187,161,9,113,230,75,27,23,122,
    169,178,214,172,157,150,182,74,50,169,227,58,254,55,216,201,
    198,184,147,182,111,109,203,241,251,36,57,28,86,143,190,251,
    43,1,102,70,65,65,175,128,13,128,18,144,10,16,156,7,
    176,9,224,237,16,245,40,234,1,10,248,16,80,132,240,5,
    176,7,120,79,67,40,250,176,136,35,26,81,125,211,138,5,
    69,118,68,178,168,212,203,114,141,185,245,37,150,27,123,73,
    250,170,155,37,62,86,198,98,141,218,183,228,127,153,30,152,
    233,154,2,4,70,33,255,52,96,184,148,236,67,88,247,1,
    35,88,15,24,106,31,64,58,132,249,34,230,109,243,128,196,
    92,176,84,42,105,217,196,235,164,44,237,217,209,247,73,214,
    114,133,58,102,66,59,36,201,178,90,42,204,50,59,118,137,
    106,138,237,134,211,144,27,118,45,186,122,222,117,89,137,178,
    64,109,251,60,73,106,169,230,204,107,35,159,98,109,45,67,
    200,122,103,7,244,87,7,27,238,57,137,185,37,73,202,70,
    97,242,89,54,91,83,110,187,170,78,86,168,166,137,209,121,
    114,226,118,168,147,118,231,206,196,155,12,251,68,130,159,231,
    152,17,220,137,212,116,242,123,203,30,103,228,171,45,3,26,
    119,62,206,116,211,249,81,255,229,113,19,239,252,29,205,226,
    35,215,185,24,139,113,240,3,164,159,128,58,
};

EmbeddedPython embedded_m5_objects_Probe(
    "m5/objects/Probe.py",
    "/home/zhoushuxin/gem5/src/sim/probe/Probe.py",
    "m5.objects.Probe",
    data_m5_objects_Probe,
    332,
    600);

} // anonymous namespace