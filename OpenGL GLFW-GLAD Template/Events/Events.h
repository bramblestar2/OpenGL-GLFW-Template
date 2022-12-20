#pragma once
#include <string>

//REWORKING EVENTS
//AND EVENTHANDLER
//When this is finished, it will be renamed
//Events
class Event
{
protected:
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
		std::string* paths;
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

public:
	enum class EventType
	{
		KEY,
		CHARACTER,
		CURSOR_MOVED,
		CURSOR_ENTERED,
		MOUSE_BUTTON,
		MOUSE_SCROLL,
		JOYSTICK,
		DROP,

		CLOSED,
		SIZE_CHANGED,
		BUFFER_CHANGED,
		SCALE_CHANGED,
		WINDOW_MOVED,
		ICONIFIED,
		MAXIMIZED,
		FOCUSED,
		REFRESH,
	};

	~Event()
	{
		if (type == EventType::DROP)
			if (drop.paths != nullptr)
				delete[] drop.paths;
	}

	EventType type;

	union
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
};