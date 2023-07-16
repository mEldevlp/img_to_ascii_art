#include "ASCII_Image.hpp"

#define MAX_BRIGHTNESS 255.0
#define STRLEN(charsset)((sizeof(charsset))/(sizeof(charsset[0]))-1)

inline char convert_br_to_char(double* brightness)
{
	char gradient[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\" ^ `\'. ";
	int8_t max_steps = STRLEN(gradient);
	double step = MAX_BRIGHTNESS / max_steps;
	double current_brightness = 0;
	int idx = max_steps - 1;

	while (current_brightness < *brightness)
	{
		idx--;
		current_brightness += step;
	}

	return gradient[idx];
}

void ASCII_Image::init_pixels(Pixel** pixels)
{
	this->chr_pixel = new char* [this->_height];
	for (int32_t i = 0; i < this->_height; i++)
		this->chr_pixel[i] = new char[this->_width];

	for (size_t y = 0; y < _height; y++)
		for (size_t x = 0; x < _width; x++)
		{
			this->chr_pixel[y][x] = convert_br_to_char(&pixels[x][y].brightness);
		}
}

void ASCII_Image::draw_to_console()
{
	for (size_t y = 0; y < this->_height; y++)
	{
		for (size_t x = 0; x < this->_width; x++)
		{
			std::cout << this->chr_pixel[y][x];
		}
		std::cout << std::endl;
	}
}

ASCII_Image::ASCII_Image(Pixel** pixels, int32_t height, int32_t width)
{
	_height = height;
	_width = width;

	if (_width * _height  > 0)
	{
		init_pixels(pixels);
	}
}

ASCII_Image::~ASCII_Image()
{
	if (_width * _height == 0)
	{
		delete this;
		return;
	}

	for (int32_t i = 0; i < _height; i++)
		delete[] chr_pixel[i];
	delete[] chr_pixel;
}
