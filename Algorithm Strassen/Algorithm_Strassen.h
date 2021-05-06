#ifndef _ALGORITHM_STRASSEN_H
#define _ALGORITHM_STRASSEN_H

#include "Matrix.h"
#include <thread>
#include <chrono>



template<typename T>
class Algorithm_Strassen
{
public:
    virtual void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) =0;
   // Algorithm_Strassen<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
    virtual void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
    virtual void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) = 0;
};

template<typename T>
class Serial_Version : public Algorithm_Strassen<T>
{
public:
    void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
    Serial_Version<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
    void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
    void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
};


#include "Algorithm_Strassen.cpp"
#endif
