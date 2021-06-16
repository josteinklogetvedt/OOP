
#include "Observasjoner.h"


int main(){

	vector<Obs> obs;
	obs = readFromFile("observasjoner.txt");
	for (auto p : obs){
		cout << p.x << " " << p.y << endl;
	}
	report(obs,1);


	keep_window_open();
}

