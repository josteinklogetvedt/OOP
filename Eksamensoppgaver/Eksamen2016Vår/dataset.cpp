#include "dataset.h"

Dataset::Dataset(int N){
    this->N = N;
    y = new double[N];
    for (int i=0;i<N;++i){
        y[i] = 0.0;
    }
} 

Dataset::Dataset(const Dataset &other)
    :y{new double[other.N]},N{other.N}{
        for (int i=0;i<N;++i){
            y[i] = other.y[i];
        }
    }

Dataset::~Dataset(){
    delete[] y;
}

Dataset& Dataset::operator=(Dataset rhs){
    double* temp = new double[rhs.N];
    for (int i=0;i<rhs.N;++i){
            temp[i] = rhs.y[i];
        }
    delete [] y;
    N = rhs.N;
    y = temp;
    return *this;
}

double Dataset::interpolate(double x){
    int xi = static_cast<int>(x);
    if (x<0){return y[0];}
    if (x>N-1){return y[N-1];}
    return y[xi] + (y[xi+1]-y[xi])* ((x-xi)/(xi+1-xi));
}

Dataset* random_data(double min, double max, int size){
    Dataset* d = new Dataset{size};
    for (int i=0; i<size;++i){
        double random = min + rand() % static_cast<int>(max-min);
        (*d)[i] = static_cast<int>(random);
    }
    return d;
}
