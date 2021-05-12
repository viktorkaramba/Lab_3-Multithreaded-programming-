#pragma once
#include "Tests.h"
#include "Simple_Timer.h"
#include <fstream>

using namespace std;
std::vector<float> p1;
std::vector<float> p2;

/*!Function for writing a table to a file*/
void Table(){
	string path = "Table.txt";
	fstream fs;
	fs.open(path,fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		std::cout << "Error" << std::endl;
	}
	else {
		fs << "-----------------------------------------------------------------------------------------------------------------------" << "\n";
		fs << "                              3            5             10           15           20         30          40         50" << "\n";
		std::vector<Matrix<int>> vecMatrix_A = Tests_Matrix();
		std::vector<Matrix<int>> vecMatrix_B = Tests_Matrix();
		std::vector<Matrix<int>> vecMatrix_C1;
		std::vector<Matrix<int>> vecMatrix_C2;
		
		for (size_t i = 0; i < count_row.size(); i++)
		{
			Simple_Timer p_1 ;
			vecMatrix_C1.push_back(The_Product_Of_Matrices_Serial(vecMatrix_A[i], vecMatrix_B[i], count_row[i]));
			p_1.~Simple_Timer();
			p1.push_back(p_1.GetResult());
			
		}
		fs << "Serial version            ";
		for (size_t i = 0; i < count_row.size(); i++)
		{
			fs<< p1[i] << "     ";
		}
	
		for (size_t i = 0; i < count_row.size(); i++)
		{
			Simple_Timer p_2;
			vecMatrix_C2.push_back(The_Product_Of_Matrices_Multithreaded_Version(vecMatrix_A[i], vecMatrix_B[i], count_row[i]));
			p_2.~Simple_Timer();
			p2.push_back(p_2.GetResult());

		}
		fs << "\n" << "Multi-threaded version    ";
		for (size_t i = 0; i < count_row.size(); i++)
		{
			fs << p2[i] << "     ";
		}
		fs << "\n"<<"-----------------------------------------------------------------------------------------------------------------------" << "\n";
	}
}