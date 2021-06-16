#pragma once

#include "utilities.h"
#include <tuple>
#include <vector>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include  <FL/Fl.H>


bool circleCollision(double delX, double delY, double sumR);

enum class Obstacle{Spill, Boost, Peel, None};

class Track : public Fl_Widget{
    private:
        std::vector<std::pair<double,double>> goals;
        std::vector<std::tuple<double,double,Obstacle>> obstacles;
    public:
        Track();
        void draw() override;
        const std::vector<std::pair<double,double>>& getGoals() const{return goals;}
        const std::vector<std::tuple<double,double,Obstacle>>& getObstacles() const{return obstacles;}
};
