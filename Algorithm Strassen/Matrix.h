#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
private:
	int count_of_rows;
	int count_of_columns;
	std::vector<std::vector<T>> data;
	template<typename T1> friend istream& operator>> (istream& in, Matrix<T1>& A);
public:
	Matrix<T>();
	Matrix<T>(const int& cofr, const int& cofc);
	std::vector<std::vector<T>> GetData();
	int GetCount_Of_Rows();
	int GetCount_Of_Columns();
	void SetData(std::vector<std::vector<T>> data_);
	void Print();
	void SetElement(const T& d, const int& row,const int& column);

	
};


#include "Matrix.cpp"
#endif
