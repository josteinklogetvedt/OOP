#include "std_lib_facilities.h"
#include "Plant.h"
#include "Series.h"
#include "Nettverk.h"

int main()
{	
	//srand(time(nullptr));
	//menu();

	//findHighestIter(1e-6);
	//testnFacRobust();

	Network net = loadNetwork("airports.txt", true);
	auto m = net.traverse("BOO");
	for (auto p: m){
		cout << p.first << " " << p.second << endl;
	}

	keep_window_open();
}

