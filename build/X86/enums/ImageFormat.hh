#ifndef __ENUM__Enums__ImageFormat__
#define __ENUM__Enums__ImageFormat__

namespace Enums {
    enum ImageFormat {
        Auto = 0,
        Bitmap = 1,
        Png = 2,
        Num_ImageFormat = 3
    };
extern const char *ImageFormatStrings[Num_ImageFormat];
}

#endif // __ENUM__Enums__ImageFormat__
