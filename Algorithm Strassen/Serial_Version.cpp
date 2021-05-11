#ifndef _SERIAL_VERSION_CPP
#define _SERIAL_VERSION_CPP


#include "Serial_Version.h"

template<typename T>

void Serial_Version<T>::strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
{
  
    if (n <= 1) {
        C.SetElement(A.GetData()[0][0] * B.GetData()[0][0], 0, 0);
        return;
    }
    else {
        int newN = n / 2;
        Matrix<T> a11(newN, newN), a12(newN, newN), a21(newN, newN), a22(newN, newN), b11(newN, newN), b12(newN, newN), b21(newN, newN), b22(newN, newN), c11(newN, newN), c12(newN, newN), c21(newN, newN), c22(newN, newN),
            p1(newN, newN), p2(newN, newN), p3(newN, newN), p4(newN, newN), p5(newN, newN), p6(newN, newN), p7(newN, newN), aResult(newN, newN), bResult(newN, newN);
        int i, j;
        for (i = 0; i < newN; i++) {
            for (j = 0; j < newN; j++) {
                a11.SetElement(A.GetData()[i][j], i, j);
                a12.SetElement(A.GetData()[i][j + newN], i, j);
                a21.SetElement(A.GetData()[i + newN][j], i, j);
                a22.SetElement(A.GetData()[i + newN][j + newN], i, j);
                b11.SetElement(B.GetData()[i][j], i, j);
                b12.SetElement(B.GetData()[i][j + newN], i, j);
                b21.SetElement(B.GetData()[i + newN][j], i, j);
                b22.SetElement(B.GetData()[i + newN][j + newN], i, j);
            }
        }
        
        sum(a11, a22, aResult, newN); // a11 + a22
        sum(b11, b22, bResult, newN); // b11 + b22
        strassenR(aResult, bResult, p1, newN); // p1 = (a11+a22) * (b11+b22)

        sum(a21, a22, aResult, newN); // a21 + a22
        strassenR(aResult, b11, p2, newN); // p2 = (a21+a22) * (b11)

        subtract(b12, b22, bResult, newN); // b12 - b22
        strassenR(a11, bResult, p3, newN); // p3 = (a11) * (b12 - b22)

        subtract(b21, b11, bResult, newN); // b21 - b11
        strassenR(a22, bResult, p4, newN); // p4 = (a22) * (b21 - b11)

        sum(a11, a12, aResult, newN); // a11 + a12
        strassenR(aResult, b22, p5, newN); // p5 = (a11+a12) * (b22)

        subtract(a21, a11, aResult, newN); // a21 - a11
        sum(b11, b12, bResult, newN); // b11 + b12
        strassenR(aResult, bResult, p6, newN); // p6 = (a21-a11) * (b11+b12)

        subtract(a12, a22, aResult, newN); // a12 - a22
        sum(b21, b22, bResult, newN); // b21 + b22
        strassenR(aResult, bResult, p7, newN); // p7 = (a12-a22) * (b21+b22)

        sum(p3, p5, c12, newN); // c12 = p3 + p5
        sum(p2, p4, c21, newN); // c21 = p2 + p4
        sum(p1, p4, aResult, newN); // p1 + p4
        sum(aResult, p7, bResult, newN); // p1 + p4 + p7
        subtract(bResult, p5, c11, newN); // c11 = p1 + p4 - p5 + p7
        sum(p1, p3, aResult, newN); // p1 + p3
        sum(aResult, p6, bResult, newN); // p1 + p3 + p6
        subtract(bResult, p2, c22, newN); // c22 = p1 + p3 - p2 + p6
        for (i = 0; i < newN; i++) {
            for (j = 0; j < newN; j++) {
                C.SetElement(c11.GetData()[i][j], i, j);
                C.SetElement(c12.GetData()[i][j], i, j + newN);
                C.SetElement(c21.GetData()[i][j], i + newN, j);
                C.SetElement(c22.GetData()[i][j], i + newN, j + newN);
            }
        }
    }
}

template<typename T>
Serial_Version<T>::Serial_Version(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
{
  
    if (A.GetCount_Of_Rows() != B.GetCount_Of_Rows()) {
        throw Serial_VersionException("The number of rows of the first matrix must be equal to the number of rows of the second matrix");
    }

    int m = pow(2, int(ceil(log2(n))));
    Matrix<T> APrep(m, m), BPrep(m, m), CPrep(m, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            APrep.SetElement(A.GetData()[i][j], i, j);
            BPrep.SetElement(B.GetData()[i][j], i, j);
        }
    }
    strassenR(APrep, BPrep, CPrep, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C.SetElement(CPrep.GetData()[i][j], i, j);
        }
    }
}

template<typename T>
Serial_Version<T>::Serial_Version()
{
}

template<typename T>
void Serial_Version<T>::sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C.SetElement(A.GetData()[i][j] + B.GetData()[i][j], i, j);
        }
    }
}

template<typename T>
void Serial_Version<T>::subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C.SetElement(A.GetData()[i][j] - B.GetData()[i][j], i, j);
        }
    }
}



#endif