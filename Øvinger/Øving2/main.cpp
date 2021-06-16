// Øving 2
#include "std_lib_facilities.h"

// 1a)
void inputAndPrintInteger(){
	cout << "Skriv inn et tall: ";
	int tall = 0;
	cin >> tall;
	cout << "Du skrev: " << tall << "\n";
}

// 1b)
int inputInteger(){
	cout << "Skriv inn et tall: ";
	int tall = 0;
	cin >> tall;
	return tall;
}

// 1c)
void inputIntegersAndPrintSum(){
	int tall_1 = inputInteger();
	int tall_2 = inputInteger();
	cout << "Summen av tallene: " << tall_1+tall_2 << "\n";
}
// 1d)
//Valgte inputInteger for at tallene skal lagres og adderes med hverandre etterpå

// 1e)
bool isOdd(int number){
	//bool verdi = false;
	if (number%2==0){
		return false;
	}else{
		//verdi = true;
		return true;
	}
}

// 1f)
void printHumanReadableTime(int sekunder){
	int timer = sekunder/3600;
	int minutter = sekunder/60 - timer*60;
	sekunder = sekunder - 3600*timer - 60*minutter;
	cout << timer << " timer, "
		<< minutter << " minutter og "
		<< sekunder << " sekunder\n";
}
// 2a)
void addNumbers(){
	int antall = 0;
	cout << "Hvor mange tall skal summeres? ";
	cin >> antall;
	int k = 0;
	for (int i=1; i<antall+1; ++i){
		k+= inputInteger();
	}
	cout << "Summen av tallene ble: " << k << "\n";
}

// 2b)
void addManyNumbers(){
	int n = inputInteger();
	int k = n;
	while (n){
		n = inputInteger();
		k+=n;
	}
	cout << "Summen av tallene ble: " << k << "\n";
}
//2c) -- For-løkke på a) fordi man får oppgitt hvor mange ganger man skal kjøre løkka og 
// while-løkke på b) fordi man nettopp ikke får vite antall iterasjoner.

//2d)
double inputDouble(){
	cout << "Skriv inn ett tall: ";
	double tall = 0.0;
	cin >> tall;
	return tall;
}

//2e)
void konvertere(){
	double kurs = 9.75;
	cout << "Konverterer fra NOK til Euro. \n";
	double penger = inputDouble();
	while (penger<0){
		cout << "Det må være et positivt tall.";
		penger = inputDouble();
	}
	penger = penger/kurs;
	cout << "Det blir " << setprecision(2) << fixed << penger << " euro \n";
}
//2f) Må bruke inputDouble fordi brukeren må kunne konvertere desimaltall også. 
//    Har brukt returtypen void fordi ingenting skal returneres, men bare skrive ut til skjerm.

// 3a)
int velgfFunksjon(){
	int valg = 0;
	cout << "Velg funksjon: \n 0) Avslutt\n 1) Summer to tall\n 2) Summer flere tall\n 3) Konverter NOK til Euro\n 4) Gangetabell\n 5) Annengradsliknign.\n 6) Pythagoras \n 7) Sammenligne laantyper \n Angi valg (0-6): ";
	cin >> valg;
	return valg; 
}
// 3b)
void gangetabell(){
	int høyde = 0;
	int bredde = 0;
	cout << "Lengden, bredden til tabellen: ";
	cin >> høyde >> bredde;
	for (int i=1; i<høyde+1;++i) {
		for (int j=1; j<bredde+1; ++j) {
			cout << setw(5);
			cout << i*j;
		}
		cout << "\n";
	}
}

// 4a)
double discriminant(double a, double b, double c){
	return b*b-4*a*c;
}
//4b)
void printRealRoots(double a, double b, double c){
	double d = discriminant(a,b,c);
	if (d<0){
		cout << "No real roots\n";
	}else if (d==0){
		cout << "One root; " << -b/(2*a) << "\n";
	}else{
		double x_1 = (-b+sqrt(d))/2*a;
		double x_2 = (-b-sqrt(d))/2*a;
		cout << "Two roots; " << x_1 << " " << x_2 << "\n";
	}
}
//4c)
void solveQuadraticEquations(){
	double a = 0;
	double b = 0.0;
	double c = 0.0;
	cout << "Skriv inn 3 desimaltall hhv. a, b og c: ";
	cin >> a >> b >> c;
	printRealRoots(a,b,c);
}


