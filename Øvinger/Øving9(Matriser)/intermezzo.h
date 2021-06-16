#pragma once
#include <iostream>

class Dummy {
    public:
        int *num;
        Dummy() {
            num = new int{0};
        }
        ~Dummy() {delete num;}
        Dummy(const Dummy& d);
        Dummy& operator=(const Dummy& d);
};
void dummyTest();
    
