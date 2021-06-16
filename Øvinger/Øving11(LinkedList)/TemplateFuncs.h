#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

template<typename T>
T maximum(T& a, T& b){
    if (a > b){
        return a;
    }return b;
}

void testMaximum(){
    int a = 1, b=2;
	int c = maximum(a,b);
	std::cout << c << std::endl;

    double d=1.4, e=3.14;
    double f = maximum(d,e);
    std::cout << f << std::endl;
}

template<typename C>
void shuffle(vector<C>& vec){
    for (int i=0; i<vec.size(); ++i){    //shuffler vec.size() antall ganger
        int randomNum1 = rand() % vec.size();
        int randomNum2 = rand() % vec.size();
        auto temp = vec[randomNum1];
        vec[randomNum1] = vec[randomNum2];
        vec[randomNum2] = temp;
    }
}

void testShuffle(){
    vector<int> a{1, 2, 3, 4};
    vector<double> b{1.2, 2.2, 3.2, 4.2};
    vector<string> c{"one", "two", "three", "four"};
    shuffle(b);
    shuffle(a);
    shuffle(c);
    for (int i=0; i<a.size(); ++i){
        std::cout << a[i] << " " << b[i] << " " << c[i] << std::endl;
    }
}





