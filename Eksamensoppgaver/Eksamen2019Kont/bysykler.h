#pragma once
#include "std_lib_facilities.h"
#include "Graph.h" //Eller Grap_lib.h?

struct Location{
    string name;
    Graph_lib::Point p;
    Location(string str, Graph_lib::Point pt);
};
constexpr int dispWidth = 30;
constexpr int dispHeight = 20;

class BikeStation{ 
    private:
        Location loc;
        unsigned int capacity; 
        unsigned int bikes;
        Graph_lib::Vector_ref<Graph_lib::Shape> display;
    public:
        BikeStation(Location where, unsigned int cap, unsigned int numBikes);
        void setBikes(unsigned int numBikes);
        unsigned int getBikes();
        string getName(){return loc.name;}
        string status();
        unsigned int getCapacity(){return capacity;}
};

constexpr int ridesPerDay = 20;
map<string,int> simulateOneDay(vector<BikeStation*>);
void printStats(map<string,int> rejections);