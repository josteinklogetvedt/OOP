#include "Vehicle.h"

Vehicle::Vehicle(double x, double y, double angle, const Track& track)
     :Fl_Widget(10,10,10,10), track{track}{
                state.x = x;
                state.y = y;
                state.angle = angle;
};

void Vehicle::draw(){
    
    bool colTarget = collisionBool(track.getGoals().at(goalIndex).first, track.getGoals().at(goalIndex).second, goalRadius);
    bool colSpill = collisionBool(track.getGoals().at(3).first, track.getGoals().at(3).second, spillRadius);
    bool colBoost = collisionBool(track.getGoals().at(6).first, track.getGoals().at(6).second, boostRadius);
    bool colPeel = collisionBool(track.getGoals().at(9).first, track.getGoals().at(9).second, peelRadius);
    if (colSpill){state.grip = 0.5;}
    if (colBoost){state.grip = 2;}

    if (colPeel && state.speed >= 2){
        status = Obstacle::Peel;
        initAngle = state.angle;
    }
    if (status == Obstacle::Peel){
        if (colTarget){++goalIndex;}
        if (goalIndex >= track.getGoals().size()-1){goalIndex = 0;}
        state.slide(initAngle);
        drawBody();
        if (state.speed < 0.3){status = Obstacle::None;}
    }else{
        if (colTarget){++goalIndex;}
        if (goalIndex >= track.getGoals().size()-1){goalIndex = 0;} 
        parSpeed = steer();
        state.update(parSpeed.first, parSpeed.second);
        drawBody();
    }
}

void PlayerVehicle::drawBody(){
    if (state.x > screenWidth){state.x = screenWidth;}
    else if(state.x < 0){state.x = 0;}
    if(state.y > screenHeight){state.y = screenHeight;}
    else if(state.y < 0){state.y = 0;}

    fl_rectf(state.x-5, state.y-5, 10, 10, FL_YELLOW);
    fl_line_style(FL_SOLID);
    fl_color(FL_BLACK);
    fl_circle(state.x,state.y,vehicleRadius);
    fl_color(FL_YELLOW);
    fl_circle(track.getGoals().at(goalIndex).first,track.getGoals().at(goalIndex).second, goalRadius/3);
}

std::pair<double,double> PlayerVehicle::steer() const{
    double linAcc=0.0;
    double vinkelAcc = 0.0;
    if (Fl::event_key('w')){linAcc = -1;}
    else if(Fl::event_key('s')){linAcc = 1;}
    else if (Fl::event_key('a')){vinkelAcc = -1;} 
    else if (Fl::event_key('d')){vinkelAcc = 1;}
    
    return std::make_pair(linAcc,vinkelAcc);
}

void Vehicle::obstacleStatus(){
    if (status == Obstacle::Spill){
        
    }else if(status == Obstacle::Boost){
        state.grip = 2;
    }else if(status == Obstacle::Peel){

    }
}

bool Vehicle::collisionBool(double x, double y, int radius){
    double delX = x - state.x;
    double delY = y - state.y;
    double sumR = radius+ vehicleRadius;
    return circleCollision(delX, delY, sumR);
}





