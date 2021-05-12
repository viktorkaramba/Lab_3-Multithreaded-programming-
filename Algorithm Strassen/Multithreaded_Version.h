#ifndef _MULTITHREADED_VERSION_H
#define _MULTITHREADED_VERSION_H

#include "Matrix.h"
#include <thread>
#include <mutex>
#include <chrono>
#include "Algorithm_Strassen.h"
#include <iostream>

/*!Template class for the multithreaded version of the algorithm*/
template<typename T>
class Multithreaded_Version : public Algorithm_Strassen<T>
{
private:
	/*!Variable for method strassenR*/
	int first_;
	/*!Recursive mutex for threads synchronization*/
	std::recursive_mutex rm;
	/*!Vector of threads*/
	std::vector<std::thread> some_threads;
public:
	/*!Method that implements the Strassen algorithm */
	void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	/*!A constructor that accepts two parameters*/
	Multithreaded_Version<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
	/*!A constructor that does not accept input parameters*/
	Multithreaded_Version<T>();
	/*!Method for adding matrices*/
	void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	/*!Method for subtracting matrices*/
	void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	
};

/*!Class to find exceptions*/
class Multithreaded_VersionException
{
private:
	/*!Message of exeptions*/
	std::string m_error;
public:
	/*!Constructor that accepts one parameters*/
	Multithreaded_VersionException(std::string error)
		: m_error(error)
	{
	}
	/*!Method for outputting the message of exeption*/
	const char* getError() { return m_error.c_str(); }
};


#include "Multithreaded_Version.cpp"
#endif

