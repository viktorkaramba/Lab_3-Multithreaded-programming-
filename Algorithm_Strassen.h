#ifndef _ALGORITHM_STRASSEN_H
#define _ALGORITHM_STRASSEN_H

#include "Matrix.h"

using namespace std;

template<typename T>
class Algorithm_Strassen
{
public:
    void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
    Algorithm_Strassen<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
    void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
    void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
};

#include "Algorithm_Strassen.cpp"
#endif
