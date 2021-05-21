#ifndef _ALGORITHM_STRASSEN_H
#define _ALGORITHM_STRASSEN_H

#include "Matrix.h"
/*!
 * \brief 
 * Virtual class of the Strassen algorithm through which other versions of the algorithm are implemented
 */


/*!A class hierarchy that defines the algorithms Strassen*/
template<typename T>
class Algorithm_Strassen
{
public:
    /*!Virtual method that implements the Strassen algorithm */
    virtual void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) =0;
    /*!Virtual method for adding matrices*/
    virtual void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
    /*!Virtual method for subtracting matrices*/
    virtual void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
};

/*!
 * \brief
 *  Realisation exeptions of  of algorithm
 */
 /*!Class to find exceptions*/
class Algorithm_StrassenException
{
private:
	/*!Message of exeptions*/
	std::string m_error;
public:
	/*!Constructor that accepts one parameters*/
	Algorithm_StrassenException(std::string error)
		: m_error(error)
	{
	}
	/*!Method for outputting the message of exeption*/
	const char* getError() { return m_error.c_str(); }
};


#include "Algorithm_Strassen.cpp"
#endif
