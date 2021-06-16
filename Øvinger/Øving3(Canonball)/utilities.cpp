
#include "utilities.h"


int random_number(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int tilfeldig_tall = rand();
    return tilfeldig_tall;
} 

int randomWithLimits(int LLimit, int ULimit){
	return rand()%(ULimit-LLimit+1) + LLimit;
}
