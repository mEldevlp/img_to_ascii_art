#ifndef STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include <iostream>
#include "Image.hpp"
#endif


class ASCII_Image
{
protected:
	void init_pixels(Pixel** pixel);
	int32_t _width;
	int32_t _height;

public:
	char** chr_pixel;
	void draw_to_console();
	ASCII_Image() = delete;
	ASCII_Image(Pixel** pixels, int32_t height, int32_t width);
	~ASCII_Image();
};

char convert_br_to_char(double*);