#pragma once

#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include  <FL/Fl.H>
#include <tuple>
#include "utilities.h"
#include <vector>
#include "Track.h"


class Vehicle : public Fl_Widget{
    public:
        Vehicle(double x, double y, double angle, const Track& track);
    
        void draw() final;
    protected:
        virtual std::pair<double,double> steer() const = 0;
        virtual void drawBody() = 0;
        void obstacleStatus();
        bool collisionBool(double x, double y, int radius);

        double initAngle;
        Obstacle status = Obstacle::None;
        int goalIndex=0;
        const Track& track;
        PhysicsState state;
        std::pair<double,double> parSpeed;
};

class PlayerVehicle : Vehicle{
    public:
        PlayerVehicle(double x, double y, double angle, const Track& track)
            :Vehicle(x,y,angle,track){};
        void drawBody();
        std::pair<double,double> steer() const;
};





