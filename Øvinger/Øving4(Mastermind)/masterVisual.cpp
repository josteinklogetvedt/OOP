#include "masterVisual.h"

void addGuess(MastermindWindow& mwin,const string code, const int size, const char startLetter, const int round){
    int colorvalue = 0;
    for (int i=1; i<size+1;++i){
        colorvalue = code[i-1]-startLetter+1;
        mwin.vr.push_back(new Rectangle{Point{padX*(2*i-1),3*padY +padY*(2*round)},padX,padY});
        mwin.vr[mwin.vr.size()-1].set_fill_color(colorvalue);
        mwin.attach(mwin.vr[mwin.vr.size()-1]);
    }
}

void addFeedback(MastermindWindow &mwin,int correctPosition, int correctCharacter, const int size,
 const int round){
    int colorvalue;
    for (int j=1; j<size+1;++j){
        if (correctPosition>0){
            colorvalue = Color::white; 
            correctPosition -=1;
        }else if (correctCharacter >0){
            colorvalue = Color::black; 
            correctCharacter-=1;
        }else{
            colorvalue = Color::gray; 
        }
        mwin.vc.push_back(new Circle{Point{padX*(2*size+1)+2*radCircle*j,3*padY+padY/2+padY*2*round},radCircle});
        mwin.vc[mwin.vc.size()-1].set_fill_color(colorvalue);
        mwin.attach(mwin.vc[mwin.vc.size()-1]);
    }
    
}

void hideCode(MastermindWindow &mwin,const int size){
	mwin.vr.push_back(new Rectangle{Point{padX,3*padY},winW-size*padX,padY});
	mwin.vr[mwin.vr.size()-1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size()-1]);
}

MastermindWindow::MastermindWindow(Point xy,int w, int h, const string& title):Window(xy,w,h,title),
    button_pressed{false},
	guessBtn{upperLeftCornerBtn,btnW,btnH,"Add",cb_guess},
    guess{upperLeftCornerInBox,inBoxW,inBoxH,"Guess"}
    {
        attach(guess);
        attach(guessBtn);
};

 string MastermindWindow::wait_for_guess(){
		while (!button_pressed)
			Fl::wait();
		button_pressed = false;
		Fl::redraw();
        string newGuess =guess.get_string();
        guess.clear_value();
        return newGuess;
}


string MastermindWindow::getInput(unsigned int n, char lower, char upper){
	bool validInput = false;
	string guess;
	while(!validInput){
		guess.clear();
		string input = wait_for_guess();
		if(input.size() == n){
			for(unsigned int i = 0; i < n; i++){
				char ch = input[i];
				if(isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch)){
					guess += toupper(ch);
				} 
				else 
				break;
			}
		}
		if(guess.size() == n) validInput=true;
		else cout<<"Invalid input guess again\n";
	}
	return guess;
}