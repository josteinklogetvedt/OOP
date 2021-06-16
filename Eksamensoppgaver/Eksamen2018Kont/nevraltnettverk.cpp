#include "nevraltnettverk.h"

Layer::Layer(int N, int M){
    this -> N = N;
    this -> M = M;
    a = vector<double>(N);
    w = vector<double>(M*N,1);
}

void Layer::setWeight(int j, int i, double weight){
    int index = j*M + i;
    w[index] = weight;
}

double Layer::getWeight(int j, int i){
    int index = j*M + i;
    return w[index];
}

void Layer::forward(const vector<double> &input){
    if (static_cast<int>(input.size()) != M){
        throw invalid_argument("wrong dimension on input");
    }
    for (int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            a[i] += getWeight(i,j)*input[j];
        }
        a[i] = fn(a[i]);
    }
}

void Layer::forward(Layer* input){
    forward(input -> a);
}
 
void NeuralNet::addLayer(Layer* layer){
    if (layers.size()==0){
        layers.push_back(layer);
    }else{
        assert (layers[layers.size()-1]-> getSize() == layer->getInputSize());
        layers.push_back(layer);
    }   
}

Layer* NeuralNet::forward(const vector<double>& input){
    layers[0] -> forward(input);
    for (unsigned int i=1; i<layers.size(); ++i){
        layers[i]-> forward(layers[i-1]);
    }
    return layers[layers.size()-1];
    
    
}
