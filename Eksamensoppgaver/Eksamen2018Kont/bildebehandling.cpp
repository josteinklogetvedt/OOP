#include "bildebehandling.h"

float clip(float n, float lower, float upper){
    if (n <= lower){
        n = lower;
    }else if(n >= upper){
        n = upper;
    }
    return n;
}

Color::Color()
    :r{0},g{0},b{0}{}

Color::Color(int red, int green, int blue){
    r = static_cast<int>(clip(static_cast<float>(red), 0.0, 250.0));
    g = static_cast<int>(clip(static_cast<float>(green), 0.0, 250.0));
    b = static_cast<int>(clip(static_cast<float>(blue), 0.0, 250.0));
}

Image::Image(int width, int height){
    this->width = width;
    this->height = height;
    data = new Color[width*height];
}

Image::Image(const Image &other) : width(other.width), height(other.height){
    data = new Color[width * height];
    for (unsigned int i = 0; i < width * height; i++){
        data[i] = other.data[i];
    }
}

//Image& Image::operator=(Image rhs){
//    for (unsigned int i=0; i<height; ++i){
//        for (unsigned int j=0; j<width; ++j){
//            Color rhsCol = rhs.getPixel(j,i);
//            (*data).r = rhsCol.r;
//            (*data).g = rhsCol.g;
//            (*data).b = rhsCol.b;
//            ++data;
//        }
//    }
//}

Image::~Image(){
    delete[] data;
}

Color Image::getPixel(int x, int y){
    int index = y*width + x;
    return data[index];
}

void Image::setPixel(int x, int y, Color c){
    int index = y*width + x;
    data[index].r = c.r;
    data[index].g = c.g;
    data[index].b = c.b;
}

Image Image::grayscale(){
    Image imGray{*this};
    for (unsigned int i=0; i<height; ++i){
        for (unsigned int j=0; j<width; ++j){
            Color c = getPixel(j,i);
            float r = static_cast<float>(c.r);
            float g = static_cast<float>(c.g);
            float b = static_cast<float>(c.b);
            int meanCol = static_cast<int>(round((r+g+b)/3.0));
            imGray.setPixel(j,i, Color{meanCol,meanCol,meanCol});
        }
    }
    return imGray;
}

Image Image::threshold(unsigned int t){
    Image imThresh{*this};
    for (unsigned int i=0; i<height; ++i){
        for (unsigned int j=0; j<width; ++j){
            Color c = getPixel(j,i);
            if (c.r >= static_cast<int>(t)){c.r = 255;}
            else{c.r = 0;}
            if (c.g >= static_cast<int>(t)){c.g = 255;}
            else{c.g = 0;}
            if (c.b >= static_cast<int>(t)){c.b = 255;}
            else{c.b = 0;} 
        imThresh.setPixel(j,i, Color{c.r,c.g,c.b});
        }
    }
    return imThresh;
}

Image Image::operator+(Image other){
    Image imC{static_cast<int>(width), static_cast<int>(height)};
    if (width != other.width || height != other.height){
        throw out_of_range("Not a fit");
    }
    for (unsigned int i=0; i<height; ++i){
        for (unsigned int j=0; j<width; ++j){
            int r = static_cast<int>(round((getPixel(j,i).r + other.getPixel(j,i).r)/2.0));
            int g = static_cast<int>(round((getPixel(j,i).g + other.getPixel(j,i).g)/2.0));
            int b = static_cast<int>(round((getPixel(j,i).b + other.getPixel(j,i).b)/2.0));
            imC.setPixel(j,i,Color{r,g,b});
        }
    }
    return imC;
}

Color Image::applyKernel(int x, int y, Kernel k){
    vector<float> weights(3);
    for (unsigned int i=0; i<3; ++i){
        for (unsigned int j=0; j<3; ++j){
            Color c = getPixel(x-1+j,y-1+i);
            weights[0] += c.r*k[i][j];
            weights[1] += c.g*k[i][j];
            weights[2] += c.b*k[i][j];
        }
    }
    Color c{static_cast<int>(weights[0]), static_cast<int>(weights[1]), static_cast<int>(weights[2])};
    return c;
}

Image Image::convolve(Kernel k){
    Image im{*this};
    for (unsigned int i=1; i<height-1; ++i){
        for (unsigned int j=1; j<width-1; ++j){
            Color c =applyKernel(j, i, k);
            im.setPixel(j, i, c);
        }
    }
    return im;
}

