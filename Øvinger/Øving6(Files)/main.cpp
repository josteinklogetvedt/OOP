#include "graphingTemps.h"
//Øving 6

enum Animal{COW,GOAT, HORSE,DOG};

int main()
{
	//writeToFile();          //Skriver til fil ord for ord (bruker textfile.txt), overskriver det som står der allerede
	//addLineNumberToFile();  //Åpner fil, lager ny fil Numberedfilavn med nummererte linjer

	//characterCount("Grunnlov.txt");   //Funker ikke med Grunnlov.txt pga '§' ikke er i ASCII tabellen.
	
	
	//CourseCatalog dict = addSpesifiedCourses();
	//cout << dict;
	//dict.addCourse("TDT4102", "C++");  //Does not change with .insert() when key already exists. Must use [] to change value.
	//cout << dict;
	//dict.readFromFile("catalog.txt");  //Saves it to dict. 
	//cout << dict;
	
	
	//ifstream temp_file{"temps.txt"};
	//Temps t;
	//temp_file >> t;
	//cout << t;
	//vector<Temps> vec = readTempsFromFile("temps.txt");
	//for (unsigned int i=0;i<vec.size();++i){
	//	cout << vec[i];	
	//}

	//graphingTemps(vec);
	string str = "";
    if (true){
        getline(cin,str);
        //hasCaffeine = false;
    }
    cout << str << endl;
	keep_window_open();
}

