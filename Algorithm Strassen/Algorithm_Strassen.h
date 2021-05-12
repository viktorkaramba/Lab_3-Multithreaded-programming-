#ifndef _ALGORITHM_STRASSEN_H
#define _ALGORITHM_STRASSEN_H

#include "Matrix.h"

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



#include "Algorithm_Strassen.cpp"
#endif
