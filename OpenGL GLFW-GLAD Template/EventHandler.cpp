#include "EventHandler.h"

std::vector<EventHandler::events> EventHandler::eventList;

int EventHandler::event_count() const
{
	return eventList.size();
}

bool EventHandler::isEmpty() const
{
	return eventList.empty();
}

bool EventHandler::isSetup() const
{
	return setup;
}

void EventHandler::setup_events(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetCharCallback(window, character_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetCursorEnterCallback(window, cursor_enter_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetJoystickCallback(joystick_callback);
	glfwSetDropCallback(window, drop_callback);

	setup = true;
}

void EventHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::character_callback(GLFWwindow* window, unsigned int codepoint)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::cursor_enter_callback(GLFWwindow* window, int entered)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::joystick_callback(int jid, int event)
{
	events temp;
	eventList.push_back(temp);
}

void EventHandler::drop_callback(GLFWwindow* window, int count, const char** paths)
{
	events temp;
	eventList.push_back(temp);
}
