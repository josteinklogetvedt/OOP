
#include "std_lib_facilities.h"
#include "snake.h"
#include <thread>

int main()
{	srand(time(nullptr));

	Simple_window win{Point{50,50},WIN_WIDTH,WIN_HEIGHT,"snake"};
	vector<Rectangle*> snake;
	initSnake(snake, win);
	//win.wait_for_button();
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000*5));

	Rectangle piece{Point{10,10},RECT_WIDTH,RECT_HEIGHT};
	piece.set_fill_color(Color::green);
	win.attach(piece);
	placePiece(piece,snake);
	Direction dir = Direction::RIGHT;

	auto nextDrawing = std::chrono::steady_clock::now();
	while(true){
		
		moveSnake(snake,win,dir);
		std::this_thread::sleep_until(nextDrawing);
		nextDrawing += std::chrono::microseconds(1'000'0000 / 60);

		dir = steer(dir);
		Fl::check();
		Fl::redraw();
	}
	//win.redraw();
	//win.wait_for_button();
}

