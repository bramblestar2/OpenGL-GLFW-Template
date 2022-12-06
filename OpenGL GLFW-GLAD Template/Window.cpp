#include "Window.h"
#include <iostream>

Window::Window(const float _Width, const float _Height)
{
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
	//glClearColor(0, 0, 0, 1);
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

	window = glfwCreateWindow(_Width, _Height, "Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	lastDTCheck = glfwGetTime();

	return 1;
}