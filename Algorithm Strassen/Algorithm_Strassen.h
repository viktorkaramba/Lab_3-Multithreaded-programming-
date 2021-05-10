#ifndef _ALGORITHM_STRASSEN_H
#define _ALGORITHM_STRASSEN_H

#include "Matrix.h"


template<typename T>
class Algorithm_Strassen
{
public:
    virtual void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) =0;
    virtual void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
    virtual void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
};



#include "Algorithm_Strassen.cpp"
#endif
