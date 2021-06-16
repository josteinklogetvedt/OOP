// Opg. 1
#pragma once
#include "std_lib_facilities.h"

double acclY();

double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocityY);
 
//Opg. 4a)
double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);