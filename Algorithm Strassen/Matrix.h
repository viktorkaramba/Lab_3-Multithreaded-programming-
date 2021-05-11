#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <iostream>


template<typename T>
class Matrix
{
private:
	int count_of_rows;
	int count_of_columns;
	std::vector<std::vector<T>> data;
	template<typename T1> friend std::istream& operator>> (std::istream& in, Matrix<T1>& A);
public:
	Matrix<T>();
	Matrix<T>(int cofr, int cofc);
	std::vector<std::vector<T>> GetData();
	int GetCount_Of_Rows();
	int GetCount_Of_Columns();
	void SetCount_Of_Rows(int row);
	void SetCount_Of_Columns(int column);
	void SetCount_Of_Row_Columns(int row ,int column);
	void SetData(std::vector<std::vector<T>> data_);
	void Print();
	void SetElement(const T& d, int row,int column);
};


class MatrixException
{
private:
	std::string m_error;

public:
	MatrixException(std::string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};

#include "Matrix.cpp"
#endif
