#ifndef __PARAMS__VncInput__
#define __PARAMS__VncInput__

class VncInput;

#include <cstddef>
#include <cstddef>
#include "enums/ImageFormat.hh"

#include "params/SimObject.hh"

#include "enums/ImageFormat.hh"

struct VncInputParams
    : public SimObjectParams
{
    VncInput * create();
    bool frame_capture;
    Enums::ImageFormat img_format;
};

#endif // __PARAMS__VncInput__
