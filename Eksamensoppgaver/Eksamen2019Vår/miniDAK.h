
/**
#pragma once 
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"    //for Simple_window only (doesn't really belong in Window.h)
#include "Simple_window.h"

map<string, Color> colors = {
	{"red", Color::red},
	{"blue", Color::blue},
	{"green", Color::green},
	{"yellow", Color::yellow},
	{"white", Color::white},
	{"black", Color::black},
	{"magenta", Color::magenta},
	{"cyan", Color::cyan},
};

map<Color,string> backColors = {
    {Color::red,"red"},
	{Color::blue,"blue"},
	{Color::green, "green"},
	{Color::yellow, "yellow"},
	{Color::white, "white"},
	{Color::black, "black"},
	{Color::magenta, "magenta"},
	{Color::cyan, "cyan"},
};


bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height);
bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad);
Color string_to_color(string s);
string color_to_string(Color c);

bool operator==(const Color& lhs, const Color& rhs);

class DAKShape{
protected:
	Shape &shape; // The underlying Shape to draw
	DAKShape(Shape &s) : shape(s) { }
public:
	virtual bool is_inside(Point xy) = 0;
	virtual string to_string() = 0;
	virtual ~DAKShape() { }
	void attach_to(Graph_lib::Window & win) { win.attach(shape); }
	void move(int dx, int dy) { shape.move(dx, dy); }
	void set_color(Color c) { shape.set_fill_color(c); }
	Color get_color() { return shape.fill_color(); }
};

class DAKRectangle : public DAKShape{
	protected:
        Rectangle rect;
    public:
		DAKRectangle(Point xy, int ww, int hh)
			:DAKShape{rect}, rect{xy,ww,hh}{}
		string to_string();
		bool is_inside(const Point p);
};

class DAKCircle : public DAKShape{
	protected:
        Circle circle;
    public:
		DAKCircle(Point xy, int rr)
			:DAKShape{circle}, circle{xy,rr}{}
		string to_string();
		bool is_inside(const Point p);
};

class MiniDAK : public Graph_lib::Window {
private:
	In_box cmd_box; // input box for commands
	Vector_ref<DAKShape> shapes; // vector of shapes in the drawing
	int selected_shape; // selected shape (index into shapes) or -1 if none are selected
	Point mouse; // mouse position

public:
	MiniDAK(int w, int h);
	void add_shape(DAKShape *shape);
	int handle(int event); // handle events, calls on_* functions depending on event
	void on_enter_pressed();
	void on_mouse_click(int x, int y);
	void on_mouse_drag(int x, int y);
	void save(string filename);
	void load(string filename);
	void do_command(string command);
};
**/
