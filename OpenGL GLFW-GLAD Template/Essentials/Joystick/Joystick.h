#ifndef JOYSTICK_H
#define JOYSTICK_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

class Joystick
{
public:

	static bool isConnected(int _Joystick);
	static int getButtonCount(int _Joystick);

private:
};

#endif