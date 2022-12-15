#pragma once
#include "Window2D.h"

class Window3D : Window2D
{
public:
	Window3D(const unsigned int _Width,
		const unsigned int _Height,
		const std::string _Title,
		const bool _IsTransparent = GLFW_FALSE);
	Window3D();
	~Window3D();

private:

};

