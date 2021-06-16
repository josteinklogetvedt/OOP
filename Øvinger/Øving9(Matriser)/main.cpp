
#include "fibonacci.h"
#include "matrix.h"
#include "intermezzo.h"

int main()
{
	using namespace std;
	//createFibonacci();
	
	//dummyTest();

	Matrix m{3,4};
	cout << m << endl;
	Matrix m1{3};
	cout << m1 << endl;
	m1 = m;  //Kopiering
	m = {1,2};  
	cout << m1 << endl;
	cout << m << endl;

	Matrix A{2,2};
	Matrix B{2,2};
	Matrix C{2,2};
	
	A.set(1,1,1.0); A.set(1,2,2.0); A.set(2,1,3.0); A.set(2,2,4.0);
	B.set(1,1,4.0); B.set(1,2,3.0); B.set(2,1,2.0); B.set(2,2,1.0);
	C.set(1,1,1.0); C.set(1,2,3.0); C.set(2,1,1.5); C.set(2,2,2.0);

	A += B + C;
	cout << A << endl;	

	keep_window_open();
}


