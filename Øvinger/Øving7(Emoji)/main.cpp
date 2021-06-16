#include "utilities.h"
#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main(){
	testAnimal();
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};
	
	Point cEmptyFace{100,100};
	EmptyFace emptyFace{cEmptyFace,100,100,emojiRadius};
	
	Point cSmilingFace{300,100};
	SmilingFace smilingFace{cSmilingFace,300,100,emojiRadius};

	Point cSadFace{500,100};
	SadFace sadFace{cSadFace,500,100,emojiRadius};

	Point cAngryFace{100,300};
	AngryFace angryFace{cAngryFace,100,300,emojiRadius};

	Point cWinkingFace{300,300};
	WinkingFace winkingFace{cWinkingFace,300,300,emojiRadius};

	Point cSurprisedFace{500,300};
	SurprisedFace surprisedFace{cSurprisedFace,500,300,emojiRadius};

	surprisedFace.attach_to(win);
	winkingFace.attach_to(win);
	angryFace.attach_to(win);
	sadFace.attach_to(win);
	smilingFace.attach_to(win);
	emptyFace.attach_to(win);

	win.wait_for_button();
	keep_window_open();
}


