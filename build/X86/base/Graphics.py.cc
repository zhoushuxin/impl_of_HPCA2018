#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Graphics[] = {
    120,156,165,80,61,79,132,64,16,125,11,220,69,79,11,59,
    91,43,67,206,228,104,188,206,24,189,68,205,53,106,192,70,
    26,178,7,43,96,88,32,236,98,212,86,255,183,206,128,95,
    189,147,221,151,153,217,153,121,111,54,197,151,185,116,207,14,
    4,204,49,57,25,29,129,10,208,2,177,128,224,216,65,229,
    224,46,115,161,92,60,8,100,30,222,129,55,224,62,246,144,
    77,16,249,83,106,44,63,200,124,65,158,221,38,136,74,125,
    179,121,84,169,29,83,12,115,187,67,184,214,50,87,151,77,
    167,165,77,255,42,88,177,130,125,114,20,152,120,212,65,212,
    185,139,216,65,24,249,92,100,61,130,243,222,54,150,41,87,
    165,213,178,181,252,112,91,231,99,193,22,65,146,212,82,171,
    36,177,179,33,208,77,214,87,28,114,243,147,172,140,207,156,
    191,96,230,4,65,209,104,21,188,22,77,111,138,254,185,172,
    131,92,233,101,96,186,52,216,72,163,130,171,78,182,69,153,
    154,69,251,18,58,84,126,196,125,236,76,113,237,79,152,120,
    151,64,47,23,63,123,135,248,254,10,202,182,178,147,218,12,
    2,46,234,94,15,35,254,167,98,88,244,100,92,237,244,144,
    251,121,248,158,152,121,159,73,253,95,217,
};

EmbeddedPython embedded_m5_objects_Graphics(
    "m5/objects/Graphics.py",
    "/home/zhoushuxin/gem5/src/base/Graphics.py",
    "m5.objects.Graphics",
    data_m5_objects_Graphics,
    283,
    472);

} // anonymous namespace
