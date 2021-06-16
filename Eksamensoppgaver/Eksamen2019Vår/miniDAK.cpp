
/**--start comment-------
#include "miniDAK.h"

//using namespace std;
//using namespace Graph_lib;


bool is_inside_rectangle(int x, int y, int r_x, int r_y, int r_width, int r_height){
    if (x < r_x || x > r_x + r_width){return false;}
    else if(y < r_y || y> r_y + r_height){return false;}
    return true;
}

bool is_inside_circle(int x, int y, int c_x, int c_y, int c_rad){
    int r = c_rad*c_rad;
    int x_diff = (x-c_x)*(x-c_x);
    int y_diff = (y-c_y)*(y-c_y);
    if (x_diff + y_diff < r){return true;}
    return false;
}

Color string_to_color(string s){
    if (colors.find(s)==colors.end()){
        throw "Color not found " + s;
    }
    return colors.at(s);
}

bool operator==(const Color& lhs, const Color& rhs){
    if (backColors.at(lhs)==backColors.at(rhs)){
        return true;
    }else{return false;}
}

string color_to_string(Color c){
    for (auto e : colors){
        if (c == e.second){
            return e.first;
        }
    }
    return "Unknown color";
}

string DAKRectangle::to_string(){
	Color c = get_color();
	Point xy = rect.point(0);
    stringstream ss;
	ss << "rect " << color_to_string(c) << " " << xy.x << " " << xy.y << " ";
    ss << rect.width() << " " << rect.height(); 
	return ss.str();
}

bool DAKRectangle::is_inside(const Point p){
	Point xy = rect.point(0);
	return is_inside_rectangle(p.x, p.y, xy.x, xy.y, rect.width(), rect.height());
}

string DAKCircle::to_string(){
    Color c = get_color();
	Point xy = circle.point(0);
    stringstream ss;
	ss << "circle " << color_to_string(c) << " " << xy.x << " " << xy.y << " ";
    ss << circle.radius(); 
	return ss.str();
}

bool DAKCircle::is_inside(const Point p){
    Point xy = circle.point(0);
    return is_inside_circle(p.x, p.y, xy.x, xy.y, circle.radius());
}

MiniDAK::MiniDAK(int w, int h)
		: Graph_lib::Window({0, 0}, w, h, "MiniDAK"),
		  cmd_box({100, 0}, 200, 25, "Command:"),
		  selected_shape(-1)
{
	attach(cmd_box);

	/*
	Rectangle *bg = new Rectangle({-10, 30}, 10000, 10000);
	bg->set_fill_color(Color::white);
	attach(*bg);
	*/

	/*
	DAKRectangle *rect = new DAKRectangle({x_max()/2, y_max()/2}, 100, 200);
	add_shape(rect);

	DAKCircle *circle = new DAKCircle({x_max()/2, y_max()/2}, 100);
	add_shape(circle);
	*/
/* <-start comment ---------
}


void MiniDAK::add_shape(DAKShape *shape) {
	shape->attach_to(*this);
	shapes.push_back(shape);
	cout << shape->to_string() << endl;
	redraw();
}


int MiniDAK::handle(int event) {
	//cout << "event" << event << endl;
	//
	if (event == FL_KEYUP) {
		int key = Fl::event_key();
		if (key == FL_Enter) {
			on_enter_pressed();
		}
	}

	if (event == FL_PUSH) {
		on_mouse_click(Fl::event_x(), Fl::event_y());
		redraw();
		//return 1;
	}
	
	if (event == FL_DRAG) {
		on_mouse_drag(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	}

	return Graph_lib::Window::handle(event);
}


void MiniDAK::on_enter_pressed(){
	try{
		do_command(cmd_box.get_string());
		cmd_box.clear_value();
	}catch(string err){
		cout << "Error: " << err << endl;
	}
}

void MiniDAK::on_mouse_click(int x, int y){
	mouse = Point{x,y};
	selected_shape = -1;
	for (unsigned int i=0; i<shapes.size(); ++i){
		if (shapes[i].is_inside(mouse)){
			selected_shape = i;
		}
	}
}

void MiniDAK::on_mouse_drag(int x, int y){
    if (selected_shape >= 0){
	shapes[selected_shape].move(x-mouse.x,y-mouse.y);
    }
	mouse = Point{x,y};
}


void MiniDAK::save(string filename){
	ofstream ost{filename};
	if (!ost){
		throw "Could not open file " + filename;
	}
	for (auto shape : shapes){
		ost << shape->to_string() << endl;
	}
}

void MiniDAK::load(string filename){
	ifstream ist{filename};
	if (!ist){
		throw "Could not open file " + filename;
	}
	int lineNumber=1;
    string s;
	while (getline(ist,s)){
        try{
            do_command(s); 
	    }
        catch(string e){
		cout << "Error at line " << lineNumber << ": "<< e << endl;
	    }
        lineNumber += 1;
    }
}


void MiniDAK::do_command(string command){
    stringstream ss{command};
    string cmd;
    ss >> cmd;
    if (cmd == "rect"){
        string color;
        int x,y,w,h;
        ss >> color >> x >> y >> w >> h;
        if (ss.fail()){
            throw string("Invalid arguments");
        }
        DAKRectangle *shape = new DAKRectangle{{x,y},w,h};
        shape -> set_color(string_to_color(color));
        add_shape(shape);
    }else if(cmd == "circle"){
        string color;
        int x,y,r;
        ss >> color >> x >> y >> r;
        if (ss.fail()){
            throw string("Invalid arguments");
        }
        DAKCircle* shape = new DAKCircle{{x,y},r};
        shape -> set_color(string_to_color(color));
        add_shape(shape);
    }else if(cmd == "save"){
        string filename;
        ss >> filename;
        if (filename.size()==0){
            throw string("Missing filename");
        }
        save(filename);
    }else if(cmd == "load"){
        string filename;
        ss >> filename;
        if (filename.size()==0){
            throw string("Missing filename");
        }
        load(filename);
    }else{
        throw "Unknown command" + cmd;
    }
}
**/  //<- stop comment

