#pragma once
#include <cmath>
//#include <iostream>
//#include <string>
#include "std_lib_facilities.h"

constexpr double PI = 3.1415927;

double radian(double degree);
double nFac(unsigned int n);
double sineTaylorTerm(double x, int n);
double sineTaylor(double x, int n);
int testTaylor(double degree, double epsilon);
void findHighestIter(double epsilon);

constexpr int NFAK_LIMIT = 9;
double nFacRobust(unsigned int n);
void testnFacRobust(); 