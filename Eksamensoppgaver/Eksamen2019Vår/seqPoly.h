#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"


vector<string> getSequence(string s);
vector<string> fileToSequence(string filename);
vector<Point> seqToPoints(vector<string> coordinates);
void drawPoints(vector<Point> points, Simple_window& win);
void menu();