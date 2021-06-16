#include "rational.h"

int Rational::gcd(int a, int b){
    //Euclids Algorithm - finds the greatest common divisor for a and b
    if ( b == 0 ){
        return a;
    }
    return gcd(b,a%b);
}

void Rational::reduce(){
    int divisor = gcd(n,d);
    n = n/divisor;
    d = d/divisor;
    if ((n>0 && d<0) || (n<0 && d<0)){
        n = -n;
        d = -d;
    }
}

Rational::Rational(int n, int d){
    if (d==0){
        throw "Error; 0 as a denominator";
    }
    this -> n = n;
    this -> d = d;
    reduce();
}

double Rational::to_double(){  //endrer to_double n og d??
    double num = static_cast<double>(n);
    double denom = static_cast<double>(d);
    return num/denom;
}

bool Rational::operator<(Rational& rhs){
    return this->to_double() < rhs.to_double();
}

bool Rational::operator==(Rational& rhs){
    if (*this < rhs || rhs < *this){return false;}
    return true;
}

Rational Rational::operator++(){
    Rational rat{*this};
    n = n + d;
    return rat;
}

Rational Rational::operator*(Rational& rhs){
    int num = (this->n) * rhs.n;
    int denom = (this->d) * rhs.d; 
    Rational rat{num, denom};
    return rat;
}

Rational Rational::operator*=(Rational& rhs){
    n *= rhs.n;
    d *= rhs.d;
    reduce();
    return *this;
}

