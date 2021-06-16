#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono> 

using namespace std;

float readSensor(int id);

enum PlantStatus{HAPPY_PLANT, WATER_LOW, WATER_HIGH, SENSOR_ERROR};

class Plant{
private:
    string name;
    string location;
    int sensorId;
    float humidityMax;
    float humidityMin;
    float humidity; 
public:
    Plant(string name, string location, int sensorId, float humidityMax, float humidityMin)
        :name{name},location{location},sensorId{sensorId}, humidityMax{humidityMax}, humidityMin{humidityMin},humidity{-1.0}{}
    void setName(string name){this->name = name;}
    string getName() const {return name;}
    float readHumidity();
    PlantStatus getStatus();
    bool operator==(Plant  &rhs);
    friend ostream& operator<<(ostream &os, Plant &p);
};

//unsigned int sleep(int seconds);

class Garden{
private:
    string name;
    vector<Plant> plants;
public:
    Garden(string name)
        :name{name},plants{}{}
    void addPlant(Plant p);
    void removePlant(Plant p);
    vector<Plant> needsHelp();
    void monitor(int interval);
};

void menu();