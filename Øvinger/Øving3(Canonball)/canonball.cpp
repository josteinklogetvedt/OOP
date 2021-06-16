#include "canonball.h"

//Opg. 2

double acclY(){
    return -9.81;
}

double velY(double initVelocityY, double time){ 
    return initVelocityY + acclY()*time;
}

double posX(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time;
}
double posY(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time + 0.5*acclY()*time*time;
}

void printTime(double time){
    int timer = time/3600;
    int minutter = time/60 - timer*60;
    double sekunder = time - 3600*timer-60*minutter;
    cout << timer << " hours, " << minutter << " minutes og " << sekunder << " seconds\n";
}
double flightTime(double initVelocityY){
    return -2*initVelocityY/acclY();
}

//Opg. 4
double getUserInputTheta(){
    double theta = 0.0;
    cout << "Write an angle(deg): ";
    cin >> theta;
    return theta;
}
double getUserInputAbsVelocity(){
    double fart = 0.0;
    cout << "Write an initial velocity: ";
    cin >> fart;
    return fart;
}
double degToRad(double deg){
    return (deg/180)*3.1415;
}

double getVelocityX(double theta, double absVelocity){
    theta = degToRad(theta);
    return absVelocity*cos(theta);
}
double getVelocityY(double theta, double absVelocity){
    theta = degToRad(theta);
    return absVelocity*sin(theta);
}
vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velocityVector;
    velocityVector.push_back(getVelocityX(theta, absVelocity));
    velocityVector.push_back(getVelocityY(theta, absVelocity));
    return velocityVector;
}

