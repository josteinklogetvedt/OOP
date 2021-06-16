#pragma once
#include "GUI.h"
  
using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public Button
{
	Cell state = Cell::closed;
	bool isMine;
	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}
public:
	Tile(Point pos, int size, Graph_lib::Callback cb, bool isMine=false)
		:Button{pos, size, size, "", cb}, isMine{isMine} {};
	
	Cell getState() const {return state; };

	bool getIsMine() const {return isMine; };
	void setIsMine(bool val) {isMine = val; }; 

	void setAdjMines(int n);

	void open();  // aapner ruten
	void flag();  // Flagger en rute
	void close();
};