#include <iostream>
#include "Matrix.h"
#include "Algorithm_Strassen.h"
#include "Algorithm_Strassen_Multithreded.h"
#include "Simple_Timer.h"

using namespace std;



int main()
{
	Simple_Timer p;
	Matrix<int> A(3, 3);
	Matrix<int> B(3, 3);
	Matrix<int> C(3,3);
	cin >> A;
	cin >> B;
	Algorithm_Strassen<int>(A, B, C, 3);
	C.Print();
}


