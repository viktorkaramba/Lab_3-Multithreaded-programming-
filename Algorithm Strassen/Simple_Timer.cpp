#include "Simple_Timer.h"

Simple_Timer::Simple_Timer()
{
	start = std::chrono::high_resolution_clock::now();
}

float Simple_Timer::GetResult()
{
	return this->result;
}

void Simple_Timer::GetTime() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	result = duration.count();
}

Simple_Timer::~Simple_Timer()
{
	
}

