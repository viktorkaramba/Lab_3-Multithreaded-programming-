#ifndef _MULTITHREADED_VERSION_H
#define _MULTITHREADED_VERSION_H

#include "Matrix.h"
#include <thread>
#include <mutex>
#include <chrono>
#include "Algorithm_Strassen.h"
#include <iostream>

template<typename T>
class Multithreaded_Version : public Algorithm_Strassen<T>
{
private:
	int first_;
	std::recursive_mutex rm;
	std::vector<std::thread> some_threads;
public:
	
	void strassenR(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	Multithreaded_Version<T>(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
	
	void sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	void subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) override;
	static void invoke_strassenR(Multithreaded_Version<T>* algorithm_strassena, Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);

	//void Create_Additional_Matrix(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
	/*void First_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p1, int n);
	void Second_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p2, int n);
	void Third_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p3, int n);
	void Fourth_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p4, int n);
	void Fifth_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p5, int n);
	void Sixth_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p6, int n);
	void Seventh_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p7, int n);
	void strassenR_Multithreded(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n);
	void first_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p1, int n);
	void second_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p2, int n);
	void third_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p3, int n);
	void fourth_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p4, int n);
	void fifth_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p5, int n);
	void sixth_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p6, int n);
	void seventh_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p7, int n);*/
};




#include "Multithreaded_Version.cpp"
#endif

