#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startvalue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& a, int& b);

void randomizeVector(vector<int>& vec, int n);

void sortVector(vector<int>& vec);
double medianOfVector(vector<int> vec);

struct Student {
	string name;
	string studyProgram;
	int age;
};
void printStudent(const Student& stud);

string randomizeString(int numberOfChar, char downLim, char upLim);
string readInputToString(int n, char downLim, char upLim);
int countChar(string str, char c);

void getGuess(int size, string& guess);
int checkCharactersAndPosition(string guess, string code);
int checkCharacters(string guess, string code);

