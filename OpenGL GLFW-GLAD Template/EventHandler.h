#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <vector>

enum class EventTypes
{
	Key,
	Character,
	CursorMoved,
	CursorEntered,
	MouseButton,
	MouseScroll,
	Joystick,
	Drop,

	Closed,
	SizeChanged,
	BufferChanged,
	ScaleChanged,
	WindowMoved,
	Iconified,
	Maximized,
	Focused,
	Refresh,
};

class EventHandler
{
/// 
/// Structs for events
/// 
protected:
	//Input events
	struct Key
	{
		int key, scancode, action, mods;
	};
	
	struct Character
	{
		int codepoint;
	};
	
	struct CursorMoved 
	{
		double xpos, ypos;
	};
	
	struct CursorEntered
	{
		int entered;
	};
	
	struct MouseButton
	{
		int button;
		int action;
		int mods;
	};
	
	struct MouseScroll
	{
		double xoffset;
		double yoffset;
	};
	
	struct Joystick
	{
		int jid, event;
	};
	
	struct Drop
	{
		int count;
		const char** paths;
	};

	//Window events
	
	//Window closed
	struct Closed
	{

	};

	//Window size change
	struct SizeChanged
	{
		int width, height;
	};

	//Frame buffer size change
	struct BufferChanged
	{
		int width, height;
	};

	//Content scale change
	struct ScaleChanged
	{
		float xscale, yscale;
	};

	//Window position moved
	struct WindowMoved
	{
		int xpos, ypos;
	};

	//Window Iconified
	struct Iconified
	{
		int iconified;
	};

	//Window maximized
	struct Maximized
	{
		int maximized;
	};

	//Windows focus is changed
	struct Focused
	{
		int focused;
	};

	//Wubdiw damage and refresh
	struct Refresh
	{

	};

	union events
	{
		Key keys;
		Character character;
		CursorMoved cursorMoved;
		CursorEntered cursorEntered;
		MouseButton mouseButton;
		MouseScroll mouseScroll;
		Joystick joystick;
		Drop drop;

		Closed closed;
		SizeChanged sizeChanged;
		BufferChanged bufferChanged;
		ScaleChanged scaleChanged;
		WindowMoved windowMoved;
		Iconified iconified;
		Maximized maximized;
		Focused focused;
		Refresh refresh;
	};

/// 
/// Simple event handling
/// 
public:
	void pop_event() 
	{ 
		if (!isEmpty())
		{
			topEvent = eventList.at(eventList.size() - 1);
			topEventType = eventTypeList.at(eventTypeList.size() - 1);
			eventTypeList.pop_back();
			eventList.pop_back();
		}
	}
	events current_event() const;
	EventTypes current_type() const;
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
	static std::vector<EventTypes> eventTypeList;
	events topEvent;
	EventTypes topEventType;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void character_callback(GLFWwindow* window, unsigned int codepoint);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow* window, int entered);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void joystick_callback(int jid, int event);
	static void drop_callback(GLFWwindow* window, int count, const char** paths);
	
	//Window callbacks
	static void window_close_callback(GLFWwindow* window);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void window_content_scale_callback(GLFWwindow* window, float xscale, float yscale);
	static void window_pos_callback(GLFWwindow* window, int xpos, int ypos);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_maximize_callback(GLFWwindow* window, int maximized);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_refresh_callback(GLFWwindow* window);
};

