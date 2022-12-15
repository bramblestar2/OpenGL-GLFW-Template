#include "Window3D.h"

Window3D::Window3D(const unsigned int _Width,
				   const unsigned int _Height,
				   const std::string _Title,
				   const bool _IsTransparent)
				   : Window2D(_Width, _Height, _Title, _IsTransparent)
{
	Window2D::setContext(24, 8, 2, 0);
}

Window3D::Window3D() : Window2D()
{
}

Window3D::~Window3D()
{
}
