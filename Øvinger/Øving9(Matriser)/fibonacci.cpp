#include "fibonacci.h"

void fillInFibonacciNumbers(int result[], int length){
    result[0] = 0;
    result[1] = 1;
    for (int i=2; i < length; ++i){
        result[i] = result[i-1] + result[i-2];
    }
}

void printArray(int arr[], int length){
    for (int i=0; i<length; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void createFibonacci(){
    std::cout << "Number of elements in the fibonacci sequence: ";
    int n;
    std::cin >> n;
    int* pArr = new int[n];
	fillInFibonacciNumbers(pArr,n);
	printArray(pArr,n);
    delete [] pArr;
}

void keep_window_open()
{
	std::cin.clear();
	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
	return;
}
