#ifndef _SERIAL_VERSION_H
#define _SERIAL_VERSION_H

#include "Matrix.h"
#include "Algorithm_Strassen.h"
#include <thread>
#include <mutex>
#include <chrono>

/*!Template class for the serial version of the algorithm*/
template<typename T>
class Serial_Version : public Algorithm_Strassen<T>
{
public:
	/*!Method that implements the Strassen algorithm */
    void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	
	/*!A constructor that accepts two parameters*/
	Serial_Version<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
	/*!A constructor that does not accept input parameters*/
    Serial_Version<T>();
	/*!Method for adding matrices*/
    void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	/*!Method for subtracting matrices*/
    void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
    
};

/*!Class to find exceptions*/
class Serial_VersionException
{
private:
	/*!Message of exeptions*/
	std::string m_error;

public:
	/*!Constructor that accepts one parameters*/
	Serial_VersionException(std::string error)
		: m_error(error)
	{
	}
	/*!Method for outputting the message of exeption*/
	const char* getError() { return m_error.c_str(); }
};

#include "Serial_Version.cpp"
#endif
