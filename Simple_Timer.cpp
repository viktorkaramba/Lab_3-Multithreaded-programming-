#include "Simple_Timer.h"

Simple_Timer::Simple_Timer()
{
	start = std::chrono::high_resolution_clock::now();
}

Simple_Timer::~Simple_Timer()
{
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	float result = duration.count();
	std::cout << result << std::endl;
}

