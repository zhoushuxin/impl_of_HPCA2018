#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Sequencer[] = {
    120,156,173,86,91,111,227,68,20,30,59,183,38,233,53,109,
    179,101,175,35,4,40,128,212,72,72,11,15,32,180,108,87,
    43,241,80,40,238,130,68,95,44,215,158,214,46,190,100,61,
    147,170,225,9,169,252,17,36,126,36,111,112,190,227,75,220,
    109,119,95,216,184,157,156,249,102,230,204,185,126,142,47,202,
    79,139,254,159,73,75,232,63,72,8,232,207,18,177,16,175,
    74,201,42,36,91,196,182,72,108,113,98,11,43,104,9,101,
    139,51,75,4,109,241,167,16,215,66,252,122,210,18,65,71,
    168,22,163,221,26,109,139,160,87,161,43,53,218,17,65,191,
    66,7,53,218,21,193,80,28,79,86,201,136,232,95,250,76,
    44,146,12,134,207,10,177,79,195,161,74,126,60,189,80,190,
    49,43,52,115,230,167,139,163,44,55,126,211,149,231,112,229,
    31,18,148,16,39,22,28,34,155,233,54,24,99,9,186,92,
    117,197,69,15,30,145,31,215,228,209,138,80,125,184,114,77,
    171,3,161,134,240,4,242,170,80,107,112,6,242,122,67,222,
    16,106,19,126,65,222,98,121,133,229,17,107,222,22,106,167,
    210,188,123,11,25,51,114,79,168,61,113,241,65,5,222,103,
    240,65,5,246,25,124,88,157,109,33,72,64,30,53,144,33,
    35,143,27,200,42,35,79,132,115,60,89,67,104,108,26,244,
    3,26,18,149,76,115,10,212,84,47,180,33,185,10,218,126,
    24,70,136,153,193,160,215,105,56,56,250,89,234,216,187,84,
    114,70,235,122,163,132,18,143,206,229,5,182,83,70,93,146,
    214,27,11,219,213,194,44,202,154,74,54,27,7,178,124,81,
    128,48,176,176,70,102,156,77,253,8,165,231,25,79,250,158,
    31,42,153,171,215,115,165,141,150,122,62,195,9,21,240,142,
    40,213,230,237,59,70,180,195,207,210,148,244,169,64,154,76,
    146,182,217,124,34,225,35,170,197,117,83,47,81,174,107,6,
    60,73,178,96,30,99,218,198,134,197,76,177,240,42,159,43,
    222,237,157,106,147,123,84,104,216,237,95,93,185,161,242,2,
    149,155,14,77,143,188,220,75,12,138,237,251,212,152,30,125,
    95,170,92,71,89,106,16,179,95,200,128,44,63,70,12,16,
    103,62,193,17,49,155,245,234,33,135,142,151,187,200,17,79,
    249,170,198,10,148,81,56,221,98,213,157,85,24,133,242,6,
    134,198,88,94,183,94,158,226,43,139,13,235,229,161,6,4,
    95,159,103,89,204,214,189,244,98,173,204,22,73,115,29,165,
    231,46,202,197,53,138,109,2,154,102,110,174,76,190,112,179,
    212,213,198,139,99,182,20,105,61,230,44,178,15,20,20,69,
    209,64,84,188,116,97,134,244,205,122,244,114,75,99,119,137,
    66,123,153,65,23,249,167,123,94,235,27,40,114,94,160,136,
    94,164,93,202,169,171,145,253,212,87,249,4,197,187,28,244,
    151,52,76,195,44,81,211,223,195,108,174,195,249,85,148,78,
    207,85,242,116,170,115,127,250,102,43,28,87,106,246,103,11,
    110,152,15,161,3,67,215,42,158,145,189,106,213,143,61,178,
    70,214,46,61,248,54,107,13,2,58,202,179,171,69,205,66,
    86,197,66,59,111,176,16,248,167,133,14,197,93,206,71,184,
    76,190,163,67,89,43,181,233,4,201,114,120,64,182,28,196,
    207,233,223,112,252,127,123,15,99,190,130,142,118,233,125,237,
    95,189,237,54,203,254,125,167,127,196,172,196,181,170,35,46,
    186,204,112,4,246,110,78,87,120,202,164,11,174,181,153,119,
    107,164,203,200,144,145,85,16,45,248,149,144,181,106,79,191,
    98,196,117,70,10,62,46,168,116,171,58,53,172,24,113,84,
    51,226,199,213,75,164,246,72,63,188,35,250,203,176,132,161,
    3,87,35,228,83,143,185,219,107,254,9,35,35,99,207,208,
    198,5,47,189,88,146,87,99,41,66,205,234,207,185,195,175,
    150,156,53,137,82,63,222,151,179,92,157,41,67,71,244,167,
    50,155,27,234,172,52,160,246,139,228,95,61,161,95,150,135,
    26,11,210,95,248,177,210,242,44,203,137,219,74,109,242,84,
    209,92,201,128,232,41,206,252,223,166,113,116,169,32,16,226,
    199,212,147,65,132,196,49,17,31,208,198,35,47,202,165,143,
    19,81,48,217,190,93,88,28,33,240,29,29,214,154,203,204,
    25,84,56,234,225,0,78,114,15,71,126,45,6,75,241,128,
    141,52,163,122,131,75,1,113,203,128,48,28,220,130,29,176,
    133,217,43,92,118,27,46,187,85,204,138,131,165,143,174,9,
    115,165,195,44,14,156,123,176,10,7,153,52,206,189,60,85,
    198,229,211,94,156,165,133,69,240,150,156,125,127,205,130,74,
    250,26,58,238,47,169,194,222,176,54,58,32,134,126,249,140,
    90,6,191,101,94,28,126,247,142,14,250,228,206,14,82,109,
    113,209,105,252,66,233,162,134,57,77,95,224,214,39,119,84,
    109,243,26,188,217,159,97,227,222,29,53,84,5,116,210,123,
    11,169,112,182,57,33,206,254,251,229,24,24,255,19,116,116,
    235,176,253,192,102,112,109,37,79,247,103,120,175,106,126,253,
    98,6,250,115,208,124,78,205,151,28,122,86,244,254,236,226,
    251,190,41,126,14,124,251,24,186,144,183,129,53,176,54,237,
    241,238,184,61,30,255,7,164,216,168,166,
};

EmbeddedPython embedded_m5_objects_Sequencer(
    "m5/objects/Sequencer.py",
    "/home/zhoushuxin/gem5/src/mem/ruby/system/Sequencer.py",
    "m5.objects.Sequencer",
    data_m5_objects_Sequencer,
    1179,
    2859);

} // anonymous namespace
