#include "utilities.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
		}
	return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
		}
}

void swapNumbers(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void randomizeVector(vector<int>& vec, int n){
	for (int i = 0; i < n; ++i)
		vec.push_back(rand() % 101);
}


void sortVector(vector<int>& vec){
	for (int i = 0; i < vec.size(); ++i){
		int j = i;
		while ((j>0) && (vec[j-1] > vec[j])){
			swapNumbers(vec[j-1], vec[j]);
			j = j-1;
		}
	}
}

double medianOfVector(vector<int> vec){
	int length = vec.size();
	double median = 0;
	if (length % 2 == 0){
		median = (vec[length/2]+vec[length/2-1])*0.5;
	}else{
		median = vec[length*0.5 - 0.5];
	}
	return median;
}

void printStudent(const Student& person){
	cout << person.name << " " << person.studyProgram << " " << person. age << endl;
}

string randomizeString(int numberOfChar, char downLim, char upLim){
	string randomString;
	for (int i = 0; i < numberOfChar; ++i){
		randomString += downLim + (rand() % (upLim - downLim));
	}
	return randomString;
}

string readInputToString(int n, char downLim, char upLim){
	string str;
	downLim = toupper(downLim);
	upLim = toupper(upLim);
	cout << "Write in " << n << " characters(between " << downLim << " and " << upLim << "):\n";
	while (str.size() < n){
		char c;
		cin >> c;
		if ((toupper(c)<=upLim) && (toupper(c)>=downLim)){
			str += c;
		}else{
			cout << "Write a character inbetween the limits.\n";
		}
	}
	return str;
}

int countChar(string str, char c){
	int count = 0;
	for (int i =0; i<str.size(); ++i){
		if (c==str[i]){
			count +=1;
		}	
	}
	return count;
}

int checkCharactersAndPosition(string guess, string code){
	int count = 0;
	for (int j=0; j<guess.size();++j){
		if (code[j] == guess[j]){
			count += 1;
		}
	}
	return count;
}

int checkCharacters(string guess, string code){ 
	set<char> guessSet;
	for (char ch : guess) {
		guessSet.insert(ch);
	}
	int count = 0;
	for (char ch : guessSet) {
		int guessCount = countChar(guess, ch);
		int codeCount = countChar(code, ch);
		count += min(guessCount, codeCount);
	}
	return count;
}
