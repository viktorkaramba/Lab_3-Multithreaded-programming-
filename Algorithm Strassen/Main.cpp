#include <iostream>
#include "Algorithm_Strassen.h"
#include "Serial_Version.h"
#include "Multithreaded_Version.h"
#include "Simple_Timer.h"
#include <cstdlib>
#include <time.h>

using namespace std;



int main()
{
	
	srand (time(NULL));
	std::vector<std::vector<int>> A1;
	int row = rand() % 1 + 15;
	Matrix<int> A(row, row);
	Matrix<int> B(row, row);
	Matrix<int> C(row, row);
	int data;
	for (int i = 0; i < row; i++) {
		std::vector<int> A2;
		for (int j = 0; j < row; j++) {
			data = rand() % 50;
			A2.push_back(data);
		}
		A1.push_back(A2);
		A2.clear();
	}

	A.SetData(A1);
	B.SetData(A1);
	
	//cin >> A;
	//cin >> B;
	Simple_Timer p;
	Algorithm_Strassen<int>* sum = new Multithreaded_Version<int>(A, B, C, row);
	C.Print();

}

