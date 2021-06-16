#pragma once
#include "std_lib_facilities.h"

float clip(float n, float lower, float upper);

struct Color{
    int r;      //representeres som heltall fordi alle fargekomponentene er heltall mellom (0,255)
    int g;
    int b;
    Color();
    Color(int red, int green, int blue);
};

typedef float Kernel[3][3];
class Image {
    private:
        Color * data;  // Array of pixels 
        unsigned int width; // Width of image
        unsigned int height; // Height of image
    public:
        Image(int width, int height);
        Image(const Image &other);
        ~Image();
        Image& operator=(Image rhs);    //Må implementere tilordningsoperatoren fordi sender inn Image som paramter pass-by-value senere
        Color getPixel(int x, int y);
        void setPixel(int x, int y, Color c);
        Image grayscale();
        Image threshold(unsigned int t);
        Image operator+(Image other);
        Color applyKernel(int x, int y, Kernel k);
        Image convolve(Kernel k);
};