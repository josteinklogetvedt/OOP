#pragma once
#include "std_lib_facilities.h"

constexpr double MAX_WIND = 13.3;

using namespace std;
int checkAlarm(const double value, const double threshold);
void printAlarm(const int id, const double wind, const int dir);

struct Sample{
    int id;
    double wind;
    int dir;
}; 

ostream& operator<<(ostream& os, const Sample& s);

const int N_MILLS = 278;
const int N_SAMPLES = 10;
Sample measurements[N_MILLS][N_SAMPLES];

void readMeasurements(const char* filename);
vector<Sample> calcStats();
bool operator<(const Sample &lhs, const Sample &rhs);
void checkMeasurements();
void repairMeasurements();