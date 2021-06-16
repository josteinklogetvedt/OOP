#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;
//For vectors
void printVector(vector<string> vec){
    for (vector<string>::iterator it=vec.begin(); it<vec.end(); ++it){
        cout << *it << endl;
    }
}

void printVectorReversed(vector<string> vec){
    for (vector<string>::reverse_iterator it=vec.rbegin(); it<vec.rend(); ++it){
        cout << *it << endl;
    }
}

void replaceVector(vector<string>& vec, string old, string replacement){
    for (vector<string>::iterator it=vec.begin(); it<vec.end(); ++it){
        if (*it == old){
            it = vec.erase(it);
            it = vec.insert(it, replacement);
        }
    }
}
//For sets
void printSet(set<string> sett){
    for (set<string>::iterator it=sett.begin(); it !=sett.end(); ++it){
        cout << *it << endl;
    }
}

void printSetReversed(set<string> sett){
    for (set<string>::reverse_iterator it=sett.rbegin(); it!=sett.rend(); ++it){
        cout << *it << endl;
    }
}


void replaceSet(set<string>& sett, string old, string replacement){
    for (set<string>::iterator it=sett.begin(); it != sett.end(); ++it){
        if (*it == old){
            it = sett.erase(it);
            it = sett.insert(it, replacement);
        }
    }
}

void exampleUseOfIterators(){
    vector<string> hei{"Lorem", "Ipsum", "Dolor", "Sit"};
	printVector(hei);
    cout << "REVERSED:" << endl;
	printVectorReversed(hei);
    cout << "REPLACE LOREM WITH LATIN: " << endl;
	replaceVector(hei, "Lorem", "Latin");
	printVector(hei);

	set<string> howdy{"Lorem", "Ipsum", "Dolor", "Sit"};
    cout << "SIMILAR FUNCTIONS FOR SET. REPLACE SIT WITH SATT AND PRINT REVERSED:" << endl;
	printSet(howdy);
    cout << endl;
	replaceSet(howdy, "Sit", "Satt");
	printSetReversed(howdy);
}