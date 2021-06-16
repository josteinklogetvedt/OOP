#include "array2D.h"

Array2D::Array2D(int xdim, int ydim, float fill)
    :xdim{xdim}, ydim{ydim}, data{new float[xdim*ydim]}{
    for (int i=0; i<xdim*ydim; i++){
        data[i] = fill;
    }
}

Array2D::Array2D(const Array2D &other)
    :xdim{other.xdim}, ydim{other.ydim}, data{new float[xdim*ydim]}{
    for (int i=0; i<xdim*ydim; i++){
        data[i] = other.data[i];
    }
}

Array2D::~Array2D(){
    delete[] data;
}

Array2D& Array2D::operator=(Array2D rhs){
    swap(data, rhs.data);
    swap(xdim, rhs.xdim);
    swap(ydim, rhs.ydim);
    return *this;
}

float* Array2D::operator[](int i){
    return &data[xdim*i];
}

float Array2D::min(){
    float min = data[0];
    for (int i=1; i<xdim*ydim;++i){
        if (data[i]< min){
            min = data[i];
        }
    }
    return min;
}

float Array2D::max(){
    float max = data[0];
    for (int i=1; i<xdim*ydim;++i){
        if (data[i] > max){
            max = data[i];
        }
    }
    return max;
}

ostream& operator<<(ostream& os, Array2D& array){
    for (unsigned int i=0; i<array.getYdim(); i++){
        for (unsigned int j=0; j<array.getXdim(); j++){
            os << array[i][j] << " ";
        }
        os << endl;
    }
    return os;
}