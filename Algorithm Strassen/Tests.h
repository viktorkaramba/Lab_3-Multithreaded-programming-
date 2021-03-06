#pragma once
#include <iostream>
#include "Algorithm_Strassen.h"
#include "Serial_Version.h"
#include "Multithreaded_Version.h"
#include "Simple_Timer.h"
#include <cstdlib>
#include <time.h>
#include <string.h>
/*!
 * \brief 
 * This file using for testing
 */

/*!Vector for storing matrix dimension values*/
const std::vector<int> count_row = {3,5,10,15,20,30,40,50};
/*!Vector for storing additional matrix for compare*/
std::vector<std::vector<int>> Additional[8];

/*!Function for generating matrices of different dimensions*/
std::vector<std::vector<int>> createMatrix(int rows) {
    srand(time(NULL));
    int row1 = rows;
    std::vector<std::vector<int>> A1;
    std::vector<int> A1_1;
    int data1 = 0;
    for (int i = 0; i < row1; i++) {
        std::vector<int> A1_1;
        for (int j = 0; j < row1; j++) {
            data1 = rand() % 50;
            A1_1.push_back(data1);
        }
        A1.push_back(A1_1);
        A1_1.clear();
    }
    return A1;
}

/*!Function for creationg vector of matrices*/
std::vector<Matrix<int>> Tests_Matrix() {
    std::vector<Matrix<int>> vecMatrix;
    Matrix<int> *M1 = new Matrix<int>[8];
    std::vector<std::vector<int>> A1[8];
    for (size_t i = 0; i < 8; i++){
        A1[i] = createMatrix(count_row[i]);
        Additional[i] = createMatrix(count_row[i]);
        M1[i].SetCount_Of_Row_Columns(count_row[i], count_row[i]);
        M1[i].SetData(A1[i]);
        vecMatrix.push_back(M1[i]);
    }
    return vecMatrix;
}

/*!Function for finding the product of matrices by serial version*/
Matrix<int> The_Product_Of_Matrices_Serial(Matrix<int>  A, Matrix<int> B,  int row) {
    Matrix<int> C(row,row);
    Algorithm_Strassen<int>* product = new Serial_Version<int>(A,B,C);
    return C;
}

/*!Function for finding the product of matrices by multithreaded version*/
Matrix<int> The_Product_Of_Matrices_Multithreaded_Version(Matrix<int>  A, Matrix<int> B,  int row) {
    Matrix<int> C(row,row);
    Algorithm_Strassen<int>* product = new Multithreaded_Version<int>(A,B,C);
    return C;
}

Matrix<int> NaiveProduct(Matrix<int>  A, Matrix<int> B) {
    Matrix<int> C(A.GetCount_Of_Columns(), A.GetCount_Of_Columns());
    std::vector<std::vector<int>> A_ = A.GetData();
    std::vector<std::vector<int>> B_ = B.GetData();
    std::vector<std::vector<int>> C_ (A.GetCount_Of_Rows(),A.GetData()[1]);
    for (size_t i = 0; i < A.GetCount_Of_Rows(); i++) {            
        for (size_t j = 0; j < A.GetCount_Of_Columns(); j++) {
            C_[i][j]= 0;
            for (size_t t = 0; t < A.GetCount_Of_Columns(); t++) {
                C_[i][j] += A_[i][t] * B_[t][j];
            }
        }
    }
    C.SetData(C_);
    return C;
}