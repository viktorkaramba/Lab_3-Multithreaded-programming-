#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "Benchmark.h"
using namespace std;


TEST_CASE("Test matrix exeption") {
 
    CHECK_THROWS(Matrix<int> A1(0, 3) , const MatrixException&);
    CHECK_THROWS(Matrix<int> A2(3, 0) , const MatrixException&);
    CHECK_THROWS(Matrix<int> A3(0, 0) , const MatrixException&);
}

TEST_CASE("Test Strassen's multithreaded algorithm exeption") {
    Matrix<int> A(3, 3);
    Matrix<int> B(2, 3);
    Matrix<int> Ñ(3, 3);
    CHECK_THROWS(Multithreaded_Version<int> M(A, B, Ñ), const Multithreaded_VersionException&);
}
TEST_CASE("Test Strassen's serial algorithm exeption") {
    Matrix<int> A(3, 3);
    Matrix<int> B(2, 3);
    Matrix<int> Ñ(3, 3);
    CHECK_THROWS(Serial_Version<int>(A, B, Ñ), exception);
}


TEST_CASE("Test of constructor of matrix") {
    std::vector<Matrix<int>> vecMatrix_A = Tests_Matrix();
    for (size_t i = 0; i < 8; i++)
    {
        CHECK(vecMatrix_A[i].GetData() == Additional[i]);
    }
}  


TEST_CASE("Test serial version of the algorithm") {
    std::vector<Matrix<int>> vecMatrix_A = Tests_Matrix();
    std::vector<Matrix<int>> vecMatrix_B = Tests_Matrix();
    std::vector<Matrix<int>> vecMatrix_C_Strassen;
    std::vector<Matrix<int>> vecMatrix_C_Naive;
    for (size_t i = 0; i < count_row.size(); i++)
    {
        vecMatrix_C_Strassen.push_back(The_Product_Of_Matrices_Serial(vecMatrix_A[i], vecMatrix_B[i], count_row[i]));
        vecMatrix_C_Naive.push_back(NaiveProduct(vecMatrix_A[i], vecMatrix_B[i]));
    }

    for (size_t i = 0; i < count_row.size(); i++)
    {
        CHECK(vecMatrix_C_Strassen[i].GetData() == vecMatrix_C_Naive[i].GetData());
    }
}

TEST_CASE("Test of multi-threaded version of the algorithm") {
    std::vector<Matrix<int>> vecMatrix_A = Tests_Matrix();
    std::vector<Matrix<int>> vecMatrix_B = Tests_Matrix();
    std::vector<Matrix<int>> vecMatrix_C_Strassen;
    std::vector<Matrix<int>> vecMatrix_C_Naive;
    for (size_t i = 0; i < count_row.size(); i++)
    {
        vecMatrix_C_Strassen.push_back(The_Product_Of_Matrices_Multithreaded_Version(vecMatrix_A[i], vecMatrix_B[i], count_row[i]));
        vecMatrix_C_Naive.push_back(NaiveProduct(vecMatrix_A[i], vecMatrix_B[i]));
    }

    for (size_t i = 0; i < count_row.size(); i++)
    {
        CHECK(vecMatrix_C_Strassen[i].GetData() == vecMatrix_C_Naive[i].GetData());
    }
}



