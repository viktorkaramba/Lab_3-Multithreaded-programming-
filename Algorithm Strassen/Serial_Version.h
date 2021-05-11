#ifndef _SERIAL_VERSION_H
#define _SERIAL_VERSION_H

#include "Matrix.h"
#include "Algorithm_Strassen.h"
#include <thread>
#include <mutex>
#include <chrono>

template<typename T>
class Serial_Version : public Algorithm_Strassen<T>
{
public:
    void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
    Serial_Version<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
    Serial_Version<T>();
    void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
    void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
    
};

class Serial_VersionException
{
private:
	std::string m_error;

public:
	Serial_VersionException(std::string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};

#include "Serial_Version.cpp"
#endif
