#pragma once
#include <chrono>
#include <iostream>
class Simple_Timer
{
public:
	Simple_Timer();
	~Simple_Timer();
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
};

