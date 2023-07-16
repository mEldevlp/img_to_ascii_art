#include "Image.hpp"

inline double Pixel::calc_bright()
{
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

inline void Image::init_pixels()
{
    this->pixels = new Pixel* [this->_height];
    for (int i = 0; i < this->_height; i++)
        this->pixels[i] = new Pixel[this->_width];
}

Image::Image(const char* filename)
{
    uint8_t* img_data = nullptr;
    try
    { 
        img_data = stbi_load(filename, &this->_width, &this->_height, &this->_bpp, 3);

        init_pixels();

        for (size_t x = 0; x < this->_width; x++)
        {
            for (size_t y = 0; y < this->_height; y++)
            {
                uint8_t* pixel_offset = img_data + (3 * (y * this->_width + x));
                this->pixels[x][y].r = pixel_offset[0];
                this->pixels[x][y].g = pixel_offset[1];
                this->pixels[x][y].b = pixel_offset[2];
                this->pixels[x][y].brightness = this->pixels[x][y].calc_bright();
            }
        }

        std::cout << "Read file successful!" << std::endl;
    }
    catch (...)
    {
        std::cout << "Something wrong!" << std::endl;
    }

    stbi_image_free(img_data);
}

Image::~Image()
{
    for (int i = 0; i < this->_height; i++)
        delete[] pixels[i];

    delete[] pixels;
}
