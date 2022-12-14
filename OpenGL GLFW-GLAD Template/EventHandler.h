#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <vector>

class EventHandler
{
/// 
/// Structs for events
/// 
protected:
	struct Key
	{
		int key, scancode, action, mods;
	};

	union events
	{
		Key keys;
	};

/// 
/// Simple event handling
/// 
public:
	events pop_event() 
	{ 
		if (!isEmpty())
		{
			events temp = eventList.at(eventList.size() - 1);
			eventList.pop_back();
			return temp;
		}
		else
			return events();
	}

	int event_count() const;
	bool isEmpty() const;
	bool isSetup() const;
	void setup_events(GLFWwindow* window);

/// 
/// Holds a list of events
/// and all event callbacks
/// 
private:
	bool setup = false;
	static std::vector<events> eventList;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void character_callback(GLFWwindow* window, unsigned int codepoint);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow* window, int entered);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void joystick_callback(int jid, int event);
	static void drop_callback(GLFWwindow* window, int count, const char** paths);
};

