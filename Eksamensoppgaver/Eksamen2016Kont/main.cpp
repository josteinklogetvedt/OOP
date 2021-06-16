#include "simpleGraphics.h"
#include "std_lib_facilities.h"



int main()
{	
	Simple_window win{{100,100},600,400,"SimpleGraphics"};
	int x[] = {0, 4, 13, 8, 21, 20};
	int y[] = {-1, 11, 4, 9, 14, 10};
	//plotScaled(win, x, y, N);
	plotMathFuncs(win, 2);
}


