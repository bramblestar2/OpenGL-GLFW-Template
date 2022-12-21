#ifndef CLOCK_H
#define CLOCK_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Clock
{
public:
	Clock();

	float getElapsedTime();
	float reset();
private:
	double time;
};

#endif