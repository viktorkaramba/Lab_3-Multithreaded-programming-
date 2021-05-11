#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "Tests.h"
using namespace std;


TEST_CASE("Test matrix exeption") {
    try
    {
       
    }
    catch (MatrixException& exception)
    {
        std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
    }
    CHECK_THROWS(Matrix<int> A1(0, 3) , exception);
    CHECK_THROWS(Matrix<int> A2(3, 0) , exception);
    CHECK_THROWS(Matrix<int> A3(0, 0) , exception);
}

TEST_CASE("Test Strassen's multithreaded algorithm exeption") {
    Matrix<int> A(3, 3);
    Matrix<int> B(2, 3);
    Matrix<int> Ñ(3, 3);
    try
    {

    }
    catch (Multithreaded_VersionException& exception)
    {
        std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
    }
 
    CHECK_THROWS(Algorithm_Strassen<int> * product = new Multithreaded_Version<int>(A, B, Ñ, 3), exception);
  
}
TEST_CASE("Test Strassen's serial algorithm exeption") {
    Matrix<int> A(3, 3);
    Matrix<int> B(2, 3);
    Matrix<int> Ñ(3, 3);
    try
    {

    }
    catch (Serial_VersionException& exception)
    {
        std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
    }

    CHECK_THROWS(Algorithm_Strassen<int> * product = new Serial_Version<int>(A, B, Ñ, 3), exception);

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
    std::vector<Matrix<int>> vecMatrix_C;
    for (size_t i = 0; i < count_row.size(); i++)
    {
        vecMatrix_C.push_back(The_Product_Of_Matrices_Serial(vecMatrix_A[i], vecMatrix_B[i], count_row[i]));
    }

    for (size_t i = 0; i < count_row.size(); i++)
    {
        CHECK(vecMatrix_C[i].GetData() == Product1[i].GetData());
    }
}

TEST_CASE("Test of multi-threaded version of the algorithm") {
    std::vector<Matrix<int>> vecMatrix_A = Tests_Matrix();
    std::vector<Matrix<int>> vecMatrix_B = Tests_Matrix();
    std::vector<Matrix<int>> vecMatrix_C;
    for (size_t i = 0; i < count_row.size(); i++)
    {
        vecMatrix_C.push_back(The_Product_Of_Matrices_Multithreaded_Version(vecMatrix_A[i], vecMatrix_B[i], count_row[i]));
    }

    for (size_t i = 0; i < count_row.size(); i++)
    {
        CHECK(vecMatrix_C[i].GetData() == Product2[i].GetData());
    }
}
