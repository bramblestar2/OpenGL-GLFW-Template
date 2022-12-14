#pragma once
#include "EventHandler.h"

class Events : public EventHandler
{
public:
	Events();
	~Events();

private:
	GLFWwindow* window;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void character_callback(GLFWwindow* window, unsigned int codepoint);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow* window, int entered);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void joystick_callback(int jid, int event);
	static void drop_callback(GLFWwindow* window, int count, const char** paths);
};

