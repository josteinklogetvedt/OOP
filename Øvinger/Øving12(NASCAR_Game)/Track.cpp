#include "Track.h"


Track::Track()
    :Fl_Widget(10,10,10,10){
        goals.push_back(std::make_pair(500,300));
        goals.push_back(std::make_pair(600,240));
        goals.push_back(std::make_pair(700,200));
        goals.push_back(std::make_pair(750,300));
        goals.push_back(std::make_pair(700,400));
        goals.push_back(std::make_pair(600,360));
        goals.push_back(std::make_pair(400,240));
        goals.push_back(std::make_pair(300,200));
        goals.push_back(std::make_pair(250,300));
        goals.push_back(std::make_pair(300,400));
        goals.push_back(std::make_pair(400,360));
        goals.push_back(std::make_pair(500,300));
    }

void Track::draw(){
    fl_line_style(FL_SOLID);
    fl_color(FL_BLACK);
    for (int i=0; i<goals.size(); ++i){
        fl_circle(goals.at(i).first,goals.at(i).second,goalRadius);
    }
    fl_rectf(goals.at(3).first-12, goals.at(3).second-12, 25, 25, FL_BLUE); //spill
    fl_rectf(goals.at(6).first-7, goals.at(6).second-7, 15, 15, FL_GREEN);  //boost
    fl_rectf(goals.at(9).first-5, goals.at(9).second-5, 10, 10, FL_RED);    //peel

  
}

bool circleCollision(double delX, double delY, double sumR){
    return delX*delX + delY*delY < sumR*sumR;
}