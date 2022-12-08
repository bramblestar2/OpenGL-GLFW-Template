#include "Window.h"
#include <iostream>
#include <time.h>

Window::Window(const float _Width, const float _Height)
{
	srand(time(NULL));

	if (!init(_Width, _Height))
		std::cout << "Initializing window/glfw has failed" << std::endl;

	glfwSetKeyCallback(window, call_backs::key_callback);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::render()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Draw Begin

	

	//Draw End
	
	glfwSwapBuffers(window);
}

void Window::run()
{
	while (!glfwWindowShouldClose(window))
	{
		update();
		updateDT();
		updateEvents();
		render();
	}
}


void Window::update()
{
}

void Window::updateDT()
{
	double time = glfwGetTime();
	dt = time - lastDTCheck;
	lastDTCheck = time;
}

void Window::updateEvents()
{
	glfwPollEvents();
}

int Window::init(const float _Width, const float _Height)
{
	if (!glfwInit())
		return -1;

	//For 3d
	//glfwWindowHint(GLFW_DEPTH_BITS, 24);
	//glfwWindowHint(GLFW_STENCIL_BITS, 8);
	
	//Normal
	glfwWindowHint(GLFW_RESIZABLE, 0);
	glfwWindowHint(GLFW_REFRESH_RATE, 60);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	
	//Transparent window
	//glfwWindowHint(GLFW_DECORATED, 0);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);	

	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	int xpos, ypos, width, height;
	glfwGetMonitorWorkarea(monitors[0], &xpos, &ypos, &width, &height);

	window = glfwCreateWindow(_Width, _Height, "Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowPos(window, width / 2 - (_Width / 2), height / 2 - (_Height/2));

	glfwMakeContextCurrent(window);

	lastDTCheck = glfwGetTime();

	return 1;
}