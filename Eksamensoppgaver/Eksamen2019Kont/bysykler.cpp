
#include "bysykler.h"

Location::Location(string str, Graph_lib::Point pt)
    :name{str},p{pt}{} 

void BikeStation::setBikes(unsigned int numBikes){
    bikes = numBikes;
}
unsigned int BikeStation::getBikes(){
    return bikes;
}

string BikeStation::status(){
    string s = to_string(bikes) + " out of " + to_string(capacity);
    return s;
} 

BikeStation::BikeStation(Location where, unsigned int cap, unsigned int numBikes)
    :loc{where},capacity{cap},bikes{numBikes}{
        Graph_lib::Rectangle* pRec = new Graph_lib::Rectangle{loc.p, dispWidth, dispHeight};
        pRec -> set_fill_color(Graph_lib::Color::white);
        Graph_lib::Text* pName = new Graph_lib::Text{loc.p, loc.name};
        pName ->set_color(Graph_lib::Color::black);
        pName -> set_font_size(20);
        Graph_lib::Text* pStatus = new Graph_lib::Text{Graph_lib::Point{loc.p.x+2,loc.p.y+15}, status()};
        pStatus -> set_color(Graph_lib::Color::black);
        display.push_back(pRec);
        display.push_back(pName);
        display.push_back(pStatus);
    }

map<string,int> simulateOneDay(vector<BikeStation*> stations){
    map<string,int> rejections;
    for (int i=0; i<ridesPerDay; ++i){
        int from = rand() % stations.size();
        int to = rand() % stations.size();

        int avail = stations[from]->getBikes();
        int bikesThere = stations[to]->getBikes();
        int space = stations[to]->getCapacity() - bikesThere;
        if (avail < 1){
            ++rejections[stations[from]->getName()];
        }else if(space < 1){
            ++rejections[stations[to]->getName()];
        }else{
            stations[to] ->setBikes(++bikesThere);
            stations[from]->setBikes(--avail);
        }
    }
    return rejections;
}   

void printStats(map<string,int> rejections){    //Map sorterer alfabetisk av seg selv
    for (auto p : rejections){
        cout << p.second << " bike trips refused at " << p.first << endl;
    }
}