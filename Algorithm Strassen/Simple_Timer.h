#pragma once
#include <chrono>
#include <iostream>

/*!Class for calculating the execution time of the algorithm*/
class Simple_Timer
{
public:
	/*!The constructor with which the timer is started*/
	Simple_Timer();
	/*!Method that returns the execution time of an algorithm*/
	float GetResult();
	/*!A destructor that stops the timer and records the result*/
	~Simple_Timer();
private:
	/*!Variables for storing start and end of algorithm*/
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	/*!Variable to store the difference between the end and start of the algorithm*/
	std::chrono::duration<float> duration;
	/*!Variable for storing result time*/
	float result;
};

