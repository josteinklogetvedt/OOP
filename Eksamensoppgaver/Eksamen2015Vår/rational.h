#pragma once
#include "std_lib_facilities.h"

class Rational{
private:
    int n; //numerator (norsk: teller)
    int d; //denominator (norsk: nevner)
    void reduce(); //reduce the fraction (norsk: forkorte brøken)
    int gcd(int a, int b); //finds the greatest common divisor
public:
    Rational(); //creates a value of 0/1
    Rational(int n, int d); //creates a value of n/d
    int numerator(){return n;}; //returns numerator
    int denominator(){return d;}; //returns denominator
    double to_double(); //returns fraction as double value
    bool operator<(Rational& rhs);
    bool operator==(Rational& rhs);
    Rational operator++();
    Rational operator*(Rational& rhs);
    Rational operator*=(Rational& rhs);
    friend ostream& operator<<(ostream& os, Rational& r){
        os << r.n << "/" << r.d;
        return os;
    }    
};



//h) Man trenger ingen kopikonstruktør eller tilordningsoperator fordi det bare er int-er.


