//Øving 1

#include "std_lib_facilities.h"

// Oppgave 1 - oversetter koden til Python
//def isFibonacciNumber(n):
//	a=0
//	b=1
//	temp = 0
//	while b<n:
//		temp=b
//		b+=a
//		a=temp
//	return b==n

// Oppgave 2 - oversetter til C++
//a)
int maxOfTwo(int a, int b){
	if (a>b){
		cout << "A is greater than B\n";
		return a;
	}else {
		cout << "B is greater than or equal to A\n";
		return b;
	}
}

//c)
int fibonacci(int n){
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:\n";
	for (int x = 1; x<n+1; x+=1){
		cout << x << " " << b << "\n";
		int temp = b;
		b += a;
		a = temp;
	cout << "----\n";
	}
	return b;	
}

//d)
int squareNumberSum(int n){
	int totalSum = 0;
	for(int i=1; i<n+1; i+=1){
		totalSum += i*i;
		cout << i*i << "\n";
	}
	cout << totalSum << "\n";
	return totalSum; 
}

//e)
int triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":\n";
	while (acc<n){
		cout << acc << "\n";
		acc += num;
		num += 1;
	}
	cout << "\n";
	return 0;
}

//f)
bool isPrime(int n){
	for(int j=2; j<n;j+=1){
		if (n%j == 0){
			return false;
		}
	}
	return true;
}

//g)
int naivePrimeNumberSearch(int n){
	for (int number=2; number<n; number+=1){
		if (isPrime(number)){
			cout << number << " is a prime\n";
		}
	}
	return 0;
}

//h)
int findGreatestDivisor(int n){
	for (int divisor=n-1; divisor>0; divisor=divisor-1){
		if (n % divisor == 0){
			return divisor;
		}
	}
}

// C++ programs start by executing the function main
int main(){
	cout << "2a)\n" << maxOfTwo(5,6) << "\n";
	cout << "2c)\n" << fibonacci(5) << "\n";
	cout << "2d)\n" << squareNumberSum(4) << "\n";
	cout << "2e)\n" << triangleNumbersBelow(7) << "\n";
	cout << "2f)\n" << isPrime(13) << "\n";
	cout << "2g)\n" << naivePrimeNumberSearch(13) << "\n"; 
	cout << "2h)\n" << findGreatestDivisor(20) << "\n";
	keep_window_open();
}


