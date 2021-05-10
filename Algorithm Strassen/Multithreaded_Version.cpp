#ifndef _MULTITHREADED_VERSION_CPP
#define _MULTITHREADED_VERSION_CPP


#include "Multithreaded_Version.h"



template<typename T>
void Multithreaded_Version<T>::strassenR(Matrix<T> &A, Matrix<T> &B, Matrix<T> &C, int n)
{
    //this->rm.lock();
    this->first_++;
    if (n <= 1) {
        //this->rm.lock();
        C.SetElement(A.GetData()[0][0] * B.GetData()[0][0], 0, 0);
        //this->rm.unlock();
        return;
    }
    else {
        /*this->rm.lock();
        int newN = n / 2;
        Matrix<T> a11(newN, newN), a12(newN, newN), a21(newN, newN), a22(newN, newN), b11(newN, newN), b12(newN, newN), b21(newN, newN), b22(newN, newN), c11(newN, newN), c12(newN, newN), c21(newN, newN), c22(newN, newN),
            p1(newN, newN), p2(newN, newN), p3(newN, newN), p4(newN, newN), p5(newN, newN), p6(newN, newN), p7(newN, newN), 
            aResult(newN, newN), bResult(newN, newN),a1Result(newN, newN), b1Result(newN, newN), a2Result(newN, newN), b2Result(newN, newN), a3Result(newN, newN), b3Result(newN, newN),
            a4Result(newN, newN), b4Result(newN, newN), a5Result(newN, newN), b5Result(newN, newN), a6Result(newN, newN), b6Result(newN, newN), a7Result(newN, newN), b7Result(newN, newN);
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
        this->rm.unlock();*/
        int newN = n / 2;
        if (this->first_ ==1 ) {
            this->rm.lock();
         
            Matrix<T> a11(newN, newN), a12(newN, newN), a21(newN, newN), a22(newN, newN), b11(newN, newN), b12(newN, newN), b21(newN, newN), b22(newN, newN), c11(newN, newN), c12(newN, newN), c21(newN, newN), c22(newN, newN),
                p1(newN, newN), p2(newN, newN), p3(newN, newN), p4(newN, newN), p5(newN, newN), p6(newN, newN), p7(newN, newN),
                aResult(newN, newN), bResult(newN, newN), a1Result(newN, newN), b1Result(newN, newN), a2Result(newN, newN), b2Result(newN, newN), a3Result(newN, newN), b3Result(newN, newN),
                a4Result(newN, newN), b4Result(newN, newN), a5Result(newN, newN), b5Result(newN, newN), a6Result(newN, newN), b6Result(newN, newN), a7Result(newN, newN), b7Result(newN, newN);

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
            this->rm.unlock();
            sum(a11, a22, a1Result, newN); // a11 + a22
            sum(b11, b22, b1Result, newN); // b11 + b22
            sum(a21, a22, a2Result, newN); // a21 + a22
            subtract(b12, b22, b2Result, newN); // b12 - b22
            subtract(b21, b11, b3Result, newN); // b21 - b11
            sum(a11, a12, a3Result, newN); // a11 + a12
            subtract(a21, a11, a4Result, newN); // a21 - a11
            sum(b11, b12, b4Result, newN); // b11 + b12
            subtract(a12, a22, a5Result, newN); // a12 - a22
            sum(b21, b22, b5Result, newN); // b21 + b22
         
        
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR,this, std::ref(a1Result), std::ref(b1Result), std::ref(p1), newN)); // p1 = (a11+a22) * (b11+b22)
         
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR, this, std::ref(a2Result), std::ref(b11), std::ref(p2), newN)); // p2 = (a21+a22) * (b11)
           
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR, this, std::ref(a11), std::ref(b2Result), std::ref(p3), newN)); // p3 = (a11) * (b12 - b22)
          
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR, this, std::ref(a22), std::ref(b3Result), std::ref(p4), newN)); // p4 = (a22) * (b21 - b11)
       
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR, this, std::ref(a3Result), std::ref(b22), std::ref(p5), newN)); // p5 = (a11+a12) * (b22)
     
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR, this, std::ref(a4Result), std::ref(b4Result), std::ref(p6), newN)); // p6 = (a21-a11) * (b11+b12)
        
            some_threads.push_back(std::thread(&Multithreaded_Version<T>::strassenR, this, std::ref(a5Result), std::ref(b5Result), std::ref(p7), newN)); // p7 = (a12-a22) * (b21+b22)
       
            for (auto& t : some_threads) t.join();
          
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
        else if(this->first_ > 1){
            this->rm.lock();
            Matrix<T> a11(newN, newN), a12(newN, newN), a21(newN, newN), a22(newN, newN), b11(newN, newN), b12(newN, newN), b21(newN, newN), b22(newN, newN), c11(newN, newN), c12(newN, newN), c21(newN, newN), c22(newN, newN),
                p1(newN, newN), p2(newN, newN), p3(newN, newN), p4(newN, newN), p5(newN, newN), p6(newN, newN), p7(newN, newN),
                aResult(newN, newN), bResult(newN, newN);
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
            this->rm.unlock();
          
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
    
    //this->rm.unlock();
}


