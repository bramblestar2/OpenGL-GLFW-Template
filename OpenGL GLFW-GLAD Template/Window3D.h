#pragma once
#include "Window2D.h"

class Window3D : Window2D
{
public:
	Window3D(const unsigned int _Width,
			 const unsigned int _Height,
			 const std::string _Title);
	Window3D();
	~Window3D();

	void setContext(const int depthBits = 0, const int stencilBits = 0, 
					const int majorVersion = 2, const int minorVersion = 0);

private:

};

