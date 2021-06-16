#pragma once
#include "std_lib_facilities.h"
#include <assert.h>

class Layer{
    private:
        int N;
        int M;
        vector<double> a; 
        vector<double> w;
    public:
        Layer(int N, int M);
        int getSize(){return N;}
        int getInputSize(){return M;}
        void setWeight(int j,int i,double weight);
        double getWeight(int j, int i);
        virtual double fn(double x) { return x; }   //Må være virtual for at senere klasser kan arve og endre funksjonen.
        void forward(const vector<double> &input);
        void forward(Layer* input);
};

class SigmoidLayer : public Layer{
    public:
        SigmoidLayer(int N, int M)
            :Layer(N,M){}
        double fn(double x) { return x/(1.0 + exp(-x));}
};

class NeuralNet {
    protected:
        vector<Layer*> layers;
    public:
        NeuralNet() {}
        void addLayer(Layer* layer);
        Layer *forward(const vector<double> &input);
};
