#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0
	<< " increment: " << increment
	<< " iterations: " << iterations
	<< " result: " << result << endl;
}

void testCallByReference() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimesRef(v0, increment, iterations);
	cout << "v0: " << v0
	<< " increment: " << increment
	<< " iterations: " << iterations
	<< endl;
}

void testVectorSorting(){
	vector<int> percentages;
	randomizeVector(percentages, 10);
	for (unsigned int j=0; j<percentages.size(); ++j){
		cout << percentages[j] << " ";
	}
	cout << "\nMedian before sorted: " << medianOfVector(percentages) << endl;
	cout << "Swapped: ";
	swapNumbers(percentages[0], percentages[1]);
	for (unsigned int j=0; j<percentages.size(); ++j){
		cout << percentages[j] << " ";
	}
	sortVector(percentages);
	cout << "\nMedian after sorted: " << medianOfVector(percentages) << endl;
	cout << "Sorted: ";
	for (unsigned int j=0; j<percentages.size(); ++j){
		cout << percentages[j] << " ";
	}
	cout << endl;
}

void testString(){
	string grades;
	grades = randomizeString(8, 'A', 'F');
	cout << "Grades: " << grades << endl;
	string str = readInputToString(4, 'a', 'z');
	cout << str << endl;
	cout << "Number of a's in inputString: " << countChar(str, 'a') << endl;
	//5h) - lager gradeCount
	vector<int> gradeCount;
	char c = 'A';
	int count = 0;
	for (int i=0; i<6;++i){
		gradeCount.push_back(countChar(grades, c));
		c += 1;
	}
	//Beregner snittet i grades
	double total = 0.0;
	for (int j=0; j<gradeCount.size();++j){
		total+= (5-j)*gradeCount[j];
	}
	cout << "Snittet til grades er: " << total/grades.size() << endl;
}
