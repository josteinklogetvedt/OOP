
#pragma once
#include "std_lib_facilities.h"

struct Obs{
    int x;
    int y;
};

vector<Obs> readFromFile(string filename);
bool operator<(Obs lhs, Obs rhs);
void report(vector<Obs> vec, int threshold);