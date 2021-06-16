//Øving 8
#include "MeetingWindow.h"

int main(){
	Car audi{2};
	Car* car = &audi; 
	const Person per{"Per", "Email",car};
	const Person aune{"Aune", "Mail"};
	cout << per << aune;
	
	Campus d{Campus::Oslo};
	cout << d << endl;

	const Person* perP = &per;
	Meeting meetup{2,23,26,Campus::Alesund,"Tur",perP};
	cout << meetup;
	

	MeetingWindow win{Point{100,100},400,300,"My GUI"};

	gui_main();
	win.printPersons();

	keep_window_open();
}


