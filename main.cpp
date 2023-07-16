#include "general.hpp"

int main(int argc, char** argv)
{  
    Image* img = new Image(argv[1]);
    ASCII_Image* ascii_img = new ASCII_Image(img->pixels, img->get_height(), img->get_width());
    
    ascii_img->draw_to_console();
    
    system("pause");
    return EXIT_SUCCESS;
}