#pragma once
#include "Graph.h"
#include "Simple_window.h"

constexpr int N = 6;
constexpr int radius = 3; 
constexpr float PI = 3.141597;

void plotPoints(Simple_window& win, int x[], int y[], int n);
void plotLines(Simple_window& win, int x[], int y[], int n);

void alim(int a[], int n, int& amin, int& amax);

int scaleX(Simple_window& win, int x, int xmin, int xmax);
int scaleY(Simple_window& win, int y, int ymin, int ymax);

void plotScaled(Simple_window& win, int x[], int y[], int n, Color c, int xmin, int xmax, int ymin, int ymax);
void plotScaled(Simple_window& win, int x[], int y[], int n, Color c=Color::black);

float sinDeg(int deg);

void plotMathFuncs(Simple_window& win, int num);
