#ifndef _MATRIX_CPP
#define _MATRIX_CPP
#include "Matrix.h"


template<typename T1> std::istream& operator>> (std::istream& in, Matrix<T1>& A)
{

	for (int i = 0; i < A.GetCount_Of_Rows(); i++) {

		for (int j = 0; j < A.GetCount_Of_Columns(); j++)
		{
			std::cout << "Input data : " << i << " . " << j << std::endl;
			in >> A.data[i][j];
		}

	}
	return(in);
}


template<typename T>
Matrix<T>::Matrix(int cofr, int cofc)
{
	
	if (cofr == 0) {
		throw MatrixException("The number of rows must be greater than 0");
	}
	if (cofc == 0) {
		throw MatrixException("The number of columns must be greater than 0");
	}
	this->count_of_rows = cofr;
	this->count_of_columns = cofc;
	std::vector<std::vector<T>> a(count_of_rows, std::vector <T>(count_of_columns));
	this->data = a;
}


template<typename T>
int Matrix<T>::GetCount_Of_Rows()
{
	return this->count_of_rows;
}

template<typename T>
int Matrix<T>::GetCount_Of_Columns()
{
	return this->count_of_columns;
}

template<typename T>
void Matrix<T>::SetCount_Of_Rows(int row)
{
	this->count_of_row = row;
}

template<typename T>
void Matrix<T>::SetCount_Of_Columns(int column)
{
	this->count_of_columns = column;
}

template<typename T>
void Matrix<T>::SetCount_Of_Row_Columns(int row, int column)
{
	this->count_of_rows = row;
	this->count_of_columns = column;
	std::vector <std::vector <T> > a(count_of_rows, std::vector <T>(count_of_columns));
	this->data = a;
}


template<typename T>
void Matrix<T>::Print()
{
	for (int i = 0; i < count_of_rows; i++) {
		for (int j = 0; j < count_of_columns; j++) {
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
void Matrix<T>::SetElement(const T& d, int row, int column)
{
	this->data[row][column] = d;
}


template<typename T>
std::vector<std::vector<T>> Matrix<T>::GetData()
{
	return this->data;
}

template<typename T>
Matrix<T>::Matrix()
{

	this->count_of_rows = 0;
	this->count_of_columns = 0;
	
}





template<typename T>
void Matrix<T>::SetData(std::vector<std::vector<T>> data_)
{
	this->data = data_;
}


#endif



