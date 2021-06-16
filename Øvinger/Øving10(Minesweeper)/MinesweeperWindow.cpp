#include "MinesweeperWindow.h"
#include "std_lib_facilities.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize + 2*cellSize, title}, width{width}, height{height}, mines{mines}, 
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
	openedTiles{0}, flaggedTiles{0}, lost{false}, txtStatus{Point{2*cellSize,height*cellSize}, 2*cellSize, cellSize, "Status:"},
	txtFlagged{Point{Width()-cellSize,height*cellSize}, cellSize, cellSize, "Mines left:"},
	restartBtn{Point{0,height*cellSize+cellSize}, Width()/2, cellSize, "Restart", cb_restart},
	quitBtn{Point{Width()/2,height*cellSize+cellSize}, Width()/2, cellSize, "Quit", cb_quit}
{	
	attach(txtStatus);
	attach(txtFlagged); 
	attach(restartBtn);
	attach(quitBtn);
	writeFlaggedTiles(mines);
	txtStatus.put("Alive");
	txtStatus.show();
	restartBtn.hide();
	quitBtn.hide();

	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) { 
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}
	//Legg til miner paa tilfeldige posisjoner
	int count = 0;
	while (count < mines){
		int num = rand() % tiles.size();
		if (!tiles[num].getIsMine()){
			tiles[num].setIsMine(true);
			++count;
		} 
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int count = 0;
	for (int i=0; i<points.size(); ++i){
		if (at(points[i]).getIsMine()){
			++count;
		}
	}
	return count;
};

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy).getState() == Cell::closed){
		at(xy).open();
		openedTiles += 1;
		if (!at(xy).getIsMine()){
			int count = countMines(adjacentPoints(xy));
			if (count){
				at(xy).setAdjMines(count);
			}else{
				for (int i=0; i<adjacentPoints(xy).size(); ++i){
					openTile(adjacentPoints(xy)[i]);
				}
			}
		}else{
			lost = true;  
		}
	check_status();
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy).getState() != Cell::open){
		at(xy).flag();
		if (at(xy).getIsMine()){
			++flaggedTiles;
		}
		int num = mines-flaggedTiles;
		if (num>0){
			writeFlaggedTiles(num);
		}
	}
}

//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}
	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}
void MinesweeperWindow::cb_quit(Address, Address pw){
	reference_to<MinesweeperWindow>(pw).hide();
}

void MinesweeperWindow::cb_restart(Address, Address pw){
	auto& win = reference_to<MinesweeperWindow>(pw);
	win.newWindow();
	win.flush();
}

void MinesweeperWindow::check_status(){
	if (!lost && openedTiles == tiles.size()-mines){
		txtStatus.put("You won!");
		txtStatus.show();
		for (int i=0; i<tiles.size(); ++i){
			if (tiles[i].getIsMine() && tiles[i].getState() == Cell::closed){
				tiles[i].flag();
			}
		}
		writeFlaggedTiles(0);
		restartBtn.show();
		quitBtn.show();
	}else if(lost){
		txtStatus.put("You died!");
		txtStatus.show();
		for (int i=0; i<tiles.size(); ++i){
			if (tiles[i].getIsMine() && (tiles[i].getState() == Cell::closed || tiles[i].getState() == Cell::flagged)){
				tiles[i].open();
			}
		}
		restartBtn.show();
		quitBtn.show();
	}
}

void MinesweeperWindow::writeFlaggedTiles(int n){
	txtFlagged.put(to_string(n));
	txtFlagged.show();
}

void MinesweeperWindow::newWindow(){   //er det mulig å heller lage ett nytt vindu med new og delete?
	for (int i=0; i<tiles.size(); ++i){
		tiles[i].close();
		tiles[i].setIsMine(false);
	}
	int count = 0;
	while (count < mines){
		int num = rand() % tiles.size();
		if (!tiles[num].getIsMine()){
			tiles[num].setIsMine(true);
			++count;
		} 
	}
	writeFlaggedTiles(mines);
	txtStatus.put("Alive");
	txtStatus.show();
	restartBtn.hide();
	quitBtn.hide();
	lost=false;
	openedTiles = 0;
	flaggedTiles = 0;
}