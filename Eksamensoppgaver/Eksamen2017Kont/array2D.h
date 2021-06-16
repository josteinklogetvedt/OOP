#pragma once
#include "std_lib_facilities.h"

class Array2D {
private:
    int xdim;    // Number of columns
    int ydim;    // Number of rows
    float *data; // Dynamic 1D array to hold data
public:
    Array2D(int xdim, int ydim, float fill=0.0);
    Array2D(const Array2D &other);
    ~Array2D();
    Array2D& operator=(Array2D rhs);
    unsigned int getXdim() const { return xdim; }
    unsigned int getYdim() const { return ydim; }
    int size() { return xdim * ydim; }
    float* operator[](int i);
    float min();
    float max();
};

ostream& operator<<(ostream& os, Array2D&);


