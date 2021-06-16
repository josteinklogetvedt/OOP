//Øving 4
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;
//1a) -- skriver ut v0=5, increment = 2, iterations = 10, result = 25.
//1e) -- Ettersom man ikke kan returne flere enn én verdi fra en funksjon må man bruke pass-by-reference
//       og funksjonstypen void for å kunne endre på noe inni funksjonen som blir med videre. 

int main()
{
	
	srand(time(nullptr));
	int answer = 0;
	cout << "MENU. Write in the desired option\n 0) Exit\n 1) testCallByValue\n 2) testCallByReference\n 3) testVectorSorting\n 4) printStudent\n 5) testString\n 6) Mastermind\n";
	cin >> answer;
	switch(answer){
		case 1: testCallByValue();
			break;
		case 2: testCallByReference();
			break;
		case 3: testVectorSorting(); //Opg 2&3.
			break;
		case 4:{  //Opg 4.
			Student person;
			person.name = "Jostein";
			person.studyProgram = "Fysmat";
			person.age = 21;
			printStudent(person);
		 	}
			break;
		case 5: //Opg 5.
			testString();
			break;
		case 6: //Opg. 6
			playMastermind();
			break;
	default: 
		break;
	}
	

	keep_window_open();
	return gui_main();
}


