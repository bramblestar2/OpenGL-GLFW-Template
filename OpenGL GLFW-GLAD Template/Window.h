#pragma once
#define GLFW_INCLUDE_NONE
#include "Events.h"

#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <string>

class Window
{
public:
	Window(const float _Width = 100, const float _Height = 100);
	virtual ~Window();

	void render();
	void run();
	void update();
	void updateDT();
	void updateEvents();

private:
	//returns whether glfw has been initialized or not
	int init(const float _Width, const float _Height);

	double dt, lastDTCheck;

	GLFWwindow* window;
};

