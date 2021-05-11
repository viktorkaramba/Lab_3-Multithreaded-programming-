#ifndef _MULTITHREADED_VERSION_H
#define _MULTITHREADED_VERSION_H

#include "Matrix.h"
#include <thread>
#include <mutex>
#include <chrono>
#include "Algorithm_Strassen.h"
#include <iostream>

template<typename T>
class Multithreaded_Version : public Algorithm_Strassen<T>
{
private:
	int first_;
	std::recursive_mutex rm;
	std::vector<std::thread> some_threads;
public:
	
	void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	Multithreaded_Version<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
	
	void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	
};

class Multithreaded_VersionException
{
private:
	std::string m_error;

public:
	Multithreaded_VersionException(std::string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};


#include "Multithreaded_Version.cpp"
#endif

