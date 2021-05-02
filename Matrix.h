#pragma once
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

template<typename T1> istream& operator>> (istream& in, Matrix<T1>& A)
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
Matrix<T>::Matrix(const int& cofr, const int& cofc)
{
	
	this->count_of_rows = cofr;
	this->count_of_columns = cofc;
	vector < vector <T> > a(count_of_rows, vector <T>(count_of_columns));
	this->data =a ;
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
void Matrix<T>::Print()
{
	for (int i = 0; i < count_of_rows; i++) {
		for (int j = 0; j < count_of_columns; j++) {
			std::cout << data[i][j] << " ";
		}
		std::cout<<std::endl;
	}
}

template<typename T>
void Matrix<T>::SetElement(const T& d,const int& row,const int& column)
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



