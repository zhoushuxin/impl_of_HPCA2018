#ifndef __PARAMS__HDLcd__
#define __PARAMS__HDLcd__

class HDLcd;

#include <cstddef>
#include <cstddef>
#include "enums/ImageFormat.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ClockDomain.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/VncInput.hh"
#include <cstddef>
#include <cstddef>

#include "params/AmbaDmaDevice.hh"

#include "enums/ImageFormat.hh"

struct HDLcdParams
    : public AmbaDmaDeviceParams
{
    HDLcd * create();
    bool enable_capture;
    Enums::ImageFormat frame_format;
    uint32_t pixel_buffer_size;
    unsigned pixel_chunk;
    ClockDomain * pxl_clk;
    Tick virt_refresh_rate;
    VncInput * vnc;
    bool workaround_dma_line_count;
    bool workaround_swap_rb;
};

#endif // __PARAMS__HDLcd__
