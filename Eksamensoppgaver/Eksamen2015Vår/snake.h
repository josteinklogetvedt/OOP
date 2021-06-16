#include "Graph.h"
#include "Simple_window.h"
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include  <FL/Fl.H>


const int RECT_WIDTH = 10;
const int RECT_HEIGHT = 10;
const int WIN_WIDTH = 1200;
const int WIN_HEIGHT = 800;

enum class Direction {UP, LEFT, DOWN, RIGHT};
Direction operator++(Direction& dir);
Direction operator--(Direction& dir);

using namespace Graph_lib;

void initSnake(vector<Rectangle*>& snake, Simple_window& win);
void moveSnake(vector<Rectangle*>& snake, Simple_window& win, Direction dir);
bool detectCollision(const Rectangle& a, const Rectangle& b);
void placePiece(Rectangle& piece, const vector<Rectangle*>& snake);
void addLength(vector<Rectangle*>& snake, Simple_window& win, Direction dir);
bool selfCollide(const vector<Rectangle*>& snake);
Direction& steer(Direction& current);


class MovingRectangle : public Rectangle{
private:
    double speed;
    int dx = -1;
    int dy = -1;
public:
    

};