// 5
#include "Graph.h"
#include "Simple_window.h" 

void pythagoras(){
	using namespace Graph_lib;
	Simple_window win{Point{100,100},400,400,"Pythagoras"};
	Polygon rightTriangle;
	rightTriangle.add(Point{150,100});
	rightTriangle.add(Point{150,200});
	rightTriangle.add(Point{250,200});
	rightTriangle.set_fill_color(Color::red);

	Polygon downSquare;
	downSquare.add(Point{150,200});
	downSquare.add(Point{250,200});
	downSquare.add(Point{250,300});
	downSquare.add(Point{150,300});
	downSquare.set_fill_color(Color::green);
	
	Polygon leftSquare;
	leftSquare.add(Point{150,100});
	leftSquare.add(Point{150,200});
	leftSquare.add(Point{50,200});
	leftSquare.add(Point{50,100});
	leftSquare.set_fill_color(Color::blue);

	Polygon lastSquare;
	lastSquare.add(Point{150,100});
	lastSquare.add(Point{250,200});
	lastSquare.add(Point{350,100});
	lastSquare.add(Point{250,0});
	lastSquare.set_fill_color(Color::magenta);
	
	win.attach(lastSquare);
	win.attach(leftSquare);
	win.attach(downSquare); 
	win.attach(rightTriangle); 
	win.wait_for_button();
}

//6a)
vector<int> calculateSeries(int laan, int rente, int aar){
	vector<int> _vector;
	double gjen_laan = static_cast<double>(laan);
	double avdrag = laan/aar;
	for (int j=0; j<aar;++j){
		double innbetaling = avdrag + (0.01)*rente*gjen_laan;
		gjen_laan -= avdrag;
		_vector.push_back(static_cast<int>(innbetaling));
	}
	return _vector;
}
//6b)
vector <int> calculateAnnuity(int laan, int rente, int aar){
	double d = 1-pow((1+rente*0.01),-aar);
	double innbetaling = static_cast<double>(laan)*(rente*0.01)*(1/d);
	vector<int> _vector;
	for (int j=0; j<aar;++j){
		_vector.push_back(static_cast<int>(innbetaling));
	}
	return _vector;
}
#include <iomanip>
//6c)
void printAnnuityAndSeries(int laan, int rente, int aar){
	vector<int> annuitet = calculateAnnuity(laan, rente, aar);
	vector<int> serie = calculateSeries(laan, rente, aar);
	cout << "Aar	Annuitet 	Serie 	Differanse\n";
	int serie_total = 0;
	int annuitet_total = 0;
	for (int j=1; j<aar+1;++j){
		int differanse = annuitet[j-1]-serie[j-1];
		cout << setw(3) << j;
		cout << setw(13) << annuitet[j-1];
		cout << setw(13) << serie[j-1];
		cout << setw(13) << differanse << "\n";
		serie_total += serie[j-1];
		annuitet_total += annuitet[j-1];
	}
	cout << "Total" << setw(11) << annuitet_total << setw(13) << serie_total << setw(13) << annuitet_total-serie_total << "\n";
}

int main(){

	//printHumanReadableTime(10000);

	int valg = velgfFunksjon();
	while (valg){
		if (valg == 1){
			inputIntegersAndPrintSum();
		}else if (valg==2){
			addNumbers();
		}else if (valg==3){
			konvertere();
		}
		else if(valg == 4){
			gangetabell();
		}else if(valg == 5){
			solveQuadraticEquations();
		}else if(valg==6){
			pythagoras();
		}else if(valg==7){
			int laan = 0;
			int rente = 0;
			int aar = 0;
			cout << "Skriv total laan, rente (i prosent) og antall aar: ";
			cin >> laan >> rente >> aar;
			printAnnuityAndSeries(laan, rente, aar);
		}
		valg = velgfFunksjon();
	}

	keep_window_open();
}

