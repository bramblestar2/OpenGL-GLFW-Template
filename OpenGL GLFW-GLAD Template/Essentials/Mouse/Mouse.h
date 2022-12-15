#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "../Vec2/Vec2.h"

class Mouse
{
public:
	Mouse();
	
	void setPosition(const Vec2d _Position);
	void setPosition(const Vec2d _Position, GLFWwindow* window);

	Vec2d getPosition();
	Vec2d getPosition(GLFWwindow* _Window);
private:

};

