#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

class EventHandler
{
private:


public:
	void pop_event();
	void push_event();
};