template<typename T>
Multithreaded_Version<T>::Multithreaded_Version(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
{
    this->first_ = 0;

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
void Multithreaded_Version<T>::sum(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C.SetElement(A.GetData()[i][j] + B.GetData()[i][j], i, j);
        }
    }
}

template<typename T>
void Multithreaded_Version<T>::subtract(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C.SetElement(A.GetData()[i][j] - B.GetData()[i][j], i, j);
        }
    }
}

template<typename T>
void Multithreaded_Version<T>::invoke_strassenR(Multithreaded_Version<T>* algorithm_strassena, Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
{
    algorithm_strassena->strassenR(A,B,C,n);
}

//template<typename T>
//void Multithreaded_Version<T>::Create_Additional_Matrix(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int newN)
//{
//	
//	for (int i = 0; i < newN; i++) {
//		for (int j = 0; j < newN; j++) {
//			a11.SetElement(A.GetData()[i][j], i, j);
//			a12.SetElement(A.GetData()[i][j + newN], i, j);
//			a21.SetElement(A.GetData()[i + newN][j], i, j);
//			a22.SetElement(A.GetData()[i + newN][j + newN], i, j);
//			b11.SetElement(B.GetData()[i][j], i, j);
//			b12.SetElement(B.GetData()[i][j + newN], i, j);
//			b21.SetElement(B.GetData()[i + newN][j], i, j);
//			b22.SetElement(B.GetData()[i + newN][j + newN], i, j);
//		}
//	}
//}

//template<typename T>
//inline void Multithreaded_Version<T>::First_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p1, int n)
//{
//
//	this->first(&Multithreaded_Version<T>::first_additional_sum, this, aResult,bResult,p1,n);
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::Second_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p2, int n)
//{
//	this->second(&Multithreaded_Version<T>::second_additional_sum,this, aResult, bResult, p2, n);
//
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::Third_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p3, int n)
//{
//	this->third(&Multithreaded_Version<T>::third_additional_sum,this, aResult, bResult, p3, n);
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::Fourth_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p4, int n)
//{
//	this->fourth(&Multithreaded_Version<T>::fourth_additional_sum,this, aResult, bResult, p4, n);
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::Fifth_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p5, int n)
//{
//	this->fifth(&Multithreaded_Version<T>::fifth_additional_sum,this, aResult, bResult, p5, n);
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::Sixth_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p6, int n)
//{
//	this->sixth(&Multithreaded_Version<T>::sixth_additional_sum,this, aResult, bResult, p6, n);
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::Seventh_Thread_Sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p7, int n)
//{
//	this->seventh(&Multithreaded_Version<T>::seventh_additional_sum,this, aResult, bResult, p7, n);
//}
//
//template<typename T>
//inline void Multithreaded_Version<T>::strassenR_Multithreded(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C, int n)
//{
//	
//	if (n <= 1) {
//		C.SetElement(A.GetData()[0][0] * B.GetData()[0][0], 0, 0);
//		return;
//	}
//	else {
//		int newN = n / 2;
//		Create_Additional_Matrix(A, B, C, newN);
//		Matrix<T>  c11(newN, newN), c12(newN, newN), c21(newN, newN), c22(newN, newN),
//			p1(newN, newN), p2(newN, newN), p3(newN, newN), p4(newN, newN), p5(newN, newN), p6(newN, newN), p7(newN, newN), aResult(newN, newN), bResult(newN, newN);
//	
//		First_Thread_Sum(aResult, bResult, p1, newN);
//		Second_Thread_Sum(aResult, bResult, p2, newN);
//		Third_Thread_Sum(aResult, bResult, p3, newN);
//		Fourth_Thread_Sum(aResult, bResult, p4, newN);
//		Fifth_Thread_Sum(aResult, bResult, p5, newN);
//		Sixth_Thread_Sum(aResult, bResult, p6, newN);
//		Seventh_Thread_Sum(aResult, bResult, p7, newN);
//		first.join();
//		second.join();
//		third.join();
//		fourth.join();
//		fifth.join();
//		sixth.join();
//		seventh.join();
//		sum(p3, p5, c12, newN); // c12 = p3 + p5
//		sum(p2, p4, c21, newN); // c21 = p2 + p4
//		sum(p1, p4, aResult, newN); // p1 + p4
//		sum(aResult, p7, bResult, newN); // p1 + p4 + p7
//		subtract(bResult, p5, c11, newN); // c11 = p1 + p4 - p5 + p7
//		sum(p1, p3, aResult, newN); // p1 + p3
//		sum(aResult, p6, bResult, newN); // p1 + p3 + p6
//		subtract(bResult, p2, c22, newN); // c22 = p1 + p3 - p2 + p6
//		for (int i = 0; i < newN; i++) {
//			for (int j = 0; j < newN; j++) {
//				C.SetElement(c11.GetData()[i][j], i, j);
//				C.SetElement(c12.GetData()[i][j], i, j + newN);
//				C.SetElement(c21.GetData()[i][j], i + newN, j);
//				C.SetElement(c22.GetData()[i][j], i + newN, j + newN);
//			}
//		}
//	}
//	
//}
//
//template<typename T>
//void Multithreaded_Version<T>::first_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p1, int n)
//{
//	
//	sum(a11, a22, aResult, n);
//	sum(b11, b22, bResult, n);
//	strassenR_Multithreded(aResult, bResult, p1, n);
//}
//
//template<typename T>
//void Multithreaded_Version<T>::second_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p2, int n)
//{
//	
//	sum(a21, a22, aResult, n);
//	strassenR_Multithreded(aResult, b11, p2, n);
//}
//
//template<typename T>
//void Multithreaded_Version<T>::third_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p3, int n)
//{
//	
//	subtract(b12, b22, bResult, n);
//	strassenR_Multithreded(a11, bResult, p3, n);
//}
//
//template<typename T>
//void Multithreaded_Version<T>::fourth_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p4, int n)
//{
//	
//	subtract(b21, b11, bResult, n);
//	strassenR_Multithreded(b21, b11, p4, n);
//}
//
//template<typename T>
//void Multithreaded_Version<T>::fifth_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p5, int n)
//{
//
//	sum(a11, a12, aResult, n);
//	strassenR_Multithreded(aResult, b22, p5, n);
//}
//
//template<typename T>
//void Multithreaded_Version<T>::sixth_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p6, int n)
//{
//	subtract(a21, a11, aResult, n);
//	sum(b11, b12, bResult, n);
//	strassenR_Multithreded(aResult, bResult, p6, n);
//}
//
//template<typename T>
//void Multithreaded_Version<T>::seventh_additional_sum(Matrix<T>& aResult, Matrix<T>& bResult, Matrix<T>& p7, int n)
//{
//	subtract(a12, a22, aResult, n);
//	sum(b21, b22, bResult, n);
//	strassenR_Multithreded(aResult, bResult, p7, n);
//}


#endif