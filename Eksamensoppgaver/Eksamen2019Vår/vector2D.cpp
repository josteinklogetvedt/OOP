#include "vector2D.h"

double Vector2D::length(){
    return sqrt(x*x+y*y);
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs){
    return Vector2D {lhs.x+rhs.x,lhs.y+rhs.y};
}

Vector2D Vector2D::operator*(double k){
    return Vector2D {this->x*k,this->y*k};
}

ostream& operator<<(ostream& os, const Vector2D& v){
    os << "[" << v.x << ", " << v.y << "]";
    return os;
}

Vector2D vectorSum(const vector<Vector2D>& vectors){
    Vector2D v{0.0,0.0};
    for (unsigned int i = 0; i<vectors.size(); ++i){
        v = v + vectors[i];
    }
    return v;
}

void trackStats(const vector<Vector2D>& track){
    double totLength;
    double maxVel;
    double velocity;
    double length;
    Vector2D temp{0.0,0.0};
    for (unsigned int i=0; i<track.size(); ++i){
        temp = track[i];
        length = temp.length();
        totLength += length; 
        velocity = (length*1000)/(10.0); 
        if (velocity > maxVel){
            maxVel = velocity;
        }
    }
    cout << "Length: " <<   totLength << "km, max-speed:" << maxVel << "m/min, ended at " << vectorSum(track) << endl;
}


void cleanTrack(vector<Vector2D>& track){
    transform(track.begin(), track.end(),track.begin(),Clean());
}


// *************************************************************** Graphic demo
// code for testing only
void addVector(vector<Shape*> &drawing, const Vector2D &vec, const Color col) {
  if ((vec.x > 10.0) || (vec.y > 10.0))
    throw "too large x or y in Vector2d object, ignored";

  Line *linePtr = new Line{{0, win_H},
                           {static_cast<int>((vec.x * win_W) / 10.0),
                            static_cast<int>(win_H - (vec.y * win_H) / 10.0)}};
  linePtr->set_color(col);
  drawing.push_back(linePtr);
}

void showDrawing(Simple_window &win, vector<Shape *> &drawing) {
  if (drawing.empty()) {
    throw "drawing vector must be non-empty";
  }

  for (auto s : drawing)
    win.attach(*s);
}

void draw(Simple_window &win, vector<Shape *> &shapes, Color col) {
  if (shapes.empty()) {
    throw "shapes vector must be non-empty";
  }

  for (auto s : shapes) {
    s->set_color(col);
    win.attach(*s);
  }
}

void addLine(vector<Shape *> &s, const doublePoint from, const doublePoint to) {
  if ((from.x < 0.0) || (from.y < 0.0) || (to.x < 0.0) || (to.y < 0.0)) {
    cerr << "addLine: negative x or y in Vector2d object, ignored.\n";

    return;
  }
  if ((from.x > 10.0) || (from.y > 10.0) || (to.x > 10.0) || (to.y > 10.0)) {
    cerr << "addLine: too large x or y in Vector2d object, ignored.\n";
    return;
  }

  Line *linePtr = new Line{{static_cast<int>((from.x * win_W) / 10.0),
                            static_cast<int>(win_H - (from.y * win_H) / 10.0)},
                           {static_cast<int>((to.x * win_W) / 10.0),
                            static_cast<int>(win_H - (to.y * win_H) / 10.0)}};
  s.push_back(linePtr);
}

vector<Shape *> makeTrack(const vector<Vector2D> &vectors) {
  vector<Shape *> sVec;
  doublePoint from{0.0, 0.0};
  for (auto v : vectors) {
    doublePoint to = {from.x + v.x, from.y + v.y};
    addLine(sVec, from, to);
    from = to;
  }
  return sVec;
}

void emptyDrawing(Simple_window &win, vector<Shape *> &v) {
  while (v.size() > 0) {
    win.detach(*v.at(v.size() - 1));
    delete v.at(v.size() - 1);
    v.pop_back();
  }
}

void printTrack(const vector<Vector2D> track) {
  cout << "Track is: ";
  for (auto elt : track)
    cout << " " << elt;
  cout << endl;
}

void plotTrack(Simple_window &win, const vector<Vector2D> &track, Color col) {
  vector<Shape *> t = makeTrack(track);
  draw(win, t, col);
}

void testVector2D() {

  cout << "Tracking based on Vector2d from exam May 2019\n";

  Point tl{100, 100};
  Simple_window win{tl, win_W, win_H, "Tracking"};

  const Vector2D a{3.0, 2.0};
  const Vector2D b{2.0, 6.0};
  vector<Vector2D> vectors{a, b};

  vector<Vector2D> track{{1.0, 0.5},  {2.0, 0.0},  {1.0, 1.0},
                         {-1.0, 2.0}, {-1.0, 0.0}, {-1.0, -1.0}};
  plotTrack(win, track, Color::black); // For 5 in exam text
  trackStats(track);
  win.wait_for_button();

  vector<Vector2D> track2{
      {1.0, 1.5}, {-2.0, 1.0}, {3.0, 12.0}, {1.0, -8.0}, {-1.0, 0.0}};

  cout << "\ntrack2:\n";
  printTrack(track2);
  plotTrack(win, track2, Color::blue);
  win.wait_for_button();
  cleanTrack(track2);
  printTrack(track2);
  plotTrack(win, track2, Color::green);
  win.wait_for_button();
  cout << "\ntrack3:\n";

  vector<Vector2D> track3{
      {3.0, 9.0}, {2.0, 0.0}, {8.0, 0.0}, {-2.0, 2.0}, {-1.0, -1.0}};
  printTrack(track3);
  plotTrack(win, track3, Color::dark_red);
  win.wait_for_button();
  cleanTrack(track3);
  printTrack(track3);
  plotTrack(win, track3, Color::cyan);
  win.wait_for_button();

  return;
}