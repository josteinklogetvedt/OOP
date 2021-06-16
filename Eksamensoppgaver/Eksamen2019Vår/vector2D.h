#pragma once
#include "std_lib_facilities.h"
#include "GUI.h" // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Simple_window.h"


class Vector2D{
    public:
        double x;
        double y;
        Vector2D(double x, double y)
            :x{x},y{y}{}
       double length();
       Vector2D operator*(double k); 
};
ostream& operator<<(ostream& os, const Vector2D& v);
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
Vector2D vectorSum(const vector<Vector2D>& vectors);
void trackStats(const vector<Vector2D>& track);
void cleanTrack(vector<Vector2D>& track);

class Clean{
    public:
        Vector2D v;
        Clean()
            :v{0.0,0.0}{}
        Vector2D operator()(Vector2D delta){
            Vector2D np = v + delta;
            if (v.x < delta.x || v.x>delta.y || v.y<delta.x || v.y>delta.y){
                return {0,0};
            }
            else{
                v = np;
                return delta;
            }
        }
};

constexpr int win_W = 500;
constexpr int win_H = 500;

void addVector(vector<Shape*> &drawing, const Vector2D &vec, const Color col);
void showDrawing(Simple_window &win, vector<Shape *> &drawing);
void draw(Simple_window &win, vector<Shape *> &shapes, Color col);

struct doublePoint {
  double x;
  double y;
};

void addLine(vector<Shape *> &s, const doublePoint from, const doublePoint to);
vector<Shape *> makeTrack(const vector<Vector2D> &vectors);
void emptyDrawing(Simple_window &win, vector<Shape *> &v);
void printTrack(const vector<Vector2D> track);
void plotTrack(Simple_window &win, const vector<Vector2D> &track, Color col);
void testVector2D();
