#ifndef STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include <iostream>
#endif

class IImage
{
public:
    int _width;
    int _height;
    virtual void init_pixels() = 0;
    int get_width() { return _width; }
    int get_height() { return _height; }
};

struct Pixel
{
    double calc_bright();

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    double brightness = 0;
};

class Image : public IImage
{
protected:
    int32_t _bpp;
    void init_pixels();

public:
    Pixel** pixels;
    Image(const char* filename);
    Image() = delete;
    ~Image();
};

