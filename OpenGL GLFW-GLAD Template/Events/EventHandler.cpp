#include "EventHandler.h"

std::vector<EventHandler::events> EventHandler::eventList;
std::vector<EventTypes> EventHandler::eventTypeList;

EventHandler::events EventHandler::current_event() const
{
	return topEvent;
}

EventTypes EventHandler::current_type() const
{
	return topEventType;
}

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

	glfwSetWindowCloseCallback(window, window_close_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetWindowContentScaleCallback(window, window_content_scale_callback);
	glfwSetWindowPosCallback(window, window_pos_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowMaximizeCallback(window, window_maximize_callback);
	glfwSetWindowFocusCallback(window, window_focus_callback);
	glfwSetWindowRefreshCallback(window, window_refresh_callback);

	setup = true;
}

void EventHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	events temp;
	temp.keys.key = key;
	temp.keys.scancode = scancode;
	temp.keys.action = action;
	temp.keys.mods = mods;
	eventTypeList.push_back(EventTypes::Key);
	eventList.push_back(temp);
}

void EventHandler::character_callback(GLFWwindow* window, unsigned int codepoint)
{
	events temp;
	temp.character.codepoint = codepoint;
	eventTypeList.push_back(EventTypes::Character);
	eventList.push_back(temp);
}

void EventHandler::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	events temp;
	temp.cursorMoved.xpos = xpos;
	temp.cursorMoved.ypos = ypos;
	eventTypeList.push_back(EventTypes::CursorMoved);
	eventList.push_back(temp);
}

void EventHandler::cursor_enter_callback(GLFWwindow* window, int entered)
{
	events temp;
	temp.cursorEntered.entered = entered;
	eventTypeList.push_back(EventTypes::CursorEntered);
	eventList.push_back(temp);
}

void EventHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	events temp;
	temp.mouseButton.button = button;
	temp.mouseButton.action = action;
	temp.mouseButton.mods = mods;
	eventTypeList.push_back(EventTypes::MouseButton);
	eventList.push_back(temp);
}

void EventHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	events temp;
	temp.mouseScroll.xoffset = xoffset;
	temp.mouseScroll.yoffset = yoffset;
	eventTypeList.push_back(EventTypes::MouseScroll);
	eventList.push_back(temp);
}

void EventHandler::joystick_callback(int jid, int event)
{
	events temp;
	temp.joystick.jid = jid;
	temp.joystick.event = event;
	eventTypeList.push_back(EventTypes::Joystick);
	eventList.push_back(temp);
}

void EventHandler::drop_callback(GLFWwindow* window, int count, const char** paths)
{
	events temp;
	temp.drop.count = count;
	temp.drop.paths = paths;
	eventTypeList.push_back(EventTypes::Drop);
	eventList.push_back(temp);
}

//Window callbacks

void EventHandler::window_close_callback(GLFWwindow* window)
{
	events temp;
	eventTypeList.push_back(EventTypes::Closed);
	eventList.push_back(temp);
}

void EventHandler::window_size_callback(GLFWwindow* window, int width, int height)
{
	events temp;
	temp.sizeChanged.width = width;
	temp.sizeChanged.height = height;
	eventTypeList.push_back(EventTypes::SizeChanged);
	eventList.push_back(temp);
}

void EventHandler::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	events temp;
	temp.bufferChanged.width = width;
	temp.bufferChanged.height = height;
	eventTypeList.push_back(EventTypes::BufferChanged);
	eventList.push_back(temp);
}

void EventHandler::window_content_scale_callback(GLFWwindow* window, float xscale, float yscale)
{
	events temp;
	temp.scaleChanged.xscale = xscale;
	temp.scaleChanged.yscale = yscale;
	eventTypeList.push_back(EventTypes::ScaleChanged);
	eventList.push_back(temp);
}

void EventHandler::window_pos_callback(GLFWwindow* window, int xpos, int ypos)
{
	events temp;
	temp.windowMoved.xpos = xpos;
	temp.windowMoved.ypos = ypos;
	eventTypeList.push_back(EventTypes::WindowMoved);
	eventList.push_back(temp);
}

void EventHandler::window_iconify_callback(GLFWwindow* window, int iconified)
{
	events temp;
	temp.iconified.iconified = iconified;
	eventTypeList.push_back(EventTypes::Iconified);
	eventList.push_back(temp);
}

void EventHandler::window_maximize_callback(GLFWwindow* window, int maximized)
{
	events temp;
	temp.maximized.maximized = maximized;
	eventTypeList.push_back(EventTypes::Maximized);
	eventList.push_back(temp);
}

void EventHandler::window_focus_callback(GLFWwindow* window, int focused)
{
	events temp;
	temp.focused.focused = focused;
	eventTypeList.push_back(EventTypes::Focused);
	eventList.push_back(temp);
}

void EventHandler::window_refresh_callback(GLFWwindow* window)
{
	events temp;
	eventTypeList.push_back(EventTypes::Refresh);
	eventList.push_back(temp);
}
