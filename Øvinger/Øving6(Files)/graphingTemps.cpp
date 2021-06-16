#include "graphingTemps.h"

//Opg. 5

void graphingTemps(vector<Temps> vec){
    double minTemp = 100.0;
	double maxTemp = -100.0;
    for (unsigned int i=0;i<vec.size();++i){
		Temps t = vec[i];
		if (t.getMax()>maxTemp){
			maxTemp=t.getMax();
		}if (t.getMin() < minTemp){
			minTemp = t.getMin();
		}
	}
	
	int lenght_vec = vec.size();   //366 elementer
	
    using namespace Graph_lib;
	Point tl{200,200};
	constexpr int width = 800;
	constexpr int height = 400;
	constexpr int xOffset = 40;
	constexpr int yAxis = height-100;   //=300
	constexpr int notchesY = 6;
	double scaling = yAxis/(maxTemp-minTemp);

	
	Simple_window win {tl, width,height,"Temperatures Feb 2018-Jan 2019"};
	Axis xa {Axis::x, Point{xOffset,height/2}, lenght_vec*2,12,"Jan Feb Mars Apr Mai Jun Jul Aug Sep Oct Nov Dec"}; //hvordan fordele én måned på hver notch?
	Axis ya {Axis::y, Point{xOffset,height/2 + yAxis/2}, yAxis,notchesY,"Degrees"};	
	
	Open_polyline poly_maxTemp;
	Open_polyline poly_minTemp;
	for (int i=0; i<vec.size();++i){
		Temps t = vec[i];
		double maxT = t.getMax()*scaling;
		double minT = t.getMin()*scaling;
		int max = static_cast<int>(round(maxT));     //Må man runde av slik?? 
		int min = static_cast<int>(round(minT));  
		poly_maxTemp.add(Point{2*i+xOffset,-max+height/2});
		poly_minTemp.add(Point{2*i+xOffset, -min+height/2});
	}
	poly_maxTemp.set_color(Color::red);
	poly_minTemp.set_color(Color::blue);

	Text t_max {Point{xOffset/2-10,height/2+10}, "Max"};
	Text t_min {Point{xOffset/2-10,height/2+30}, "Min"};
	t_max.set_color(Color::red);
	t_min.set_color(Color::blue);
	t_max.set_font_size(8);
	t_min.set_font_size(8);

	int scalingYAxis = yAxis/notchesY;
	Text t_0 {Point{xOffset-15,height/2}, "0"};
	Text t_10 {Point{xOffset-15,height/2-1*scalingYAxis}, "10"};
	Text t_20 {Point{xOffset-15,height/2-2*scalingYAxis}, "20"};
	Text t_N10 {Point{xOffset-15,height/2+1*scalingYAxis}, "-10"};
	Text t_N20 {Point{xOffset-15,height/2+2*scalingYAxis}, "-20"};
	t_0.set_font_size(9);
	t_10.set_font_size(9);
	t_20.set_font_size(9);
	t_N10.set_font_size(9);
	t_N20.set_font_size(9);

	win.attach(poly_maxTemp);
	win.attach(poly_minTemp);
	win.attach(t_0);
	win.attach(t_10);
	win.attach(t_20);
	win.attach(t_N10);
	win.attach(t_N20);
	win.attach(t_max);
	win.attach(t_min);
	win.attach(xa);
	win.attach(ya);
	win.wait_for_button();
}