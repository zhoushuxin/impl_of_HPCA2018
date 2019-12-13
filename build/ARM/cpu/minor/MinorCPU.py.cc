#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_MinorCPU[] = {
    120,156,197,90,91,115,28,73,177,174,25,93,70,35,75,214,
    197,150,228,235,186,246,102,141,118,189,210,218,176,203,66,176,
    128,124,17,225,115,108,175,104,73,108,160,0,134,86,119,205,
    76,219,125,153,237,170,150,165,13,32,136,48,65,4,17,60,
    0,63,128,55,30,8,30,8,30,32,130,135,243,27,206,15,
    224,199,156,147,153,85,213,93,51,186,172,119,87,103,143,199,
    110,119,101,85,101,103,101,101,125,153,157,217,1,51,127,70,
    224,223,247,120,141,201,255,174,49,22,194,223,26,139,25,75,
    106,108,183,198,106,216,174,179,184,206,146,17,182,59,162,219,
    35,44,30,101,219,230,110,76,223,141,178,120,156,37,13,182,
    219,208,99,198,88,60,193,146,9,182,59,161,219,227,44,110,
    178,164,201,118,155,37,143,73,61,179,193,226,115,44,57,199,
    118,207,233,158,9,22,79,177,100,154,237,78,67,187,201,68,
    131,117,106,44,156,100,191,102,236,5,99,63,218,61,207,194,
    115,150,58,85,82,103,88,56,109,169,231,75,234,44,11,103,
    176,177,59,199,194,89,219,61,87,118,207,179,112,222,82,47,
    148,212,11,44,188,200,196,60,81,23,74,234,69,22,46,90,
    234,82,73,93,96,225,37,75,189,92,82,23,89,120,197,82,
    175,150,212,37,22,94,179,212,235,37,245,18,11,95,177,212,
    27,37,245,50,11,57,19,23,136,250,106,73,189,194,194,215,
    152,184,74,212,215,75,234,53,22,190,193,196,4,81,223,44,
    169,215,89,120,147,109,181,150,97,115,163,255,129,63,45,216,
    92,166,206,195,165,159,71,169,106,119,138,52,80,81,150,106,
    250,4,92,246,138,40,14,31,164,251,154,130,151,183,244,109,
    19,46,91,81,242,209,222,83,17,40,77,106,192,229,174,47,
    197,189,205,29,77,152,130,203,253,34,73,14,239,245,68,240,
    76,228,154,58,9,151,237,40,137,210,238,131,131,126,94,77,
    253,168,127,47,246,165,164,89,143,163,52,203,13,33,176,54,
    89,71,254,104,147,43,112,35,24,154,34,216,198,110,29,141,
    19,204,16,76,114,119,148,137,49,246,116,28,77,233,69,13,
    237,206,219,106,141,194,104,25,227,220,236,0,30,202,179,14,
    55,156,185,202,120,87,40,238,231,89,145,134,156,214,202,251,
    121,182,23,139,68,114,63,165,198,126,20,10,238,243,94,150,
    61,227,157,44,159,228,240,167,83,168,34,7,106,24,70,168,
    46,98,100,121,6,184,86,233,161,242,228,34,92,130,126,177,
    150,224,114,214,80,187,237,34,141,212,106,175,39,231,160,43,
    235,243,192,202,145,248,42,232,181,38,172,222,219,237,212,79,
    68,187,77,218,106,183,147,44,44,98,108,54,168,25,102,1,
    220,227,194,212,97,95,208,152,224,224,160,221,19,126,40,114,
    53,6,205,77,63,247,19,175,97,117,155,105,225,90,168,198,
    234,34,215,224,178,214,203,18,177,246,105,47,43,100,175,0,
    5,173,117,69,242,222,154,204,131,181,74,114,218,14,216,214,
    213,254,33,45,236,3,156,140,55,227,117,248,213,198,235,106,
    102,104,211,182,132,42,247,109,196,238,219,173,207,220,183,46,
    161,192,139,186,187,117,215,225,178,206,37,236,19,236,28,169,
    201,135,13,226,86,121,66,122,179,159,161,235,15,28,93,11,
    210,246,158,208,156,68,184,202,249,122,202,69,210,87,135,60,
    142,164,226,137,240,83,220,252,67,61,158,182,196,67,107,247,
    80,205,222,57,188,160,137,122,211,168,92,108,254,16,78,64,
    150,107,141,79,216,179,97,52,46,206,68,231,184,192,245,82,
    231,53,163,243,105,171,243,141,29,125,158,142,106,252,159,199,
    106,92,140,178,167,99,168,119,163,235,113,135,50,106,180,143,
    148,9,38,154,136,218,72,153,36,202,57,26,51,78,148,41,
    162,0,192,158,71,188,70,202,140,51,102,130,40,128,175,115,
    68,105,210,121,156,167,1,23,16,196,0,143,0,191,113,204,
    69,34,46,32,130,3,118,35,101,17,247,30,87,231,93,56,
    125,103,35,210,232,53,184,36,190,164,227,201,149,144,10,79,
    249,131,3,245,216,15,122,15,83,169,228,125,26,0,219,205,
    247,253,184,16,39,141,251,22,111,137,3,213,78,160,217,142,
    160,205,111,114,100,187,194,63,252,80,91,139,92,69,224,236,
    112,149,23,226,22,87,189,72,114,28,183,202,225,38,205,20,
    23,7,34,40,148,0,36,57,212,189,27,59,242,109,220,129,
    3,149,251,60,56,12,98,109,125,82,249,113,204,131,44,73,
    34,165,133,41,89,145,121,12,140,247,225,47,207,139,244,29,
    21,37,130,11,92,129,143,207,16,0,158,66,74,132,159,127,
    31,243,12,192,38,122,84,144,229,98,47,243,243,144,231,66,
    69,0,90,196,102,224,161,146,135,160,12,232,239,130,253,139,
    92,242,44,13,4,7,209,98,225,239,35,183,30,76,48,158,
    193,143,57,233,158,243,13,96,145,136,4,166,117,228,45,142,
    90,33,126,146,191,123,139,102,128,112,69,172,150,165,126,32,
    208,19,63,127,6,114,195,122,138,20,68,15,163,64,209,65,
    70,156,77,51,20,233,57,136,137,123,18,248,41,87,254,51,
    193,251,177,31,136,85,137,219,140,44,19,255,32,74,138,132,
    167,69,178,39,114,132,3,171,163,14,200,93,238,133,132,45,
    86,61,31,246,3,118,146,195,169,194,165,17,83,56,246,254,
    190,31,197,244,220,65,197,163,178,104,170,252,143,227,208,34,
    0,53,131,35,0,177,171,121,161,8,178,80,184,0,130,32,
    53,132,31,138,76,20,13,7,148,28,228,81,31,181,8,22,
    144,27,87,132,235,34,70,208,94,211,146,104,220,89,26,196,
    157,18,114,60,116,215,106,28,46,59,15,83,245,254,215,201,
    13,160,157,18,238,147,157,18,233,110,150,197,68,218,240,99,
    144,139,252,81,209,39,155,161,217,247,72,117,228,252,201,118,
    238,145,57,62,242,149,135,189,196,226,201,206,163,71,106,254,
    200,0,116,219,4,248,68,94,7,165,37,34,196,137,232,211,
    20,29,217,60,240,68,87,122,34,246,85,180,47,160,79,131,
    180,55,111,101,223,34,5,16,124,58,122,57,11,172,196,231,
    227,22,202,75,26,43,1,41,231,107,243,117,243,27,157,25,
    153,170,53,235,65,205,196,19,168,160,123,136,148,55,24,5,
    185,16,41,253,162,198,20,5,184,16,238,252,28,254,50,196,
    164,23,172,182,213,66,88,149,223,67,212,69,227,244,249,144,
    195,227,157,60,75,128,76,110,196,137,50,4,216,171,65,30,
    189,239,146,30,95,51,64,189,133,143,39,103,66,18,224,243,
    240,97,40,221,19,15,213,76,33,18,121,150,42,46,203,250,
    237,96,208,163,127,17,101,81,228,176,151,29,24,73,59,200,
    6,159,203,106,180,83,36,3,109,156,26,33,219,234,19,133,
    102,89,1,192,253,190,241,165,55,141,140,134,168,168,217,74,
    163,33,242,67,75,100,245,230,8,5,50,198,223,29,245,116,
    159,156,226,233,32,182,120,65,59,90,57,187,6,250,62,227,
    236,38,28,138,118,118,240,134,49,137,110,171,203,28,103,55,
    137,206,174,203,172,179,59,143,78,138,130,131,214,233,78,74,
    222,97,58,78,67,155,200,250,34,247,117,204,8,62,32,123,
    14,120,2,112,64,112,50,4,177,17,238,53,133,137,112,136,
    68,26,28,2,78,25,188,35,56,49,208,87,164,42,138,1,
    110,50,0,18,13,129,121,65,108,44,224,17,168,133,242,98,
    233,35,44,218,128,83,65,94,155,248,4,99,177,27,59,192,
    1,128,25,248,146,45,63,239,69,128,160,198,149,33,195,101,
    116,19,129,128,51,77,176,45,252,60,62,228,45,3,221,34,
    92,49,168,223,154,57,13,188,42,40,240,174,162,106,198,200,
    156,0,36,200,178,73,94,139,38,116,154,105,227,21,69,56,
    146,134,236,0,22,119,83,17,42,60,226,32,149,218,208,2,
    108,128,204,27,128,138,180,130,179,192,18,156,249,12,39,207,
    150,88,178,96,208,164,89,35,240,50,246,184,9,96,123,244,
    61,229,245,83,108,18,173,177,134,214,232,105,92,241,86,63,
    195,138,80,132,33,19,145,173,198,73,122,158,179,134,73,193,
    40,206,219,161,9,103,160,20,20,244,83,156,60,94,42,69,
    205,89,85,220,23,29,31,12,0,60,147,115,72,199,172,66,
    62,40,21,34,234,168,147,110,141,148,64,58,1,229,232,136,
    20,78,37,210,89,29,174,187,99,120,36,181,150,200,45,225,
    5,152,175,199,133,247,154,197,37,104,123,28,45,7,21,31,
    33,101,88,47,203,165,193,161,61,121,24,147,121,43,3,154,
    248,226,234,120,23,230,252,138,149,177,249,76,109,10,254,169,
    139,71,21,242,184,136,255,111,116,210,208,58,0,254,170,82,
    10,180,180,82,216,255,135,82,190,6,115,126,243,50,74,185,
    31,237,59,74,57,230,228,12,41,5,143,16,233,5,180,224,
    105,39,105,109,2,88,69,184,58,82,202,177,235,124,235,44,
    151,248,62,204,249,93,117,12,102,224,32,168,165,161,5,110,
    196,153,175,182,162,36,116,214,120,221,174,241,183,67,107,116,
    55,27,54,24,28,15,120,26,120,143,130,119,39,120,83,210,
    111,71,225,52,102,178,194,25,204,92,133,115,152,169,10,41,
    51,21,46,96,38,42,92,194,204,83,120,25,51,77,225,85,
    214,189,230,88,210,53,204,47,133,175,96,62,105,192,146,184,
    177,164,87,153,137,44,72,230,245,48,172,26,247,32,182,173,
    26,251,138,32,133,26,143,35,25,56,45,88,49,101,111,202,
    214,122,16,84,51,97,127,170,177,91,159,228,138,12,23,181,
    131,79,155,172,238,113,86,217,21,23,229,61,202,81,222,239,
    107,111,129,247,36,69,217,64,33,206,57,13,228,102,146,85,
    225,86,47,234,104,17,203,150,21,145,8,40,148,237,45,245,
    48,72,0,121,6,8,40,212,32,97,127,136,7,174,123,218,
    37,144,188,131,20,20,122,118,152,130,162,13,12,67,249,244,
    9,175,244,8,125,14,248,141,127,197,231,28,193,235,15,204,
    56,174,241,218,8,28,131,38,252,195,243,62,101,79,253,176,
    111,120,44,18,231,56,52,236,113,248,254,73,199,161,59,234,
    152,177,115,52,192,128,245,233,120,193,70,140,49,55,140,49,
    79,90,88,132,103,121,194,215,182,12,247,31,231,145,18,142,
    137,154,222,105,135,64,67,28,24,133,33,164,94,138,193,111,
    88,69,127,149,58,254,33,204,249,19,78,158,36,29,79,209,
    111,161,70,47,102,3,122,5,179,58,46,50,230,71,21,219,
    173,91,56,165,220,155,9,65,200,170,30,246,115,176,59,97,
    242,176,152,22,217,132,55,124,1,111,149,164,130,214,216,73,
    11,63,171,229,254,24,230,252,153,153,184,127,188,54,127,116,
    161,67,225,86,105,65,3,158,20,2,126,115,29,161,235,40,
    93,233,69,64,140,211,181,129,215,110,3,227,127,80,0,9,
    221,28,92,28,186,118,114,101,4,246,100,236,180,27,36,163,
    183,118,70,11,110,195,156,191,176,210,87,234,253,37,237,111,
    247,114,48,207,205,44,142,32,216,63,178,175,75,204,137,46,
    245,105,233,142,96,152,105,183,19,99,237,45,8,154,99,161,
    25,9,141,178,30,38,187,189,108,47,74,201,115,122,16,200,
    103,137,142,65,203,165,211,235,63,188,178,158,73,192,248,51,
    152,243,55,102,94,45,199,181,151,177,253,229,178,70,237,178,
    254,90,63,33,104,134,245,97,29,131,78,58,54,71,108,115,
    220,32,131,105,54,176,238,241,180,105,128,194,228,46,39,40,
    11,217,176,121,201,41,75,105,218,44,228,180,67,57,103,94,
    240,144,50,67,179,166,108,54,179,164,76,19,101,206,206,34,
    167,140,148,121,103,204,44,81,46,16,229,34,19,11,232,178,
    117,126,211,204,34,247,141,148,37,103,214,69,162,92,114,56,
    47,16,229,178,195,103,145,40,87,156,49,75,68,185,234,140,
    185,68,148,107,206,152,203,68,185,238,104,227,10,81,94,113,
    198,92,37,202,13,103,204,53,162,112,75,161,40,2,41,175,
    58,26,187,65,148,215,28,62,156,40,175,59,148,87,137,242,
    134,195,249,53,162,188,233,140,121,157,40,55,45,229,13,44,
    94,33,101,217,209,207,77,162,180,136,178,194,196,91,244,110,
    191,76,196,183,157,229,183,136,114,203,82,222,97,225,10,81,
    86,157,49,111,17,101,205,161,188,77,148,119,137,114,155,137,
    59,44,4,14,95,99,79,191,142,73,153,240,29,234,125,143,
    133,171,84,64,124,31,143,26,158,8,79,48,243,146,88,157,
    0,184,131,215,182,50,211,131,255,40,209,132,134,14,54,109,
    18,60,116,4,245,187,173,62,101,148,225,193,195,24,196,95,
    54,185,131,81,80,34,146,44,63,196,250,145,248,135,61,130,
    172,126,188,84,10,224,130,158,255,68,75,129,180,237,188,16,
    58,255,212,253,210,64,64,128,148,139,79,138,40,23,237,192,
    15,122,66,254,235,115,202,228,69,86,71,103,33,15,70,38,
    152,19,205,114,213,198,124,115,59,219,23,249,127,85,34,121,
    123,204,228,17,53,128,114,137,21,163,34,198,228,73,159,80,
    89,39,105,48,193,243,164,204,73,67,183,224,228,49,133,73,
    242,80,186,57,74,121,39,142,186,61,197,125,69,25,118,93,
    188,248,79,184,108,224,224,219,124,25,103,46,235,169,92,166,
    126,159,203,232,83,154,184,119,168,128,87,235,93,147,92,46,
    164,224,242,80,42,145,112,82,163,126,36,14,94,161,48,202,
    240,179,233,114,195,240,243,243,250,14,242,210,169,21,157,121,
    226,161,136,253,67,157,27,50,15,81,153,190,187,195,91,183,
    13,203,84,28,40,61,126,69,254,18,97,221,15,158,157,194,
    227,78,201,227,54,229,214,247,114,63,5,121,77,137,128,178,
    229,81,55,5,69,162,218,75,185,163,148,82,231,210,79,132,
    230,123,139,235,231,19,217,17,129,226,53,138,13,182,80,3,
    176,65,81,218,47,20,223,43,58,29,216,176,74,254,50,189,
    246,206,115,48,136,158,30,41,149,92,125,9,61,208,26,238,
    83,61,224,120,61,96,9,106,29,109,193,25,31,228,153,148,
    70,26,212,186,169,71,167,152,33,196,138,75,28,243,172,80,
    216,75,133,12,226,68,111,242,167,174,198,72,113,242,106,190,
    123,218,106,204,108,224,243,64,23,179,142,95,206,19,224,241,
    113,20,2,223,22,60,200,201,58,202,149,74,38,71,37,152,
    44,140,146,62,28,153,72,197,135,134,188,44,121,246,60,229,
    207,145,207,138,252,105,169,161,74,134,62,88,206,0,119,45,
    36,64,26,85,120,82,56,71,194,60,76,175,4,230,116,34,
    208,91,164,228,81,221,81,45,238,101,164,54,75,167,179,169,
    69,178,202,128,78,60,48,159,71,36,231,249,239,13,224,4,
    38,58,13,50,56,220,64,48,251,48,103,230,183,143,159,169,
    209,253,101,24,124,48,192,64,151,30,213,203,62,253,195,19,
    39,27,1,240,13,33,23,41,230,141,143,229,16,97,140,46,
    191,121,138,213,218,57,39,155,237,79,170,205,67,107,66,124,
    92,169,240,204,86,210,124,229,87,90,81,34,239,96,1,209,
    162,6,237,29,161,134,3,120,143,224,228,109,17,220,125,140,
    113,233,209,18,35,96,117,145,195,234,0,184,233,197,72,84,
    169,123,16,156,234,146,250,129,134,43,217,3,9,163,1,21,
    221,139,188,123,44,111,169,192,108,164,46,86,146,92,216,182,
    90,193,252,189,46,102,246,177,69,90,121,223,81,225,163,173,
    31,112,244,166,2,43,184,240,95,129,231,44,12,177,192,199,
    21,96,168,140,169,208,160,187,86,142,76,165,33,29,44,247,
    154,185,102,21,68,247,3,103,106,52,102,221,160,59,223,149,
    149,240,224,126,133,34,118,55,67,17,68,84,106,192,34,170,
    134,117,220,59,3,246,224,82,3,170,193,31,11,49,87,16,
    166,118,52,46,150,37,215,126,158,225,22,100,57,197,70,88,
    115,51,197,219,28,246,153,42,205,85,193,150,170,235,68,146,
    203,159,49,216,212,140,105,236,143,203,67,111,171,219,238,160,
    114,207,81,5,123,162,131,58,192,117,244,104,149,64,199,111,
    112,172,53,86,46,95,151,217,73,157,242,54,60,224,65,74,
    199,71,35,132,124,22,245,251,56,255,121,79,104,247,85,46,
    19,235,230,81,24,139,73,122,115,3,195,209,129,136,164,88,
    243,174,214,232,166,118,148,89,94,70,80,117,27,65,93,98,
    182,170,8,47,70,53,85,51,85,7,252,164,78,191,35,62,
    145,111,226,88,253,121,22,125,195,112,8,106,50,49,145,254,
    144,193,6,76,250,245,159,18,174,104,15,244,193,24,133,136,
    226,32,82,85,192,40,69,220,249,146,97,25,166,99,192,144,
    141,84,247,250,197,82,205,150,1,107,147,181,214,55,216,241,
    53,15,138,119,169,38,153,8,213,203,66,175,135,61,79,241,
    130,53,28,93,122,250,25,51,223,165,41,231,221,218,195,15,
    147,40,255,70,161,210,109,178,207,71,17,162,220,133,146,72,
    56,1,160,67,24,68,229,239,138,78,52,93,204,186,82,118,
    108,103,218,213,27,95,75,199,67,93,61,210,109,163,35,221,
    191,96,251,239,60,68,132,188,75,199,11,143,93,197,248,206,
    118,166,61,164,203,216,187,100,163,227,106,29,119,168,196,79,
    124,136,175,254,94,97,152,239,213,178,103,59,51,231,118,64,
    226,217,193,153,122,249,21,209,121,198,28,25,3,113,112,134,
    58,212,19,198,82,193,143,180,189,84,81,31,19,26,57,125,
    243,14,31,253,37,2,145,47,13,79,113,59,23,135,36,114,
    150,61,63,60,79,75,123,197,33,251,7,235,6,240,31,166,
    122,140,186,89,117,3,0,192,136,45,68,65,195,150,192,124,
    19,44,22,151,73,122,173,134,122,6,168,127,128,16,64,2,
    92,27,232,223,182,104,92,13,184,60,48,192,125,208,144,252,
    26,7,180,25,96,113,142,50,74,180,69,102,192,134,45,255,
    185,66,1,30,110,35,16,110,3,234,125,148,106,173,121,151,
    173,9,31,59,136,118,195,21,156,112,242,1,22,129,157,237,
    162,227,37,8,224,30,134,24,180,211,97,209,66,150,88,165,
    243,91,89,145,227,103,142,169,186,187,73,47,194,155,62,250,
    89,15,63,214,212,159,38,148,147,188,62,59,155,108,27,190,
    169,255,29,39,255,158,217,234,229,204,40,254,154,181,242,87,
    55,255,240,55,226,208,71,134,198,140,56,247,199,253,234,39,
    244,209,39,40,67,124,234,83,181,249,250,147,214,43,118,233,
    237,182,254,200,180,221,246,152,165,37,239,173,134,162,131,30,
    209,43,191,193,5,90,31,191,60,212,149,113,108,229,217,193,
    33,169,23,26,229,23,186,30,229,247,16,67,61,202,224,254,
    17,47,148,123,160,250,140,49,16,250,96,148,190,52,209,53,
    122,74,102,83,138,23,21,174,141,235,244,164,104,219,250,129,
    7,224,172,8,109,73,227,103,176,115,36,232,183,245,135,176,
    223,193,72,94,162,36,179,245,89,240,9,147,181,89,250,193,
    255,245,217,250,98,19,126,87,154,141,197,153,197,113,250,141,
    45,78,47,54,22,71,225,174,254,191,15,93,147,11,
};

EmbeddedPython embedded_m5_objects_MinorCPU(
    "m5/objects/MinorCPU.py",
    "/home/zhoushuxin/gem5/src/cpu/minor/MinorCPU.py",
    "m5.objects.MinorCPU",
    data_m5_objects_MinorCPU,
    4270,
    12001);

} // anonymous namespace