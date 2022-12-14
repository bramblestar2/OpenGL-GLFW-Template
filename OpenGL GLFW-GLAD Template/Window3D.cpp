#include "Window3D.h"

Window3D::Window3D(const unsigned int _Width,
				   const unsigned int _Height,
				   const std::string _Title)
				   : Window2D(_Width, _Height, _Title)
{
	setContext(24, 8, 2, 0);
}

Window3D::Window3D() : Window2D()
{
}

Window3D::~Window3D()
{
}

void Window3D::setContext(const int depthBits, const int stencilBits, 
						  const int majorVersion, const int minorVersion)
{
	glfwSetWindowAttrib(Window2D::window, GLFW_DEPTH_BITS, depthBits);
	glfwSetWindowAttrib(Window2D::window, GLFW_STENCIL_BITS, stencilBits);
	glfwSetWindowAttrib(Window2D::window, GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
	glfwSetWindowAttrib(Window2D::window, GLFW_CONTEXT_VERSION_MINOR, minorVersion);
}
