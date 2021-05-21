#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <iostream>

/*!
 * \brief
 * Realisation of matrix
 */

/*!Template class for matrix representation*/
template<typename T>
class Matrix
{
private:
	/*!Number of rows*/
	int count_of_rows;
	/*!Number of columns*/
	int count_of_columns;
	/*!Vector for data storage*/
	std::vector<std::vector<T>> data;
	/*!The matrix input operator is overloaded*/
	template<typename T1> friend std::istream& operator>> (std::istream& in, Matrix<T1>& A);
public:
	/*!A constructor that does not accept input parameters*/
	Matrix<T>();
	/*!A constructor that accepts two parameters*/
	Matrix<T>(int cofr, int cofc);
	/*!Method for obtaining data from the matrix*/
	std::vector<std::vector<T>> GetData();
	/*!Method for obtaining count of rows from the matrix*/
	int GetCount_Of_Rows();
	/*!Method for obtaining count of columns from the matrix*/
	int GetCount_Of_Columns();
	/*!Method for inserting the number of rows in a matrix*/
	void SetCount_Of_Rows(int row);
	/*!Method for inserting the number of columns in a matrix*/
	void SetCount_Of_Columns(int column);
	/*!Method for inserting the number of rows and columns in a matrix*/
	void SetCount_Of_Row_Columns(int row ,int column);
	/*!Method for inserting data in a matrix*/
	void SetData(std::vector<std::vector<T>> data_);
	/*!Method for outputting the matrix to the console*/
	void Print();
	/*!Method for inserting a single element into a matrix*/
	void SetElement(const T& d, int row,int column);
};

/*!
 * \brief
 * Realisation of matrix exeptions
 */

/*!Class to find exceptions*/
class MatrixException
{
private:
	/*!Message of exeptions*/
	std::string m_error;
public:
	/*!Constructor that accepts one parameters*/
	MatrixException(std::string error)
		: m_error(error)
	{
	}
	/*!Method for outputting the message of exeption*/
	const char* getError() { return m_error.c_str(); }
};

#include "Matrix.cpp"
#endif
